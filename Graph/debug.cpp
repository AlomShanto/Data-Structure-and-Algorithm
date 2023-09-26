#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ff first;
#define ss second;

double PI = 3.14159265358979323846;

int main()
{
    FastRead
    ll t = 1;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;

        string s;
        cin>>s;

        if(n%2 != 0)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            ll o = 0, z = 0;

            for(ll i = 0; i < n; i++)
            {
                if(s[i] == '1')
                {
                    o++;
                }
                else
                {
                    z++;
                }
            }

            if(o == z)
            {
                cout<<"YES"<<endl;
                cout<<1<<" "<<n<<endl;
            }
            else if(o > z)
            {
                ll k = (n/2)-z;

                ll cnt = 0, mni = 10e6, mark = 0;

                for(ll i = 0; i < n; i++)
                {
                    if(s[i] == '1')
                    {
                        cnt++;
                        mni = min(mni, i);

                        if(cnt == k)
                        {
                            cout<<"YES"<<endl;
                            cout<<mni+1<<" "<<i+1<<endl;
                            break;
                        }
                    }
                    else
                    {
                        mni = 10e6;
                        cnt = 0;
                    }
                }
            }
            else
            {
                ll k = (n/2)-o;

                ll cnt = 0, mni = 10e6, mark = 0;

                for(ll i = 0; i < n; i++)
                {
                    if(s[i] == '0')
                    {
                        cnt++;
                        mni = min(mni, i);

                        if(cnt == k)
                        {
                            cout<<"YES"<<endl;
                            cout<<mni+1<<" "<<i+1<<endl;
                            break;
                        }
                    }
                    else
                    {
                        mni = 10e6;
                        cnt = 0;
                    }
                }
            }
        }
    }
    return 0;
}
