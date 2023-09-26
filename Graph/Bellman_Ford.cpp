///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mx=5050,INF=1e18;
ll n,m,u,v,w;
vector<tuple<ll,ll,ll>>e(mx);
ll dist[mx];
ll parent[mx];
void bellman_ford()
{
    int mark=0;
    for(int j=1; j<=n; j++)
    {
        mark=0;
        for(int i=0; i<m; i++)
        {
            tie(u,v,w)=e[i];
            //cout<<u<<" "<<v<<" "<<vis[u]<<" "<<vis1[v]<<" "<<dist[u]<<" "<<dist[v]<<" "<<w<<endl;
            if((dist[u]+w)<dist[v])
            {
                dist[v]=dist[u]+w;
                parent[v]=u;
                mark=1;
                //cout<<v<<" "<<dist[v]<<endl;
            }
        }
    }
    if(mark==0)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        ll last;
        for(int j=1; j<=n-1; j++)
        {
            for(int i=0; i<m; i++)
            {
                tie(u,v,w)=e[i];
                //cout<<u<<" "<<v<<" "<<vis[u]<<" "<<vis1[v]<<" "<<dist[u]<<" "<<dist[v]<<" "<<w<<endl;
                if((dist[u]+w)<dist[v])
                {
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                    last=v;
                    //cout<<v<<" "<<dist[v]<<endl;
                }
            }
        }
        for(int i=1; i<=n+10; i++)
        last = parent[last];
        //cout<<last<<endl;
        cout<<"YES"<<endl;
        vector<ll>ans;
        ans.push_back(last);
        ll src=parent[last];
        while(1)
        {
            ans.push_back(src);
            if(src==last)
            {
                //cout<<endl;
                break;
            }
            src=parent[src];
        }
        for(int i=ans.size()-1; i>=0; i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    FastRead
    int t=1,c=1;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=0; i<=n; i++)
        {
            dist[i]=INF;
        }
        int j=0;
        dist[1]=0;
        while(j<m)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            e[j]= {a,b,c};
            j++;
        }
        bellman_ford();
    }
}
