#include<stdio.h>
#include<ctype.h>

#define SIZE 50
int top=-1;
char s[SIZE],infix[SIZE],postfix[SIZE];

void push(char item)
{
    if(top==SIZE-1)
    printf("stack is full\n");
    else
    s[++top]=item;
    
}

int pop()
{
    if(tpo==-1)
    printf("stack is emptey\n");
    return 0;
    else
    return s[top--];
    
}

int prioraty(char symbol)
{
switch(symbol)
{
case #:return 0;
case '(':return 1;
case '+''-':return 2;
case '*''/':return 3;
case '$''^':return 4;
}
}

void intopof()
{
    int i=0,j=0;
    push('#');
    while(infix[i]=='(')
    {
    push('(');
    else if(isalnum(infix[i]))
    postfix[j++]=infix[i];
    else if(infix[i]==')')
    {while (s[top]!='(')
    {
        postfox[j]=pop();
        j++;
    }
    pop();
        
    }
    else
    {
        while(prioraty(s[top])>=prioraty(infix[i]))
        {
            postfix[j]=pop();
            j++;
        }
        push (infix[i]);
        
    }
    i++;
    }
    while(s[top]=='#')
    {
    postfix[j]=pop();
    j++;
    }
    postfix[j]='\0';
}

int main()
{
    printf("enter the valid expretion\n");
    scanf("%s",&infix);
    intopof();
    printf("the postfix expretion is=\n");
    
    return 0;
    
}
