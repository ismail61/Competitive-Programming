#include <stdio.h>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node (int dat) {
        this->data = dat;
        this->left = NULL;
        this->right = NULL;
    }
};

void inOrderTraverse (Node *root) {
    if (root != NULL) {
        inOrderTraverse(root->left);
        printf("%d ", root->data);
        inOrderTraverse(root->right);
    }
}

Node* minValueNode (Node* node) {
    Node* current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

Node* deleteNode (Node* root, int dat) {
    if (root == NULL) {
        return root;
    }
    if (dat < root->data) {
        root->left = deleteNode(root->left, dat);
    }
    else if (dat > root->data) {
        root->right = deleteNode(root->right, dat);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            root =  NULL;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            root =  NULL;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

Node* insert (Node* root, int dat) {
    if (root == NULL) {
        return new Node(dat);
    }
    else if (dat < root->data) {
        root->left = insert(root->left, dat);
    }
    else {
        root->right = insert(root->right, dat);
    }
    return root;
}


int main() {
    Node* root = NULL;
    root = insert(root, 10);
    insert(root,9);
    insert(root,3);
    insert(root,91);
    insert(root,1);
    insert(root,5);
    insert(root,200);
    insert(root,2);
    inOrderTraverse(root);
    deleteNode(root, 9);
    inOrderTraverse(root);
    deleteNode(root, 2);
    inOrderTraverse(root);
    return 0;
}
