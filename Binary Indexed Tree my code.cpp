#include<bits/stdc++.h>
using namespace std;
int arr[100],tree[100];
void update(int val,int index,int n)
{
    for( ; index<=n ; index = index + (index & (-index)))
    {
        tree[index] = tree[index] + val;
    }
}
int query(int index)
{
    int sum = 0;
    for( ; index>0 ; index = index - (index & (-index)))
    {
        sum = sum + tree[index];
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
        update(arr[i],i,n);
    }
    int q1,q2;
    cin>>q1>>q2;
    cout<<query(q2)-query(q1)+arr[q1]<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    update(3,3,n);
    cout<<query(10)<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<tree[i]<<" ";
    }
}
/*
10
1 2 3 4 5 6  7 8 9 12
*/
