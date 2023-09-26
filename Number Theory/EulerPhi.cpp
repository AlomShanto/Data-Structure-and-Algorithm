#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int phi[5000005];
unsigned long long sum[5000005];
void init(ll maxN)
{
    for(int i=2; i<=maxN; i++)
        phi[i] = i;

    for(int i =2; i<=maxN; i++)
    {
        if(phi[i]==i)
        {
            for(int j=i; j<=maxN; j+=i)
                phi[j]-=phi[j]/i;
        }
    }
    sum[1]=0;
    for(ll i = 2; i <= maxN; i++)
    {
        //cout<<i<<" "<<phi[i]<<" "<<cnt[i-1]<<endl;
        sum[i] = (phi[i]);
        sum[i]*=phi[i];

        sum[i]+=sum[i-1];
        //cout<<cnt[i]<<endl;
    }
}
int main()
{

    init(5000000);
    int t = 1;
    scanf("%d",&t);
    int p = 1;
    while(t--)
    {
        int a, b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        unsigned long long ans;

        ans = sum[b]-sum[a-1];
        //cout<<"Case "<<p<<": "<<ans<<endl;
        printf("Case %d: %llu\n",p,ans);
        p++;
    }
    return 0;
}


