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

	if(table[index].empty() || table[index].front().getSalary()==Emp.getSalary()){
		table[index].push_back(Emp);
		return;
	}else{
		while(table[index].front().getSalary()!=Emp.getSalary()&& (!table[index].empty()) ){
			index+=1;
		}
		table[index].push_back(Emp);
		return;
	}
 }
int Hash::hashFunction(int empSalary){
	if(empSalary%10==0)
		return empSalary%10;
	else if(empSalary%100==0)
		return empSalary%100;
	else if(empSalary%1000==0){
		return empSalary%1000;
	}else{
		return (empSalary%BUCKET);
	}
}
void Hash::displayEmployeesWithSameSalary() {
	for (int i = 0; i < BUCKET; i++) {
		if(table[i].size()>1){
			cout<<"Employees with same salary  are:-"<<endl;
			for(auto j=table[i].begin();j!=table[i].end();j++)
			{
				cout<<"Employee name , salary & ID: "<<(*j).getName()<<" | "<<	j->getSalary() <<" | "<<(*j).getEmpId()<<endl;
			}
		cout<<"-------------------------------------------------"<<endl;
		}
	}
}






