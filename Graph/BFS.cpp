#include<bits/stdc++.h>
using namespace std;
int level[1000000];
int bfs(vector<int>v[], int source, int destination)
{
    queue<int>q;
    int p=0;
    q.push(source);
    level[source]=0;
    while(q.size()>0)
    {
        int d;
        d=q.front();
        q.pop();
        for(int i=0; i<v[d].size(); i++)
        {
            if(level[v[d][i]]==p)
            {
                level[v[d][i]]=level[d]+1;
                q.push(v[d][i]);
            }
        }

    }
    return level[destination];
}
int main()
{
    int dist,edge;
    cin>>dist>>edge;
    vector<int>edges[dist+10];
    int dist1,dist2;
    for(int i=1; i<=edge; i++)
    {
        cin>>dist1>>dist2;
        edges[dist1].push_back(dist2);
        edges[dist2].push_back(dist1);
    }
    int pos;
    cin>>pos;
    for(int i=1; i<=dist; i++)
    {
        if(i==pos)
        {
            int time=0;
            printf("Shortest time to reach %d city : %d\n",i,time);
            continue;
        }

        int time=bfs(edges,pos,i);
        printf("Shortest time to reach %d city : %d\n",i,time);

    }
    return 0;
}

