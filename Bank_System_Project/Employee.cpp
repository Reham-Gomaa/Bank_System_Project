#include "Employee.h"


int Employee::numberOfemployee = 11000;


Employee::Employee() :Person(), salary(0) {
	numberOfemployee++;
	setid(numberOfemployee);
	this->Clients = vector<Client*>();
}

Employee::Employee(string password, string name, double salary, vector<Client*> clients) :Person(password, name) {
	numberOfemployee++;
	setid(numberOfemployee);
	setsalary(salary);
	setClients(clients);
}

bool Employee::setClients(vector<Client*> clients){
	this->Clients = clients;
	return true;
}

vector<Client*> Employee::getClients() {
	return this->Clients;
}

bool Employee::setsalary(double salary) {
	if (Validation::validatesalary(salary))
	{
		this->salary = salary;
		return true;
	}
	return false;
}

double Employee::getsalary() {
	return this->salary;
}

void Employee::addclient(Client Client) {
	this->Clients.push_back(&Client);
}

Client* Employee::searchClientById(int id) {
	for (int i = 0; i < this->Clients.size(); i++) {
		if (this->Clients.at(i)->getid() == id) {
			Client *x = Clients.at(i);
			return x;
		}
	}
	cout << "this client doesnt exist" << "\n";
}

void Employee::listallclients() {
	for (int i = 0; i < this->Clients.size(); i++) {
		this->Clients.at(i)->dispaly();
		cout << "\n-----------------------------\n";
	}
}

void Employee::editClientInfo(int id, string newname, string newpass, double newbalance) {
	for (int i = 0; i < Clients.size(); i++) {
		if (this->Clients.at(i)->getid() == id) {
			this->Clients.at(i)->setname(newname);
			this->Clients.at(i)->setpassword(newpass);
			this->Clients.at(i)->setBalance(newbalance);
		}
	}
	cout << "this client doesnt exist" << "\n";
}

void Employee::dispaly() {
	Person::dispaly();
	cout << "Salary: " << getsalary() << endl;
	cout << "list of clients:\n";
	listallclients();
}

void Employee::pushallemployees(Employee e) {
	Employee::allEmployees.push_back(&e);
}