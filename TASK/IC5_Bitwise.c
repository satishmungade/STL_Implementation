// comparigion operator using bitwise operator
#include<stdio.h>
#define EQUAL 1
#define GREATER 2
#define LESSTHAN 4
#define LESSTHANEQUAL 8
#define GREATERTHANEQUAL 16

void bitwise(int,int,char *);

int main()

{
    int iNo1,iNo2;
    char chChar;
 
    printf("Enter the Two Numbers\t");
    scanf("%d%d",&iNo1,&iNo2);
  
    bitwise(iNo1,iNo2,&chChar);
    
    if(chChar&EQUAL)
	  printf("NO Is Equal\n");
			
     if(chChar&GREATER)
	printf("No Is Greater\n");
     
     if(chChar&LESSTHAN)
	printf("No Is LessThan\n");
     
      if(chChar&LESSTHANEQUAL)
 	 printf("No Is LessThanEqual\n");
      
      if(chChar&GREATERTHANEQUAL)
	 printf("No Is GreaterThanEqual\n");

      return 0;
}

void bitwise(int iNo1,int iNo2,char *pPtr)
{
       *pPtr=*pPtr ^ *pPtr;

       if(iNo1==iNo2)
         {
          *pPtr=*pPtr | EQUAL;
          *pPtr=*pPtr | GREATERTHANEQUAL;
 		  *pPtr=*pPtr | LESSTHANEQUAL;
	    }
 
      if(iNo1>iNo2)
		{
		  *pPtr=*pPtr | GREATER;
		   *pPtr=*pPtr | GREATERTHANEQUAL;
		}

	  if(iNo1<iNo2)
        {
			*pPtr=*pPtr |LESSTHAN;
			*pPtr=*pPtr|LESSTHANEQUAL;
	   }
}
   
     
 
