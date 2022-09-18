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
/*Employee::Employee(){
    cout<<"employee created successfully"<<endl;
}*/
class Company;
class Employee;
//int Employee::empID=-99999;
Employee * findEmployeeInDep(Employee emp,Company *compObj);
Employee *findEmpInSubDep(Employee emp,Department dep);
Employee::Employee(string Name,float Age ,ROLE Role,int Salary,int empID):Person(Name,Age){
	this->setRole(Role);
	this->setSalary(Salary);
	this->setEmpId(empID);
	cout<<"Employee created! with empId : "<<this->getEmpId()<<endl;
}
void Employee::setRole(ROLE Role){
	this->Role=Role;
}
void Employee::setRole(ROLE Role,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	    Emp->setRole(Role);
	    return;
	}else{
		cout<<"Employee not found in Company"<<endl;
		return;
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
		cout<<"Employee Not found in Company"<<endl;
        return 	NO_ROLE;
	}
}
void Employee::setSalary(int salary){
	this->Salary=salary;
}
void Employee::setSalary(int salary,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
	     Emp->setSalary(salary);
	     return;
	}else{
		cout<<"Employee Not found in Company"<<endl;
		return;
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
		cout<<"Employee Not found in Company"<<endl;
		return -99999;
	}
}
void Employee::setEmpId(int empID){
	this->empID=empID;
}
void Employee::setEmpId(int empID,Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
		if(!(Emp==nullptr)){
	        Emp->setEmpId(empID);
            return;
		}else{
			cout<<"Employee Not found in Company"<<endl;
		}

	/*if(find(compObj->EmpsOfAllCompany.begin(), compObj->EmpsOfAllCompany.end(), empID) != compObj->EmpsOfAllCompany.end()){
	     cout<<"empId already exists,empId must be unique"<<endl;
	     int x;
	     	while(1){
	     		x=rand();
	     		if(find(compObj->EmpsOfAllCompany.begin(), compObj->EmpsOfAllCompany.end(), empID) == compObj->EmpsOfAllCompany.end()){
	     			this->empID=x;
	     			return;
	     		}
	       }
	}
	else{
		this->empID=empID;
		return;
	}
*/

}
int Employee::getEmpId(){
    return this->empID;
}
int Employee::getEmpId(Company *compObj){
	Employee *Emp=findEmployeeInDep(*this,compObj);
	if(!(Emp==nullptr)){
		return Emp->getEmpId();

	}else{
		cout<<"Employee Not found in Company"<<endl;
	}
	return -99999;
}
bool Employee::operator == (Employee Emp){
	return (Emp.getEmpId() == this->getEmpId());
}
bool Employee::operator == (int const &empID){
	return (empID == this->getEmpId());
}
Employee::~Employee(){
		//cout<<"Employee has deleted successfully, in Employee destructor,Employee number is : "<<this->getEmpId()<<endl;
}



