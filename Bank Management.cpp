#include <iostream>
#include <vector>
using namespace std;
class BankAccount{
	private:
		string name;
		int accountNumber;
		double balance;
	public:
	    BankAccount(string n, int acc, double bal){
	    	name =n ;
	    	accountNumber= acc;
	    	balance= bal;
		}	
		string getName(){
			return name;
		}
		int getAccountNumber(){
			return accountNumber;
		}
		double getBalance(){
			return balance;
		}
		void depositAmount(double amount){
			balance = balance + amount;
		}
		void withdrawAmount(double amount){
			if(balance >= amount){
				balance = balance - amount;
				cout<<"\t\tWithdraw Successfully."<<endl;
			}else{
				cout<<"\t\tInsufficient Balance!"<<endl;
			}
		}
};
class BankManagement{
	private:
		vector<BankAccount> accounts;
	public:
		void addAccount(string name, int accountNumber, double balance){
			accounts.push_back(BankAccount(name,accountNumber,balance));
		}
		void showAllAccounts(){
			cout<<"\t\tAll Accounts Holders"<<endl;
			for(int i = 0; i<accounts.size(); i++){
				cout<<"\t\tName:"<<accounts[i].getName()<<" \t\t\nAccount Number:"<<accounts[i].getAccountNumber()<<" \t\t\nBalance:"<<accounts[i].getBalance()<<endl;
				
			}
		}
		void searchAccount(int account){
			cout<<"\t\tAccount Holder "<<endl;
			for(int i = 0; i<accounts.size();i++){
				if(accounts[i].getAccountNumber()==account){
		        	cout<<"\t\tName:"<<accounts[i].getName()<<" \t\tAccount Number:"<<accounts[i].getAccountNumber()<<" \t\tBalance:"<<accounts[i].getBalance()<<endl;	
				}
			}
		}
		BankAccount* findAccount(int accountNumber){
			for(int i = 0; i<accounts.size(); i++){
				if(accounts[i].getAccountNumber() == accountNumber){
					return &accounts[i];
				}
			}
		}
};
main(){
	BankManagement bank;
	int choice;
	char option;
	do{
		system("cls");
	cout<< "\t\t::Bank Management System"<< endl;
	cout<<"\t\t\tMain Menu"<<endl;
	cout<<"\t\t 1. Create New Account" <<endl;
	cout<<"\t\t 2. Show All Account"<<endl;
	cout<<"\t\t 3. Search Account"<<endl;
	cout<<"\t\t 4. Deposit Money"<<endl;
	cout<<"\t\t 5. Withdraw Money"<<endl;
	cout<<"\t\t 6. Exit"<<endl;
	cout<<"\t\t ------------------------------------"<<endl;
	cout<<"\t\t Enter Your Choice:";
	cin>>choice;
	switch(choice){
		case 1:{
			string name;
			int accountNumber;
			double balance;
			cout<<"\t\tEnter name:";
			cin>>name;
			cout<<"\t\tEnter Account Number:";
			cin>>accountNumber;
			cout<<"\t\tEnter Initial Balance:";
			cin>>balance;
			bank.addAccount(name,accountNumber,balance);
			cout<<"\t\tAccount Created Successfully."<<endl;
			break;
		}
		case 2:{
			bank.showAllAccounts();
			break;
		}
		case 3:{
				int accountNumber;
				cout<<"Enter Account Number :";
				cin>>accountNumber;
				bank.searchAccount(accountNumber);
				break;
			}
		case 4:{
			int accountNumber;
			double amount;
			cout<<"\t\tEnter Account Number to deposit Money:";
			cin>>accountNumber;
			BankAccount* account = bank.findAccount(accountNumber);
			if(account != NULL){
				cout<<"\t\tEnter Amount to Deposit:";
				cin>>amount;
				account->depositAmount(amount);
				cout<<"\t\t"<<amount<<" Deposit Successfully."<<endl;
				}else{
					cout<<"\t\tAcount Not Found."<<endl;
			}
			break;
		}	
		case 5:{
			int accountNumber;
			double amount;
			cout<<"\t\tEnter Account Number to Withdraw Money:";
			cin>>accountNumber;
			BankAccount* account = bank.findAccount(accountNumber);
			if(account != NULL){
				cout<<"\t\tEnter Amount to Withdraw:";
				cin>>amount;
				account->withdrawAmount(amount);
				
				}else{
					cout<<"\t\tAcount Not Found."<<endl;
				}
			break;
		}
	}
	cout<<"\t\tDo you want to continue or exit [Yes/No]??";
	cin>>option;
    }while(option == 'y' || option == 'Y');
	
}
