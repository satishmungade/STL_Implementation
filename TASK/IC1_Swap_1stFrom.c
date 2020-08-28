// Function having no input, no output.

#include<stdio.h>
void swap();
int main()
{

   swap();
   
   return 0;

}
void swap()
{ 
   
    int iNo1,iNo2;

    printf("Enter The Two Swap Numbers\t");
    scanf("%d%d",&iNo1,&iNo2);  

    iNo1 = iNo1 + iNo2;
    iNo2 = iNo1 - iNo2;
    iNo1 = iNo1 -iNo2;
   

  printf("%d %d After Swaping  Numbers ",iNo1,iNo2);
}

   
