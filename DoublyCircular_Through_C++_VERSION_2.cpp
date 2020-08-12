#include<iostream>
using namespace std;
class List;
class node
{
	private :
		node *pPrev;
		int iData;
		node *pNext;

	public :
		node ( int iNo)
		{
			
			iData = iNo;
			pPrev = NULL;
			pNext = NULL ;

		}
		~node ()
		{
			iData ==0;
			if (pNext != NULL)
			{
				pNext = NULL ;
                pPrev =NULL;
                
			}

            
		}
	friend class List;
};
class List 
{
	private:
		node *pFirst;
		node *pLast ;
	public :
		List ()
		{
			
			pFirst = NULL ;
			pLast = NULL ;
		}
		~List ()
		{
			if(pFirst != NULL)
			  delete_all();
        }

	void insert_first(int iNo)
	{
		node *pNewnode = NULL;
		pNewnode = new node (iNo);
		if( NULL == pNewnode)
		{
			cout<<"Memory Allocatin is Faild"<<endl;
			return ;
		}
		pNewnode -> iData = iNo;
		if(NULL == pFirst)
		{
			pFirst = pLast = pNewnode;
			pFirst -> pPrev  = pLast;
			pLast -> pNext =pFirst;
			return ;
		}	
		pNewnode -> pNext = pFirst;
		pNewnode -> pNext -> pPrev = pNewnode;
		pFirst = pNewnode;
		pFirst -> pPrev = pLast;
		pLast -> pNext = pFirst;

	}
	void insert_last(int iNo)
	{
		node *pNewnode =NULL;
		pNewnode = new node (iNo);
		if( NULL == pNewnode)
		{
			cout<<"Memory Allocatin is Faild"<<endl;
			return ;
		}
		pNewnode -> iData = iNo;
		if(NULL == pFirst)
		{
			pFirst = pLast = pNewnode;
			pFirst -> pPrev  = pLast;
			pLast -> pNext =pFirst;
			return ;
		}	
		pLast -> pNext = pNewnode ;
		pNewnode -> pPrev = pLast ;
		pLast = pNewnode ;
		pFirst ->pPrev = pLast ;
		pLast -> pNext = pFirst ;
	}
	int count_node()
	{
		int iCounter =0 ;
		if (NULL == pFirst)
		{
			return 0;
		}
		do{
			iCounter ++;
			pFirst =pFirst -> pNext ;
		}while(pFirst != pLast ->pNext);
		return iCounter ;
	}
	void insert_at_position(int iPos,int iNo)
	{ 
		int iCounter;
    	node *pNewnode = NULL;
	    node *pTemp = NULL;
    	iCounter=count_node();
    
    	if(1 == iPos)
    	{
    
        	insert_first(iNo);
        	return ;
    	}
    	if(iPos ==iCounter + 1)
    	{    
        	insert_last(iNo);
        	return ;
    	}
    	pNewnode = new node (iNo);
		if( NULL == pNewnode)
		{
			cout<<"Memory Allocatin is Faild"<<endl;
			return ;
		}
		pNewnode -> iData = iNo ;
    	pTemp =pFirst ;
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
    int delete_first()
    {
    	int iDelData;
    	node *pTemp = NULL;
    	if(NULL == pFirst)
    	{
    		return -1;
    	}
    	iDelData=pFirst-> iData ;
    	if(pFirst == pLast)
    	{
    		pFirst ->pNext =NULL;
    		pFirst -> pPrev=NULL;
    		delete pFirst;
    		pFirst = pLast =NULL;
    		return iDelData;
    	}
    	pTemp =pFirst;
    	pFirst =pTemp -> pNext;
    	pTemp ->pNext =NULL;
    	pTemp -> pPrev =NULL;
    	pFirst ->pPrev =pLast;
    	pLast -> pNext =pFirst;
    	delete pTemp;
    	return iDelData;

    }
    int delete_last()
    {
    	int iDelData;
    	node *pTemp = NULL;
    	if(NULL == pFirst)
    	{
    		return -1;
    	}
    	
    	if(pFirst == pLast)
    	{
    		pFirst ->pNext =NULL;
    		pFirst -> pPrev=NULL;
    		iDelData = pFirst -> iData;
    		delete pFirst;
    		pFirst = pLast =NULL;
    		return iDelData;
    	}
    	pTemp =pFirst;
    	while (pTemp -> pNext != pLast)
    		pTemp=pTemp->pNext;

    	pLast = pTemp;
    	pTemp =pLast ->pNext;
    	pTemp ->pNext =NULL;
    	pTemp -> pPrev = NULL;
    	iDelData =pTemp -> iData;
    	pLast ->pNext =pFirst;
    	pFirst ->pPrev =pLast;
    	delete pTemp;
    	pTemp =NULL;
    	return iDelData;

    }
    int delete_at_position(int iPos)
    {
    	int iDelData;
    	node *pTemp =NULL;
    	if(pFirst == NULL)
    	{
    		return 0;
    	}
    	iDelData=count_node();
    	if(iPos == 1)
    	{
    		return delete_first();
    	}
    	if(iPos == iDelData)
    	{
    		return delete_last();
    	}
    	pTemp =pFirst;
    	iDelData =1;
    	while(iDelData < iPos)
    	{
    		iDelData ++;
    		pTemp = pTemp ->pNext;
    	}
    	pTemp -> pPrev -> pNext = pTemp -> pNext;
    	pTemp -> pNext -> pPrev =pTemp -> pPrev;
    	iDelData =pTemp ->iData;
    	pTemp -> pNext =NULL;
    	pTemp -> pPrev =NULL;
    	delete pTemp;
    	pTemp =NULL;
    	return iDelData;
    }
  void  delete_all()
    {
        while( pLast != pFirst )
        {
           pLast = pLast -> pPrev ;
           delete (pLast -> pNext);
            pLast -> pNext = pFirst;
            pFirst -> pPrev = pLast;
        }
            delete pLast;
            pLast=NULL;
            pFirst =NULL;
            cout<<"\n \t Deleted All Sucessfully"<<endl;
    }
    int search_all(int iKey)
	{
		int iCount=0;
        if(NULL == pFirst)
		{
			return 0;
		} 
		do
		{
			if(iKey == pFirst ->iData)
				iCount ++;
			pFirst = pFirst ->pNext;

		}while(pFirst != pLast ->pNext);
		return iCount;
	}
	
	int search_first_occurrence(int iKey)
    {
        int iPos=0;
        node *pTemp= pFirst;
        node *pTemp1=pLast;
        if(pTemp == NULL)
        {
            return 0;
        }
        do{
            if(iKey == pTemp -> iData)
            {
                iPos ++;
                break;
            }
            iPos ++;
            pTemp = pTemp -> pNext;
        }while(pTemp != pTemp1 -> pNext);
        if(iKey == pTemp -> iData)
            return iPos ;
        else
            return -1;
    }
    int search_last_occurrence(int iKey)
    {
        int iPos =0; 
        iPos=count_node();
        node *pTemp= pFirst;
        node *pTemp1=pLast;
        if(pTemp == NULL)
        {
            return 0;
        }
        do{
            if(iKey == pTemp1 ->iData)
                break;
            iPos --;
            pTemp1 =pTemp1 ->pPrev;
        }while(pTemp1 != pTemp -> pPrev);
        if(iKey == pTemp1 ->iData)
            return iPos;
        else 
            return -1;
    }
	void display ()
	{
		if (pFirst == NULL)
		{
			cout<<"\n\n\t\tYour List is Empty\t :";
			return;
		}
		cout<<"\n\n\t\t Your list is :";
		do{
			cout<<"<-|"<<pFirst->iData<<"|->";
			pFirst = pFirst -> pNext ;
		}while(pFirst != pLast -> pNext);

	}
	
};

int main()
{
	
	List obj;
	int iCount =0,iDelData=0,iData=0,iChoice=0,iPosition=0;
	 cout<<"\n \t * DOUBLY CIRCULAR LINKED LIST USING C++ *"<<endl;
       cout<<"\n \t \t \tVERSION - 2 "<<endl;
	while(1)
    {
    	
        cout<<"\n [1] INSERT_ELEMENT \t:\n [2] DELETE_ELEMENT \t:\n [3] SEARCH_ELEMENT \t:\n [4] COUNT_ELEMENT \t:\n [5] EXIT \t:\n"<<endl;
        cout<<"\n\t Enter your choice \t:";
        cin>>iChoice; 
		 
            switch(iChoice)
            {
                case 1:
                
                    while(1)
                    {
                        cout<<"\n\n\t [1] ADD ELEMENT AT BEGINNING \t:\n\t [2] ADD ELEMNET AT END \t:\n\t [3] ADD ELEMENT AT POSITION \t:\n\t [4] BACK "<<endl;
                        cout<<"\n\n\t\tEnter your choice inserting element \t:";
                        cin>>iChoice;
						if(iChoice == 3)
                        {
                            cout<<"\n\t\t Enter The Position of Node \t:";
                            cin>>iPosition;
                            if(iPosition<=0 || iPosition>(obj.count_node()+1))
                            {
                                cout<<"\n\n\t Your Position is invalid :\n";
                                continue;
                            }
                        }
                        if(iChoice<=3)
                        {
                            cout<<"\n\n\t\t Enter the Element to list \t:";
                            cin>>iData;
                        }
                    	 switch(iChoice)
                    	{
                        	case 1:
                        
                            	obj.insert_first(iData);
                            	cout<<"\n\t\t Element to be inserted first position\t:";
                       		     break;
                        
                        	case 2:
                        
                            	obj.insert_last(iData);
                            	cout<<"\n\t\t Element to be inserted last position \t:";
                            	break;
                            
                        	case 3:
                        
                            	obj.insert_at_position(iPosition,iData);
                            	cout<<"\n\t\t Element to be inserted at-posotion \t:";
                            	break;
                            
                        	case 4:
                                break ;


                        	default:
                           			 cout<<"\n \t Your choice is worng \t:"<<endl;
                    	}   
											if(iChoice == 4)
												break;
											obj.display();
			
				}
				break ;
				case 2:
					 while(1)
                    {
                     iCount=obj.count_node();
                     if(iCount == 0)
                       	break;
                     else	 
                        cout<<"\n\t [1] DELETE THE FIRST ELEMENT :\n\t [2] DELETE THE LAST ELEMENT :\n\t [3] DELETE THE AT-POSITION : \n\t [4] BACK \n ";
                        cout<<"\n\t Enter your choice \t:";
                        cin>>iChoice;
                        switch(iChoice)
                        {
                            case 1:
                            
                                 iDelData=obj.delete_first();
                                 if(iDelData== -1)
                                    cout<<"Data is wrong :\t";
                                 else
                                    cout<<"\n\t\t Deleted element value is \t:"<<iDelData;
                                 break;    
                              
                            case 2 :
                            
                                 iDelData=obj.delete_last(); 
                                 if(iDelData== -1)
                                    cout<<"Data is wrong :\t";
                                 else
                                    cout<<"\n\t\t Deleted element value is \t:"<<iDelData;
                                 break;
                                  
                            case 3:
                            
                                cout<<"\n\t\tEnter the position to de deleted :\t";
                                cin>>iPosition;
                                    if(iPosition<=0 || iPosition>(obj.count_node())) 
                                    {
                                        cout<<"\n\t Your position is invalid \n";
                                        continue;
                                    }
                                    iDelData=obj.delete_at_position(iPosition );
                                        if(iDelData == -1)
                                            cout<<"\t Position is wrong \t :";
                                        else 
                                            cout<<"\n\t\t Deleted element value is \t:"<<iDelData; 
                                  break;
                                  
                            case 4:
                                    break;
                                    
                            default :
                                  cout<<"\n\t choice is worng :\t";
                                          
                        }   
                         if(iChoice == 4)
                            break;
                            
                          obj.display();        
                }
				break;
				case 3:
					 while(1)
                    {
                     	iCount=obj.count_node();
                     	if(iCount == 0)
                       		break;
                     	else
                        cout<<"\n\n\t [1] SEARCH FIRST OCCURRENCE LIST :\n\t [2] SEARCH LAST OCCURRENCE LIST :\n\t [3] SEARCH ALL OCCURRENCE LIST :\n\t [4] BACK : \n";
                        cout<<"\n\t Enter your choice \t:";
                        cin>>iChoice;
                        switch(iChoice)
                        {
                            case 1:
                            	cout<<"\n\t\t Enter the element which want to search first occurrence \t:";
                                cin>>iData;
                                iCount=obj.search_first_occurrence(iData);
								if(iCount == -1)
										cout<<"\n\t\t Data Not Present in List :\n";
								else	
										cout<<"\n\t\t Data First found At position :"<<iCount ;
                            break;
                            
							case 2:
                            	cout<<"\n\t\t Enter the element which want to search last occurrence\t:";
                                cin>>iData;
                                iCount=obj.search_last_occurrence(iData);
                            	if(iCount == -1)
										cout<<"\n\t\t Data Not Present in List :\n";
								else	
									cout<<"\n\t\t Data Last found At position :"<<iCount ; 
                                break;
							 
                            case 3:
                                
                                cout<<"\n\t\t Enter the Element to search All \t:";
                                cin>>iData;
                                iCount=obj.search_all(iData);
                                if(iCount == 0)
									cout<<"\n\t\t Data Not Present in List :\n"<<iCount;
								else
									cout<<"\n\t\tData Occurrence given number is  :"<<iCount;
                             break;
                            
                            case 4:
                                break;
                            
                             default :
                                  cout<<"\n\t choice is worng :\t";
                                          
                        }   
                         
                         if(iChoice == 4)
                            break; 
                        obj.display();
                        
                    }
                break; 
				case 4:
					iCount=obj.count_node();
					cout<<"\n\t Total Number of Count is : "<<iCount<<endl;
					break;

				case 5:
					    return 0;
				default :
					cout<<"\n \t Your Choice is worng"<<endl;
                
            }

    }
               					
               return 0;
}
