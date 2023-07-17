
#include <iostream>//for input and output
#include <string>// for string functions
#include "medicineType.h"//
#include <stdlib.h>
#include <cctype>
#include <cstdio>
#include <fstream>
#include <iomanip>//for output manupulation
#define max 10
#include<time.h>//for time


using namespace std;

int main()	// Main function
{
    system("COLOR 1E");		//Color to change background
    system("cls");//it clears the output screen
    string password;
    password="afriyiemighty112";
    string username="group22";
    char email[100];
     cout<<"\t\t ENTER USER DETAILS TO LOGIN \n"<<endl;
        cout<<"\t\t=============================="<<endl;

        do//login to to the system
        {

            time_t ct=time(0);//record time pharmacist signed in/got to work
    string currenttime=ctime(&ct);
    cout<<"Time: "<<currenttime;


             cout<<"Enter Username: ";
        cin>>username;
        if(username!="group22")
        {
            cout<<"Pharmacist name is not in our records"<<endl;
            cout<<"Retry access"<<endl;
        }
        else
        cout<<" ";
        }while (username!="group22");
    do
    {
cout<<"Enter access code: ";
        cin>>password;
        if (password=="afriyiemighty112")
        {
            cout<<"ACCESS GRANTED"<<endl;
        }
        else
        {
            cout<<"ACCESS DENIED"<<endl;
            cout<<"RETRY ACCESS"<<endl;
        }

    }while (password!="afriyiemighty112");
    {
	medicineType medicine;
	int menu;
	do
	{
		system("cls");
		cout<<"\t\t\t WELCOME TO GROUP 22 PHARMACY \n";
		cout<<"\t\t\t LOCATION:UMAT-SRID(SR5) \n";
		cout<<"\t\t\t EMAIL:abanmighty@gmail.com\n";
		cout<<"\t\t\t TEL: 0508151068/0555881085/0556123150\n";
		cout<<"\t\t==================================================\n\n";
		cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
		cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
		cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
		cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
		cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";//for pharmacy managers only
		cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
		cout<<"\t\t--------------------------------------------------\n";
		cout<<"Enter choice: ";

		cin>>menu;

		switch (menu)//choose between the menu
		{
		case 1:
			{
				medicine.take_order();	//select the drugs you want
				break;
			}	//end case 1


		case 2:
			{
				medicine.delete_order();	// cancel an order
				system("PAUSE");//pause a program and wait for keyboard input to continue
				break;
			}	//end case 2

		case 3:
			{
				medicine.modify();	//modify or change order details
				system("PAUSE");
				break;
			}	//end case 3

		case 4:
			{
				medicine.order_list();	//Display and print and payment of receipts and cost of drugs
				system("PAUSE");
				break;
			}	//end case 4
		case 5:
			{
				medicine.daily_summary();	//Total transactions and summary throughout the day
				system("PAUSE");
				break;
			}	//end case 5
        case 6:
			{
				medicine.exit();	//EXIT
				goto a;
				break;
			}	//end case 6


		default:
			{
				cout<<"You enter invalid input\nre-enter the input\n"<<endl;
				break;
			}//end defeault
		}//end Switch
	}while(menu!=6);//end do
	a://goto

	system ("PAUSE");
	return 0;
}
}//end  main function


