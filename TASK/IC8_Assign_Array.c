//Assign element one Array to Another Array
#include<stdio.h>
void fun(int arriArray1[],int arriArray2[],int iNo);
int main()
{
	int arriArray1[20], arriArray2[20], iCounter,iNo;

	printf("Enter The size of the Array  :");
        scanf("%d",&iNo);
	for(iCounter = 0;iCounter < iNo; iCounter ++)
	{
                printf("\nThis is index %d Number\t:",iCounter);
		scanf("%d",&arriArray1[iCounter]);

	}

        
         fun(arriArray1,arriArray2,iNo);
	
	return 0;
		
}

void fun(int arriArray1[],int arriArray2[],int iNo)
{     
	int iCounter;
	for(iCounter = 0; iCounter < iNo;iCounter ++)
	{	
	      arriArray2 [ iCounter ]=arriArray1 [ iCounter ];
    }
    printf("\nAfter Assign Element in Another Array:");
    for(iCounter = 0 ;iCounter < iNo;iCounter ++)
    {
            printf("\n\nThis is index Number %d : ",iCounter);  
            printf("%d",arriArray2[iCounter]);     		
    }
        	 
}
	
