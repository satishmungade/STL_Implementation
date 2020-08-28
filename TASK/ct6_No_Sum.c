#include<stdio.h>
int count(int iNo);
int main()
{
        int iNo,iSum;
        printf("Enter a Number :\t");
        scanf("%d",&iNo);
        
        iSum=count(iNo);
        printf("Your Enter Number Sum is :%d\t",iSum);
        
   return 0;
}
int count(int iNo)
{
        int iSum=0,iRem=0;
        while(iNo > 0)
        {
                iRem = iNo % 10;
                
                iNo=iNo/10;

               iSum=iSum + iRem; 
        }
        return iSum;
}
/*
r=421%10=1
n=421/10=42
s=0+1=1

r=42%10=2
n=42/10=4
s=1+2=3

r=4%10=4
n=4/10=0
s=3+4=7

*/
