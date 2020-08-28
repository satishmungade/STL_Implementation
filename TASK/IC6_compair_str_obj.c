//Structure object comparigion
#include<stdio.h>

struct demo
{
   int iNo;
   char chChar;
};
int fun(struct demo,struct demo );
int main()
{
     struct demo obj1,obj2;
     int iNo;
  
     printf("Enter the value of 1st object1\t");
     scanf("%d%c",&obj1.iNo,&obj1.chChar);
   
     printf("Enter the value of 2nd object2\t");
     scanf("%d%c",&obj2.iNo,&obj2.chChar);

      iNo=fun(obj1,obj2);

     if(iNo==1)
           printf("object Are Equal\n");
     else
          printf(" object is Not Equal\n");
     return 0;
}


int fun(struct demo  obj3,struct demo obj4 )
{

	if(obj3.iNo==obj4.iNo && obj3.chChar==obj4.chChar)
	    return 1; 
	else
            return 0;
 }


