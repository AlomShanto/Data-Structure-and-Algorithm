///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define U unsigned int
int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};

ll trailingZero(ll n)
{
    ll ans = 0;
    ll k = 5;
    while(n/k>0){
        ans += n/k;
        k *= 5;
    }
    return ans;
}

void solve(int cs)
{
    ll q;
    cin>>q;

    ll l=1,r=1e9,up=-1;
    while(l<=r)
    {
        ll mid=(l+r)/2;

        if(trailingZero(mid)==q)
        {
            up=mid;
            r=mid-1;
        }
        else if(trailingZero(mid)>q)
        {
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<"Case "<<cs<<": ";
    if(up==-1)
    {
        cout<<"impossible"<<endl;
        return;
    }
    cout<<up<<endl;
}
int main()
{
    FastRead

    int test_case=1,cs=1;
    cin>>test_case;
    while(test_case--)
    {
        solve(cs++);
    }
    return 0;
}

