#include<stdio.h>
int MAX=3;
int stack[3];
int top=-1;
int isempty()
{
    if(top==-1)return 1;
    else return 0;
}
int isfull()
{
    if(top==MAX-1)return 1;
    else return 0;
}
char peak()
{
    return stack[top];
}
int push(int data)
{
    top++;
    stack[top]=data;
}
int pop()
{
    int data;
    data= stack[top];
    top--;
    return data;
}
int main()
{
   int i=1;
   while(1)
   {
       if(!isfull())
       {
           printf("Pushing integer %d\n",i);
           push(i++);
       }
       else
       {
           printf("stack is full can not push %d\n",i);
           break;
       }
   }
   printf("Elements of stack:\n");
   while(!isempty())
   {
       printf("%d\n",pop());
   }
   if(isempty())
   {
       printf("Stack is empty\n");
   }
   return 0;
}
