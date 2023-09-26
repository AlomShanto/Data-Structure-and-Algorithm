#include<stdio.h>
int binary_search(int arr[], int low, int high, int element)
{
   int mid=low+(high-low)/2;
   if(arr[mid]==element)
   {
       while(arr[mid]==element)
       {
           mid--;
       }
       return mid+1;
   }
   if(arr[mid]>element)
   {
       if(low==high)
       {
           return -1;
       }
       return binary_search(arr,low,mid-1,element);
   }
   if(arr[mid]<element)
   {
       if(low==high)
       {
           return -1;
       }
       return binary_search(arr,mid+1,high,element);
   }
}
int binary_search1(int arr[], int low, int high, int element)
{
   int mid=(low+high)/2;
   if(arr[mid]==element)
   {
       while(arr[mid]==element)
       {
           mid++;
       }
       return mid-1;
   }
   if(arr[mid]>element)
   {
       if(low==high)
       {
           return -1;
       }
       return binary_search1(arr,low,mid-1,element);
   }
   if(arr[mid]<element)
   {
       if(low == high)
       {
           return -1;
       }
       return binary_search1(arr,mid+1,high,element);
   }

}
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int arr[n+10];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans,ans1;
    ans=binary_search(arr,0,n-1,d);
    ans1=binary_search1(arr,0,n-1,d);
    if(ans==-1 && ans1==-1)
    {
        printf("%d is not present in the array\n",d);
    }
    else
    {
        int total=ans1-ans+1;
        printf("%d is present in the array %d times\n",d,total);
    }


}
