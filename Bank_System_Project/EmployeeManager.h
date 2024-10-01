#pragma once
#include <iostream>
#include "Employee.h"
#include "Client.h"

using namespace std;

class EmployeeManager
{
public:
	static void PrintEmployeeMenu() {
		cout << "1-Log in \n";
		cout << "2-Add new client \n";
		cout << "3-Search for client \n";
		cout << "4-List all clients \n";
		cout << "5-Edit client's info \n";
		cout << "6-Display my info \n";
	}

	static void newClient(Employee* employee) {
		string password, name;
		double balance;
		cout << "enter client's name : ";
		cin >> name;
		cout << "\n enter password : ";
		cin >> password;
		cout << "\n enter balance : ";
		cin >> balance;

		Client c (string password , string name , double balance);
		
		employee->addclient(c);
	}

	static void listAllClients(Employee* employee) {
		employee->listallclients();
	}

	static void searchForClient(Employee* employee) {
		int id;
		cout << "enter client's id : ";
		cin >> id;
		employee->searchClientById(id);
	}

	static void editClientInfo(Employee* employee) {
		int id;
		string name, password;
		double balance;
		cout << "enter the client's id you want to edit : ";
		cin >> id;
		cout << "\n now enter the new name : ";
		cin >> name;
		cout << "\n new password is : ";
		cin >> password;
		cout << "\n new balance : ";
		cin >> balance;
		employee->editClientInfo(id, name, password, balance);
	}

	static Employee* login(int id, string password) {
		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			if (Employee::allEmployees.at(i)->getid() == id) {
				if (Employee::allEmployees.at(i)->getpassword() == password)
					return Employee::allEmployees.at(i);
				else {
					cout << "Incorrect password\n";
					return nullptr;
				}
			}
			else {
				cout << "This ID is not valid\n";
				return nullptr;
			}
				
		}
	}

	static bool employeeOptions(Client* client) {
		PrintEmployeeMenu();
		int choice;
		cout << "insert the operation number you need to proceed : ";
		cin >> choice;
		switch (choice)
		{
		
		}
	}
};

