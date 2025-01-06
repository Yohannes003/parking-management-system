#include <iostream>
#include <fstream>
using namespace std;
int nun = 0;
string minhr[5] = {};
class timee
{
	int duration;
	int payment = 30;

  public:
	void timee_hourmin_selecter()
	{
		cout << "enter 1 for hour and \nenter 2 for minutes:- ";
		int a;
		cin >> a;
		if (a == 1)
		{
			payment_setter(1);
		}
		else
		{
			payment_setter(2);
		}
	}
	void timee_setter()
	{
		cout << "how long was the car parked :-";
		cin >> duration;
		timee_hourmin_selecter();
	}
	int duration_getter()
	{
		return duration;
	}
	void payment_setter(int v)
	{
		if (v == 1)
		{
			payment = duration * 25;
			minhr[nun] = "hour";
		}
		else
		{
			payment = duration + 5;
			minhr[nun] = "minute";
		}
	}
	int payment_getter()
	{
		return payment;
	}
};
class driver_info : public timee
{
	string driver_name;
	string licence_number;

  public:
	string driver_name_getter()
	{
		return driver_name;
	}
	string licence_number_getter()
	{
		return licence_number;
	}

	void driver_info_setter()
	{
		cout << "enter driver name :-";
		getline(cin, driver_name);
		cout << "enter liscense number :-";
		getline(cin, licence_number);
		timee_setter();
	}
};
class admin_fun
{
	string admin_name[5];
	string password;

  protected:
	driver_info driv[5];

  public:
	void display_all_spaces()
	{
		ofstream fout;
		fout.open("file.txt", ios::out);
		if (nun > 0)
		{
			for (int x = 0; x < nun; x++)
			{
				fout << "parking station number " << x + 1 << "\n---- admin name : " << admin_name[x] << endl;
				fout << "---- driver name : " << driv[x].driver_name_getter() << endl;
				fout << "---- licence number : " << driv[x].licence_number_getter() << endl;
				fout << "---- time parked for : " << driv[x].duration_getter() << " " << minhr[x] << endl;
				fout << "---- money counted : " << driv[x].payment_getter() << " birr" << endl;
					cout << "parking station number " << x + 1 << "\n---- admin name : " << admin_name[x] << endl;
				cout << "---- driver name : " << driv[x].driver_name_getter() << endl;
				cout << "---- licence number : " << driv[x].licence_number_getter() << endl;
				cout << "---- time parked for : " << driv[x].duration_getter() << " " << minhr[x] << endl;
				cout << "---- money counted : " << driv[x].payment_getter() << " birr" << endl;
			}
			fout << "\n<<<< there are " << 5 - nun << " available spaces >>>>\n\n " << endl;
		fstream fin;
		fin.open("file2.txt");
		string output;
		while(getline(fin,output))
		 {
		 	cout<<output<<endl;
		 }
		}
		else
		{
			system("cls");
			cout << endl
				 << "\n\nit's empty \n\n"
				 << endl;
		}
		display_all();
	}
	void admin()
	{
		cout << "enter admin name:- ";
		cin >> admin_name[nun];
	admin:
		cout << "\nEnter Password: ";
		getline(cin, password);
		if (password == "1")
		{
			cout << "Access Granted!\n";
			driv[nun].driver_info_setter();
		}
		else
		{
			cout << "Try Again!!\n";
			system("cls");
			goto admin;
		}
	}
	void display_all()
	{
		int choose;
	choice:
		cout << "enter 1 to to see available space :- \n";
		cout << "enter 2 to get parking service :- \n";
		cout << "enter 3 to display all spaces :- \n";
		cout << "enter 4 to delete delete used spaces :- \n";
		cout << "enter 5 to exit :- \n";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			cout << "their are " << 5 - nun << " spaces available\n";
			goto choice;
		}
		case 2:
		{
			if (nun < 5)
			{
				admin();
				++nun;
				display_all();
			}
			else
			{
				cout << endl
					 << "out of space" << endl;
				goto choice;
			}
			break;
		}
		case 3:
		{
			display_all_spaces();
		}
		case 4:
		{
			if (0 < nun)
			{
				nun = 0;
				system("cls");
				cout << "\nparking station is free you can add new \n";
				goto choice;
			}
			else
			{
				system("cls");
				cout << "\n\n there is nothing to delete  here\n\n\n";
				goto choice;
			}
		}
		case 5:
		{
			return;
		}
		}
	}
};
int main()
{
	admin_fun f;
	f.display_all();
}
