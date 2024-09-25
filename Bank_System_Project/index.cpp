#include <iostream>
#include <vector>
#include "Validation.h"
#include "Person.h"
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "DataSourseInterface.h"
#include "FileManager.h"
#include "Parser.h"

using namespace std;

int main()
{
	Client c , x( "1234568" , "vvvvv" , 1500);
	c.setBalance(5000);
	c.setname("reham");
	c.setpassword("123456789");
	
	c.deposit(500);
	c.checkbalance();
	cout << "\n------------------------------\n";
	c.withdraw(500);
	cout << "\n------------------------------\n";
	c.transfer(x , 500);
	cout << "\n------------------------------\n";
	x.checkbalance();
	cout << "\n------------------------------\n";
	c.dispaly();

	cout << "\n\n=================================\n\n";

	Employee e;
	Client* p = &c;
	vector<Client*> ptr;
	ptr.push_back(p);
	vector<Employee*> po;
	

	e.setname("yasmin");
	e.setpassword("12345678");
	e.setsalary(10000);
	e.setClients(ptr);

	Employee* pp = &e;
	po.push_back(pp);
	cout << "all clients  1\n";
	e.listallclients();
	cout << "\n------------------------------\n";
	p = &x;
	e.addclient(x);
	cout << "all clients   2\n";
	e.listallclients();
	cout << "\n------------------------------\n";

	e.editClientInfo(555, "ahmed", "1234567", 50000 );
	cout << "client after editing\n";
	c.dispaly();
	cout << "\n------------------------------\n";
	cout << "all clients   3\n";
	 e.listallclients();
	cout << "\n------------------------------\n";
	e.searchClientById(x.getid());
	cout << "\n------------------------------\n";
	e.dispaly();

	cout << "\n\n=================================\n\n";

	Employee ex("12345678", "taliaa", 20000, ptr);
	// pp = &ex;

	Admin a;

	a.setname("rehaam");
	a.setpassword("12345678");
	a.setsalary(50000);
	a.setClients(ptr);
	a.setEmployees(po);

	//a.addclient(p);
	a.listallclients();
	cout << "\n\n=================================\n\n";

	a.addNewEmployee(ex);
	a.listAllEmployees();
	cout << "\n\n=================================\n\n";

	a.editEmployee(777, "aliaaaa", "4569871" , 5000);
	a.searchForEmployee(ex.getid());


	Admin ad("12345678", "omaaaaar", 20000, ptr , po);
	ad.dispaly();
	ad.login("12389564", ad.getid());

	//FileManager::saveAllClients();
	
}


