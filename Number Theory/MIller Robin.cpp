///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll __int128
#define srt(s) sort(s.begin(),s.end())
#define rsrt(s) sort(s.rbegin(),s.rend())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define U unsigned int
int dx[]= {1,-1,0,0};
int dy[]= {0,0,-1,1};

long long n;

ll read()
{
    string s;
    cin>>s;
    ll x=0;
    for(int i=0; i<s.length(); i++)
    {
        x*=10;
        x+=(s[i]-'0');
    }
    return x;
}

ll pow1(ll a,ll b, ll mod)
{
    long long sol1 =1;
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

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}



void solve(int cs)
{
    cin>>n;
    if(MillerRabin(n))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

