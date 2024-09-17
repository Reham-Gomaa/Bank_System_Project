#pragma once
#include "Admin.h"

int Admin::adminCounter = 22000;

Admin::Admin() : Employee() {
	adminCounter++;
	setid(adminCounter);
	this->Employees = new vector<Employee*>();
	//Admin::allAdmins;
}

Admin::Admin(string password, string name, double salary, vector<Client*>* clients, vector<Employee*>* employee) :Employee(password, name, salary, clients) {
	adminCounter++;
	setid(adminCounter);
	setEmployees(employee);
	/*for (int i = 0; i < Admin::allAdmins.size(); i++) {
		Admin::allAdmins.at(i)->setid(adminCounter);
		Admin::allAdmins.at(i)->Employee::setpassword(password);
		Admin::allAdmins.at(i)->Employee::setname(name);
		Admin::allAdmins.at(i)->Employee::setsalary(salary);
		Admin::allAdmins.at(i)->setEmployees(employee);
	}*/
}

void Admin::setEmployees(vector<Employee*>* employee) {
	this->Employees = employee;
}

vector<Employee*>* Admin::getEmployees() {
	return this->Employees;
}

void Admin::addNewEmployee(Employee* newemployee) {
	this->Employees->push_back(newemployee);
}

Employee* Admin::searchForEmployee(int id) {
	Employee* x = new Employee();
	for (int i = 0; i < Employees->size(); i++) {
		if (Employees->at(i)->getid() == id) {
			x = Employees->at(i);
			return x;
		}
	}
	cout << "this employee doesnt exist" << "\n";
}

void Admin::editEmployee(int id , string newname, string newpass , double newsalary) {
	for (int i = 0; i < Employees->size(); i++) {
		if (Employees->at(i)->getid() == id) {
			Employees->at(i)->setname(newname);
			Employees->at(i)->setpassword(newpass);
			Employees->at(i)->setsalary(newsalary);
		}
	}
	cout << "this employee doesnt exist" << "\n";
}

void Admin::listAllEmployees() {
	for (int i = 0; i < Employees->size(); i++) {
		Employees->at(i)->dispaly();
		cout << "\n-----------------------------\n";
	}
}

void Admin::dispaly() {
	Person::dispaly();
	cout << "Salary: " << getsalary() << endl;
	cout << "list of employees:\n";
	listAllEmployees();
}