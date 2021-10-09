//DFS

#include <bits/stdc++.h>

using namespace std;

#define SZ 100
vector <int> graph[SZ];
bool visited[SZ];

void DFS(int now)
{
    visited [now] = true;
    printf("Now VIsiting %d\n",now);

    int i,to,k;
    k = graph[now].size();
    for(i =0; i<k; i++)
    {
        to = graph[now][i];
        if(visited[to] == false)
        {
            DFS(to);
        }
    }
    return;
}

int main()
{
    int vertics,edges,from,to,i;
    while(scanf("%d %d",&vertics,&edges))
    {
        for ( i = 0; i< vertics; i++)
        {
            graph[i].clear();
            visited[i] = false;
        }
        for(i = 0; i < edges; i++)
        {
            scanf("%d %d",&from,&to);
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for (i =1; i < vertics; i++)
        {
            if(visited[i] == false)
            {
                //printf("root ----->>>> %d\n",i);
                DFS(i);
            }
        }
    }
    return 0;
}

