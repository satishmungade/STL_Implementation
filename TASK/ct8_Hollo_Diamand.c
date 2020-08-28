#include<stdio.h>
int main()
{
        
        int iNo,iRow,iCol;
        char chArray[100][100];
        printf("Enter a Number For Pattern \t :");
        scanf("%d",&iNo);
        if(iNo%2==0)
        {
              
                for(iRow = 1; iRow <= iNo;iRow ++)
                {
                        for(iCol=1; iCol <= iNo ; iCol ++)
                        {
                                if(iRow == 1 || iRow == iNo || iCol ==1 || iCol == iNo)
                                          chArray[iRow][iCol]='*';
                                else  
                                          chArray[iRow][iCol]=' ';      
                        }
                printf("\n");
               }
       }
       else
         {
              int iMid=iNo/2+1;
                
                for(iRow =1 ; iRow <=iNo ; iRow ++)
                {
                        for (iCol = 1; iCol <=iNo; iCol ++)
                        {      
                               if ( iCol == iMid || iCol == iNo-iMid + 1)
                                {
                                     chArray[iRow][iCol]='*';
                                }                
                                else
                                {
                                      chArray[iRow][iCol]=' ';   
                                }    
                         }       
                        if(iRow <= iNo/2)
                        {                                
                                iMid --;
                                                            
                        }
                        else
                               iMid ++;
                               
                         printf("\n");
                }       
          }     
           
         for(iRow=1;iRow<=iNo;iRow ++)
         {
                for(iCol=1;iCol<=iNo;iCol ++) 
                   {
                         printf("%c",chArray[iRow][iCol]);
                    }
                printf("\n");
          }       
        return 0;
        
}       

                
               
