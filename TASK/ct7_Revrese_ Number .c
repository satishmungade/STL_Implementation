
/* revers number and check that number palindrom or not*/
#include<stdio.h>
int Reverse(int iNo);
int main()
{
        int iNo,iRev=0;
        printf("Enter the number :\t");
        scanf("%d",&iNo);
        iRev=Reverse(iNo);
        printf("Revrese Number is:%d\n",iRev);
      return 0;  
}
int Reverse(int iNo)
{
   int iRev=0,iRem,iNo1=iNo;
   while(iNo > 0)
        {
                iRem=iNo%10;
                
                iNo=iNo/10;
                
                iRev= iRev*10 + iRem; 
                   
        }
        if(iRev == iNo1)
        {
          printf("true");
        }
        else
        {
          printf("false \n ");
        }
        return iRev;
}

/*
enter number :123

3=0*10+3;
32=3*10+2;
321=32*10+1
  revese output is 321 ,               


*/
