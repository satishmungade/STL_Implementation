#include<stdio.h>
#include<stdlib.h>
int addition (int,int);
int subtraction (int,int);
int multiplication(int,int);
int division(int ,int);
int modulus(int,int);
int main()
{
	int iNo1,iNo2,iAns;
          
                     

        while(1)
           {     
                printf("\n1.Addition :- \n2.Subtraction :-\n3.Multiplication :-\n4.division :-\n5.modulus:-\n6.Exit :-\n ");
                printf(" \n Enter Your choice  :\t");
                scanf("%d",&iAns);
                if(iAns<=5)
                {
                   printf("Enter two Number for performing operation  :");
	           scanf("%d%d",&iNo1,&iNo2);             
                }
        switch (iAns)
                {
                        case 1:

                                        iAns=addition(iNo1,iNo2);
	                                printf("Addition is : %d\n",iAns);
                                        break;
                        case 2:
                                        

                                        iAns=subtraction(iNo1,iNo2);
	                                printf("substactin is : %d\n",iAns);
                                        break;
                        case 3:
                                       
                                        iAns=multiplication(iNo1,iNo2);
	                                printf("Multiplication is : %d\n",iAns);
                                        break;
                
                        case 4:
                                       
                                        iAns=division(iNo1,iNo2);
	                                printf("Division is : %d\n",iAns);
                                        break;
                        case 5:
                                       
                                        iAns=modulus(iNo1,iNo2);
	                                printf("Modulus is : %d\n",iAns);
                                        break;
                       
                                
                         case 6 :
                                        exit (0);               
                        default:
				        printf("Your choice is Wrong :-\n"); 
	          }
                        
                                     
         }


	return 0;
}

int addition(int iNo1,int iNo2)
{
	return iNo1+iNo2;
}
int subtraction(int iNo1,int iNo2)
{
	return iNo1-iNo2;
}
int multiplication(int iNo1,int iNo2)
{
      return iNo1 * iNo2;
}
int division(int iNo1 ,int iNo2)
{
      return iNo1 / iNo2;
}
int modulus(int iNo1,int iNo2)
{
      return iNo1 % iNo2;
}

