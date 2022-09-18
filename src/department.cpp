 /*
 * department.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: aseel
 */

#include "../headers/department.h"
#include <iostream>
#include "../headers/company.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Company;
Department * findSubDepartment(Department neededDep, Department parentDep);
Department * findDepartment(Department neededDep,Company *compObj);
Department::Department(std::string DepName,int DepNum,Company *compObj ){
	this->setDepName(DepName);
	this->setDepNum(DepNum,compObj);
	cout<<"department created with DepNum"<<this->getDepNum()<<endl;
}
Department::Department(string DepName,int DepNum,vector<Department> SubDeps,vector<Employee> EmpsOfDep,Company *compObj){
    this->setDepName(DepName);
	this->setDepNum(DepNum,compObj);
	this->setSubDeps(SubDeps,compObj);
	this->setEmpsOfDep(EmpsOfDep);
	cout<<"department created with DepNum"<<this->getDepNum()<<endl;
}

vector <Employee> Department::getEmpsOfDep(){
	return this->EmpsOfDep;
}
vector <Employee> Department::getEmpsOfDep(Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		return dep->getEmpsOfDep();
	}
	else{
		cout<<"department not found in company"<<endl;
		return {};
	}

}
void Department::setEmpsOfDep(vector <Employee> EmpsOfDep){
	this->EmpsOfDep=EmpsOfDep;
}
void Department::setEmpsOfDep(vector <Employee> EmpsOfDep,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		dep->setEmpsOfDep(EmpsOfDep);
	}
	else{
		cout<<"department not found in company "<<endl;
		cout<<"Employees are not inserted in department "<<endl;
		return;
	}
}
bool Department::isAnySubDeps(){
	return getSubDeps().size()!=0;
}
vector<Department> Department::getSubDeps(){
    return this->SubDeps;
}
vector<Department> Department::getSubDeps(Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
			return dep->getSubDeps();
		}
	else{
		cout<<"department not found in company "<<endl;
		return {};
	}
}
void Department::setSubDeps(vector<Department> SubDeps){
	this->SubDeps=SubDeps;
}
void Department::setSubDeps(vector<Department> SubDeps,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
			dep->setSubDeps(SubDeps);
		}
		else{
			cout<<"department not found in company "<<endl;
			cout<<"SubDeps are not inserted in department "<<endl;
			return;
		}
}
int Department::getDepNum(){
   return this->DepNum;
}
int Department::getDepNum(Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
        return dep->getDepNum();
	}
	else{
		cout<<"department not found in company "<<endl;
		return -99999;
	}
}
void Department::setDepNum(int DepNum){
	this->DepNum=DepNum;
}
void Department::setDepNum(int DepNum,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		//int DepNumber=isDepNumValed(DepNum);
		dep->setDepNum(DepNum);
		return;
	}else{
		cout<<"Department not found in Company"<<endl;
		return;
	}
  /*if(find(compObj->getMainDeps().begin(), compObj->getMainDeps().end(), DepNum) != compObj->getMainDeps().end()){
	cout<<"department number already exists ,DepNum must be unique!"<<endl;
	int x;
	while(1){
		x=rand();
		if(find(compObj->getMainDeps().begin(), compObj->getMainDeps().end(), DepNum) == compObj->getMainDeps().end()){
			this->DepNum=x;
			return;
		}
      }
   }else{
	   this->DepNum=DepNum;
	   return;
   }*/

}


bool Department::operator == (int const &DepNum){
	return (DepNum == this->getDepNum());
}
string Department::getDepName(){
	return this->DepName;
}
string Department::getDepName(Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		return dep->getDepName();
	}else{
		cout<<"Department not found in Company"<<endl;
		return "";
	}
}

void Department::setDepName(string DepName){
	this->DepName=DepName;
}
void Department::setDepName(string DepName,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		 dep->setDepName(DepName);
		 return;
	}else{
		cout<<"Department not found in Company"<<endl;
		return;
	}
}
void Department::removeEmpFromDep(Employee emp){
	auto i=find(this->EmpsOfDep.begin(), this->EmpsOfDep.end(), emp);
		if(i != this->EmpsOfDep.end()){
			this->EmpsOfDep.erase(i);
		}else{
			cout<<"Employee with "<<emp.getEmpId()<<" removed successfully from"<<this->DepName<<endl;
			return;
		}
		cout<<"Employee with "<<emp.getEmpId()<<"dose not exists in "<<this->DepName<<endl;
	  return;




	/* for(auto i=EmpsOfDep.begin(); i !=EmpsOfDep.end() ;i++)
    {
  	  if((*i).getEmpId() == emp.getEmpId()){
  		  EmpsOfDep.erase(i);
  		  cout<<"Employee with "<<emp.getEmpId()<<" removed successfully from"<<this->DepName<<endl;
  		  return;
  	  }
    }
    cout<<"Employee with "<<emp.getEmpId()<<"dose not exists in "<<this->DepName<<endl;
    return;
    */

}
void Department::removeEmpFromDep(Employee emp,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		dep->removeEmpFromDep(emp);
		auto i=find(compObj->EmpsOfAllCompany.begin(),compObj->EmpsOfAllCompany.end(),emp);
		if(i != compObj->EmpsOfAllCompany.end()){
			compObj->EmpsOfAllCompany.erase(i);
			cout<<"employee deleted from EmpsOfAllCompany successfully"<<endl;
		}
		else{
			cout<<"employee didn't deleted from EmpsOfAllCompany successfully"<<endl;
		}
		return;
	}else{
		cout<<" Department not found in Company & Employee not removed !"<<endl;
		return;
	}
}
void Department::addEmpToDep(Employee emp){
	this->EmpsOfDep.push_back(emp);
	return;
}
void Department::addEmpToDep(Employee emp,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		dep->addEmpToDep(emp);
		compObj->EmpsOfAllCompany.push_back(emp);
		return;
	}else{
		cout<<" Department not found in Company & Employee not added !"<<endl;
		return;
	}

}
/*void Department::addEmpToDep(Employee emp,Company *compObject, vector<Department>::iterator i){
	EmpsOfDep.push_back(emp);
	compObject->EmpsOfAllCompany.push_back(emp);
	(*i).EmpsOfDep.push_back(emp);



}*/
void Department::RemoveSubDep(Department department){
     auto i=find(this->getSubDeps().begin(), this->getSubDeps().end(),department);
     if(i!=this->getSubDeps().end()){
    	 this->getSubDeps().erase(i);
   	     cout<<"Sub_department "<<department.DepName<<" removed successfully from"<<this->DepName<<endl;
   	     return;
     }else{
    	 cout<<"sub_department "<<department.DepName<<"dose not exists in "<<this->DepName<<endl;
    	 return;
     }
	/*for(auto i=this->getSubDeps().begin();i!=this->getSubDeps().end();i++)
      {
    	  if((*i).DepNum == department.DepNum){
    		  SubDeps.erase(i);
    		  cout<<"Sub_department "<<department.DepName<<" removed successfully from"<<this->DepName<<endl;
    		  return;
    	  }
      }
      cout<<"sub_department "<<department.DepName<<"dose not exists in "<<this->DepName<<endl;
      return;
*/
	}
void Department::RemoveSubDep(Department department,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
	if(!(dep==nullptr)){
		dep->RemoveSubDep(department);
		return;
	}else{
		cout<<"Parent Department not found in Company"<<endl;
		return;
	}
}
void Department::addSubDep(Department dep){
	this->getSubDeps().push_back(dep);
	cout<<"sub-department added successfully"<<endl;
}
void Department::addSubDep(Department department,Company *compObj){
	Department *dep=findDepartment(*this,compObj);
		if(!(dep==nullptr)){
			dep->addSubDep(department);
			return;
		}else{
			cout<<" Department not found in Company"<<endl;
			return;
		}

}
Department::~Department(){
	//cout<<"Department has deleted successfully, in Department destructor"<<endl;
}
bool Department::operator == (Department depObj) {
         return (depObj.getDepNum() == this->getDepNum());
    }
