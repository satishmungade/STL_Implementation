#include<iostream>
using namespace std;
class Node
{
	private:
		Node *pNext;
		int iData;
		Node *pPrev;
	public:
		Node()
		{
			iData=0;
			pNext=NULL;
			pPrev=NULL;
		}
		~Node()
		{
			iData =0;
			if(pNext != NULL)
			{
				pNext=NULL;
				pPrev=NULL;
			}
		}
		friend class List;
};
class List
{
	private:
		Node *pDummyNode;
	public:
		List()
		{
			pDummyNode  = new Node;
			pDummyNode->pNext = pDummyNode;
			pDummyNode->pPrev = pDummyNode;

		}
		~List()
		{

			delete_all();
		}
	void insert_first(int );
	void insert_last(int);
	void insert_at_position(int,int);
	int count_node();
	int delete_first();
	int delete_last();
	int delete_at_position(int iPos);
	int search_all(int iKey);
	int search_first_occurrence(int iKey);
	int search_last_occurrence(int iKey);
	void delete_all();


	class Iterator
	{
		private:
			Node *pCurrentNode;
		public:
			Iterator()
			{
				pCurrentNode=NULL;
			}	
			~Iterator()
			{

			}

		int operator *()
		{
			return pCurrentNode->iData;
		}	
		Iterator& operator  ++()
		{
			pCurrentNode=pCurrentNode ->pNext;
			return *this;
		}
		Iterator& operator --()
		{
			pCurrentNode=pCurrentNode ->pPrev;
			return *this;
		}
		Iterator operator ++(int)
		{
			Iterator iTemp;
			pCurrentNode=pCurrentNode->pNext;
			return iTemp;
		}
		Iterator operator --(int)
		{
			Iterator iTemp;
			pCurrentNode=pCurrentNode->pPrev;
			return iTemp;
		}
		bool operator !=(Iterator Iter)
		{
			Iter.pCurrentNode = Iter.pCurrentNode->pNext;
			return pCurrentNode != Iter.pCurrentNode;
		}
		bool operator ==(Iterator Iter)
		{
			Iter.pCurrentNode = Iter.pCurrentNode->pNext;
			return pCurrentNode ==Iter.pCurrentNode;
		}
		bool operator < (Iterator Iter)
		{
			return pCurrentNode < Iter.pCurrentNode;
		}
		bool operator >(Iterator Iter)
		{
			return pCurrentNode > Iter.pCurrentNode;
		}
		bool operator <=(Iterator Iter)
		{
			return pCurrentNode <=Iter.pCurrentNode;
		}
		bool operator >=(Iterator Iter)
		{
			return pCurrentNode >=Iter.pCurrentNode;
		}

		void set_current(Node *pNew)
        {
            pCurrentNode = pNew; 
        }
        

	};	
	Iterator IterStart,IterEnd;
		
		Iterator& begin ()
		{
         	IterStart.set_current(pDummyNode->pNext);
			return IterStart; 
		}
	 	Iterator& end()
		{
        	IterEnd.set_current(pDummyNode ->pPrev);
			return IterEnd;
		}


};

void display_iterator(List &refList)
{   

    cout<<"\n\n\t\tIterator Display Start:"<<endl<<endl;
    for (List ::Iterator Iter=refList.begin();Iter !=refList.end(); ++ Iter )
    {

        cout<<"<-|"<<*Iter<<"|->";
    }
    cout<<endl;
}
void List :: insert_first(int iNo)
{
	
	Node *pNewNode=NULL;
	pNewNode =new Node;
	
	pNewNode ->iData=iNo;
	pNewNode ->pNext =pDummyNode->pNext;
	pDummyNode->pNext =pNewNode;
	pNewNode ->pPrev=pDummyNode;
	pNewNode->pNext->pPrev=pNewNode;
}
void List :: insert_last(int iNo)
{
	Node *pNewNode =new Node;
	pNewNode ->iData=iNo;
	
	pNewNode ->pPrev =pDummyNode-> pPrev;
	pNewNode->pNext=pDummyNode;
	pDummyNode->pPrev->pNext=pNewNode;	
	pDummyNode->pPrev=pNewNode;
}
int List :: count_node()
{
	int iCount=0;
	Node *pTemp=NULL;
	
	 pTemp = pDummyNode->pNext;
	if(pDummyNode->pNext == pDummyNode)
		return 0;
	do 
	{
		iCount ++;
		pTemp = pTemp->pNext;
		 
	}while(pTemp != pDummyNode ->pPrev->pNext );
	return iCount; 

} 
void List :: insert_at_position(int iPos,int iNo)
{
	int iCounter=0;
	Node *pTemp=pDummyNode->pNext;
	Node *pNewNode =new Node;
	iCounter=count_node();
	if(iPos == 1)
	{
		insert_first(iNo);
		return ;
	}
	if(iPos == iCounter + 1)
	{
		insert_last(iNo);
		return;
	}

	pNewNode ->iData=iNo;
	iCounter =1;
	while(iCounter < iPos -1)
	{
		iCounter ++;
		pTemp=pTemp->pNext;
	}
	pNewNode->pNext = pTemp->pNext;
	pNewNode->pNext->pPrev=pNewNode;
	pTemp->pNext=pNewNode;
	pNewNode->pPrev=pTemp;
	pTemp->pNext->pPrev=pTemp;
}	
int List :: delete_first()
{
	int iDelData=0;
	iDelData=pDummyNode->pNext->iData;
	pDummyNode->pNext = pDummyNode->pNext->pNext;
	pDummyNode->pNext->pPrev->pNext=NULL;
	pDummyNode->pNext->pPrev->pPrev=NULL;
	delete pDummyNode->pNext->pPrev;
	pDummyNode->pNext->pPrev=pDummyNode;
	return iDelData; 
}
int List :: delete_last()
{
	int iDelData =0;
	iDelData=pDummyNode->pPrev->iData;
	pDummyNode->pPrev = pDummyNode->pPrev->pPrev;
	pDummyNode->pPrev->pNext-> pNext=NULL;
	pDummyNode->pPrev->pNext-> pPrev=NULL;
	delete pDummyNode->pPrev->pNext;
	pDummyNode->pPrev->pNext=pDummyNode;
	return iDelData;
}
int List :: delete_at_position(int iPos)
{
	int iDelData =0;
	int iCount =0;
	Node *pTemp=pDummyNode->pNext;
	iCount=count_node();
	if(iPos == 1)
	{
		return delete_first();
	}
	if(iPos == iCount)
	{
		return delete_last();
	}
	iCount =1;
	while(iCount < iPos)
	{
		iCount ++;
		pTemp=pTemp->pNext;
	}
	pTemp ->pPrev ->pNext=pTemp->pNext;
	pTemp->pNext->pPrev=pTemp->pPrev;
	iDelData=pTemp->iData;
	pTemp->pNext=NULL;
	pTemp->pPrev=NULL;
	delete pTemp;
	pTemp=NULL;
	return iDelData;
}
int List :: search_all(int iKey)
{
	int iCount=0;
	Node *pTemp=NULL;
	pTemp = pDummyNode->pNext;
	do
	{
		if(iKey == pTemp ->iData)
			iCount ++;
		pTemp=pTemp ->pNext;
	}while(pTemp !=pDummyNode->pNext);
	return iCount;
}
int List :: search_first_occurrence(int iKey)
{
	int iPos=0;
	Node *pTemp=pDummyNode->pNext;
	do
	{
		if(iKey ==pTemp ->iData)
		{
			iPos ++;
			break;
		}
		iPos ++;
		pTemp=pTemp->pNext;
	}while(pTemp != pDummyNode->pNext);
	
	if(iKey == pTemp ->iData)
		return iPos;
	else
		return -1;
}
int List ::search_last_occurrence(int iKey)
{
	int iPos=0;
	iPos=count_node();
	Node *pTemp=pDummyNode->pNext;
	Node *pTemp1=pDummyNode->pPrev;
	do{
		if(iKey ==pTemp1 ->iData)
			break;
		iPos --;
		pTemp1=pTemp1->pPrev;
	 }while(pTemp1 !=pTemp->pPrev);
	
	if(iKey == pTemp1 ->iData)
			return iPos;
		else
			return -1;	

}
void List :: delete_all()
{
	while (pDummyNode->pNext != pDummyNode)
	{
		pDummyNode->pNext->pPrev=NULL;
		pDummyNode->pNext=pDummyNode->pNext->pNext;
		pDummyNode->pNext->pPrev->pNext=NULL;
		delete pDummyNode->pNext->pPrev;
		pDummyNode->pNext->pPrev=pDummyNode;
	}
	pDummyNode->pNext=NULL;
	pDummyNode->pPrev=NULL;
	delete pDummyNode;
	cout<<"\n \t Deleted All Sucessfully"<<endl;
}	
int main()
{
	
	List  obj;
	int iCount =0,iDelData=0,iData=0,iChoice=0,iPosition=0;
	 cout<<"\n \t * DOUBLY CIRCULAR LINKED LIST USING C++ *"<<endl;
       cout<<"\n \t \t \tVERSION : 5 "<<endl;
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
											display_iterator(obj);
                                            if(iChoice == 4)
												break;
											

			
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
                            
                          
                         display_iterator(obj);      
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
                        display_iterator(obj);
                        
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
