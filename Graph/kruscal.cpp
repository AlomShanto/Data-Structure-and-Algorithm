///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s,a) sort(s.begin(),s.end(),a)
const ll mx = 1e6+7;

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
vector<pair<ll,ll>>v[mx];
ll parent[mx],cost[mx], mstValue=0, cnt=0,visited[mx];

bool cmp(edge a, edge b)
{
    return a.w<b.w;
}

int _find(ll src)
{
    if(parent[src]==src)
        return src;
    return parent[src]=_find(parent[src]);
}

void initPar(ll src)
{
    for(ll i=0 ; i<src ; i++)
    {
        parent[i]=i;
    }
}
void kruskals_Algorithm(ll n)
{
    srt(graph,cmp);
    initPar(n);
    for(ll i=0; i<graph.size() ; i++)
    {
        ll up=_find(graph[i].u);
        ll vp=_find(graph[i].v);

        if(up!=vp)
        {
            if(cnt==n-1)
                break;
            output.push_back(graph[i]);
            mstValue+=graph[i].w;
            parent[up]=vp;
            cnt++;
        }
    }

}

void bfs(ll src, ll siz)
{
    visited[src]=1;
    queue<ll>q;
    q.push(src);
    while(q.size()>0)
    {
        ll src1=q.front();
        q.pop();
        for(auto x:v[src1])
        {
            if(!visited[x.first])
            {
                visited[x.first]=1;
                cost[x.first]=max(cost[src1],x.second);
                q.push(x.first);
            }
        }
    }
    for(int i=0; i<siz; i++)
    {
        if(cost[i]==0)
        {
            if(i==src)
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<"Impossible"<<endl;
            }
        }
        else
        {
            cout<<cost[i]<<endl;
        }
    }
    for(ll i=0; i<=siz; i++)
    {
        v[i].clear();
        cost[i]=0;
        visited[i]=0;
        parent[i]=i;
    }
    graph.clear();
    output.clear();
    mstValue=0;
    cnt=0;
}

int main()
{

    ll t=1,cc=1;
    cin>>t;
    while(t--)
    {
        cout<<"Case "<<cc++<<":"<<endl;
        ll k, m, a, b, c, d;
        ll n, e;
        cin>>n>>e;

        for(ll i=0 ; i<e ; i++)
        {
            ll u, v, w;
            cin>>u>>v>> w;

            edge input;
            input.u=u;
            input.v=v;
            input.w=w;
            graph.push_back(input);
        }

        kruskals_Algorithm(n);
        for(int i=0; i<output.size(); i++)
        {
            v[output[i].u].push_back({output[i].v,output[i].w});
            v[output[i].v].push_back({output[i].u,output[i].w});
        }
        ll src;
        cin>>src;
        bfs(src,n);
    }
}
