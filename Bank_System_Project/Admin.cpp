#pragma once
#include "Admin.h"

int Admin::adminCounter = 22000;

Admin::Admin() : Employee() {
	adminCounter++;
	setid(adminCounter);
	this->Employees = vector<Employee*>();
}

Admin::Admin(string password, string name, double salary, vector<Client*> clients, vector<Employee*> employee) :Employee(password, name, salary, clients) {
	adminCounter++;
	setid(adminCounter);
	setEmployees(employee);
}

void Admin::setEmployees(vector<Employee*> employee) {
	this->Employees = employee;
}

vector<Employee*> Admin::getEmployees() {
	return this->Employees;
}

void Admin::addNewEmployee(Employee newemployee) {
	this->Employees.push_back(&newemployee);
}

Employee* Admin::searchForEmployee(int id) {
	for (int i = 0; i < this->Employees.size(); i++) {
		if (this->Employees.at(i)->getid() == id) {
			Employee *x = Employees.at(i);
			return x;
		}
	}
	cout << "this employee doesnt exist" << "\n";
}

void Admin::editEmployee(int id , string newname, string newpass , double newsalary) {
	for (int i = 0; i < this->Employees.size(); i++) {
		if (this->Employees.at(i)->getid() == id) {
			this->Employees.at(i)->setname(newname);
			this->Employees.at(i)->setpassword(newpass);
			this->Employees.at(i)->setsalary(newsalary);
		}
	}
	cout << "this employee doesnt exist" << "\n";
}

void Admin::listAllEmployees() {
	for (int i = 0; i < Employees.size(); i++) {
		this->Employees.at(i)->dispaly();
		cout << "\n-----------------------------\n";
	}
}

void Admin::dispaly() {
	Person::dispaly();
	cout << "Salary: " << getsalary() << endl;
	cout << "list of employees:\n";
	listAllEmployees();
}

void Admin::pushAllAdmins(Admin a) {
	Admin::allAdmins.push_back(&a);
}