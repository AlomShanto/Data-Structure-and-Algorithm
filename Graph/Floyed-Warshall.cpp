///BISMIintAHIR-RAHMANIR-RAHIM///
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll mx=6006,INF=LONG_MAX;
int n,m,q;
ll mat[mx][mx];
void floyed_warshall()
{
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(mat[i][j]>(mat[i][k]+mat[k][j]) && mat[i][k]!=INF && mat[k][j]!=INF)
                {
                    mat[i][j]=mat[i][k]+mat[k][j];
                }
            }
        }
    }
}
int main()
{
    FastRead
    ll t=1,c=1;
    //cin>>t;
    while(t--)
    {
        cin>>n>>m>>q;
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                if(i==j)mat[i][j]=0;
                else mat[i][j]=INF;
            }
        }
        while(m--)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            mat[a][b]=min(mat[a][b],c);
            mat[b][a]=min(mat[b][a],c);
        }
        floyed_warshall();
        while(q--)
        {
            ll a,b;
            cin>>a>>b;
            if(mat[a][b]==INF)
            {
                cout<<-1<<endl;
                continue;
            }
            cout<<mat[a][b]<<endl;
        }
    }
}
