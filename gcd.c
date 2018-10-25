#include<stdio.h>
int gcd(int m,int n)
{
    if(!n)
    {return m;}
    if(n>m)
    return gcd(n,m);
    return gcd(n,m%n);
}
void main()
{
int n,m;
printf("enter the 2 numbers to find gcd\n");
scanf("%d %d",&m,&n);
printf("\n gcd of %d,%d=%d",m,n,gcd(m,n));
return 0;
}
