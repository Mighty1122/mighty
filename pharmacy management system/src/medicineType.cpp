#include "medicineType.h"
#include<iostream>
#include<iostream>
#include<time.h>//for time
using namespace std;

medicineType::medicineType()
{
    //ctor
}

void medicineType::take_order()		//function to take_order
{
	system("cls");
	int i;
    int choice, quantity, price,None;

	cout <<"\nAdd Order Details\n";
	cout <<"_____________________________________ \n\n";

	node *temp;
	temp=new node;

								cout <<"**************************************************************************\n";
				cout<<"DRUGS ID"<<"\tDRUGS TYPE"<<"   \t\tDRUGS NAME"<<"                                    DRUGS PRICE(RM)"<<endl;
				cout <<"*******************************************************************************************************\n";
                cout<<"0001"<<"\t"<<"\tOTC"<<"\t\t"<<"    Paracetamol"<<"                                   GHC 2.00"<<endl;
                cout<<"0002"<<"\t"<<"\tOTC"<<"\t\t"<<"    Vitamin C(500mg)"<<"                              GHC 3.00"<<endl;
                cout<<"0003"<<"\t"<<"\tOTC"<<"\t\t"<<"    Diclofenac tab(500mg) "<<"                        GHC 1.00"<<endl;
                cout<<"0004"<<"\t"<<"\tOTC"<<"\t\t"<<"    Metronedazol"<<"                                  GHC 4.00"<<endl;
                cout<<"0005"<<"\t"<<"\tOTC"<<"\t\t"<<"    Gebedol"<<"                                       GHC 1.00"<<endl;
                cout<<"0006"<<"\t"<<"\tOTC"<<"\t\t"<<"    lufart"<<"                                        GHC 5.00"<<endl;
                cout<<"0007"<<"\t"<<"\tOTC"<<"\t\t"<<"    Ampicilin"<<"                                     GHC 7.00"<<endl;
                cout<<"0008"<<"\t"<<"\tOTC"<<"\t\t"<<"    Madam Cathrine Blood Tonic"<<"                    GHC 4.00"<<endl;
                cout<<"0009"<<"\t"<<"\tOTC"<<"\t\t"<<"    Tabea Herbal mixture "<<"                         GHC 3.00"<<endl;
                cout<<"0010"<<"\t"<<"\tOTC"<<"\t\t"<<"    Adutwumwaa malamix"<<"                            GHC 5.00"<<endl;
                cout<<" "<<endl;


	temp = new node;
	cout << "Type Order no: ";
    cin >> temp->reciept_number;
	cout<< "Enter Customer Name: ";
	cin>> temp->customerName;
	cout<<"Enter Date : ";
	cin>>temp->date;
	cout << "How many Medicine would you like to order:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please select drug ID to choose a drug : "<<endl;
		cin>> temp->menu2[i];
        cout<< "Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay is: " << temp->amount[i]<<" GHC"<<endl;
        system("PAUSE");

	}
	cout<<"==========================================================================="<<endl;
    cout << "Order Taken Successfully"<<endl;
    cout<<"==========================================================================="<<endl;
    cout << "Go to Reciept Menu to Pay The Bill"<<endl;
    cout<<"==========================================================================="<<endl;
	system ("PAUSE");

    temp->next=NULL;
	if(start_ptr!=NULL)
	{
		temp->next=start_ptr;
	}
	start_ptr=temp;
	system("cls");
}
}//End function take_order



void medicineType::delete_order()	//function to delete_order
{
	system("cls");
	int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
	node *temp;
	bool found;

	if(start_ptr == NULL)
		cerr<<"Can not delete from an empty list.\n";
	else
	{
		if(start_ptr->reciept_number == num)
		{
			q = start_ptr;
			start_ptr = start_ptr->next;
			count--;
			if(start_ptr == NULL)
			last = NULL;
			delete q;
			cout<<"The Reciept is Deleted Successfully"<<endl;
		}
		else
		{
			found = false;
			temp = start_ptr;
			q = start_ptr->next;

		while((!found) && (q != NULL))
		{
  			if(q->reciept_number != num)
			{
				temp = q;
				q = q-> next;
			}
			else
				found = true;
		}

			if(found)
			{
				temp->next = q->next;
				count--;

				if(last == q)
				last = temp;
				delete q;
				cout<<"The Reciept is Deleted Successfully"<<endl;
			}
			else
				cout<<"Item to be deleted is not in the list."<<endl;
			}
		}
}	//End function delete_order


void medicineType::modify()		//function to modify order
{
 system("cls");
 int i, ch, sid;
 bool found;
 found = false;
 temp = start_ptr;
 cout<<"Enter Receipt Number To Modify: ";
 cin>>sid;
 if (temp==NULL && sid==0)
 {
    cout<<"NO RECORD TO MODIFY..!"<<endl;
 }

 else
 {
 	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==sid)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
    if (found)
    {
	cout << "Change  Order Number: ";
    cin >> temp->reciept_number;
	cout<< "Change Customer Name: ";
	cin>> temp->customerName;
	cout<<"Change Date : ";
	cin>>temp->date;
	cout << "How many New Medicine would you like to Change:"<< endl;
	cout<<"( Maximum is 10 order for each transaction ) \n";
	cout << "  " ;
	cin >> temp->x;
	if (temp->x >10)
	{
		cout << "The Medicine you order is exceed the maximum amount of order !";
		system("pause");
	}
	else{
	for (i=0; i<temp->x; i++)
	{

		cout << "Please select drug ID to Change: "<<endl;
		cin>> temp->menu2[i];
        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
        cout << "How many New medicine do you want: ";
        cin >> temp->quantity[i];
        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" GHC"<<endl;
        system("PAUSE");
	}
	temp = temp->next;
	system("cls");

	}

 cout<<"RECORD MODIFIED....!"<<endl;
 }
 else
 {
 	if(temp != NULL && temp->reciept_number != sid)
 	{
 	cout<<"Invalid Reciept Number...!"<<endl;
    }
 }
}
}
}		//End modify function
void medicineType::order_list()		//Function to display receipt
{
      time_t ct=time(0);//record time pharmacist signed in/got to work
    string currenttime=ctime(&ct);

	int i, num, num2;
	bool found;			//variable to search
	system("cls");
	node *temp;

	temp=start_ptr;
	found = false;

	cout<<" Enter the Reciept Number To Print The Reciept\n";
	cin>>num2;
	cout<<"\n";
	cout<<"==========================================================================="<<endl;
	cout <<"\t\tHere is the Order list\n";
	cout<<"==========================================================================="<<endl;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
		if (temp->reciept_number==num2)
		{
			found = true;
		}
		else
		{
			temp = temp -> next;
		}
        if (found)	//print the receipt
        {
            cout<<" \t\t                    OFFICIAL RECEIPT                                   \n "<<endl;
            cout<<"t\t\                     GROUP 22 PHARMACY LIMITED                               \n"<<endl;
            cout<<"_____________________________________________________________________________"<<endl;
		cout <<"Reciept Number : "<<temp->reciept_number;
		cout <<"\n";
		cout<<"Customer Name: "<<temp->customerName<<endl;

		cout<<"Print Date : "<<currenttime<<endl;
		cout<<"Cashier: MIGHTY"<<endl;
		cout<<"TRANSCRIPTION FROM : DR. EZEKIEL MARTEY"<<endl;
		cout<<"_____________________________________________________________________________"<<endl;

		cout << "===============================================================================" << endl;
		cout << "|Medicine Type|     Medicine Name      |  Quantity     |  Total Price |" << endl;
		cout << "++============================================================================" << endl;
		for (i=0;i<temp->x;i++)
		{
			cout << temp->type <<"  \t\t";
			cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
			cout<<temp->quantity[i] <<"\t\t";
			cout<< temp->amount[i]<<" GHC"<<endl;
			cout<<"_________________________________________________________________________________"<<endl;
		}

		temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
						+temp->amount[8]+temp->amount[9];
		cout<<"Total Bill is : GHC"<<temp->total;
		cout<<"\n";
		cout << "Type the exact amount You need to pay: ";
        cin >> num;

		cout <<"\n";
		cout <<"\n";
		cout<<"Payment Done\nThank You\n";
		cout <<"\n_______________________________________________________________________________\n";
		}


}
}	//End function order_list


void medicineType::daily_summary()		//Function to display Daily Summary
{
	int i,num;
	system("cls");
	node *temp ;

	temp=start_ptr;


	if(temp == NULL) //Invalid receipt code
	{
		cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	else
	{
		cout<<"\n";
		cout<<"==========================================================================="<<endl;
		cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
		cout<<"==========================================================================="<<endl;

		while(temp!=NULL)
		{

				cout <<"Reciept Number : "<<temp->reciept_number;
				cout <<"\n";
				cout<<"Customer Name: "<<temp->customerName<<endl;

				cout<<"Order Date : "<<temp->date<<endl;

				cout<<"____________________________________________________________________________"<<endl;

				cout << "==========================================================================" << endl;
				cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
				cout << "=======++==================++================++===============++==========" << endl;
			for (i=0;i<temp->x;i++)
			{
				cout << temp->type <<"  \t\t";
				cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
				cout<<temp->quantity[i] <<"\t\t";
				cout<< temp->amount[i]<<" GHC"<<endl;
				cout<<"_____________________________________________________________________________"<<endl;
			}

			temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
			+temp->amount[8]+temp->amount[9];
			cout<<"Total Bill is : "<<temp->total;

			cout <<"\n";
			cout <<"\n";
			cout <<"\n_______________________________________________________________________________\n";

			temp=temp->next;
		}
	}
}		//End daily summary
void medicineType::exit() //Function to exit
{
	cout<<"\nYou choose to exit.\n"<<endl;
	cout<<"THANK YOU FOR USING GROUP 22 PHARMACY"<<endl;
	cout<<"YOUR HEALTH OUR PRIORITY"<<endl;
}	//end function exit


////////////////////////////THE END OF PROGRAM//////////////////////////////////////////
