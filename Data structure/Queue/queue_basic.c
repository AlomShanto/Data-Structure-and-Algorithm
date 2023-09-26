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
void enqueue(int data)
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
    if(front==MAXSIZE)
    {
        front=0;
    }
    int data=q[front++];
    cnt--;
    return data;
}
int main()
{
    if(!isfull())
    {
        enqueue(1);
    }
    else
    {
        printf("queue is full\n");
    }

    if(!isfull())
    {
        enqueue(2);
    }
    else
    {
        printf("queue is full\n");
    }

    if(!isfull())
    {
        enqueue(3);
    }
    else
    {
        printf("queue is full\n");
    }

    if(!isfull())
    {
        enqueue(4);
    }
    else
    {
        printf("queue is full\n");
    }

    if(!isempty())
    {
        int data =deque();
        printf("%d\n",data);
    }
    else
    {
        printf("queue is empty");
    }

    if(!isfull())
    {
        enqueue(5);
    }
    else
    {
        printf("queue is full");
    }

    if(!isempty())
    {
        int data =deque();
        printf("%d\n",data);
    }
    else
    {
        printf("queue is full");
    }

    if(!isempty())
    {
        int data =deque();
        printf("%d\n",data);
    }
    else
    {
        printf("queue is empty\n");
    }

    if(!isempty())
    {
        int data =deque();
        printf("%d\n",data);
    }
    else
    {
        printf("queue is empty\n");
    }

    if(!isempty())
    {
        int data =deque();
        printf("%d\n",data);
    }
    else
    {
        printf("queue is empty\n");
    }


}
