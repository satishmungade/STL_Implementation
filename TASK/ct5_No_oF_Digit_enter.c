#include<stdio.h>
int digit( long int);
int main()
{
        long int iNo,iCount;
        printf("Enter an Number \t:");
        scanf("%ld",&iNo);
        
        iCount=digit(iNo);
        printf("Number of Digits is\t:%ld",iCount);
        return 0;
}


int digit(long int iNo)
{
   
       long int iCount = 0;
          while(iNo > 0)
           {   
               iNo = iNo/10;
               iCount  ++ ;
              
          }
  
        return iCount;
                      
}
/*
number enter 431
 43=431/10;
        count 1
  4=43/10;
        conut 2
  0.4=4/10;
        count 3
*/
