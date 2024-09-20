#pragma once
#include <iostream>
#include<string>
#include "validation.h"
#include "Person.h"
#include "Client.h"
#include<vector>
#include "DataSourseInterface.h"
#include "FileManager.h"
#include "Parser.h"

using namespace std;

class Employee :public Person
{
private:
	static  int numberOfemployee;
	double salary;
	vector<Client*>* Clients;

public:

	Employee();

	Employee(string password, string name, double salary, vector<Client*>* clients);

	bool setClients(vector<Client*>* clients);

	vector<Client*>* getClients();

	bool setsalary(double salary);

	double getsalary();

	void addclient(Client* Client);

	Client* searchClientById(int id);

	void listallclients();

	void editClientInfo(int id, string newname, string newpass, double newbalance);

	void dispaly();

	static vector<Employee*> allEmployees;

	static void pushallemployees(Employee e);

	~Employee() {};
};