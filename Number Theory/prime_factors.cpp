#include <bits/stdc++.h>
using namespace std;

#define MAXN   100010
#define ll long long

int spf[MAXN];
map<ll,vector<ll>>mp;

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        spf[i] = i;

    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)

                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

///LogN
vector<int> getFactorization(int x)
{
    vector<int> ret;
    map<ll,ll>mp1;
    while (x != 1)
    {
        if(mp1[spf[x]]==0)
            ret.push_back(spf[x]);
        mp1[spf[x]]++;
        x = x / spf[x];
    }
    return ret;
}

void pre()
{
    for(int i=2; i<=100000; i++)
    {
        vector<int>d=getFactorization(i);
        mp[d.size()].push_back(i);
    }
}
int main(int argc, char const *argv[])
{
    sieve();
    pre();

    ll t;
    cin>>t;
    while(t--)
    {
        ll a,b,k;
        cin>>a>>b>>k;
        ll d=upper_bound(mp[k].begin(),mp[k].end(),b)-mp[k].begin();
        ll d1=lower_bound(mp[k].begin(),mp[k].end(),a)-mp[k].begin();
        //cout<<d<<" "<<d1<<endl;
        cout<<d-d1<<endl;
    }
}

