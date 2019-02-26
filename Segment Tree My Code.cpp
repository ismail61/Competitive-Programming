#include<bits/stdc++.h>
using namespace std;
#define mx 10001
int arr[mx];
int tree[mx*3];
void buildTree(int node,int start,int endd)
{
    if(start==endd)
    {
        tree[node] = arr[start];
        return;
    }
    int left = node * 2;
    int right = node * 2 +1;
    int mid = (start + endd) / 2;
    buildTree(left,start,mid);
    buildTree(right,mid+1,endd);
    //tree[node]= max(tree[left] , tree[right]);
    tree[node] = tree[left] + tree[right];
}
int query(int node,int start,int endd,int i,int j)
{
    if(j < start or i > endd)
    {
        return 0;
    }
    if(start >= i and endd <= j)
    {
        return tree[node];
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (start + endd) / 2;
    int q1 = query(left,start,mid,i,j);
    int q2 = query(right,mid+1,endd,i,j);
    //return max(q1,q2);
    return q1 + q2;
}
void updateValue(int node,int start,int endd,int index,int value)
{
    if(index < start or index > endd)
    {
        return;
    }
    if(start >= index and endd <= index)
    {
        tree[node] = value;
        return;
    }
    int left = node * 2;
    int right = node * 2 + 1;
    int mid = (start + endd) / 2;
    updateValue(left,start,mid,index,value);
    updateValue(right,mid + 1,endd,index,value);
    tree[node] = tree[left] + tree[right];
}
int main()
{
    int n;
    cin>>n;
    for(int i=1 ; i<=n ;i++)
    {
        cin>>arr[i];
    }
    int node=1;
    int start=1;
    int endd=n;
    buildTree(node,start,endd);
    int i,j;
    cin>>i>>j;
    int sum = query(node,start,endd,i,j);
    cout<<sum<<endl;
    int index,value;
    cin>>index>>value;
    updateValue(node,start,endd,index,value);
    int sums = query(node,start,endd,i,j);
    cout<<sums<<endl;
}
