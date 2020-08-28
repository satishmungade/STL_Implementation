#include<stdio.h>
int main()
{
	  int arrArray[10][10][10];
	  int iRow,iCol,iPlan;
	  int iCounter1,iCounter2,iCounter3;
		
  	
      printf("enter the how many plan you want\t");
      scanf("%d",&iPlan);
 
 	
      printf("enter the row and cols\t");
      scanf("%d%d",&iRow,&iCol);

      printf("Enter the elements in Array\n");
	  for(iCounter1=0;iCounter1<iPlan;iCounter1++)
      {
  		   for(iCounter2=0;iCounter2<iRow;iCounter2++)	
			{
				for(iCounter3=0;iCounter3<iCol;iCounter3++)
					{
						scanf("%d",&arrArray[iCounter1][iCounter2][iCounter3]);
					}
			}
		}
        
		for(iCounter1=0;iCounter1<iPlan;iCounter1++)
        {
            for(iCounter2=0;iCounter2<iRow;iCounter2++)
			{
				for(iCounter3=0;iCounter3<iCol;iCounter3++)
				{
                  printf(" %d ",arrArray[iCounter1][iCounter2][iCounter3]);

				}
                  	printf("\n");
			}
		}
			
   return 0;
}

                  
