///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
const int mx =1e6;
int parent[mx];
int n,m;
void dijkstra(int src, vector<pair<int,int>>adj[])
{
    vector<ll> dist(n+10, LONG_LONG_MAX);
    priority_queue< pair<int,int>, vector<pair<int,int>>,
    greater<pair<int,int>> > pq;
    pq.push({0,src});
    dist[src] = 0;
    while(pq.size()>0)
    {
        pair<int, int> cur=pq.top();
        pq.pop();
        int u=cur.second;
        int d=cur.first;

        if(d>dist[u])
        {
            continue;
        }
        for(int i=0; i<adj[u].size(); i++ )
        {
            int v =adj[u][i].first;
            int d1=adj[u][i].second;
            if(dist[u]+d1<dist[v] )
            {
                parent[v]=u;
                dist[v]=dist[u]+d1;
                pq.push({dist[v],v});
            }
        }
    }
    int ans=dist[n];
    cout<<ans<<endl;

}
int main()
{
    cin>>n>>m;
    vector<pair<int,int>>adjList[n+10];
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adjList[a].push_back({b,c});
    }
    parent[1]=1;
    dijkstra(1,adjList);
}
