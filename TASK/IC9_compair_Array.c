// Comaparision of Array Element
#include<stdio.h>
int fun(int arriArray3[],int arriArray4[],int iNo);

int main()
{
	int arriArray1[20];
	int arriArray2[20];	
	int iNo,iCounter;
    printf("\nEnter the size of First Array :\t");
    scanf("%d",&iNo);

	for(iCounter =0;iCounter < iNo ; iCounter ++)
	{
        printf("\nElement index Number %d is\t:",iCounter);
        scanf("%d",&arriArray1[iCounter]);

	}
	
	printf("\nEnter the size of second Array :\t");
    scanf("%d",&iNo);

	for(iCounter =0;iCounter < iNo ;iCounter++)
	{
        printf("\nElement index Number %d is\t:",iCounter);
		scanf("%d",&arriArray2[iCounter]);

	}
	
	
    iNo=fun(arriArray1,arriArray2,iNo);
        
	if(iNo == 1)
		printf("\nArray Elements Are equal");
	else
		printf("\nArray Elements Are not equal");
	

	return 0;
		
}

int fun(int arriArray3[],int arriArray4[],int iNo)
{
	int iCounter;
	for(iCounter = 0;iCounter < iNo ; iCounter ++)
	{	
	    if(arriArray3[iCounter] == arriArray4[iCounter])
            continue;
		
        else 
            break;
    }	
	if(iCounter == iNo)

	    return 1;
	else
        return 0;


}


