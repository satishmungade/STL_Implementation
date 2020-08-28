#include<iostream>
using namespace std;
class cDemo
{
    public :

	  static int M_iNo;
    static int M_iNo1;   
         
    public :          
	cDemo()
	{
	     M_iNo ++; 
	     M_iNo1 ++; 
                        
	}
    void Total_Object ()
    {
            cout<<"Total objects is :"<<M_iNo<<endl;
    
    }
    void Current_Object()
    {
            cout<<"Current objects is :"<<M_iNo1<<endl;
    }
     ~cDemo()
    {
          M_iNo1 --;
              
    }   
};

int cDemo::M_iNo=0;
int cDemo::M_iNo1=0;
void find()
    {
            
        cDemo obj;
             
    }
void find1()
    {
        cDemo obj1;
             
    }
void find2()
    {
             
        cDemo obj2; 
        
    }

int main()
{
     cDemo obj3,obj4;
     find();
     find1();
     find2();   
      
	 obj3.Current_Object(); 
	 obj3.Total_Object();  
     
  return 0;
}	
