#pragma once
#include "Person.h"
#include "Employee.h"
#include "DataSourseInterface.h"
#include "FileManager.h"
#include "Parser.h"

class Admin :public Employee
{
private:
	static int adminCounter;
	vector<Employee*>* Employees;
public:

	Admin();


	Admin(string password, string name, double salary, vector<Client*>* clients, vector<Employee*>* employee);


	void setEmployees(vector<Employee*>* employee);


	vector<Employee*>* getEmployees();


	void addNewEmployee(Employee* newemployee);


	Employee* searchForEmployee(int id);


	void editEmployee (int id, string newname, string newpass, double newsalary);


	void listAllEmployees();


	void dispaly();

	static vector<Admin*> allAdmins;


	static void pushAllAdmins(Admin a);


	~Admin() {};
};