#include<stdio.h>
#include<malloc.h>

struct node 
{
    int data;
    struct node *LL;
    struct node *RL;
};
typedef struct node NODE;
NODE *start=NULL,*currptr,*newnode;

NODE *getnode(int value)
{
    newnode=(NODE*)malloc(sizeof(NODE));
    
    newnode->data=value;
    newnode->LL=NULL;
    newnode->RL=NULL;
    return newnode;
}

//inserting nodes

void insert_beg()
{   int value;
    printf("enter the value of node\n");
    scanf("%d",&value);
    newnode=getnode(value);
    
    if(start==NULL)
    {
        start=newnode;
        start->LL=NULL;
        start->RL=NULL;
        printf("node is inserted\n");
    }
    else
    {
    
        newnode->RL=start;
        newnode->LL=NULL;
        start->LL=newnode;
        start=newnode;
       /* currptr=start;
        start=newnode;
        start->LL=NULL;
        start->RL=currptr;*/
    }
 }
 
 
 void insert_end()
 {  int value; 
  printf("enter the value of node\n");
    scanf("%d",&value);
    newnode=getnode(value);
    if(start==NULL)
    {
        start=newnode;
        start->LL=NULL;
        start->RL=NULL;
    }
    
    else
    {
        currptr=start;
        while(currptr->RL!=NULL)
        {
            currptr=currptr->RL;
            
        }
        currptr->RL=newnode;
        newnode->LL=currptr;
        newnode->RL=NULL;
        
    }
 }
 
 void insertat_pos()
 {  
    int pos,i,count=0;
    int value;
 
    printf("enter the position\n");
    scanf("%d",&pos);
    
    currptr=start;
   
    while(currptr!=NULL)
    {
    currptr=currptr->RL;
    count++;
    }
    
    if(pos==1)
    {
        insert_beg();
    }
    else if(pos>1&&pos<count)
    {
        currptr=start;
        printf("enter the value of node");
            scanf("%d",&value);
            newnode=getnode(value);
            
            for(i=1;i<pos-1;i++)
            {
            currptr=currptr->RL;
            }
            currptr->RL->LL=newnode;
            newnode->RL=currptr->RL;
            newnode->LL=currptr;
            currptr->RL=newnode;
            
            printf("\n NODE INSERTED");
         }
         else if(pos==count+1)
         {
            insert_end();
         }
                        
        else
    printf("\n Position out of range");
    }
  
    
    /*
    else if(pos<count+1)
    {
        insert_end();
    }
    else if(pos>1&&pos<count+1)
    {   currptr=start;
        printf("enter the value of node");
            scanf("%d",&value);
            newnode=getnode(value);
            
        for(i=1;i<pos-1;i++)
        {
            currptr=currptr->RL;
        }
        currptr->RL->LL=newnode;
        newnode->RL=currptr->RL;
        newnode->LL=currptr;
        currptr->RL=newnode;
        /*
        newnode->RL=currptr;
        newnode->LL=currptr->LL;
        currptr->LL->RL=newnode;
        currptr->LL=newnode;*/
        
    //}
    
    
 
 //}
 
 
 
 
 
 //delition
 
 
 void delet_beg()
 {
    if(start==NULL)
    {
        printf("list is emptey\n");
        return;
    }
    else if(start->RL==NULL)//only 1 node
    {
        currptr=start;
        start=NULL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
        
    }
    else//meny nodes
    {
        currptr=start;
        start=start->RL;
        start->LL=NULL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
    
    }
 
 }
 
 void delet_end()
 {
    if(start==NULL)
    {printf("list is emptey\n");
    return;
    }
    
     if(start->RL==NULL)
    {
        currptr=start;
        start=NULL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
    }
    else 
    {
        currptr=start;
        while(currptr->RL!=NULL)
        {
            currptr=currptr->RL;
           
        }
        
        currptr->LL->RL=NULL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
    
    }
 
 }
 
 void delet_at_pos()
 {
    int count=0,i,pos;
    
    if(start==NULL)
    {printf("list is emptey\n");
    return;
    }
    
    printf("enter the postion\n");
    scanf("%d",&pos);
    currptr=start;
    while(currptr!=NULL)
    {
        currptr=currptr->RL;
        count++;
    }
    printf("numbur of elements in list ====>%d===>\n",count);
    if(pos==1)
    {
     delet_beg();
    }
    else 
    {
        currptr=start;
        for(i=1;i<pos;i++)
        {
            currptr=currptr->RL;
            
        }
        currptr->LL->RL=currptr->RL;
        currptr->RL->LL=currptr->LL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
        
    }
    
    
    /*else if(pos>1&&pos<count+1)
    {
        for(i=1;i<pos;i++)
        {
            currptr=currptr->RL;
        }
        currptr->LL->RL=currptr->RL;
        currptr->RL->LL=currptr->LL;
        printf("%d is deleted\n",currptr->data);
        free(currptr);
    
    
    
    }
    else if(pos==count+1)
    {
        delet_end();
    }*/
    
 
 }
 
void display()
{
    if(start==NULL)
    {printf("list is emptey\n");
    return;
    }
    else
    {   
    printf("elements of list are:\n");
        currptr=start;
        
        while(currptr->RL!=NULL)
        currptr=currptr->RL;
        printf("\nThe elements in the list are:");
        while(currptr!=NULL)
        {
        printf("%d=>", currptr->data);
        currptr=currptr->LL;
        }
        
       
        /* while(currptr->RL!=NULL)
         {
           printf("%d=>",currptr->data);
            currptr = currptr->RL;
        }*/
           
        
        
       
    }

}





void main()
{
    int ch;
    while(1)
    {
    printf("\n1:for instert@ begining\n2:insert node end\n3:insert at pos\n4:delet at beg\n5:delet end\n6:delet at pos\n9:display");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:insert_beg();
                break;
        case 2:insert_end();break;
        case 3:insertat_pos();break;
        
        case 4:delet_beg();break;
        case 5:delet_end();break;
        case 6:delet_at_pos();break;
        case 9:display();break;
    
    
    }
    }


}
