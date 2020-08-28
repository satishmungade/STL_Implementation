#include<stdio.h>
#include<malloc.h>
int main()
{
	int **pPtr=NULL;
	int iCounter1,iCounter2,iRow,iCol;
	
	 
	printf("Enter how many rows and column you want :");
	scanf("%d %d",&iRow,&iCol);

	 

	pPtr=(int **)malloc(iRow*sizeof(int *));
	if(NULL==pPtr)
	{
		printf("Memory Allocation Falied");
		return -1;
	}
	
	for(iCounter1=0;iCounter1<iRow;iCounter1++)
	{
		 pPtr[iCounter1]=(int *)malloc(iCol*sizeof(int));
		  
		if(NULL==pPtr[iCounter1])
		{
			printf("Memory allocation failed");
			return -1;
		}
		printf("Enter The Elements in Array:");
		for(iCounter2=0;iCounter2<iCol;iCounter2++)
         	 { 
             		scanf("%d",&pPtr[iCounter1][iCounter2]);
          	}
         }

	
	for(iCounter1=0;iCounter1<iRow;iCounter1++)
	{
		for(iCounter2=0;iCounter2<iCol;iCounter2++)
		{
			printf(" %d ",pPtr[iCounter1][iCounter2]);
			
		}		
		printf("\n");
	}
	

	for(iCounter1=0;iCounter1<iRow;iCounter1++)
	{
		 free(pPtr[iCounter1]);
		 pPtr[iCounter1]=NULL;
	}

	free(pPtr);
	pPtr=NULL;
	return 0;
}
