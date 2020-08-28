#include <stdio.h>
#include <string.h>
#define MAX 100	
int top=-1;
int item;
char stack_string[MAX];
void push(char item);
char pop();
int isEmpty();
int isFull();
int main()
{
    char Chchar[MAX];
    int iCounter;
    
    printf("Enter a string: ");
    scanf("%s",Chchar); 

    
    for(iCounter = 0 ;iCounter < strlen(Chchar); iCounter++)
        push(Chchar[iCounter]);
        
    for(iCounter = 0 ;iCounter < strlen(Chchar); iCounter++)
        Chchar[iCounter]=pop();

    printf("Reversed String is: %s\n",Chchar);
    
    return 0;
}
 

void push(char item)
{

    if(isFull())
    {
         printf("Stack is overflow");
        return;
    }
    
    top=top+1;
    stack_string[top]=item;
}
 
 char pop()
{
    if(isEmpty())
    {
        printf("\nStack is EMPTY!!!\n");
        return 0;
    }


    item = stack_string[top];
    top=top-1;
    return item;
}
 

int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

 
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
