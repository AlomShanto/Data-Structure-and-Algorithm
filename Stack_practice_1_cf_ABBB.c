#include<stdio.h>
#include<string.h>
const MAX=10000000;
char stack[1000000];
int top=-1;
int isempty()
{
    if(top==-1)return 1;
    else return 0;
}
int isfull()
{
    if(top==MAX)return 1;
    else return 0;
}
char peak()
{
    return stack[top];
}
int push(char data)
{
    top++;
    stack[top]=data;
}
int pop()
{
    char data;
    data= stack[top];
    top--;
    //return data;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[MAX];
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0; i<len; i++)
        {
            if(str[i]=='A')
            {
                push(str[i]);
            }
            else
            {
                if(isempty())
                {
                    push(str[i]);
                }
                else
                {
                    pop();
                }
            }
        }
        if(isempty())
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",top+1);
        }
        top=-1;
    }
}

