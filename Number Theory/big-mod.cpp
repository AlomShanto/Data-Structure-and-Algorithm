#include<bits/stdc++.h>
using namespace std;

int pow1(long long a,long long b)
{
    long long sol1 =1;
    long long int mod = 1e9+7;
    while(b>0)
    {
        if((b&1)!=0)
        {
            sol1 = (sol1*(a%mod))%mod;
        }
        a = ((a%mod)*(a%mod))%mod;
        b=b>>1;
    }
    return sol1;
}

int main()
{
    ll n
    cin>>n;
    while(n--)
    {
        long long a,b,c,d;
        cin>>a>>b;
        long long ans = pow1(2,a);
    }
}
