#include "../headers/hash.h"
class Employee;

Hash::Hash(int BUCKET)
{
 this->BUCKET = BUCKET;
 table = new list<Employee>[this->BUCKET];
}

void Hash::insertItem(Employee Emp)
{
 int index = hashFunction(Emp.getSalary());
 table[index].push_back(Emp);
}
int Hash::hashFunction(int empSalary){
	return (empSalary%BUCKET);
}
void Hash::displayEmployeesWithSameSalary() {
	cout<<"number of buckets : "<<BUCKET<<endl;
	for(auto it=Company::EmpsOfAllCompany.begin();it!=Company::EmpsOfAllCompany.end();it++){
		cout<<"Employee name & Salary : "<<(*it).getName()<<" | "<<(*it).getSalary()<<endl;
		cout<<"-----------------------------------------------"<<endl;
	}
	for (int i = 0; i < BUCKET; i++) {
	//cout<<i<<endl;

		if(table[i].size()>1){
			cout<<"Employees with around same salary  are:-"<<endl;
			for(auto j=table[i].begin();j!=table[i].end();j++)
			{
				cout<<"Employee name & ID : "<<(*j).getName()<<" | "<<(*j).getEmpId()<<endl;
			}
		cout<<"-------------------------------------------------"<<endl;
		}
	}
}






