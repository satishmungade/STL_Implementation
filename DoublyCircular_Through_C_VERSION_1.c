    #include<stdio.h>
#include<stdlib.h>
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
int search_all(struct node *pHead,struct node *pTail,int iKey);
int search_first_occurrence(struct node *pHead,struct node *pTail,int iKey);
int search_last_occurrence(struct node *pHead,struct node *pTail,int ikey);
void display (struct node *pHead,struct node *pTail);

int main ()
{
    int iChoice=0,iData=0,iPosition=0,iDelData=0,iCount=0;
    struct node *pFirst =NULL ;
    struct node *pLast = NULL ;
    printf("\n \t *** Welcome to STL First Step *** \t \n");
    while(1)
    {
    	
        printf("\n [1] INSERT_ELEMENT \t:\n [2] DELETE_ELEMENT \t:\n [3] SEARCH_ELEMENT \t:\n [4] COUNT_ELEMENT \t:\n [5] EXIT \t:\n");
        printf("\n\t Enter your choice \t:");
        scanf("%d",&iChoice);  
		 
            switch(iChoice)
            {
                case 1:
                
                    while(1)
                    {
                        printf("\n\n\t [1] ADD ELEMENT AT BEGINNING \t:\n\t [2] ADD ELEMNET AT END \t:\n\t [3] ADD ELEMENT AT POSITION \t:\n\t [4] BACK ");
                        printf("\n\n\t\tEnter your choice inserting element \t:");
                        scanf("%d",&iChoice); 
						if(iChoice == 4)
							break;
                        
						if(iChoice == 3)
                        {
                            printf("\n\t\t Enter The Position of Node \t:");
                            scanf("%d",&iPosition);
                            if(iPosition<=0 || iPosition>(count_node(pFirst,pLast)+1))
                            {
                                printf("\n\n\t Your Position is invalid :\n");
                                continue;
                            }
                        }
                        if(iChoice<=3)
                        {
                            printf("\n\n\t\t Enter the element to list \t:");
                            scanf("%d",&iData);
                        }
                    	 switch(iChoice)
                    	{
                        	case 1:
                        
                            	insert_first(&pFirst,&pLast,iData);
                            	printf("\n\t\t Element to be inserted first position\t:");
                       		     break;
                        
                        	case 2:
                        
                            	insert_last(&pFirst,&pLast,iData);
                            	printf("\n\t\t Element to be inserted last position \t:");
                            	break;
                            
                        	case 3:
                        
                            	insert_at_position(&pFirst,&pLast,iPosition,iData);
                            	printf("\n\t\t Element to be inserted at-posotion \t:");
                            	break;
                            
                        	case 4:
                            	break;
                            
                        	default:
                           			 printf("\n \t Your choice is worng \t:");
                    }   
					 						display(pFirst,pLast);
                
                       	  	
                    	 					     
               }
               					
				break;
                case 2: 
                  
                    while(1)
                    {
                        if(pFirst == NULL)
                        {
                            printf("\n\n\t Your list is Empty \t:\n");
                            break;
                        }
                        printf("\n\t [1] DELETE THE FIRST ELEMENT :\n\t [2] DELETE THE LAST ELEMENT :\n\t [3] DELETE THE AT-POSITION : \n\t [4] BACK \n ");
                        printf("\n\t Enter your choice \t:");
                        scanf("%d",&iChoice);
                        switch(iChoice)
                        {
                            case 1:
                            
                                 iDelData=delete_first(&pFirst,&pLast);
                                 if(iDelData== -1)
                                    printf("Data is wrong :\t");
                                 else
                                    printf("\n\t\t Deleted element value is \t:%d\n",iDelData);
                                 break;    
                              
                            case 2 :
                            
                                 iDelData=delete_last(&pFirst,&pLast); 
                                 if(iDelData== -1)
                                    printf("Data is wrong :\t");
                                 else
                                    printf("\n\t\t Deleted element value is \t:%d\n",iDelData);
                                 break;
                                  
                            case 3:
                            
                                printf("\n\t\tEnter the position to de deleted :\t");
                                scanf("%d",&iPosition);
                                    if(iPosition<=0 || iPosition>(count_node(pFirst,pLast))) 
                                    {
                                        printf("\n\t Your position is invalid \n");
                                        continue;
                                    }
                                    iDelData=delete_at_position(&pFirst,&pLast,iPosition );
                                        if(iDelData == -1)
                                            printf("Position is wrong \t :");
                                        else 
                                            printf("\n\t\t Deleted element value is \t:%d\n",iDelData); 
                                  break;
                                  
                            case 4:
                                    break;
                                    
                            default :
                                  printf("\n\t choice is worng :\t");
                                          
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
                            printf("\n\n\t Your list is Empty \t:\n");
                            break;
                        }
                        printf("\n\n\t [1] SEARCH FIRST OCCURRENCE LIST :\n\t [2] SEARCH LAST OCCURRENCE LIST :\n\t [3] SEARCH ALL OCCURRENCE LIST :\n\t [4] BACK : \n");
                        printf("\n\t Enter your choice \t:");
                        scanf("%d",&iChoice);
                        switch(iChoice)
                        {
                            case 1:
                            	printf("\n\t\t Enter the element which want to search occurrence first \t:");
                                scanf("%d",&iData);
                                iCount=search_first_occurrence(pFirst,pLast,iData);
								if(iCount == -1)
										printf("\n\t\t Data %d  Not Present in List :\n",iData);
								else	
										printf("\n\t\t Data %d First found At position :%d\n",iData,iCount);
                                break;
                            
							case 2:
                            	printf("\n\t\t Enter the element which want to search occurrence last \t:");
                                scanf("%d",&iData);
                                iCount=search_last_occurrence(pFirst,pLast,iData);
                            	if(iCount == -1)
										printf("\n\t\t Data %d Not Present in List :\n",iData);
								else	
									printf("\n\t\t Data %d Last found At position :%d\n",iData,iCount);
                                break;
							 
                            case 3:
                                
                                printf("\n\t\t Enter the element to search All \t:");
                                scanf("%d",&iData);
                                iCount=search_all(pFirst,pLast,iData);
                                if(iCount == 0)
									printf("\n\t\t Data %d Not Present in List :%d\n",iData,iCount);
								else
                               		printf("\n\t\tData %d Occurrence given number is  :%d \n",iData,iCount);
                             break;
                            
                            case 4:
                                break;
                            
                             default :
                                  printf("\n\t choice is worng :\t");
                                          
                         }   
                         display(pFirst,pLast);
                         if(iChoice == 4)
                            break; 
                          display(pFirst,pLast);
                            
                             
                     }             
                break;
                case 4:
                        display(pFirst,pLast);
                         iCount=count_node(pFirst,pLast);
                         printf("\n\t Total number of count is %d\t",iCount);
						
                
				break;                              
                case 5:
						return 0;
                        
                default :
                            printf("Your choice is worng");   
            
			
			}
    }
		while(pFirst != NULL)
		{
			if(pFirst == pLast)
				{
				pFirst -> pNext = pFirst -> pPrev =NULL;
				free(pFirst);
				pFirst = pLast = NULL;
				
				}
			else
				{
					pLast = pLast -> pPrev;
					pLast -> pNext ->pNext = NULL;
					pLast -> pNext ->pPrev = NULL;
					free(pLast -> pNext);
					pLast -> pNext = pFirst;
					pFirst -> pPrev = pLast;
	 			
				}
		}   
    
    return 0;
}
void insert_first(struct node **ppHead,struct node **ppTail ,int iNo)
{
    struct node *pNewnode =NULL;
    pNewnode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewnode)
    {
        printf("Memory Allocation is failed :");
        return  ;
    }
    pNewnode -> iData = iNo ;
    if(NULL == *ppHead)
    {
    
        *ppHead = *ppTail =pNewnode ;
        (*ppHead )-> pPrev = *ppTail ;
        (*ppTail)-> pNext = *ppHead ;
        
        return ;
        
    }
    pNewnode -> pNext = *ppHead;
    pNewnode -> pNext -> pPrev = pNewnode ;
    *ppHead = pNewnode;
    (*ppHead) -> pPrev = *ppTail ;
    (*ppTail) -> pNext =*ppHead ;
    
}
void insert_last(struct node **ppHead,struct node **ppTail ,int iNo)
{
    struct node *pNewnode =NULL;
    pNewnode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewnode)
    {
        printf("Memory Allocation is failed :");
        return ;
    }
    pNewnode -> iData = iNo ;
    if(NULL == *ppHead)
    {
    
        *ppHead = *ppTail =pNewnode ;
        (*ppHead )-> pPrev = *ppTail ;
        (*ppTail)-> pNext = *ppHead ;
        
        return ;
        
    }    
    (*ppTail) -> pNext = pNewnode ;
    pNewnode ->pPrev = *ppTail ;
    *ppTail = pNewnode ;
    (*ppHead) -> pPrev = *ppTail ;
    (*ppTail) -> pNext =*ppHead ;
    
}
int count_node (struct node *pHead,struct node *pTail)
{
    int iCounter = 0;
   if(NULL == pHead )
    {
       
        return  0;
    }
    do 
    {
        iCounter ++;
        pHead = pHead -> pNext;
    }while (pHead != pTail -> pNext );
     
     return iCounter;
}
void insert_at_position(struct node **ppHead,struct node **ppTail,int iPos,int iNo)
{ 
	int iCounter;
    struct node *pNewnode = NULL;
	struct node *pTemp = NULL;
    iCounter=count_node(*ppHead,*ppTail);
    
    if(1 == iPos)
    {
    
        insert_first(ppHead,ppTail,iNo);
        return ;
    }
    if(iPos ==iCounter + 1)
    {    
        insert_last(ppHead,ppTail,iNo);
        return ;
    }
    pNewnode=(struct node *)malloc(sizeof(struct node));
    if(NULL == pNewnode)
    {
        printf("Memory Allocation is failed :");
        return ;
    }
    pNewnode -> iData = iNo ;
    pTemp =*ppHead ;
    iCounter =1;
    while(iCounter < iPos -1)
    {
    
        iCounter ++;
        pTemp = pTemp -> pNext;
    }
    pNewnode -> pNext = pTemp ->pNext ;
    pNewnode ->pNext -> pPrev = pNewnode ;
    pTemp ->pNext = pNewnode ;
    pNewnode ->pPrev = pTemp;
    pTemp -> pNext -> pPrev =pTemp;
    
        
}
int delete_first(struct node **ppHead,struct node **ppTail)
{
	int iDelData;
    struct node *pTemp=NULL;
    
    if(NULL == *ppHead)
    {
               return -1;
    }
    iDelData=(*ppHead)->iData;
    if(*ppHead == *ppTail)
    {
        (*ppHead) -> pNext = NULL;
        (*ppHead)-> pPrev = NULL ;
        free(*ppHead);
        *ppHead=*ppTail=NULL;
        return iDelData;
    }
    pTemp = *ppHead;
    *ppHead = pTemp -> pNext;
    pTemp -> pNext = NULL;
    pTemp -> pPrev = NULL;
    (*ppHead) -> pPrev = *ppTail;
    (*ppTail) -> pNext = *ppHead;
    
    free(pTemp);
    pTemp=NULL;
    return iDelData;
    
}
int delete_last(struct node **ppHead,struct node **ppTail)
{
	int iDelData;
    struct node *pTemp=NULL;
    
    if(NULL == *ppHead)
    {
        
        return -1;
    }
    
    if(*ppHead == *ppTail)
    {
        (*ppHead) -> pNext = NULL;
        (*ppHead)-> pPrev = NULL ;
        iDelData=(*ppHead)->iData;
        free(*ppHead);
        *ppHead=*ppTail=NULL;
        return iDelData;
    }
    pTemp = *ppHead;
    while(pTemp -> pNext != *ppTail)
        pTemp=pTemp->pNext;
             
    (*ppTail) = pTemp;
    pTemp = (*ppTail ) -> pNext;
    pTemp -> pNext = NULL;
    pTemp -> pPrev = NULL;
    iDelData = pTemp -> iData;
    (*ppTail)-> pNext = *ppHead;
    (*ppHead) -> pPrev = *ppTail; 
    free(pTemp);
    pTemp=NULL;
    return iDelData;      
  
}  
int delete_at_position(struct node **ppHead,struct node **ppTail,int iPos)

{
	int iDelData;
    struct node *pTemp=NULL;  
    if(ppHead == NULL)
	{
		
		return 0;
	}
	iDelData=count_node(*ppHead,*ppTail);
 	   
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
    while (iDelData < iPos)
    {
        iDelData ++;
        pTemp = pTemp -> pNext;
    }
    pTemp -> pPrev -> pNext = pTemp -> pNext;
    pTemp -> pNext -> pPrev = pTemp -> pPrev;
    iDelData = pTemp -> iData;
    pTemp -> pNext = NULL;
    pTemp -> pPrev = NULL;      
    free(pTemp);
    pTemp=NULL;
    return iDelData;
}
int search_all(struct node *pHead,struct node *pTail,int iKey)    
{
    int iCount =0;
    if(NULL == pHead)
    {
      
        return 0;
        
    }
    do 
    {
        if(iKey == pHead -> iData)
            iCount ++;
        pHead = pHead ->pNext ;
    }while(pHead != pTail -> pNext);
    
    return iCount;
    
            
}
int search_first_occurrence(struct node *pHead,struct node *pTail,int iKey)    

{
    int iPosition = 0;
    
    do{
        
        if(iKey == pHead ->iData )
		{	
		  iPosition ++;
      	  break;
		}	
		iPosition ++;
		pHead = pHead -> pNext;
    }while(pHead != pTail -> pNext);
    if(iKey == pHead ->iData )
        return iPosition;
    else 
   		return -1;
}
int search_last_occurrence(struct node *pHead,struct node *pTail,int iKey)
{
 	int iPosition = 0;
	iPosition=count_node(pHead,pTail);
    do
    {
         
        if(iKey == pTail ->iData )
  			break;
		iPosition --;
        pTail = pTail -> pPrev;
    }while(pTail != pHead -> pPrev);
    if(iKey == pTail -> iData)
        return iPosition;
    else
       return -1; 
}
void display(struct node *pHead , struct node *pTail)
{
	if(pHead == NULL)
	{
		
		return ;
	}
    printf("\n\n\t Your List is \t :" );
    do
    {
        printf("<-| %d |->",pHead -> iData);
        pHead = pHead -> pNext;
     }while(pHead != pTail -> pNext);    
}
