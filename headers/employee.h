/*
 * employee.h
 *
 *  Created on: Sep 8, 2022
 *      Author: aseel
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include "person.h"
#include "company.h"
class Person;
class Company;
enum ROLE {CEO, MANAGER, TEAM_LEAD, DEVELOPER, TESTER, HR,NO_ROLE};
class Employee : public Person{
private:
	ROLE Role;
	int Salary;
	static int ID;
	int empID;
	void setEmpId(int empID);
public:
	//Employee();
	Employee(std::string Name,float Age ,ROLE Role,int Salary);
	std::string getName();
	void setName(std::string Name);
	void setName(std::string Name,Company *compObj);
	float getAge();
	void setAge(float Age);
	void setAge(float Age,Company *compObj);
	float getAge(Company *compObj);
	std::string getName(Company *compObj);
	void setRole(ROLE Role);
	void setRole(ROLE Role,Company *compObj);
	ROLE getRole();
	ROLE getRole(Company *compObj);
	void setSalary(int salary);
	void setSalary(int salary,Company *compObj);
	int getSalary();
	int getSalary(Company *compObj);
	int getEmpId();
	//int getEmpId(Company *compObj);
	bool operator == (Employee Emp);
	bool operator == (int const &empID);
	~Employee();

};



#endif /* EMPLOYEE_H_ */

