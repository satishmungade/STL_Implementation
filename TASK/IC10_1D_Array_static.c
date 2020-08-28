//1D Array using static 
#include<stdio.h>
int main()
{
	int arriArray[20];
	int iNo,iCounter;
	printf("Enter the size of First Array :");
	scanf("%d",&iNo);

	printf("Enter Elements in Array :\n\n");
	for(iCounter = 0;iCounter < iNo ; iCounter ++)
	{
                printf("Element index Number %d is\t:",iCounter);		
                scanf("%d",&arriArray[iCounter]);
	}

	for(iCounter = 0;iCounter < iNo;iCounter ++)
	{
		printf("%d\t",arriArray[iCounter]);
	}
	return 0;
}
