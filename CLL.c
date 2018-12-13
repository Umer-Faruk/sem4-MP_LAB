#include<stdio.h>
#include<malloc.h>

struct node
{
int data;
struct node *link;
};
typedef struct node NODE;

NODE *newnode, *last=NULL,*currptr,*prevptr;

NODE *getnode(int value)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=value;
    newnode->link=NULL;
    return newnode;
}

void insert_beg()
{
    int value;
    printf("enter the value to the node\n");
    scanf("%d",&value);
    
    newnode=getnode(value);
    if(last==NULL)
    {
        last=newnode;
        last->link=last;
    }
    else
    {
         newnode->link=last->link;
        last->link=newnode;
    }
}

void insart_end()
{
    int value;
    printf("enter the elenemt to the node\n");
    scanf("%d",&value);
    newnode=getnode(value);
    if(last==NULL)
    {
        last=newnode;
        last->link=last;
    }
    else
    {
        newnode->link=last->link;
        last->link=newnode;
        last=newnode;    
    }
    
}


void insert_at_pos()
{
    int value,count=0,i,pos;
    printf("enter the position\n");
    scanf("%d",&pos);
    currptr=last->link;
    while(currptr!=last)
    {
        currptr=currptr->link;
        count++;
    }
    
    if(pos==1)
    {
    insert_beg();
    }
    
    else if(pos==count+1)
    {
        insart_end();
    }
    else if(pos>1&&pos<count+1)
    {
        printf("enter the value to the node\n");
        scanf("%d",&value);
        newnode=getnode(value);
        
        for(i=1;i<pos;i++)
        {
            currptr=currptr->link;
        
        }
            newnode->link=currptr->link;
            currptr->link=newnode;    
         }
}



//delition 




void delet_beg()
{
    if(last==NULL)
    {
        printf("list is emptey\n");
        return;
    }
     
    else if(last->link==last)//if 1 node is exist
    {   currptr=last->link;
        last=NULL;
        printf("%d is deleited\n",currptr->data);
        
        free(currptr);
    }
    else 
    {
    currptr=last->link;
    last->link=currptr->link;
     printf(" %d is deleted from list\n",currptr->data);
     free(currptr);
     
     }
 }


void delet_end()
{
    if(last==NULL)
    {printf("list is emptey\n");
    }
    else if(last->link==last)
    {
        currptr=last;
        last=NULL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
    }
    else
    {
        currptr=last->link;
        prevptr=NULL;
        while(currptr->link!=last->link)
        {   prevptr=currptr;
            currptr=currptr->link;
        }
        
        prevptr->link=last->link;
        last=prevptr;
       
        printf("%d is deleted\n",currptr->data);
        free(currptr);
        
    }
    
}




void delet_at_pos()
{
    int pos,i,count;
    if(last==NULL)
    {
        printf("list is emptey\n");
        return;
    }
    printf("enter the postions\n");
    scanf("%d",&pos);
    if(pos==1)
    {
    delet_beg();
    } 
    else
    {
        currptr=last->link;
        
        for(i=1;i<pos;i++)
        {
            prevptr=currptr;
            currptr=currptr->link;
        }
        prevptr->link=currptr->link;
         if(currptr==last)
         last=prevptr;
         printf("%d is deleted \n",currptr->data);
         free(currptr);
        
    } 
      
}



void display()
{
    if(last==NULL)
    {printf("list is emptey\n");}
    else
    printf("element of list are \n");
       
        
    for(currptr=last->link;currptr!=last;currptr=currptr->link)
     {
     
     printf("%d=>",currptr->data);
     }
    printf("%d=>",currptr->data);
}


void main()
{
    int ch;
    while(1)
    {
    printf("circular linked list\n");
    printf("\n1:insert node begining\n2:insart at end\n3:insert node at position\n4:deleting beg\n5:delete end\n6:deleting at given positon\n9:display\n7:for exit");
    scanf("%d",&ch);
    switch(ch){
    
    case 1:insert_beg();break;
    case 2: insart_end();break;
    case 3:insert_at_pos();break;
    
    case 4:delet_beg();break;
    case 5:delet_end();break;
    case 6: delet_at_pos();break;
    case 7:exit(0);
    
    
    case 9:display();break;
    
    }
    
   }
}
