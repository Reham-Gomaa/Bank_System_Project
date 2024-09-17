#pragma once

#include "DataSourseInterface.h"
#include "Parser.h"

#include <fstream>

using namespace std;

class FileManager
{
public:
	 static void addClient(Client* c) {
		fstream file("client.txt", ios::app);
		file << c->getid() << "&" << c->getname() << "&" << c->getpassword() << "&" << c->getBalance() << "\n";
		file.close();		
	}

	static void addEmployee(Employee* e) {
		fstream file("employee.txt", ios::app);
		file << e->getid() << "&" << e->getname() << "&" << e->getpassword() << "&" << e->getsalary() << "\n";
		file.close();
	}

	static void addAdmin(Admin* a) {
		fstream file("admin.txt", ios::app);
		file << a->getid() << "&" << a->getname() << "&" << a->getpassword() << "&" << a->getsalary() << "\n";
	}

	static void saveAllClients() {
		for (int i = 0; i < Client::allClients.size(); i++) {
			Client* c = Client::allClients.at(i);
			addClient(c);
		}
	}

	static void saveAllEmployees() {
		for (int i = 0; i < Employee::allEmployees.size(); i++) {
			Employee* e = Employee::allEmployees.at(i);
			addEmployee(e);
		}
	}

	static void saveAllAdmins() {
		for (int i = 0; i < Admin::allAdmins.size(); i++) {
			Admin* a = Admin::allAdmins.at(i);
			addAdmin(a);
		}
	}

	static void saveAllData() {
		saveAllClients();
		saveAllEmployees();
		saveAllAdmins();
	}

	//---------------------------------------------------------------------------------------

	static void getAllClients() {
		fstream file("client.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Client *c = Parser::parseClient(line);
			Client::allClients.push_back(c);
		}
		file.close();
	}

	static void getAllEmployees() {
		fstream file("employee.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Employee *e = Parser::parseEmployee(line);
			Employee::allEmployees.push_back(e);
		}
		file.close();
	}

	static void getAllAdmins() {
		fstream file("admin.txt", ios::in);
		string line;
		while (getline(file, line)) {
			Admin* a = Parser::parseAdmin(line);
			Admin::allAdmins.push_back(a);
		}
		file.close();
	}

	static void getAllData() {
		getAllClients();
		getAllEmployees();
		getAllAdmins();
	}

	// ----------------------------------------------------------------------------

	static void removeAllClients() {
		fstream file("client.txt",ios::out);
		file.close();
	}

	static void removeAllEmployees() {
		fstream file("employee.txt", ios::out);
		file.close();
	}

	static void removeAllAdmins() {
		fstream file("admin.txt", ios::out);
		file.close();
	}

	static void removeAllData() {
		removeAllClients();
		removeAllEmployees();
		removeAllAdmins();
	}

};

