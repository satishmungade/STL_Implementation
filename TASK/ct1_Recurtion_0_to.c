/* 
input :5
output :012345
*/
#include<stdio.h>
void num(int );
int main()
{
        int iNo;
        printf("Enter a Number");
        scanf("%d",&iNo);
        num(iNo);
        return 0;
}
void num(int iNo)
{
        if(iNo == 0)
                printf("%d\n",iNo);
        else
        {
                num(iNo - 1);
                printf("%d\n",iNo);
        }
       
}
