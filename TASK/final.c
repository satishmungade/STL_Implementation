#include<stdio.h>
#include <stdlib.h>
#include<malloc.h>
struct node
{
        struct node *pPrev; 
    	int iData;
	struct node *pNext;
};
void insert_first(struct node **pHead,struct node **pTail,int iNo);
void insert_last(struct node **ppHead,struct node **ppTail,int iNo);
void insert_at_position(struct node **ppHead,struct node **ppTail,int iPos,int iNo);
int delete_first(struct node **ppHead,struct node **ppTail);
int delete_last(struct node **ppHead,struct node **ppTail);
int delete_at_position(struct node **ppHead , struct node **ppTail , int iPos);
int count_node(struct node *pHead,struct node *pTail);
int search_all(struct node *pHead,struct node *pTail,int iNo);
int search_first_occurrence(struct node *pHead,struct node *pTail,int iNo);
void concat_list(struct node **ppHead1,struct node **ppHead2,struct node **ppTail1 ,struct node **ppTail2);
void concat_at_position(struct node **ppHead1,struct node **ppHead2,struct node **ppTail1 ,struct node **ppTail2,int iPos);
void reverse(struct node **pHead,struct node **pTail);
void display (struct node *pHead,struct node *pTail);

int main()
{ 

         int iCounter,iDelData,iData,iPosition,iChoice;
	
        struct node *pFirst = NULL;
		struct node *pLast = NULL;

        struct node *pFirst1 = NULL;
		struct node *pLast1 = NULL;

        while(1)
		{
			printf(" \n 1.Insret_Element :-\n 2.Delete_Element :-\n 3.Search_Element :-\n 4.count_list :-\n 5.concat_list :-\n 6.Reveres_list :-\n 7.Display_list \n 8.Exit :-\n " );
		
			printf("\n! Enter Your choice !:-\t");
			scanf("%d",&iChoice);
                               
                switch(iChoice)
                {
                     case 1: 
                        while(1)
                           {
                                printf("\n\n\t1.Add At beginning list :-\n\t2.Add At End :-\n\t3.Add After possition :\n\t4.back :-\n");
                                printf("\n\t! Enter Your choice for Insreting !:-\t");
		                scanf("%d",&iChoice);
                            
                                if(iChoice ==3)
                                    {
                                        printf("\n\tEnter the  possition of Node :-\t");
										scanf("%d",&iPosition);    
                                        if(iPosition<=0 ||iPosition>(count_node(pFirst,pLast)+1))	
										{
											printf("\n\n\t Your Position is invalid :\n");
											continue;
										}  
								}
                                if(iChoice<=3) 
                                    {  
                                           printf("\n\n\tEnter the element to be insert First List \t:");
										   scanf("%d",&iData);            
                                    }        
                        
		       	     switch(iChoice)
			       {
			             case 1:
				              insert_first(&pFirst,&pLast,iData);
                                                printf("\n\t!!Element to be inserted First position !!\n");
                                                break;
	                            case 2:
	                                    insert_last(&pFirst,&pLast,iData);
                                             printf("\n\t!!Element to be inserted Last Position!:\n");                                     
                                                 break;
                                    case 3:
					        insert_at_position(&pFirst,&pLast,iPosition,iData);
                                                printf("\n\tElement to be inserted At-Position %d \t ",iPosition);
			        	      break;
                                    case 4:
	
					      break ;
			           default:
				              printf("\n\t! Your choice is Wrong !:-\n"); 
                                        
                                 }
                                                                               
                                           if(iChoice == 4)
                                              break;
 
                                         display(pFirst,pLast);
                    }
                        break;
                    case 2:
                         while(1)
                         {

                                 if(pFirst == NULL)
                                 {                                        
                                     printf("\n\n! Your List is Empty !");                               
                                       break; 
                                 }    
                                 printf("\n\t1.Delete First Element :\n\t2.Delete last Element :\n\t3.Delete AtpossitionElement\n\t4.Back:-\n");
                                 printf("\n\t! Enter Your choice for Deleting !:-\t");
				 scanf("%d",&iChoice);
                                           
                                                        
                                  switch(iChoice)
			             {
                                           case 1:
					                iDelData=delete_first(&pFirst,&pLast);
                                                         if(iDelData == -1)
                                                                printf("Your Data is Wrong :\n");
                                                         else
					        	        printf("\n\tDeleted element value :-\t%d\n",iDelData);
					        	break;
        
				           case 2:
						
					        	iDelData=delete_last(&pFirst,&pLast);
                                                        if(iDelData == -1)
                                                                printf("Your Data is Wrong :\n");
                                                         else
					                         printf("\n\tDeleted element value :-\t%d\n",iDelData); 
					        	break;
					
				           case 3:

					        	printf("\n\tEnter the position to be deleted :-\t");
					        	scanf("%d",&iPosition);
                                                        if(iPosition<=0 ||iPosition>(count_node(pFirst,pLast)))	
        			                         {
					                        printf("\n\n\t Your Position is invalid :\n");
								continue;
					                 }  
					        	 iDelData=delete_at_position(&pFirst,&pLast,iPosition);
                                                             if(iDelData == -1)
                                                                 printf("Your Position is Wrong :\n");
                                                                
                                                              else
					        	          printf("\n\tDeleted element given value :- \t%d\n",iDelData); 
					        	break;
                        	                                                             
                                            case 4:
                                                         break;

				            default:
        
					        	printf("! Your choice is Wrong !:-\n"); 
                                        
                                         }
                                                
                                                        if(iChoice == 4)
                                                        break;
                                                display(pFirst,pLast);
                                }
                                                                
                                        break;
                        
                        case 3:

                                while(1) 
                                { 
                                     if(pFirst == NULL)
                                         {
                                                printf("\n\t! Your List is Empty pleses Insert First Data Than search your Data...! :-\n\n");
                                                break; 
                                          } 
                                   printf("\n\t1.Search All_list :-\n\t2.Search Firstoccurnse list :-\n\t3.Back :-\n");
                                   printf("\n\t! Enter Your choice For Searching !:-\t");
	                           scanf("%d",&iChoice);
                                          
                                     switch(iChoice)
         			     {
                                        case 1:
                                                printf("\n\tEnter the element which you want to sreached :-\t  ");
						scanf("%d",&iData);
						iCounter=search_all(pFirst,pLast,iData);
						printf("\n\t Occurrence given Number :%d\n",iCounter); 
						break;
				
				        case 2:		
				        	printf("\n\tEnter the element which you want to search First Occurence :-\t");
						scanf("%d",&iData);
					        iCounter=search_first_occurrence(pFirst,pLast,iData);
                                                printf("\n\tItem Found at-This position :%d\t\n",iCounter);
		                                break;
                                        
                                        
                                        case 3:

                                                break;

                                         default:
						   printf("! Your choice is Wrong !:-\n"); 
                                  }
                                         display(pFirst,pLast);
                                        if(iChoice == 3)
                                        break;
                            }
                                break;
                                                                
                                                                            
		    case 4:                 
        		        iCounter=count_node(pFirst,pLast);
                                printf("\t! Total Number of Elements Count is !:- %d\n",iCounter);
			        break;                
                   case 5:
                         while(1)
                            {
                                if(pFirst == NULL)
                                      {
                                               printf("! Your List is Empty pleses InsertFirst list Data...! :-\n\n");
                                                break; 
                                      } 
                                     printf("\n\t1..2nd list inserting :-\n\t2.concat list :-\n\t3.concat Atpossition list :- \n\t4.Back :-\n");
                                    printf("\n\t!Enter Your choice For concating !:-\t");
				      scanf("%d",&iChoice);
                                        
                                      switch(iChoice)
                                      {
                                                
                                        case 1: 	
                                                 printf("\n\tCalling 2nd list......:-\n");
        					 for(iCounter=1;iCounter<10;iCounter++)
		                                 insert_first(&pFirst1,&pLast1,25*iCounter);
        				         break;
                                        case 2:

						  concat_list(&pFirst,&pLast,&pFirst1,&pLast1);
						  printf("\n\t Merged two list :-\n");
						
						  break;
			
				         case 3:

						  
                                                printf("\n\t! Your 2nd list is Empty. You Want To Enter a Data Than Press 1 No then enter 0 \t:");
                                                scanf("%d",&iChoice);
                                                if(iChoice !=0)
                                                {
                                                       for(iCounter=1;iCounter<10;iCounter++)
		                                       insert_first(&pFirst1,&pLast1,5*iCounter); 
                                                        printf("\n\tYour 2nd list is :\t");
                                                        display(pFirst1,pLast1);
                                                        printf("\n\n\tEnter the  position will start marge list :-");
						        scanf("%d",&iPosition);
						        concat_at_position(&pFirst,&pLast,&pFirst1,&pLast1,iPosition);
            					        break;
                                                }
                                                else
                                                        break;
                                              
                                         

                                         case 4:
                                                   break;

                                         default:
						  printf("! Your choice is Wrong !:-\n"); 
                                          

                                         }
                                            
                                           if(iChoice == 4)
                                                break;
                                           display(pFirst,pLast);
                                }
                                break;

                        case 6:
			while(1)

                               {
                                 if(pFirst == NULL)
                                       {
                                               printf("! Your List is Empty please Insert First Data we can't reverse...! :-\n\n");
                                               break; 
                                       } 
                                     printf("\n\t1.Reverse call \n\t2.physically display \n\t3.Back :-\n");
                                     printf("\n\t! Enter Your choice For Reversing !:-\t");
				      scanf("%d",&iChoice);
                                           
                                      switch(iChoice)
                                      {		
                                        case 1:	
		                                 reverse(&pFirst,&pLast);
                                                 break;

                                        case 2:
                                                 display(pFirst,pLast);
                                                 break;

                                        case 3 :
                                                 break;
                
                                        default:
						   printf("! Your choice is Wrong !:-\n"); 
                                          

                                       }
                                           if(iChoice == 3)
                                              break;
                                        display(pFirst,pLast);
                                 }  
                                   break; 
                  case  7:  
                                display(pFirst,pLast);
                                break;
                        
                  case 8:
	
			    exit(1) ;
	          default:
			        printf("! Your choice is Wrong !:-\n"); 

             }
      }



	 return 0;

}
void insert_first(struct node **ppHead,struct node **ppTail,int iNo)
{
	struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf  ("Memory Allocation is failed :- ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
	{
		*ppHead =*ppTail=pNewnode ;
		 (*ppHead)->pPrev=*ppTail;
		(*ppTail)-> pNext = *ppHead;
               
		return ;
	}
	pNewnode->pNext=*ppHead;
        pNewnode->pNext->pPrev=pNewnode;
        *ppHead=pNewnode;
        (*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext = *ppHead;
	
}  

void insert_last(struct node **ppHead,struct node **ppTail,int iNo)
{
        struct node *pNewnode = NULL;
	pNewnode = (struct node *)malloc (sizeof (struct node));
	if(NULL == pNewnode)
	{
		printf  ("Memory Allocation is failed :- ");
		return ;
	}
        pNewnode->iData=iNo;
	if(NULL == *ppHead)
        {
                *ppHead =*ppTail=pNewnode ;
		 (*ppHead)->pPrev=*ppTail;
		(*ppTail)-> pNext = *ppHead;
               
		return ;
	}
        (*ppTail)-> pNext =pNewnode;
        pNewnode->pPrev=*ppTail;
        *ppTail =pNewnode;
        (*ppHead)->pPrev=*ppTail;
        (*ppTail)-> pNext = *ppHead;
                
}
int count_node(struct node *pHead,struct node *pTail)
{
        int iCounter = 0;
        if(NULL == pHead)
        {
               	printf("\n ! Your List is Empty...!:- ");
                return 0;
        }
        do
        {
                iCounter ++;
                pHead = pHead -> pNext;
        }while(pHead != pTail -> pNext );
               
         return iCounter;
}
  

void insert_at_position(struct node **ppHead,struct node **ppTail,int iPos,int iNo)
{
        struct node *pNewnode = NULL;
        struct node *pTemp=NULL;
        int iCounter=count_node(*ppHead,*ppTail);
        

        if(1 == iPos)
        {
                insert_first(ppHead,ppTail,iNo);
                return ;
        }
        if(iPos == iCounter +1)
        {
                insert_last(ppHead,ppTail,iNo);
                return ;
        }
        pNewnode=(struct node *)malloc (sizeof(struct node));
        if(NULL == pNewnode)
        {
                printf("Memory Allocatin is Faild :-");
                return ;
        }
        pNewnode->iData=iNo;
        pTemp=*ppHead;
        iCounter = 1;
        while(iCounter < iPos - 1)
        {
                iCounter ++;
                pTemp = pTemp -> pNext;
        }
        pNewnode -> pNext = pTemp -> pNext;
        pNewnode ->pNext -> pPrev=pNewnode;
        pTemp ->pNext = pNewnode ;
       pNewnode ->pPrev =pTemp;
        pTemp ->pNext ->pPrev =pTemp;


	

}
int delete_first(struct node **ppHead,struct node **ppTail)
{
	struct node *pTemp=NULL;
	int iDelData;	

	if(NULL == *ppHead)
	{
                printf("\n ! Your List is Empty...! :-");
		return -1;
	}
	iDelData=(*ppHead)->iData;
	if(*ppHead == *ppTail)
	{
		(*ppHead)->pNext=NULL;
		(*ppHead)->pPrev=NULL;
		free(*ppHead);
		*ppHead=*ppTail=NULL;
		return iDelData;
	}
	pTemp=*ppHead;
	*ppHead=pTemp->pNext;
	pTemp->pNext=NULL;
	pTemp->pPrev=NULL;
	(*ppHead)->pPrev=*ppTail;
	(*ppTail)->pNext=*ppHead;
	
	free(pTemp);
	pTemp=NULL;
	return iDelData;	
}

int delete_last(struct node **ppHead,struct node **ppTail)
{
        struct node *pTemp=NULL;
        int iDelData;
        if(NULL == *ppHead)
        {
                printf("\n ! Your List is Empty...! :-");
                return -1;
        }
        if(*ppHead == *ppTail)
        {
                (*ppHead)->pNext = NULL;
                (*ppHead)->pPrev=NULL;
                iDelData=(*ppHead)->iData;
                free(*ppHead);
                *ppHead=*ppTail=NULL;
                return iDelData;
        }
        pTemp=*ppHead;
        while(pTemp->pNext != *ppTail)
              pTemp=pTemp->pNext;

        (*ppTail)=pTemp;
        pTemp=(*ppTail)->pNext;
        pTemp->pNext=NULL;
        pTemp->pPrev=NULL;
        iDelData=pTemp->iData;
        (*ppTail)->pNext=*ppHead;
       (*ppHead)->pPrev=*ppTail;
        free(pTemp);
        pTemp=NULL;
        return iDelData;
}
int delete_at_position(struct node **ppHead , struct node **ppTail , int iPos)
{
	struct node *pTemp = NULL;
	 
	int iDelData=count_node(*ppHead,*ppTail);
	
	if(iPos == 1)
	{
		return delete_first(ppHead,ppTail);
	}
	if(iPos == iDelData)
	{
		return delete_last(ppHead,ppTail);
	}
	pTemp = *ppHead;
	iDelData = 1;
	while(iDelData < iPos)
	{	
		iDelData ++;
		pTemp = pTemp -> pNext;
	}
	pTemp -> pPrev -> pNext = pTemp -> pNext;
	pTemp -> pNext -> pPrev = pTemp -> pPrev;
	iDelData = pTemp -> iData;
	pTemp -> pNext = NULL;
	pTemp -> pPrev = NULL;
	free (pTemp);
	pTemp = NULL;
 
	return iDelData;
	
}

int search_all(struct node *pHead,struct node *pTail,int iNo)
{
        int iCounter = 0;
        if(NULL == pHead)
        {
                printf("\n! Your List is Empty...! :->");
                return 0;
        }
        do
        {
                if(iNo == pHead ->iData)
                iCounter ++;
                pHead = pHead -> pNext;
        }while(pHead != pTail ->pNext);
        return iCounter;
} 
                                   
int search_first_occurrence(struct node *pHead,struct node *pTail,int iNo)
{
         int iCounter = 0;
         do
        {
              iCounter ++;
                if(iNo == pHead ->iData)
                break;
                pHead = pHead ->pNext;
        }while(pHead != pTail ->pNext);
          if(pHead == pTail -> pNext)
                return iCounter;
          else
                return iCounter;
}  
 
void concat_list(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2)
{
        if(NULL == *ppHead2)
        {
                printf("! Your List is Empty...! :- ");
                return ;
        }
        if(NULL == *ppHead1)
        {
                printf("! Your List is Empty...! :- ");
                *ppHead1 = *ppHead2;
                *ppTail1 = *ppTail2;
                *ppTail2 = *ppHead2 = NULL;
                     
                return ;
        }
         (*ppTail1) -> pNext = *ppHead2;
        (*ppHead2) -> pPrev=*ppTail1;
          *ppTail1 = *ppTail2;   
        (*ppTail1) -> pNext = *ppHead1;
        (*ppHead1) -> pPrev = *ppTail1;
         *ppTail2 = *ppHead2 = NULL;
        printf("\n\t     ! Concatating of The Linked List is Successfully Done ! :-\n");
}  
void concat_at_position(struct node **ppHead1,struct node **ppTail1 ,struct node **ppHead2,struct node **ppTail2,int iPos)
{	
	struct node *pTemp = NULL;
	
	int iCounter;
	 iCounter=count_node(*ppHead1,*ppTail1);
	if(iPos <= 0 ||iPos > iCounter +1)
	{
		printf(" ! Position invalid ! :-");
		return ;
	}
	if(NULL == *ppHead2)
	{
		return ;
	}
	if(1 == iPos)
	{
		concat_list( ppHead2,ppTail2,ppHead1,ppTail1);
		*ppHead1 = *ppHead2;
                *ppTail1 = *ppTail2;
		 *ppTail2 = *ppHead2 =NULL;
		return ;
	}
	if(iPos == iCounter + 1)
	{
		concat_list(ppHead1,ppTail1,ppHead2,ppTail2);
		return ;
						
	}
	pTemp = *ppHead1;
	iCounter = 1;
	while(iCounter < iPos -1)
        {
                iCounter ++;
                pTemp = pTemp -> pNext;	
        	
        }
       (*ppTail2) -> pNext = pTemp -> pNext;
        (*ppTail2) -> pNext -> pPrev = (*ppTail2);		
         pTemp -> pNext -> pPrev = *ppTail2;
        pTemp ->pNext = *ppHead2;
	(*ppHead2) -> pPrev = pTemp;
        *ppTail2 = *ppHead2 =NULL; 

      printf("\n\t! Concat The List is successfully Done....! :-\n");

} 
void reverse( struct node **ppHead , struct node **ppTail)
{
	
        struct node *pCurrent = *ppHead;
        struct node *Next = NULL;
	if(NULL == *ppHead)
	{
		printf("\n! Your List is Empty...! :- ");
		return;
	}
	do
	{
		Next = pCurrent -> pNext;
		pCurrent -> pNext = pCurrent -> pPrev;
		pCurrent -> pPrev = Next;
		pCurrent = Next;
	}while(pCurrent != *ppHead);
        *ppTail = pCurrent;
	*ppHead = (*ppTail) -> pNext;
         printf("\n\tYour List is Reverse order Display...:-\t ");
}

         
void display (struct node *pHead,struct node *pTail)
{
	if(NULL == pHead)
	{
		printf("\n\n\t! Your List is Empty...! :-");
		return ;
	}
        printf(" \n\n\t! Your List is...! :-\t");      
	do
	{
		printf("<-|%d|->",pHead -> iData);
		pHead = pHead -> pNext;
	}while (pHead != pTail -> pNext);
}
