#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
static int choice,x;
static string data;
static char var;
int repeat();
int menu(){
	ifstream Get; ofstream Write;
	system("clear");
	cout<<"\n| | | | | SkuL01 Reminder Program | | | | |\n\n";
	cout <<"[1]Add Reminder\n[2]View Reminder\n[3]Delete File\n\nchoice:";
	cin>>choice;
	cin.ignore();
	if(choice == 1){
		cout<<"\nReminder: ";
		getline(cin,data);
		Write.open("rem\\Reminder.txt",ios::app);
		Write << data << endl;
		Write.close();
		cout<<"\n[*******] File successfully saved..\n";
	}
	else if(choice == 2){
		Get.open("rem\\Reminder.txt");
		cout<<"\n<< Reminders >>\n\n";
		while(getline(Get, data)){
			cout << data << endl;
		}
		cout<<"\n[*******] File successfully opened..\n";				
		Get.close();

	}
	else if(choice == 3){
		cout<<"Are you sure you want to delete the file?[y/n]\nchoice: ";
		cin >> var;
		if(var == 'y' || var =='Y'){
		remove("rem\\Reminder.txt");
		cout<<"[*******] File successfully deleted..\n\n";
		}
		else{
			cout<<"File not deleted..\n";
		}
	}
	return repeat();
}
int repeat(){
	cout << "\nDo you want to repeat? [y/n]\nchoice:";
	cin >> var;
	if(var == 'y' || var == 'Y'){
		x = 1;
	}
	else{
		x = 0;
	}
	return x;
}


int main(){
	string quote = "Remember your tasks. - SkuL01\n";
	while(menu() == 1){

	}
	system("clear");
	cout<<quote;
	return 0;
}
