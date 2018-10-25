#include<stdio.h>
void TOH(int n ,char source,char temp,char dest)
{
    if(n==1)
    {printf("move  disk %d form %c to %c\n",n,source,dest);}
    else
    {
    TOH(n-1,source,dest,temp);
    printf("move disk%d  from %c to %c \n",n,source,dest);
    
    TOH(n-1,temp,source,dest);
    
    }
}
void main()
{
    int n=0;
    printf("enter the number of disk\n");
    scanf("%d",&n);
    TOH(n,'a','b','c');
}
