/*
 * employee.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: aseel
 */
#include "../headers/employee.h"
#include "../headers/company.h"
#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
class Company;
class Employee;

Employee * findEmployeeInDep(Employee emp,Company *compObj);
Employee *findEmpInSubDep(Employee emp,Department dep);
Employee *findEmployeeInCompany(Employee emp,Company *compObj);
int Employee::ID=0;
Employee::Employee(string Name,float Age ,ROLE Role,int Salary):Person(Name,Age){
	this->setRole(Role);
	this->setSalary(Salary);
	this->setEmpId(ID+=1);
	cout<<"Employee created! with empId : "<<this->getEmpId()<<endl;
}
string Employee::getName(){
	return Person::getName();
}
void Employee::setName(string Name){
	Person::setName(Name);
}
float Employee::getAge(){
	return Person::getAge();
}
void Employee::setAge(float Age){
	Person::setAge(Age);
}
void Employee::setAge(float Age,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	    Emp->Person::setAge(Age);
	    this->Person::setAge(Age);
	    return;
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			Emp->Person::setAge(Age);
			this->Person::setAge(Age);
		}else{
		    cout<<"Employee not found in Company"<<endl;
		    return;
		}
	}

}
float Employee::getAge(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
		return Emp->Person::getAge();
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			return Emp->Person::getAge();
		}else{
			cout<<"Employee not found in Company"<<endl;
	        return 	-9999;
		}
	}
}
void Employee::setName(std::string Name,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	    Emp->Person::setName(Name);
	    this->setName(Name);
	    return;
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			Emp->Person::setName(Name);
			this->setName(Name);
		}else{
		    cout<<"Employee not found in Company"<<endl;
		    return;
		}
	}
}
string Employee::getName(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
		return Emp->Person::getName();
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			return Emp->Person::getName();
		}else{
			cout<<"Employee not found in Company"<<endl;
		    return 	this->Person::getName();
		}
	}
}

void Employee::setRole(ROLE Role){
	this->Role=Role;
}
void Employee::setRole(ROLE Role,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	    Emp->setRole(Role);
	    this->setRole(Role);
	    return;
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			Emp->setRole(Role);
			this->setRole(Role);
		}else{
		    cout<<"Employee not found in Company"<<endl;
		    return;
		}
	}

}
ROLE Employee::getRole(){
		return this->Role;
}
ROLE Employee::getRole(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	    return Emp->getRole();
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			return Emp->getRole();
		}else{
			cout<<"Employee not found in Company"<<endl;
            return 	NO_ROLE;
		}
	}
}
void Employee::setSalary(int salary){
	this->Salary=salary;
}
void Employee::setSalary(int salary,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	     Emp->setSalary(salary);
	     this->setSalary(salary);
	     return;
	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			Emp->setSalary(salary);
			this->setSalary(salary);
		}else{
			cout<<"Employee Not found in Company"<<endl;
			return;
		}
	}
}
int Employee::getSalary(){
		return this->Salary;
}
int Employee::getSalary(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
        return Emp->getSalary();

	}else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			 return Emp->getSalary();
		}else{
			cout<<"Employee Not found in Company"<<endl;
			return -99999;
		}
	}
}
void Employee::setEmpId(int empID){//private function
	this->empID=empID;
}
/*void Employee::setEmpId(int empID,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
		if(!(Emp==nullptr)){
	        Emp->setEmpId(empID);
            return;
		}else{
			Emp=findEmployeeInCompany(*this,compObj);
			if(!(Emp==nullptr)){
				Emp->setEmpId(empID);
				//compObj->getCeoEmp().setEmpId(empID,compObj);
				//cout<<Emp->getEmpId()<<endl;
				//cout<<Emp->getEmpId(compObj)<<endl;
				//cout<<compObj->getCeoEmp().getEmpId(compObj)<<endl;
				cout<<"employee id has been changed to "<<empID<<endl;
				return;
			}else{
			cout<<"Employee Not found in Company"<<endl;
			return;
			}
		}
}*/

int Employee::getEmpId(){
    return this->empID;
}
/*int Employee::getEmpId(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
		return Emp->getEmpId();
	}
	else{
		Emp=findEmployeeInCompany(*this,compObj);
		if(!(Emp==nullptr)){
			return Emp->getEmpId();
		}else{
			cout<<"Employee Not found in Company"<<endl;
			return -99999;
		}
	}
}*/
bool Employee::operator == (Employee Emp){
	return (Emp.getEmpId() == this->getEmpId());
}
bool Employee::operator == (int const &empID){
	return (empID == this->getEmpId());
}
Employee::~Employee(){
		//cout<<"Employee has deleted successfully, in Employee destructor,Employee number is : "<<this->getEmpId()<<endl;
}



