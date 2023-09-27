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

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(int cs)
{
    string s,s1;
    cin>>s;

    s1=s;
    reverse(s1.begin(),s1.end());

    s = s + "#" + s1;

    vector<int> v = prefix_function(s);

    int mx=0;
    //cout<<s<<endl;
    for(int i=(s.length()/2); i<v.size(); i++)
    {
        mx=max(mx,v[i]);
        //cout<<i<<" "<<v[i]<<endl;
    }

    for(int i=mx-1; i>=0; i--)
    {
        cout<<s[i];
    }
    cout<<endl;

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
