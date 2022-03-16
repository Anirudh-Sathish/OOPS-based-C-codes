// Anirudh Sathish 

// Intern and Manager records Using concepts of Inherintance 

#include<iostream>

using namespace std;


/*----------------------------------------------------------------------------*/
/*----------------------  Class node ----------------------------------*/
class node   // defining a class node 
{
	public:
		int data;
		string name ;
		long double amount ;
		int months;
		node *next;
		
		node() // Constructor 
		{
			data = 0 ;
			name = "John Doe";
			amount = 0.0 ;
			months = 0;
			next = NULL;
		}
		node(int dat , string s , long double am , int month) // paramterised constructor 
		{
			data = dat;
			name = s;
			amount = am ;
			months = month;
		}
};


/*--------------------------------------------------------------------------------*/
/*------------------------- Class LinkedList------------------------------------*/
class Linkedlist // Class linkedlist
{
	private:
		node* head = NULL ;
	public:
		void insert(node *n) // inserting the node to the linkedlist (Appending)
		{
			if(head == NULL)
			{
				head = n ;
				n->next = NULL;
			}
			else
			{
				node * ptr = head ;
				
				while(ptr->next != NULL)
				{
					ptr = ptr->next ;
				}
				ptr->next = n ;
				n->next = NULL;
			}
		}
		void display()
		{
		  node * ptr = head ;
		  
		  if( head == NULL)
		  {
		  	cout<<"There are no people in this list "<<endl ;
		  }
		  else
		  {
		  	while(ptr != NULL)
		  	{
		  		cout<<"The ID is : "<<ptr->data<<endl ;
		  		cout<<"THe name is : "<<ptr->name<<endl ;
		  		cout<<"THe salary is : "<<ptr->amount<<endl ;
		  		cout<<"THe time worked in the organisation : "<<ptr->months<<endl ;
		  		ptr = ptr->next ;
			  }
		  }
		}
		node *search(int value ) // searching for a particular node in the linkedList
		{
		    node * ptr = head ;
			
			if(head == NULL)
			{
			  return NULL;
			}
			else
			{
				
				while(ptr != NULL)
				{
					if(ptr->data == value)
					{
						return ptr ;
					}
					ptr = ptr->next;
				}
			}
			return ptr;
		}
		int unique(int data)
		{
			node * ptr = head ;
			if( head == NULL)
			{
				cout<<"No data yet created , so your ID is unique "<<endl ;
		        return 1 ;
			}
			else
			{
				
				while(ptr != NULL)
				{
					if(ptr->data == data)
					{
						cout<<"ID not unique "<<endl ;
						return 0 ;
					}
					ptr = ptr->next;
				}
		    }
		    
		    return 1 ;
	    }
		
};


/*--------------------------------------------------------------------------------*/
/*--------------------------------- Class Employee -------------------------------*/
/*----------------------------- Its a base class --------------------------------*/
class Employee   // creating a base class Employee
{
	protected:
		int employee_ID ;
		string employee_name;		
};

/*--------------------------------------------------------------------------------*/
/*--------------------------------- Class Contract -------------------------------*/
/*-------------------------It inherits from Employee --------------------------------*/

class Contract : protected Employee // Class contract which inherits in protected form from Employee
{
	protected:
		long double pay_per_hour;
	public:
		long double setPay()
		{
			cout<<"Enter the amount to be set ,Salary per hour : "<<endl ;
			cin >>pay_per_hour;
			return pay_per_hour ;
			
		}
		void getPay()
		{
			cout<<"The pay granted to the employee is : "<<pay_per_hour<<endl ;
		}
};

/*--------------------------------------------------------------------------------*/
/*--------------------------------- Class Salaried -------------------------------*/
/*----------------------------- Inherits from Employee --------------------------------*/

class Salaried : protected Employee // Class inherits in the protected form from Employee
{
	protected:
		long double monthlyPay;
	public:
		long double setPay()
		{
			cout<<"Enter the amount to be set as monthly salary : "<<endl ;
			cin >>monthlyPay;
			return monthlyPay;
		}
		void getPay()
		{
			cout<<"The pay granted to the employee is : "<<monthlyPay<<endl ;
		}
};



/*--------------------------------------------------------------------------------*/
/*--------------------------------- Class Manager -------------------------------*/
/*----------------------------- Inherits from Employee --------------------------------*/
class Manager : private Employee  // Class inherits privately from Employee
{
	public:
		Salaried person ;
		long double a ;
		int workPeriod;
		Linkedlist list1;
		void setDetails()
		{
		  int check ;
		  node * n1 = new node ;
		  cout<<"Enter employee ID :"<<endl ;  
		  cin>>employee_ID;
		  check = list1.unique(employee_ID); // Checks if ID is unique 
		  
		  while(check == 0) // Ensures ID is unique 
		  {
		  	cout<<"Create unique ID"<<endl ;
		  	cout<<"Enter Manager ID"<<endl ;
		    cin>>employee_ID;
		    check = list1.unique(employee_ID);
		  	
		  }
		  n1->data = employee_ID ;
		  cout<<"Enter First Name : "<<endl ;
		  cin>>employee_name;
		  n1->name = employee_name ;
		  cout<<"Monthly pay : "<<endl ;
		  a = person.setPay();
		  n1->amount = a ;
		  cout<<"Enter the time the person has worked in the organisation in months : "<<endl ;
		  cin>>workPeriod;
		  n1->months = workPeriod;
		  list1.insert(n1);

		}
		void updateDetails()
		{
		  node * n9 = new node ();
		  cout<<"Enter the employee id : "<<endl ;
		  cin>>employee_ID;
		  n9 = list1.search(employee_ID);
		  cout<<"Name of the Manager : "<<n9->name<<endl ;
		  cout<<"Enter the time the person has worked in the organisation in months : "<<endl ;
		  cin>>workPeriod;
		  n9->months = workPeriod;
		}
		void getDetails()
		{
		  node * n7 = new node ();
		  cout<<"Enter the employee id : "<<endl ;
		  cin>>employee_ID;
		  n7 = list1.search(employee_ID);
		  cout<<"Name of the Manager : "<<n7->name<<endl ;
		  cout<<"Monthly pay of the Manger : "<<n7->amount<<endl ;
		  cout<<"Time in the organiasation : "<<n7->months<<endl ;
		}
		void setSalary()
		{
			node * n2 = new node();
			cout<<"Enter the employee id : "<<endl ;
			cin>>employee_ID;
			n2 = list1.search(employee_ID);
			cout<<"Enter the new salary of the employee : "<<endl ;
			a = person.setPay();
		    n2->amount = a ;
		}
		void getSalary()
		{
			node * n3 = new node();
			cout<<"Enter the employee id : "<<endl ;
			cin>>employee_ID;
			n3 = list1.search(employee_ID);
			cout<<"The salary of the employee is : "<<n3->amount <<endl ;
			cout<<"The time of work for the person in the oranisation :  "<<n3->months <<endl ;
			
			cout<<"The total salary of the person for the months worked in the organisation : "<<n3->amount*n3->months<<endl ;
		
		}
		
};

/*--------------------------------------------------------------------------------*/
/*--------------------------------- Class Intern -------------------------------*/
/*----------------------------- Inherits from Employee --------------------------------*/


class Intern : private Employee // Inherits privately from employee 
{
	public :
		Contract Worker;
		Linkedlist list2;
		long double a ;
		int workPeriod ;
		void setDetails()
		{
		  int check ;
		  node * n4 = new node ;
		  cout<<"Enter Intern ID"<<endl ;
		  cin>>employee_ID;
		  check = list2.unique(employee_ID);  // Checks if ID is unique 
		  
		  while(check == 0)  // Ensures unique ID is taken 
		  {
		  	cout<<"Create unique ID"<<endl ;
		  	cout<<"Enter Intern ID"<<endl ;
		  cin>>employee_ID;
		  check = list2.unique(employee_ID);
		  	
		  }
		  n4->data = employee_ID ;
		  cout<<"Enter First Name : "<<endl ;
		  cin>>employee_name;
		  n4->name = employee_name ;
		  cout<<"Dailywages : "<<endl ;
		  a = Worker.setPay();
		  n4->amount = a ;
		  cout<<"Enter the time the person has worked in the organisation in hours :"<<endl ;
		  cin>>workPeriod;
		  n4->months = workPeriod;
		  list2.insert(n4);

		}
		void getDetails()
		{
		  node * n8 = new node ();
		  cout<<"Enter the employee id : "<<endl ;
		  cin>>employee_ID;
		  n8 = list2.search(employee_ID);
		  cout<<"Name of the Intern : "<<n8->name<<endl ;
		  cout<<"Daily pay of the Intern :"<<n8->amount<<endl ;
		  cout<<"Time in the organiasation : "<<n8->months<<endl ;
		}
		void updateDetails()
		{
		  node * n10 = new node ();
		  cout<<"Enter the employee id : "<<endl ;
		  cin>>employee_ID;
		  n10 = list2.search(employee_ID);
		  cout<<"Name of the Intern :"<<n10->name<<endl ;
		  cout<<"Enter the time the person has worked in the organisation in months : "<<endl ;
		  cin>>workPeriod;
		  n10->months = workPeriod;
		}
		void setSalary()// Set Salary
		{
			node * n5 = new node();
			cout<<"Enter the employee id :"<<endl ;
			cin>>employee_ID;
			n5 = list2.search(employee_ID);
			cout<<"Enter the new salary of the employee : "<<endl ;
			a = Worker.setPay();
		    n5->amount = a ;
		}
		void getSalary()  // Function to get the salary of Intern
		{
			node * n6 = new node();
			cout<<"Enter the Intern id : "<<endl ;
			cin>>employee_ID;
			n6 = list2.search(employee_ID);
			cout<<"The salary of the Intern per hour is :"<<n6->amount <<endl ;
			cout<<"The time of work for the person in the oranisation in weeks :"<<n6->months <<endl ;
			cout<<"The total salary of the person for the hours worked in the organisation :"<<n6->amount*n6->months<<endl ;
		
		}
};



int main()
{
	Manager Bank;  // Manager Object 
	Intern Banki;  // Intern Object
	

	while(1)  // Menu Driven Code 
	{
		int choice , num ;
		cout<<"Chose which of the following u would wish to do "<<endl ;
	    cout<<"1.Create Employee Records"<<endl ;
	    cout<<"2.Update Employee Records  "<<endl ;
	    cout<<"3.Print Employee Details "<<endl ;
	    cout<<"4.Update Pay"<<endl ;
	    cout<<"5.Calculate Salary "<<endl ;
	    cout<<"6.Exit "<<endl ;
	    cin>>choice;
	    
	    switch(choice)
	    {
	    	case 1 :
	    		cout<<"Enter the details "<< endl ;
	    		cout<<"Chose whose details you want to enter "<<endl ;
	    		cout<<"1.Manager "<<endl ;
	    		cout<<"2.Intern" <<endl ;
	    		cin>>num ;
	    		
	    		if(num == 1)
	    		{
	    			Bank.setDetails();
	                cout<<"You have succesfully set Details of Managers "<<endl ;
				}
				else if(num == 2)
				{
					Banki.setDetails();
	                cout<<"You have succesfully set Details of Interns"<<endl ;
				}
				else
				{
					cout<<"Wrong inputs "<<endl ;
				}
				break;
				
		    case 2 :
		    	cout<<"Updating Emplyee details  "<<endl ;
		    	cout<<"1. Manager "<<endl ;
		    	cout<<"2.Intern "<<endl ;
		    	cin>>num ;
		    	
		    	if(num == 1)
	    		{
	    			Bank.updateDetails();
	                cout<<"You have succesfully set Details of Managers "<<endl ;
				}
				else if(num == 2)
				{
					Banki.updateDetails();
	                cout<<"You have succesfully set Details of Interns"<<endl ;
				}
				else
				{
					cout<<"Wrong inputs "<<endl ;
				}
				break ;
			
			case 3:
				cout<<"Print the employee details "<<endl ;
				cout<<"1. Manager "<<endl ;
		    	cout<<"2.Intern "<<endl ;
		    	cin>>num ;
		    	
		    	if(num == 1)
	    		{
	    			Bank.getDetails();
	                cout<<"Printing the details of Managers "<<endl ;
				}
				else if(num == 2)
				{
					Banki.getDetails();
	                cout<<"Printing the details of Interns"<<endl ;
				}
				else
				{
					cout<<"Wrong inputs "<<endl ;
				}
				break ;
			case 4:
				cout<<"Update Pay "<<endl ;
				cout<<"1. Manager "<<endl ;
		    	cout<<"2.Intern "<<endl ;
		    	cin>>num ;
		    	
		    	if(num == 1)
	    		{
	    			Bank.setSalary();
	                cout<<"You have succesfully set Details of Managers "<<endl ;
				}
				else if(num == 2)
				{
					Banki.setSalary();
	                cout<<"You have succesfully set Details of Interns"<<endl ;
				}
				else
				{
					cout<<"Wrong inputs "<<endl ;
				}
				break ;
			case 5 :
				cout<<"Update Pay "<<endl ;
				cout<<"1. Manager "<<endl ;
		    	cout<<"2.Intern "<<endl ;
		    	cin>>num ;
		    	
		    	if(num == 1)
	    		{
	    			Bank.getSalary();
	                cout<<"You have succesfully set Details of Managers "<<endl ;
				}
				else if(num == 2)
				{
					Banki.getSalary();
	                cout<<"You have succesfully set Details of Interns"<<endl ;
				}
				else
				{
					cout<<"Wrong inputs "<<endl ;
				}
				break ;
			case 6:
				exit(1);
				break;
			default:
				cout<<"Wrong input"<<endl ;
	   } 	
	}
	
	return 0 ;	
}	
