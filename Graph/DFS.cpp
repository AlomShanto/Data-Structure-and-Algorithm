#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[1000000];
vector<ll>v[1000000];
vector<ll>v1[1000000];
ll visited[1000000];
ll mod=pow(2,32);
void Dfs(int src)
{
    visited[src]=1;
    for(int i=0; i<v[src].size(); i++)
    {
        ll x=v[src][i];
        if(!visited[x])
        {
            v1[x]=v1[src];
            v1[x].push_back(arr[x]);
            Dfs(x);
        }
    }
}
int main()
{
    ll n,q;
    cin>>n>>q;
    ll a,b;
    for(int i=1; i<=n; i++)
    {
        cin>>a;
        arr[i]=a;
    }
    for(int i=1; i<n; i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
    }
    v1[1].push_back(arr[1]);
    Dfs(1);
    while(q--)
    {
        cin>>a>>b;
        ll dot=0;
        for(int i=0; i<v1[a].size(); i++)
        {
            cout<<v1[a][i]<<" "<<v1[b][i]<<" ";
            dot+=(v1[a][i]*v1[b][i])%mod;
        }
        cout<<dot<<endl;
    }

}
