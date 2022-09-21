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
int Hash::hashFunction(int x){
	return (x % BUCKET);
}
void Hash::displayEmployeesWithSameSalary() {
for (int i = 0; i < BUCKET; i++) {
	cout<<"Employees with "<<table[i].front().getSalary()<<"salary are:-"<<endl;
	for(auto j=table[i].begin();j!=table[i].end();j++)
	{
	//	cout<<"Employee name & ID : "<<(*j).getName()<<" | "<<(*j).getEmpId()<<endl;
	}
	cout<<"****************************************"<<endl;

}
}






