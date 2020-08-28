//1D Array using Dyanamic 
#include<stdio.h>
#include<malloc.h>
int main()
{
	int *pPtr=NULL;
	int iNo,iCounter;
	 
	printf("Enter the size of First Array :-");
	scanf("%d",&iNo);

	pPtr=(int *)malloc(iNo*sizeof(int));
	if(NULL==pPtr)
	{
		printf("Memory Allocation Falied");
		return -1;
	}
	printf("Enter The Elements in Array :\n\n");
	for(iCounter = 0 ;iCounter < iNo ; iCounter ++)
	{
                printf("Element index Number %d is\t:",iCounter);		
                scanf("%d",&pPtr[iCounter]);
	}

	for(iCounter = 0 ;iCounter < iNo ; iCounter ++)
	{
		printf("%d ",pPtr[iCounter]);
	}

	free(pPtr);
	pPtr=NULL;
	return 0;
}
