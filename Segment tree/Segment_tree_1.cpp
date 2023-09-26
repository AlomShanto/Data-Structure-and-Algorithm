#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(s) sort(s.begin(),s.end())
#define mx 1000000
int st[4*mx+10],lazy[4*mx+10];
void build_tree(int a[], int i, int low, int high)
{
    if(low==high)
    {
        st[i]=a[low];
    }
    else
    {
        int mid=(low+high)/2;
        build_tree(a, 2*i, low, mid);
        build_tree(a, 2*i+1, mid+1, high);

        st[i]= st[2*i]+st[2*i+1];
    }
}
int query(int i, int low, int high, int left, int right)
{
    if(left>high || right<low)
    {
        return 0;
    }
    if(low>=left && high<=right)
    {
        return st[i];
    }
    int mid=(low+high)/2;
    int l=query(2*i, low, mid, left, right);
    int r=query(2*i+1, mid+1, high, left, right);

    return l+r;
}
void update(int a[], int i, int low, int high, int qi)
{
    if(low==high)
    {
        st[i]=a[low];
        return;
    }
    int mid=(low+high)/2;
    if(qi<=mid)
    {
        update(a,2*i,low,mid,qi);
        st[i]=st[2*i]+st[2*i+1];
    }
    else
    {
        update(a,2*i+1,mid+1,high,qi);
        st[i]=st[2*i]+st[2*i+1];
    }
}
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        int arr[n+10];
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&arr[i]);
        }
        //cout<<"xx"<<endl;
        build_tree(arr, 1, 1,n);
        printf("Case %d:\n",c++);
        while(q--)
        {
            int code;
            scanf("%d",&code);
            int l,r,qval;
            if(code==1)
            {
                scanf("%d",&l);
                arr[l+1]=0;
                int ans= query(1,1,n,l+1,l+1);
                printf("%d\n",ans);
                update(arr,1,1,n,l+1);
                continue;
            }
            else if(code==2)
            {
                scanf("%d%d",&l,&qval);
                arr[l+1]+=qval;
                update(arr,1,1,n,l+1);
                continue;
            }

            scanf("%d%d",&l,&r);
            int ans= query(1,1,n,l+1,r+1);
            printf("%d\n",ans);
        }
    }
}

