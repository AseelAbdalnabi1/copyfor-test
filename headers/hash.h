#include "Company.h"
#include <list>
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

class Hash
{
private:
 int BUCKET;
 list<Employee> *table;
public:
 Hash(int BUCKET);
 void insertItem(Employee Emp);
 int hashFunction(int x);
 void displayEmployeesWithSameSalary();
};
