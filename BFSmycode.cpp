#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MOD 1000000007
#define mul(num) (num)*(num)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define newline printf("\n")
#define ios ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
int arr[100][100];
int v,e;
int label[1000];
vector<int>matrixList[100];
int store_previous_node[100];///path
void BFS(int start,int finish)
{
    bool visited[1000];
    memset(visited,0,sizeof visited);///false
    visited[start]=1;///true

    memset(store_previous_node,-1,sizeof store_previous_node);
    memset(label,0,sizeof label);

    label[start]=0;

    queue<int>qu;
    qu.push(start);

    //cout<<"hi1"<<endl;
    while(!qu.empty())
    {
        int num = qu.front();
        //cout<<num<<endl;
        qu.pop();
        for(int i=0; i<matrixList[num].size(); i++)
        {
            //cout<<"hi2"<<endl;
            int v = matrixList[num][i];
            //cout<<v<<endl;
            if(visited[v]==0) ///if v is not visit
            {
                qu.push(v);
                //cout<<v<<" ";
                visited[v]=1;
                label[v] = label[num]+1;///label has been increased by 1
                //cout<<label[v]<<endl;
                store_previous_node[v]=num;
            }
        }
        matrixList[num].clear();
    }
    printf("%d\n",abs(label[start]-label[finish]));
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        //printf("Enter the vertex ");
        scanf("%d",&v);
//        printf("Enter the edge ");
//        scanf("%d",&e);
        int e=v;

        for(int i=0; i<v; i++)
        {
            for(int j=0; j<e; j++)
            {
                scanf("%d",&arr[i][j]);
                if(arr[i][j]==1)
                    matrixList[i].push_back(j);
            }
        }
//        for(int i=0; i<v; i++)
//        {
//            printf("%d : ",i);
//            for(int j=0; j<matrixList[i].size(); j++)
//            {
//                printf("%d ",matrixList[i][j]);
//            }
//            newline;
//        }
        int st,en;
        scanf("%d%d",&st,&en);
        BFS(st,en);

        vector<int> path;
        path.push_back(en);

//        for(int i=1;i<=en;i++)
//        {
//            cout<<store_previous_node[i]<<" ";
//        }newline;

        while (store_previous_node[en] != -1)
        {
            path.push_back(store_previous_node[en]);
            en = store_previous_node[en];
        }
        //cout << "\nPath is::\n";
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
        newline;
    }


}
