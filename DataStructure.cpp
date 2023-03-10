#include <iostream>
using namespace std;

class Node
{
    public:
    string name;
    string id;
    int phone;
    string address;
    double invoice;
    Node* next;
};
/* Arjwan Alharbi / 2110826 
 Ruba  Alsulami / 2110618 
 Jawhara Alghamdi/ 2110081 */
Node* head = new Node();

// Check Function to check that if record already Exist or Not
bool check(string information)
{
    Node* temp=head;
   if(head == NULL) 
   return false;
   
   while(temp!=NULL)
   {
       if(temp->id==information)
       return true;
   
   temp=temp->next;
   
   }
   return false;
}

void creat(string name, string id, int phone, string address, double invoice)
{
    Node* node=new Node();
    Node*last=head;
   if(check(id))
   {
       cout<<"**The Patient is already Exist**\n";
       return;
   }
   node->name = name ;
   node->id= id;
   node->phone = phone ;
   node->address = address ; 
   node->invoice = invoice ;
   node->next=NULL;
   
   if(head == NULL || (head->id >= node->id))
   {
   		   node->next=head;
		   head=node;
   }
   
   else{
   		while(last->next !=NULL && last->next->id < node->id)
   		{
   			last=last->next;
   		}
   		node->next=last->next;
   		last->next=node;
   }
   cout<<"**The Patient Record inserted successfullu**\n";
}

// Function to search record Patient

void search(string id){
	if(head == NULL){
		cout<<"**There is no record like this**\n";
		return;
	}
	else {
		
		Node *temp = head ;
		while (temp){
			if(temp->id == id ){
			    cout<<endl;
				  cout << "Name:\t"
                     << temp->name << endl;
                cout << "Id:\t"
                     << temp->id << endl;
                cout << "Phone number:\t"
                     << temp->phone << endl;
                cout << "Address:\t"
                     << temp->address << endl;
                cout << "Invoice:\t"
                     << temp->invoice << endl;     
                return;
			}
			temp= temp->next;
		}
		
	}
}

// Function to delete record Patient

void Delete(string id )
{
	Node *temp = head;
	Node *prav = NULL;
	if (temp != NULL && temp->id == id )
	{
		head = temp->next;
		delete temp ;
		cout << "**Record Deleted Successfully**\n";
		return;
	}
	while (temp != NULL )
	{
	    if (temp->next ->id == id){
		
		prav = temp -> next ;
		temp -> next = temp -> next -> next ;
		delete prav ;
		cout << "**Record Deleted Successfully**\n";
		return; 
    	}
		temp = temp -> next ;
	}

}
void Show_Record()
{
    Node* temp = head;
    if (temp == NULL) {
        cout << "**No Record "
            << "Available**\n";
    }
    else {
        
        while (temp != NULL) {
            cout << temp->name << "\t"
                << temp->id << "\t"
                << temp->phone << "\t"
                << temp->address<< "\t"
                << temp->invoice<< endl;
            temp = temp->next;
        }
    }
}

void updateInvoice()
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->invoice > 100)
        {
            temp->invoice += (temp->invoice * 15 / 100);
        }
        temp = temp->next;
    }
}


int main()
{
    string name;
    string id=" ";
    int phone;
    string address;
    double invoice;
    int choice;
    head=NULL;
   
    while(true)
    {
       cout<<"\t\t\nWELCOME TO PATIENT'S RECORD\n\n";
        cout<<"Enter 1 to Creat new Patient Record\n";
        cout<<"Enter 2 to Search specfic Patient Record\n";
        cout<<"Enter 3 to Delet Patient Record\n";
        cout<<"Enter 4 to Show Patient Record\n";
        cout<<"Enter 5 to Update Invoice Patient Record\n";
		 cout<<"Enter 6 to Exist\n";
        cout<<"___________________________________________\n\n";
        cout<<"ENTER YOUR CHOICE:\n";
        cin>>choice;
        
        if(choice==1)
        {
            cout<<"Enter the name of Patient\n";
            cin>>name;
            cout<<"Enter the ID of Patient\n";
            cin>>id;
            while(id.length()!=10){
                cout<<"Invalid Number!..Try again.";
                cout<<"Enter the ID number of Patient (10 numbers):\n";
                cin>>id;
            }
            cout<<"Enter the phone number of Patient\n";
            cin>>phone;
            cout<<"Enter the address of Patient\n";
            cin>>address;
            cout << "Enter Patient Invoice: \n";
            cin >> invoice;
            creat(name, id, phone, address, invoice);
            cout<<"___________________________________________\n\n";
        }
        
        else if(choice==2)
        {
			  cout<<"Enter the ID of Patient\n";
			  cin>>id;
			  while(id.length()!=10){
                cout<<"Invalid Number!..Try again.";
                cout<<"Enter the ID number of Patient (10 numbers):\n";
                cin>>id;
            }
		     search(id);
            
        }
        
        else if(choice==3)
        {
            cout<<"Enter the ID of Patient\n";
			cin>>id;
			while(id.length()!=10){
                cout<<"Invalid Number!..Try again.";
                cout<<"Enter the ID number of Patient (10 numbers):\n";
                cin>>id;
            }
		    Delete(id);
		    cout<<"___________________________________________\n\n";
        }
        
        else if(choice==4)
        {
            Show_Record();
            cout<<"___________________________________________\n\n";
        }
        
        else if(choice==5)
        {
          updateInvoice();
          cout << "Patients Invoice are updating\n";
          cout<<"___________________________________________\n\n";
        }
        
        else if(choice==6)
        {
          cout << "SYSTEM IS CLOSED\n";
          exit(0);
        }
        
        else
        cout<<"Invalid choice Try Again\n";
    }
    
    return 0;
}