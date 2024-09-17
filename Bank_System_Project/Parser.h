#pragma once
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Parser
{
public:
	static  vector<string> split(string line) {
		vector<string> tokens = {};
		stringstream ss(line);
		string token;
		while (getline(ss, token, '&')) {
			tokens.push_back(token);
		}
		return tokens;
	}

	static Client *parseClient(string line) {
		vector<string> tokens = split(line);
		Client* c = new Client();
		
		c->setid(stoi(tokens.at(0)));
		c->setname(tokens.at(1));
		c->setpassword(tokens.at(2));
		c->setBalance(stod(tokens.at(3)));

		return c;
	}

	static Employee* parseEmployee(string line) {
		vector<string> tokens = split(line);
		Employee *e = new Employee();

		e->setid(stoi(tokens.at(0)));
		e->setname(tokens.at(1));
		e->setpassword(tokens.at(2));
		e->setsalary(stod(tokens.at(3)));

		return e;
	}

	static Admin* parseAdmin(string line) {
		vector<string> tokens = split(line);
		Admin* a = new Admin();

		a->setid(stoi(tokens.at(0)));
		a->setname(tokens.at(1));
		a->setpassword(tokens.at(2));
		a->setsalary(stod(tokens.at(3)));

		return a;
	}
};

