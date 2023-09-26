///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int mx=1e6;
int last=-1,top;
vector<int>v[mx];
int visited[mx];
int parent[mx];
void dfs(int src)
{
    //cout<<src<<" "<<last<<endl;
    visited[src]=1;
    for(auto x:v[src])
    {
        if(!visited[x])
        {
            parent[x]=src;
            dfs(x);
        }
        else if(parent[src]!=x)
        {
            //cout<<src<<" "<<x<<" "<<parent[src]<<endl;
            if(last==-1)
            {
                top=x;
                last=src;
                parent[x]=src;
            }
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++)
    {
        //cout<<i<<" XX "<<last<<endl;
        if(last>-1)
        {
            break;
        }
        if(!visited[i])
        {
            if(v[i].size()==0)
            {
                continue;
            }
            //cout<<i<<" ";
            parent[i]=v[i][0];
            dfs(i);
        }
    }
    if(last==-1)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        vector<int>ans;
        ans.push_back(top);
        ll cnt=0;
        //cout<<top<<" XX "<<last<<endl;
        while(1)
        {
            cnt++;
            //cout<<last<<" cc "<<top<<endl;
            ans.push_back(last);
            last=parent[last];
            if(last==top)
            {
                ans.push_back(last);
                break;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1; i>=0; i--)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}

