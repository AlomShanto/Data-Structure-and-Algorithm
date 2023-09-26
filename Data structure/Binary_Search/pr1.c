#include<stdio.h>
int binary_searh(int arr[], int low, int high, int element)
{
    while(low<=high)
    {
        int mid;
        mid=low+(high-low)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        if(arr[mid]>element)
        {
            high= mid-1;
            continue;
        }
        if(arr[mid]<element)
        {
            low= mid+1;
            continue;
        }
    }
    return -1;
}
int main()
{
    printf("Enter Number of plans and the particular fee\n");
    int n,element;
    scanf("%d%d",&n,&element);
    int arr[n+10];
    printf("Enter the subscription fees for all plans\n");
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans=binary_searh(arr,1,n,element);
    if(ans==-1)
    {
        printf("%d particular fee does not exist in the set of subscription fees\n",element);
        return 0;
    }
    printf("%d particular fee is suitable for plan no %d\n",element,ans);
    return 0;
}
