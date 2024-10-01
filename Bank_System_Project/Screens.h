#pragma once
#include <iostream>
#include <string>

#include "EmployeeManager.h"

using namespace std;

class Screens
{
public:

	static void BankName() {
		cout << "Route \n";
	}

	static void Welcome() {
		cout << "Welcome to our Bank ^_^ \n";
	}

	static void LogInOptions() {
		cout << "Log in as : \n";
		cout << "1-Client \n";
		cout << "2-Employee \n";
		cout << "3-Admin \n";
	}

	static int LogInAs() {
		int choice;
		cin >> choice;
		if (choice >= 1 && choice <= 3)
			return choice;
		
		else
			return -1;
	}

	static void loginScreen(int c) {
		int id;
		string password;

		cout << "Enter your ID : ";
		cin >> id;

		cout << "Enter your password : ";
		cin >> password;

		switch (c)
		{
			case 2: {
				EmployeeManager::login(id, password);
			}
		
		}

	}


};

