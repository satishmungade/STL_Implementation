#include<stdio.h>
int main()
{
        int Arr[50][50];
        int iRow,iCol,iCounter1,iCounter2;
        printf("Enter a Row & Col 2D Array \t:");
        scanf("%d%d",&iRow,&iCol);
        printf("Enter the Element in 2D Array \t :");
        for(iCounter1=0; iCounter1 < iRow ; iCounter1++)
         {
               
               for(iCounter2=0; iCounter2 <iCol ; iCounter2 ++)
                {
                         printf("\nThis is indext Number[%d] [%d] \t:",iCounter1,iCounter2);
                        scanf("%d",&Arr[iCounter1][iCounter2]);
                }
        }
        for(iCounter1=0; iCounter1 < iRow ; iCounter1++)
         {
               for(iCounter2=0; iCounter2 <iCol ; iCounter2 ++)
                {
                        printf("[%d] [%d] %d\t",iCounter1,iCounter2,Arr[iCounter1][iCounter2]);
                }
                printf("\n");
        }
}
