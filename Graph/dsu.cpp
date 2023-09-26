///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s,a) sort(s.begin(),s.end(),a)
const ll mx = 1e6+7;

ll siz[mx],parent[mx];

void make_set(ll x)
{

    for(ll i=0; i<=x; i++)
    {
        parent[i] = i;
        siz[i] = 1;
    }
}

ll find_set(ll x)
{
    if (x == parent[x])
        return x;
    return parent[x] = find_set(parent[x]);
}

void union_sets(ll a, ll b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (siz[a] < siz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }
}

int main()
{

    ll t=1,c=1;
    //cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        make_set(n);
        vector<pair<ll,ll>>destroy;
        vector<ll>ans;
        map<ll,ll>mp;
        for(int i=0; i<n-1; i++)
        {
            ll u,v;
            cin>>u>>v;
            if(find_set(u)==find_set(v))
            {
                destroy.push_back({u,v});
                continue;
            }
            union_sets(u,v);
        }
        for(ll i=1; i<=n; i++)
        {
            ll par=find_set(i);
            if(mp[par]==0)
            {
                ans.push_back(par);
                mp[par]++;
            }
        }

        if(ans.size()==1)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<ans.size()-1<<endl;
            ll j=0;
            for(int i=0; i<ans.size()-1; i++)
            {
                cout<<destroy[j].first<<" "<<destroy[j++].second<<" "<<ans[i]<<" "<<ans[i+1]<<endl;
            }
        }
    }
}
