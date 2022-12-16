/* This program is designed by Saroj kumar tharu to change the password of the computer */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <conio.h>
#include <windows.h>
using namespace std;
class sys
{
private:
	int ch, num;
	int i;
	string str, str1, str3;
	string username, password;
	char strfinal[30];

public:
	void menu();
	void user_list();
	void new_user();
	void del_user();
	void pass_change();
	void add_in_admin();
	void remove_from_admin();
	void animation(int, string);
	string banner = "art/banner.txt";
	string admin = "art/admin.txt";
	string thankyou = "art/thankyou.txt";
};
void menu();
void intial();
void art(int, int, string); // type,speed,filename
void sys::animation(int speed, string temp)
{
	int i = 0;
	while (temp[i] != NULL)
	{
		cout << temp[i];
		i++;
		Sleep(speed);
	}
}
void intial()
{
	string Developer = "art/Developer.txt";
	string welcome = "art/Art.txt";

	string thankyou = "art/thankyou.txt";

	system("color a");

	system("cls");
	art(99, 2, welcome);
	Sleep(1000);

	system("cls");
	art(1, 0, Developer);
	getch();
}

void art(int type, int speed, string name)
{
	string filename(name);

	FILE *input_file = fopen(filename.c_str(), "r");
	unsigned char character;
	while (!feof(input_file))
	{
		character = getc(input_file);

		if (type == 99)
			Sleep(speed);
		else
			Sleep(0);

		cout << character << "";
	}
	cout << endl;
	fclose(input_file);
}

int main()
{
	sys sy;
	intial();
	sy.menu();
}
void sys::user_list()
{
	str = "\n\t   <----------- LIST USER ------------>";
	animation(2, str);

	str = "\n\t   <----- Showing ----->";
	animation(2, str);
	system("net user");
}
void sys::new_user()
{
	str = "\n\t   <----------- ADD NEW USER ------------>";
	animation(2, str);
	system("net user");
	str = "\n\t\t Enter New Username ----->";
	animation(2, str);

	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str = "\n\t\t Enter Password ----->";
	animation(2, str);
	fflush(stdin);
	cout << endl;
	getline(cin, password);
	str1 = "net user";
	str = str1 + " " + "\"" + username + "\"" + " " + password + " /add ";

	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	cout << endl
		 << "\t\t " << strfinal;
	system(strfinal);

	str = "\n\t   <----------- SUCESSFULLY ADDED  ------------>";
	animation(2, str);
}
void sys::del_user()
{
	str = "\n\t   <----------- DELETE USER ------------>";
	animation(2, str);

	system("net user");
	str = "\n\t\t Enter Username ----->";
	animation(2, str);
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net user";
	str = str1 + " /delete " + "\"" + username + "\"";

	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}

	system(strfinal);

	str = "\n\t   <----------- SUCESSFULLY DELETED ";
	animation(2, str);
	str = username + "  ------------>";
	animation(2, str);
}

void sys::pass_change()
{
	str = "\n\t   <----------- WELCOME TO PASS CHANGER  ------------>";
	animation(2, str);
	system("net user");

	str = "\n\t\t Enter  Username ----->";
	animation(2, str);
	//	getline(username,cin);
	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net user";
	str = str1 + " " + "\"" + username + "\"" + " *";

	num = str.length();

	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}

	system(strfinal);
	str = "\n\t   <----------- SUCESSFULLY CHANGED PASSWORD  ------------>";
	animation(2, str);
}

void sys::add_in_admin()
{
	str = "\n\t\t\t  <-----------  WELCOME TO ADD IN ADMINITRATION  ------------>";
	animation(2, str);

	system("net user");
	str = "\n\t\t Enter  Username ----->";
	animation(2, str);

	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net localgroup administrators";
	str = str1 + " " + "\"" + username + "\"" + " /add ";

	num = str.length();
	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	//	cout<<endl<<"\t\t "<<strfinal;
	system(strfinal);
	str = "\n\t   <----------- SUCESSFULLY ADDED IN ADMINITRATION ------------>";
	animation(2, str);
}

void sys::remove_from_admin()
{
	str = "\n\t   <----------- WELCOME TO REMOVE FROM ADMIN  ------------>";
	animation(2, str);

	system("net user");

	str = "\n\t\t Enter  Username ----->";
	animation(2, str);

	fflush(stdin);
	cout << endl;
	getline(cin, username);

	str1 = "net localgroup administrators";
	str = str1 + " " + "\"" + username + "\"" + " /delete ";

	num = str.length();
	for (i = 0; i <= num; i++)
	{
		strfinal[i] = str[i];
	}
	//	cout<<endl<<"\t\t "<<strfinal;
	system(strfinal);
	str = "\n\t   <----------- SUCESSFULLY REMOVED FROM ADMIN  ------------>";
	animation(2, str);
}
void sys::menu()
{

	do
	{
		system("cls");
		art(2, 1, banner);
		str = "\n\t\t\t  <-----------  WELCOME TO MAIN MENU  ------------>";
		animation(2, str);
		cout << endl
			 << "\t\t <-------------------------------------------------------->";
		cout << endl
			 << "\t\t <---  Welcome to the main security of the computer ---> ";
		cout << endl
			 << "\t\t <---------- 1  . User List --------> ";
		cout << endl
			 << "\t\t <---------- 2  . Password Change --------> ";
		cout << endl
			 << "\t\t <---------- 3  . Delete User --------> ";
		cout << endl
			 << "\t\t <---------- 4  . Add New User --------> ";
		cout << endl
			 << "\t\t <---------- 5  . Add user in Administration --------> ";
		cout << endl
			 << "\t\t <---------- 6  . Remove user from Administration --------> ";
		cout << endl
			 << "\t\t <---------- 99 . Exit --------> ";
		cout << endl
			 << "\t\t <---------- 100. NOTE --------> ";
		cout << endl
			 << "\t\t <-------------------------------------------------------->";
		cin >> ch;

		switch (ch)
		{
		case 1: // user list

			system("cls");
			art(9, 0, banner);
			user_list();
			getch();
			break;

		case 2: // user change
			system("cls");
			art(9, 0, banner);
			pass_change();
			getch();

			break;
		case 3:
			system("cls");
			art(9, 0, banner);
			del_user();
			getch();
			break;

		case 4: // add user
			system("cls");
			art(9, 0, banner);
			new_user();
			getch();
			break;
		case 5:
			system("cls");
			art(9, 0, banner);
			add_in_admin();
			getch();
			break;
		case 6:
			system("cls");
			art(9, 0, banner);
			remove_from_admin();
			getch();
			break;
		case 99:
			system("cls");
			art(99, 1, thankyou);
			getch();
			break;
		case 100:
			system("cls");
			art(99, 2, admin);
			getch();
			break;

		default:
			str = "\n\t   <----- INVALID OPTIONS ---->";
			animation(2, str);

			break;
		}
	} while (ch != 99);
}