#include<bits/stdc++.h>
using namespace std;

int matrix[100][100],node,edges,parent[100];

typedef pair<int,int> ipair;
priority_queue<ipair, vector<ipair>, greater<ipair> >q;

void dijkstra(int dist[])
{
    while(!q.empty())
    {
        int i,src;
        pair<int,int>top;
        top=q.top();
        q.pop();

        //src=top.second;
//        visit[src]=1;
        //cout << " -> " << top.first << " " << top.second << endl;
        for(i=0; i<=node; i++)
        {
            if(matrix[src][i]!=0 && dist[src]+matrix[src][i]<dist[i])
            {
                dist[i]=dist[src]+matrix[src][i];
                parent[i]=src;
                //cout << i << " " << dist[i] << endl;
                q.push({dist[i],i});
            }
        }
    }
}

void getroot(int i)
{
    if(parent[i]==-1)
        {
        cout << i ;
        return;
        }
    else
    {
        cout << i << " <- " ;
        getroot(parent[i]);
    }
}

int main()
{
    int i,a,b,weight,src;
    cin >> node >> edges;
    int dist[node];
    for(i=0; i<node; i++)
        dist[i]=INT_MAX;

    for(i=0; i<edges; i++)
    {
        cin >> a >> b >> weight;
        matrix[a][b]=weight;
        matrix[b][a]=weight;
    }
    cin >> src;
    dist[src]= 0 ;
    parent[src]=-1;
    q.push({dist[src],src});
    dijkstra(dist);
  //  cout <<endl <<endl;
    for(i=0;i<node;i++)
    {
        cout << "Path ";
        getroot(i);
        cout << endl << "Node:" <<i << "   Distance:" << dist[i] << endl;
    }
}

/**
6 7
0 1 2
0 2 3
1 4 2
1 2 1
1 3 4
2 5 1
3 5 1
0
**/

