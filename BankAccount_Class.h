class BankAccount
{
public:
	char name[200];
	char addrs[200], ans, branch[20];
	int balance, acc_no, pincode;

	void create_account()
	{
		system("CLS");
		cout << "\nEnter account number :\t";
		cin >> acc_no;
		cout << "\n Enter full name of applicant:\t";
		cin.ignore();
		cin.getline(name, 200);
		cout << "\n Enter residential addresss of applicant:\n";
		cin.ignore();
		cin.getline(addrs, 200);
		cout << "\n Enter pincode: \t";
		cin >> pincode;
		cout << "\n Enter Branch name : \t";
		cin.ignore();
		cin.getline(branch, 20);

		cout << "\n Enter account type: Savings (S) or Current (C) :";
		cin >> ans;
		// if (ans != 'S' || ans != 'C' || ans != 's' || ans != 'c')
		// {
		// 	cout << "invalid input" << endl;
		// 	 break;
		// }
		// else
		// {
		// 	continue;
		// }
		ans = toupper(ans);
		cout << "\n Enter starting deposit :";
		cin >> balance;
		cout << "\n Congratulations! Your account has been created....\n";
	}

	void deposit()
	{
		int amount;
		cout << "\n Enter amount to be deposited :";
		cin >> amount;

		balance += amount;
		cout << "\n Current Account balance is : Rs." << balance << endl;
	}

	void withdraw()
	{
		double w_amt;
		cout << "\n Amount withdrawl process....\n";
		cout << "Enter amount to be withdrawn : ";
		cin >> w_amt;
		if (balance - w_amt < 0)
			cout << "\n INSUFFICIENT BALANCE!!! \n";
		else
			balance -= w_amt;
		cout << "\n Updated account balance : Rs." << balance << endl;
	}

	void modify_account()
	{
		cout << "\n Account Number : " << acc_no;
		cout << "\n Modify Account Holders' name : ";
		cin.ignore();
		cin.getline(name, 200);
		cout << "\n Modify account type :";
		cin >> ans;
		ans = toupper(ans);
		cout << "\n Modify branch :";
		cin >> branch;

		cout << "\n Modify account balance :";
		cin >> balance;
	}

	void display()
	{
		cout << "\n Account Number :" << acc_no;
		cout << "\n Account holders Name:" << name;
		cout << "\n Residential Address of Account Holder: \n"<< addrs;
		cout << "\n Pincode : " << pincode;
		cout << "\n Branch Name : " << branch;
		cout << "\n Account Type : " << ans;
		cout << "\n Total Account Balance : Rs." << balance;
	}

	int returnacno() const{
		return acc_no;
	}
	void report() const{
        cout << acc_no << "        " << name << "          " << pincode << "       " << ans << "       " << branch << "            " << balance << endl;
	}
};
