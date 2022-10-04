/*
 * company.cpp
 *
 *  Created on: Sep 8, 2022
 *      Author: aseel
 */
#include "../headers/company.h"
#include "../headers/hash.h"
#include <thread>
#include <algorithm>
#include <set>
using namespace std;

 Company * Company::compObject;
 vector<Employee> Company::allEmpsOfDepartments  = {};//ALL EMPS FILLED BY A FUNCTION IN COMPANY
 vector<Employee> Company::EmpsOfAllCompany = {};
 set<string> Company::ChildsOfDeps={};
 vector<Employee> Company::listOfFloatingEmps={};
 vector<Employee> Company::empsOfMultiDeps_Results={};
Company::Company(){
	this->CeoEmp=new Employee("Tareq",35,CEO,50000);
	 EmpsOfAllCompany.push_back(*CeoEmp);
     cout<<"company created successfully!"<<endl;
}

Employee Company::getCeoEmp(){
     return *CeoEmp;
}
void Company::setCeoEmp(Employee CeoEmp){
     this->CeoEmp=&CeoEmp;
     EmpsOfAllCompany[0]=CeoEmp;

}
void Company::setMainDeps(vector<Department> MainDeps){
     this->MainDeps=MainDeps;
}
vector<Department> *Company::getMainDeps(){
     return &MainDeps;
}
void Company::addMainDepToCompany(Department dep){
	if(find(getMainDeps()->begin(),getMainDeps()->end(), dep) == getMainDeps()->end()){
		MainDeps.push_back(dep);
		cout<<"Main-Department "<<dep.getDepName()<<" has added successfully!"<<endl;
	}else{
		cout<<dep.getDepName()<<" is already a main department !"<<endl;
	}
}

void Company::removeMainDepFromCompany(Department dep){
	auto i=find(getMainDeps()->begin(),getMainDeps()->end(), dep);
	if(i != this->getMainDeps()->end()){
		  MainDeps.erase(i);
          cout<<"department has bee deleted successfully"<<endl;
	 }else{
		 cout<<"Department with  "<<dep.getDepName()<<"  dose not exists in company"<<endl;
	     return;
	 }
}
void allEmpsFun(Department dep,Company *obj ){
     obj->allEmpsOfDepartments.insert(obj->allEmpsOfDepartments.end(), dep.getEmpsOfDep()->begin(),dep.getEmpsOfDep()->end() );//stops here
    if(dep.isAnySubDeps()==1){
    	for(auto f=dep.getSubDeps()->begin();f!=dep.getSubDeps()->end();f++){
         allEmpsFun((*f),obj);
    	}
    }
    else{
       return ;
    }
}
vector<Employee> Company::allEmployees(){
	if(!(this->allEmpsOfDepartments.empty())){
		allEmpsOfDepartments.clear();
	}
    int size=(int) MainDeps.size();
    for(int i=0;i<size;i++){
    	 thread th(allEmpsFun,MainDeps.at(i),this);
    	 th.join();
    }
    return this->allEmpsOfDepartments;
}

void Company::empsWithSameSalary(){
	if(EmpsOfAllCompany.size()!=0){
		   Hash hashForEmpsWithSameSalary(EmpsOfAllCompany.size());
		   for(auto i=EmpsOfAllCompany.begin();i!=EmpsOfAllCompany.end();i++){
			   hashForEmpsWithSameSalary.insertItem((*i));
		   }
		   hashForEmpsWithSameSalary.displayEmployeesWithSameSalary();
		   return;
	}else{
		cout<<"Company has NO employees "<<endl;
		return;
	}
}

void Company::addEmpToCompany(Employee emp){//employees who are in company but not in department
	auto i=find(this->EmpsOfAllCompany.begin(), this->EmpsOfAllCompany.end(), emp);
	if(i != this->EmpsOfAllCompany.end()){
		cout<<"employee already exists in Company"<<endl;
		return;
	}else{
		this->EmpsOfAllCompany.push_back(emp);
		cout<<"Employee added successfully to the Company!"<<endl;
		return;
	}
}
void Company::removeEmpFromCompany(Employee emp){//employees who are in company but not in department
	auto i=find(this->EmpsOfAllCompany.begin(), this->EmpsOfAllCompany.end(), emp);
	if(i != this->EmpsOfAllCompany.end()){
		this->EmpsOfAllCompany.erase(i);
	}
	else{
		cout<<"employee with empID number: "<<emp.getEmpId()<<" is not part of the company"<<endl;
	}
}
vector<Employee> Company::empsOfMultiDeps(){
	vector<Employee>  EmpsOfDeps=allEmployees();
	 empsOfMultiDeps_Results={};
	set<int> SetOfEmps;
	for(auto i=EmpsOfDeps.begin();i!=EmpsOfDeps.end();i++){
		if(SetOfEmps.find((*i).getEmpId())==SetOfEmps.end()){
			SetOfEmps.insert((*i).getEmpId());
		}else{
			empsOfMultiDeps_Results.push_back((*i));
		}
	}
	cout<<"Employees of multi-Departments : "<<endl;;
	for(auto i=empsOfMultiDeps_Results.begin();i!=empsOfMultiDeps_Results.end();i++){
		cout<<"Employee name & ID : "<<	i->getName()<<"  |  "<<i->getEmpId()<<endl;;
	}
	return empsOfMultiDeps_Results;
}//using sets or hash or maps
bool Company::loop_IN_Deps(){
	if(ChildsOfDeps.empty()==0){
		ChildsOfDeps.clear();
	}
	bool result;
	for(auto it1=this->getMainDeps()->begin();it1!=this->getMainDeps()->end();it1++){
		for(auto it2=(*it1).getSubDeps()->begin();it2!=(*it1).getSubDeps()->end();it2++){//children of main deps
			if(ChildsOfDeps.find((*it2).getDepName())==ChildsOfDeps.end()){
				ChildsOfDeps.insert((*it2).getDepName());
			}else{
				return true;
			}
			if((*it2).isAnySubDeps()==1){
				result=loop_IN_Deps_hand((*it2));
				if(result==1){
					return true;
				}
			}

		}
	}
	return false;
}
bool Company::loop_IN_Deps_hand(Department 	ParentDep){
	bool result;
	for(auto it1=ParentDep.getSubDeps()->begin();it1!=ParentDep.getSubDeps()->end();it1++){
		if(ChildsOfDeps.find((*it1).getDepName())==ChildsOfDeps.end()){
				ChildsOfDeps.insert((*it1).getDepName());
		}else{
			return true;//child already exists
		}
		if((*it1).isAnySubDeps()==1){
			result=loop_IN_Deps_hand((*it1));
			if(result==1){
				return true;
			}
		}
	}
	return false;
}
bool Company::floatingEmps(){
	 listOfFloatingEmps={};
	vector<Employee> AllEmpsOfDeps=allEmployees();
	for(auto i=EmpsOfAllCompany.begin(); i!=EmpsOfAllCompany.end();i++){
		if(find(AllEmpsOfDeps.begin(),AllEmpsOfDeps.end(),(*i))==AllEmpsOfDeps.end()){
			if((*i).getRole(this)!="CEO"){
				listOfFloatingEmps.push_back((*i));
			}
		}
	}
	if(!listOfFloatingEmps.empty()){
		cout<<"-----------------------------------------------------------------------"<<endl;
		cout<<"Floating employees in company are: "<<endl;
		for(auto i=listOfFloatingEmps.begin();i!=listOfFloatingEmps.end();i++){
			cout<<"Employee name : "<<(*i).getName()<<"  |  Employee ID : "<<(*i).getEmpId()<<endl;
		}
		cout<<"-----------------------------------------------------------------------"<<endl;
		return true;
	}
	cout<<"Company doesn't have any floating employees "<<endl;
	return false;
}
Company::~Company(){
	cout<<"Company has deleted successfully, in Company destructor"<<endl;
}




