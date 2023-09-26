///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll arr[20][20];
ll n;
ll dp[20][(1<<16)+10];

ll bitmaskdp(ll i, ll mask)
{
    if(mask==((1<<n)-1))return 0;

    if(~dp[i][mask]) return dp[i][mask];

    ll ans=0;

    for(int j=0; j<n; j++)
    {
        if((mask&(1<<j))==0)
        {
            ans=max(ans,arr[i][j]+bitmaskdp(i+1,mask|(1<<j)));
        }
    }

    return dp[i][mask]=ans;
}
void solve(int cs)
{
    cout<<"Case "<<cs<<": ";

    cin>>n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    cout<<bitmaskdp(0,0)<<endl;

}
int main()
{
    FastRead

    int test_case=1,cs=1;
    cin>>test_case;
    //scanf("%d",&test_case);

    while(test_case--)
    {
        solve(cs++);
    }
}
