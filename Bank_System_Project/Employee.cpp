#include "Employee.h"


int Employee::numberOfemployee = 11000;


Employee::Employee() :Person(), salary(0) {
	numberOfemployee++;
	this->setid(numberOfemployee);
	this->Clients = new vector<Client*>();
	//Employee::allEmployees;
}

Employee::Employee(string password, string name, double salary, vector<Client*>* clients) :Person(password, name) {
	numberOfemployee++;
	this->setid(numberOfemployee);
	setsalary(salary);
	setClients(clients);
	/*for (int i = 0; i < Employee::allEmployees.size(); i++) {
		Employee::allEmployees.at(i)->setid(numberOfemployee);
		Employee::allEmployees.at(i)->Person::setpassword(password);
		Employee::allEmployees.at(i)->Person::setname(name);
		Employee::allEmployees.at(i)->setsalary(salary);
		Employee::allEmployees.at(i)->setClients(clients);
	}*/
}

bool Employee::setClients(vector<Client*>* clients)
{

	this->Clients = clients;
	return true;
}

vector<Client*>* Employee::getClients() {
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

void Employee::addclient(Client* Client) {
	this->Clients->push_back(Client);
}

Client* Employee::searchClientById(int id) {
	Client* x = new Client();
	for (int i = 0; i < Clients->size(); i++) {
		if (this->Clients->at(i)->getid() == id) {
			x = this->Clients->at(i);
			return x;
		}
	}
	cout << "this client doesnt exist" << "\n";
}

void Employee::listallclients() {
	for (int i = 0; i < Clients->size(); i++) {
		Clients->at(i)->dispaly();
		cout << "\n-----------------------------\n";
	}
}

void Employee::editClientInfo(int id, string newname, string newpass, double newbalance) {
	for (int i = 0; i < Clients->size(); i++) {
		if (Clients->at(i)->getid() == id) {
			Clients->at(i)->setname(newname);
			Clients->at(i)->setpassword(newpass);
			Clients->at(i)->setBalance(newbalance);
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