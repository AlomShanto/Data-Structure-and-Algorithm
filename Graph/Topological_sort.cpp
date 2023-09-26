///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
#define ll long long
#define srt(s) sort(s.begin(),s.end())
using namespace std;

int n;
vector<int> graph[1000000];
int visited[1000000];///this one is used for detecting Cycle
bool vis[1000000];

stack<int>st;

bool cycleFound(int src)
{
    if(visited[src]==1) return true;

    if(visited[src]==2) return false;

    visited[src]=1;
    for(auto v: graph[src])
        if(cycleFound(v)) return true;

    visited[src]=2;
    return false;
}
bool detectCycle()
{
    for(int u=1; u<=n; u++)
    {
        if(!visited[u])
            if(cycleFound(u)) return true;
    }

    return false;
}

void Dfs(int u)
{
    vis[u]=true;
    //cout<<u<<" xx ";
    for(auto v: graph[u])
    {
        if(!vis[v])
            Dfs(v);
    }
    //cout<<endl;
    st.push(u);
}

int main ()
{
    int m,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        graph[u].push_back(v);
    }
    for(int i=n; i>=1; i--)
    {
        if(!vis[i])
        {
            Dfs(i);
        }
    }

    if(detectCycle())
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        while(!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
}
