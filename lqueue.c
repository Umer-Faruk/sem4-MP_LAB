#include<stdio.h>
#include<stdlib.h>
#define SIZE 30
int Q[SIZE];
int f=-1;
int r=-1;


void insert()
{   int item;


    if(r==SIZE-1)
    {printf("queue is full");}
    else
    {
    if(r==-1)
    f=0;
    
    printf("enter the item in queue\n");
    scanf("%d",&item);
   r++;
    Q[r]=item;}
    

}

void deletion()
{   int ditem;

    if(f==-1||f>r)
    {printf("queue is emtey no item to delete\n");}
    else
    
    ditem=Q[f];
    f++;
    printf("%d is deleted from queue\n",ditem);
    
}

void display()
{


    int i;
    if(f>r)
    {printf("queue is emtey no item to display\n");}
    
    for(i=f;i<=r;i++)
    {
    printf("%d->",Q[i]);
    }
    
}
int main()
{
    
    
    
    while(1){
    int ch;
    printf("\n enter the choice 1:for insertion 2:for deletion 3:for display 4:exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert();
                break;
         case 2:deletion();
                break;
           case 3:display();
            break;
            case 4:exit(0);
            
            default:printf("enter the right option\n");
            
    }
  
   }
}
