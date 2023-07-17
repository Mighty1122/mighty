#ifndef MEDICINETYPE_H
#define MEDICINETYPE_H
#include<iostream>
#include<iostream>
using namespace std;

class medicineType
{
    public:
    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void modify(); //to modify the order
	void order_list(); //to display the order_list
	void daily_summary(); //to display daily_summary
	void exit();  //function to exit system
	medicineType();//constuctor
	struct node //constract node
{
	int reciept_number;
	string customerName;
	string date;
	int quantity[10];
	string type = {"OTC"};
	int x, menu2[10];
    double amount[10];
    string medicineName[10]={"Paracetamol","Vitamin C(500mg)","Diclofenac(500mg)","metronedazol","Gebedol","lufart",
	"Ampicilin","Madam Cathrine Blood Tonic","Tabea Herbal mixture ","Adutwumwaa malamix"};

	double Medicine[10] = {2.00,3.00,1.00,4.00,1.00,5.00,7.00,4.00,3.00,5.00};
	double total;

	node *prev;
	node *next;
	node *link;

}*q, *temp;				//pointer declaration


node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;


    protected:

    private:
};

#endif // MEDICINETYPE_H
