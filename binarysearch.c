#include <stdio.h>

/**
 * Demonstrates concept of recursion to implement recursive binary search
 */

int bs(int ele, int a[], int low, int high)
{
	int mid;
	if(low > high) 
	return -1;
	
	
	mid = (low+high)/2;
	
	if(a[mid] == ele ) 
	return mid;
	
	else if(a[mid]>ele)
		return bs(ele,a,low, mid -1);
		
	else
		return bs(ele,a,mid+1,high);
}


int main ( void )
{
	int n,a[100],item,i;
	printf("Enter No of Elements:");
	scanf("%d",&n);
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
		for(i=0;i<n;i++)
		  {  for(int j=0;j<n-1-i;j++)
		    {
		        if(a[j]>a[j+1])
		        {
		            int temp=a[j];
		            a[j]=a[j+1];
		            a[j+1]=temp;
		        }      
		    }
		  }
	while(1)
	{
		printf("Enter an element to search for:");
		scanf("%d",&item);
		int low=0;
		int high=n-1;
		i= bs(item,a,low,high);
		if(i!=-1)
			printf("Found at position: %d\n",i+1);
		else
			printf("Element not found\n");
			
			
		printf("Do you want to search again? (yes = 1,no = 0):");
		fflush(stdin);
		scanf("%d",&i);
		if(!i) break;
	}
	return 0;
}
