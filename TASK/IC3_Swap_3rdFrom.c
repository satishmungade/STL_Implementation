// Function having inputs, one output
#include<stdio.h>
int swap(int,int*);

void main()
{
	int iNo1,iNo2;

		  printf("Enter The Two Swap Numbers\t");
		  scanf("%d%d",&iNo1,&iNo2);  
		 
		     
	 	 iNo1=swap(iNo1,&iNo2);
    	 printf("%d %d After Swap Numbers",iNo1,iNo2);

}
int swap(int iNo1,int* iNo2)
{
    iNo1=iNo1+*iNo2;
    *iNo2=iNo1-*iNo2;
    iNo1=iNo1-*iNo2;

 return iNo1;
}


 	
