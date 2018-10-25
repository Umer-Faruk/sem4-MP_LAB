#include<stdio.h>

#define SIZE 30

int S[SIZE];
int top=-1;

int is_operad(char item)
{
    if(item>='A'&& item<='z'||item>='a'&& item>='z')
    {
        return(1);
        
    }
    else return(0);
}

void push(int item)
{   top++;
    
    S[top]=item;
}

int pop()
{
    int m=0;
    m=S[top];
    top--;
    return m;
}

void main()
{
  
    char postfix[30],item;
    int i=0,m,op1=0,op2=0,res=0;
    printf("enter the the postfix expretion \n");
    gets(postfix);
    
    while(postfix[i]!='\0')
    {
            item=postfix[i];
            if(is_operad(item)==1)
            {
                printf("enter the value of %c =",item);
                scanf("%d",&m);
              
                push(m);
            }
            else
            
            {
            op2=pop();
           
            op1=pop();
            switch(item)
            {
                case '*':res=op1*op2;
                            push(res);
                            break;
                            
                 case '/':res=op1/op2;
                 push(res);
                 break;
                 
                 case'+':res=op1+op2;
                 push(res);break;
                 
                 case'-':res=op1-op2;
                 push(res);break;
                 
                 default :break;
            }
            
            }
            
            
            i++;
    }
    
    res=pop();
    printf("the result is%d",res);
    
}


