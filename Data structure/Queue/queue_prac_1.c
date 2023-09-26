#include<stdio.h>
int MAXSIZE = 3;
int q[3];
int front=0;
int rear=-1;
int cnt=0;
int isempty()
{
    if(cnt==0)return 1;
    else return 0;
}
int isfull()
{
    if(cnt==MAXSIZE)return 1;
    else return 0;
}
int peak()
{
    return q[front];
}
int size()
{
    return cnt;
}
void enque(int data)
{
    if(!isfull())
    {
        if(rear==MAXSIZE-1)
        {
            rear=-1;
        }
        q[++rear]=data;
        cnt++;
    }
}
int deque()
{
    int data=q[front++];

    if(front==MAXSIZE)
    {
        front=0;
    }
    cnt--;
    return data;
}
int main()
{
    for(int i=1; i<10; i++)
    {
        if(!isfull())
        {
            enque(i);
        }
        else
        {
            printf("Can't insert element %d cause queue is full\n",i);
        }
    }
    while(!isempty())
    {
        int data=deque();
        printf("%d\n",data);
    }
}

