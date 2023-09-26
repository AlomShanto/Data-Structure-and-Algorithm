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
    string s,s1;
    cin>>s>>s1;
    if(s1.length()>s.length())
    {
        cout<<"Case "<<cs<<": 0"<<endl;
        return;
    }
    ll ans=0;

    ll needHash =0,currHash=0,power = 1;
    for(int i=0; i<s1.length(); i++)
    {
        needHash = (needHash*base + s1[i]-'a'+1)%mod;
        currHash = (currHash*base + s[i]-'a'+1)%mod;

        //cout<<needHash<<" ::--> "<<currHash<<endl;
        if(i>0)
        {
            power=(power*base)%mod;
        }
    }
    ans=(needHash==currHash);

    for(int i=s1.length(); i<s.length(); i++)
    {
        currHash -= ((power*(s[i-s1.length()]-'a' +1 ))%mod);
        if(currHash<0)currHash+=mod;
        currHash = (currHash*base + s[i]-'a'+1)%mod;

        //cout<<i<<" --> "<<needHash<<" "<<currHash<<endl;

        if(needHash==currHash)ans++;

    }

    cout<<"Case "<<cs<<": "<<ans<<endl;

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



