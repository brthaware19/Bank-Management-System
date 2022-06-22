#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;
#include "BankAccount_class.h"

void write_account()
{
	BankAccount bank;
	ofstream outFile;
	outFile.open("BankAccount.dat", ios::binary | ios::app);
	bank.create_account();
	outFile.write(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
	outFile.close();
}

void display_sp(int n)
{
	BankAccount bank;
	bool flag = false;
	ifstream inFile;
	inFile.open("BankAccount.dat", ios::binary);
	if (!inFile)
	{
		cout << "File doesnot exist !! Press any Key...";
		return;
	}
	cout << "\n\t BALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount)))
	{
		if (bank.returnacno() == n)
		{
			bank.display();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\ttAccount number does not exist";
}

void modify_acc(int n)
{
	bool found = false;
	BankAccount bank;
	fstream File;
	File.open("BankAccount.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
		if (bank.returnacno() == n)
		{
			bank.display();
			cout << "\n\n\tEnter The New Details of account" << endl;
			bank.modify_account();
			int pos = (-1) * static_cast<int>(sizeof(BankAccount));
			File.seekp(pos, ios::cur); // fncallat1353
			File.write(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
			cout << "\n\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\t Record Not Found ! ";
}

void delete_account(int n)
{
	BankAccount bank;
	ifstream inFile;
	ofstream outFile;
	inFile.open("BankAccount.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount)))
	{
		if (bank.returnacno() != n)
		{
			outFile.write(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
		}
	}
	inFile.close();
	outFile.close();
	remove("BankAccount.dat");
	rename("Temp.dat", "BankAccount.dat");
	cout << "\n Bank Record Deleted ..";
}

void display_all()
{
	system("CLS");
	BankAccount bank;
	ifstream inFile;
	inFile.open("BankAccount.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	else
	{

		cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
		cout << "==================================================================================\n";
		cout << "A/c no.      NAME            Pincode         Type        Branch          Balance\n";
		cout << "==================================================================================\n";
		while (inFile.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount)))
		{
			bank.report();
		}
	}
	inFile.close();
}

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	BankAccount bank;
	fstream File;
	File.open("BankAccount.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press random Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
		if (bank.returnacno() == n)
		{
			bank.display();
			if (option == 1)
			{
				bank.deposit();
			}
			if (option == 2)
			{
				bank.withdraw();
			}
			int pos = (-1) * static_cast<int>(sizeof(bank));
			File.seekp(pos, ios::cur); // fn1353
			File.write(reinterpret_cast<char *>(&bank), sizeof(BankAccount));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\tRecord Not Found ";
}


int main()
{
	// BankAccount bank;
	int num;
	char rep, x;
	cout << "--------------------------------------------" << endl;
	cout << "-----------BANK MANAGEMENT SYSTEM-----------" << endl;
	cout << "--------------------------------------------" << endl;
	do
	{

		cout << "\n\t 1. Open Account\n";
		cout << "\t 2. Deposit Amount\n";
		cout << "\t 3. Withdraw Amount\n";
		cout << "\t 4. Display Account\n";
		cout << "\t 5. All Account Holders' list \n";
		cout << "\t 6. Close Account \n";
		cout << "\t 7. Modify Account\n";
		cout << "\t 8. Exit \n";
		cout << "\n\t Choose an option....\n";
		cin >> rep;
		switch (rep)
		{
		case '1':
			system("CLS");
			cout << "\n\nChosen option - 1 :: Open Account \n";
			write_account();
			break;

		case '2':
			system("CLS");
			cout << "\n\nChosen option - 2 :: Deposit Ammount \n";
			cout << "Enter account number : ";
			cin >> num;
			deposit_withdraw(num, 1);
			break;

		case '3':
			system("CLS");
			cout << "\n\nChosen option - 3:: Withdraw Amount \n";
			cout << "Enter account number : ";
			cin >> num;
			deposit_withdraw(num, 2);
			break;

		case '4':
			system("CLS");
			cout << "\n\nChosen option - 4:: Display Amount \n";
			cout << "Enter account number : ";
			cin >> num;
			display_sp(num);
			break;

		case '5':
			system("CLS");
			cout << "\n\nChosen option - 5 :: Display all Account Holders' list \n";
			display_all();
			break;

		case '6':
			system("CLS");
			cout << "\n\nChosen option - 6 :: Close Account \n";
			cout << "Enter account number : ";
			cin >> num;
			delete_account(num);
			break;

		case '7':
			system("CLS");
			cout << "\n\nChosen option - 7 :: Modify Account \n";
			cout << "Enter The account No. : ";
			cin >> num;
			modify_acc(num);
			break;

		case '8':
			system("CLS");
			cout << "\n\n System Exit...\n\n";
			break;

		default:
			cout << "\n Please select a legitimate option and try again.\n";
		}
	} while (rep != '8');

	return 0;
}