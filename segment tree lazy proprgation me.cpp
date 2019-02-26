#include<bits/stdc++.h>
using namespace std;
#define mx 10001
int arr[mx];
struct node{
    int sum,pro;
}tree[mx*3];
int query(int node,int b,int e, int i,int j,int carry=0)
{
    if(i>e or j< b)
    {
        return 0;
    }
    if(b>= i and e<= j)
    {
        return tree[node].sum + (carry * (e-b+1));
    }
    int left = node *2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    int q1=query(left,b,mid,i,j,carry+tree[node].pro);
    int q2=query(right,mid+1,e,i,j,carry+tree[node].pro);
    return q1+q2;
}
void updateRange(int node, int b,int e,int i,int j,int val)
{
    if(i>e or j<b)
    {
        return;
    }
    if( b>= i and e <= j)
    {
        tree[node].sum += (e-b+1)*val;
        tree[node].pro += val;
        return;
    }
    int left = node *2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    updateRange(left,b,mid,i,j,val);
    updateRange(right,mid+1,e,i,j,val);
    tree[node].sum = tree[left].sum + tree[right].sum + (e-b+1)*tree[node].pro;

}
void buildTree(int node,int b,int e)
{
    if(b==e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = node *2;
    int right = node * 2 + 1;
    int mid = (b+e)/2;
    buildTree(left,b,mid);
    buildTree(right,mid+1,e);
    tree[node].sum = tree[left].sum + tree[right].sum;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    buildTree(1,1,n);
    ///updateRange(node,begin,end,i,j,val);
    updateRange(1,1,n,1,4,2);
    cout<<query(1,1,n,1,n,0);
    updateRange(1,1,n,1,4,2);
    cout<<query(1,1,n,1,n,0);
}

