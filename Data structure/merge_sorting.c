#include<stdio.h>
#define max 100
int arr[max+10];
int brr[max+10];
void merging(int low, int mid, int high)
{
    int i,j,k;
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            brr[k++]=arr[i++];
        }
        else
        {
            brr[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        brr[k++]=arr[i++];
    }
    while(j<=high)

    {
        brr[k++]=arr[j++];
    }
    for(int k=low; k<=high; k++)
    {
        arr[k]=brr[k];
    }
}
void merge_sorting(int low, int high)
{

    if(low<high)
    {
        int mid=(low+high)/2;
        merge_sorting(low,mid);
        merge_sorting(mid+1,high);
        merging(low,mid,high);
    }
    else
    {
        return;
    }
}
int main()
{
    int n;
    scanf("%d",&n); ///range 1 to max
    for(int i=0; i<n; i++)
    {

        scanf("%d",&arr[i]);
    }
    merge_sorting(0,n-1);
    for(int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
