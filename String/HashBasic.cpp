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
const ll mod = 1000001137;
ll base = 2551;

void solve(int cs)
{
    string s;
    cin>>s;

    ll ans=0;

    ll hashVal = 0,revHashVal=0,power = 1;
    for(int i=s.length()-1; i>=0; i--)
    {
        hashVal = (hashVal*base + s[i]-'a'+1)%mod;
        revHashVal = (revHashVal + ((s[i]-'a'+1)*power)%mod)%mod;

        //cout<<hashVal<<" ::--> "<<revHashVal<<endl;
        power=(power*base)%mod;

        if(hashVal==revHashVal)
        {
            ans=s.length()-i;
        }
    }
    cout<<"Case "<<cs<<": "<<s.length()*2-ans<<endl;

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




