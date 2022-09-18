/*
 * department.h
 *
 *  Created on: Sep 8, 2022
 *      Author: aseel
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include "stdbool.h"
#include "employee.h"
#include "company.h"
#include <vector>
class Employee;
class Company;
class Department{
private:
	std::string DepName;
	int DepNum;//id
	std::vector<Department> SubDeps={};
	std::vector<Employee> EmpsOfDep={};
public:
	Department(std::string DepName,int DepNum,Company *compObj);
	Department(std::string DepName,int DepNum,std::vector<Department> SubDeps,std::vector<Employee> EmpsOfDep,Company *compObj);
	std::vector <Employee> getEmpsOfDep();
	std::vector <Employee> getEmpsOfDep(Company *compObj);
	void setEmpsOfDep(std::vector <Employee> EmpsOfDep);
	void setEmpsOfDep(std::vector <Employee> EmpsOfDep,Company *compObj);
	bool isAnySubDeps();
	std::vector<Department> getSubDeps();
	std::vector<Department> getSubDeps(Company *compObj);
	void setSubDeps(std::vector<Department> SubDeps);
	void setSubDeps(std::vector<Department> SubDeps,Company *compObj);

	int getDepNum();
	int getDepNum(Company *compObj);
	void setDepNum(int DepNum);
	void setDepNum(int DepNum,Company *compObj);
	std::string getDepName();
	std::string getDepName(Company *compObj);
    void setDepName(std::string DepName);
    void setDepName(std::string DepName,Company *compObj);
    void removeEmpFromDep(Employee emp);
    void removeEmpFromDep(Employee emp,Company *compObject);
    void addEmpToDep(Employee emp);
    void addEmpToDep(Employee emp,Company *compObject);
    //void addEmpToDep(Employee emp,Company *compObject, std::vector<Department>::iterator i);
    void RemoveSubDep(Department department);
    void RemoveSubDep(Department department,Company *compObj);
	void addSubDep(Department department);
	void addSubDep(Department department,Company *compObj);
	bool operator == (int const &DepNum);
	bool operator == (Department depObj);
	~Department();
};


#endif /* DEPARTMENT_H_ */
