//structure object assignment
#include<stdio.h>
struct demo
{
	int iNo;
	char chChar;
};

void fun(struct demo,struct demo );

int main()
{
	struct demo obj1,obj2;
	int iNo;

	printf("Enter the value 1st obj :\t");
	scanf("%d %c",&obj1.iNo,&obj1.chChar);
 
  
       fun(obj1,obj2); 
	
   
	return 0;

}

void fun(struct demo  obj1,struct demo obj2 )
{
	
  
	obj2.iNo=obj1.iNo;
	obj2.chChar=obj1.chChar;
    printf("after assigning  obj2=%d %c",obj2.iNo,obj2.chChar);
     	
}
