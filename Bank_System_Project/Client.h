#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include<vector>
#include "validation.h"
#include "Person.h"
#include "DataSourseInterface.h"
#include "FileManager.h"
#include "Parser.h"

using namespace std;

class Client : public Person {
private:
    static int clientCounter;
    double balance;

public:

    Client();

    Client(string password , string name, double balance);
  
    bool setBalance(double balance);
  
    double getBalance();
   
    void deposit(double amount);
   
    void withdraw(double amount);
 
    void checkbalance();
   
    void transfer(Client& otherClient, double amount);

    void dispaly();

    static vector<Client*> allClients;

    static void pushallclients(Client c);
 
    ~Client() {};
};

