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

const int mx = 500000 + 7;
int sz=0;

struct Node{
    bool isEnd = false;
    int nxt[26];

    Node()
    {
        isEnd = false;
        memset(nxt,-1,sizeof(nxt));
    }
};

Node trie[mx+7];

void insertIntoTrie(string s)
{
    int now=0;
    int cnt = 0;
    for(auto ch:s)
    {
        cnt++;
        int d = ch-'a';
        if(trie[now].nxt[d]==-1)
        {
            trie[now].nxt[d]=++sz;
        }
        now=trie[now].nxt[d];

    }
    trie[now].isEnd = true;
}

int dfs(int src, string &s1)
{
    int cnt=trie[src].isEnd;

    for(int i=0; i<26; i++)
    {
        if(~trie[src].nxt[i])
        {
            s1+=(i+'a');

            if(trie[trie[src].nxt[i]].isEnd==true)cout<<s1<<endl;
            cnt+=dfs(trie[src].nxt[i],s1);
            s1.pop_back();
        }
    }
    return cnt;
}

int searchInTrie(string s)
{
    int now=0;
    int cnt = 0;
    bool ok=true;
    for(auto ch:s)
    {
        int d = ch-'a';
        if(trie[now].nxt[d]==-1)
        {
            ok = false;
            break;
        }
        now=trie[now].nxt[d];
    }

    if(!ok) return 0;
    for(int i=0; i<26; i++)
    {
        string s1=s;
        if(~trie[now].nxt[i])
        {
            s1+=(i+'a');
            if(trie[trie[now].nxt[i]].isEnd==true)
            {
                cout<<s1<<endl;
            }
            int d = dfs(trie[now].nxt[i],s1);

            cnt+=d;
        }

    }
    return cnt;
}



void solve(int cs)
{

    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        insertIntoTrie(s);
    }

    int k;
    cin>>k;

    for(int i=1; i<=k; i++)
    {
        cout<<"Case #"<<i<<":"<<endl;
        string s;
        cin>>s;
        int d = searchInTrie(s);

        if(d==0)
        {
            cout<<"No match."<<endl;
        }
    }



}
int main()
{
    FastRead

    int test_case=1,cs=1;
    //cin>>test_case;
    while(test_case--)
    {
        solve(cs++);
    }
    return 0;
}

