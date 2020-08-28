#include<stdio.h>
#include<malloc.h>

int main()
{

	int ***pPtr=NULL;
	int iRow,iCol,iPlan;
	int iCounter1,iCounter2,iCounter3;
	
	printf("Enter the How Many plan you want :\t");
	scanf("%d",&iPlan);

	printf("Enter The row & col for 3D Array :\t ");
	scanf("%d%d",&iRow,&iCol);


	pPtr=(int ***)malloc(iPlan*sizeof(int **)); // Memory Allocation for Plan
	
	if(NULL==pPtr)
	{
		printf("memory Allocation Failed");
		return -1;
	}
	for(iCounter1=0;iCounter1<iPlan;iCounter1++)
	{
		pPtr[iCounter1]=(int **)malloc(iRow*sizeof(int *)); //Memory Allocation for Row
		
		if(NULL==pPtr[iCounter1])
		{
			printf("memory Allocation Failed");
			return -1;
		}
		for(iCounter2=0;iCounter2<iRow;iCounter2++)
		{

			pPtr[iCounter1][iCounter2]=(int *)malloc(iCol*sizeof(int)); //Memory Allocation for element
		
			if(NULL==pPtr[iCounter1][iCounter2])
			{
				printf("memory Allocation Failed");
				return -1;
			}
			
                        for(iCounter3=0;iCounter3<iCol;iCounter3++)
                        {
			   printf("\n\tThis is index NO [%d][%d][%d]Enter the Element\t:",iCounter1,iCounter2,iCounter3); //give to element
                           scanf("%d",&pPtr[iCounter1][iCounter2][iCounter3]);
                        }
          	}


	}
	 


         for(iCounter1=0;iCounter1<iPlan; iCounter1 ++)
         {
               for(iCounter2=0; iCounter2 < iRow ; iCounter2++)
                 {
                    for(iCounter3=0; iCounter3 <iCol ; iCounter3 ++)
                        {
                                printf("[%d] [%d] [%d]  %d\t",iCounter1,iCounter2,iCounter3,pPtr[iCounter1][iCounter2][iCounter3]); //printing element
                        }
                        printf("\n");
                }
        }  
	for(iCounter1=0;iCounter1<iPlan;iCounter1++)
		{	
			for(iCounter2=0;iCounter2<iRow;iCounter2++)
			{
		
				 free(pPtr[iCounter1][iCounter2]);//Deallocation memory of element
				 pPtr[iCounter1][iCounter2]=NULL;
			}
		}
	for(iCounter2=0;iCounter2<iPlan;iCounter2++)
		{
			 free(pPtr[iCounter2]); // deallocation memory of rows
			 pPtr[iCounter2]=NULL;
		}
	
	free(pPtr);// deallocation memory of plan
	pPtr=NULL;

	
	return 0;
}
