//Function having inputs, no output.
#include<stdio.h>
void swap(int,int);
int main()
{ 

 	 int iNo1,iNo2;
  	 printf("Enter The Two Swap Numbers\t ");
 	 scanf("%d%d",&iNo1,&iNo2);
  
  	swap(iNo1,iNo2);
  
 	return 0;

}
void swap(int iNo1,int iNo2)
{ 
	   
	   iNo1=iNo1+iNo2;
       iNo2=iNo1-iNo2;
       iNo1=iNo1-iNo2;

	   printf(" %d  %d After Swap Numbers",iNo1,iNo2);
}
  
