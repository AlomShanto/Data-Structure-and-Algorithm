///BISMILLAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define U unsigned int

const int MOD = 1000000007;
const int MAX = 100000001;

bool prime[MAX];
U arr[MAX];
vector<int>v;
int cnt=1;

void sieve ()
{
    U i,j;

    arr[2] = 1;

    prime[0] = prime[1] = true;

    for (i=4; i<MAX; i+=2)
        prime[i] = true;

    v.push_back(2);
    for (i=3; i*i<MAX; i+=2)
        if (!prime[i]){

            for (j=i*i; j<MAX; j+=2*i)
                prime[j] = true;
        }

    for (i=3; i<MAX; i+=2)
    {
        if (!prime[i]){
                cnt++;
                v.push_back(i);
            arr[i+1] = arr[i] = arr[i-1]+1;
        }
        else
            arr[i+1] = arr[i] = arr[i-1];
    }
}
int main()
{
    sieve();
    //cout<<v.size()<<endl;

    cout<<v[0]<<endl;
    ll q;
    cin>>q;
    while(q--)
    {
        ll order;
        cin>>order;
        ll d=upper_bound(v.begin(),v.end(),order)-v.begin();
        cout<<d<<endl;
    }
}
