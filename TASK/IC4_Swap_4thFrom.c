//Function having inputs, more than one outputs.

#include<stdio.h>

void swap(int*,int*);

void main()
{
	   int iNo1,iNo2;

	   printf("enter the two swap numbers :\t ");
	   scanf("%d%d",&iNo1,&iNo2);

	   swap(&iNo1,&iNo2);
	   printf("\n After swaping numbers is  %d %d ",iNo1,iNo2);
}

void swap(int* iNo1,int* iNo2)
{ 
     *iNo1=*iNo1+*iNo2;
    *iNo2=*iNo1-*iNo2;
    *iNo1=*iNo1-*iNo2;
	   
	  
}

