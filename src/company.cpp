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
using namespace std;

 Company * Company::compObject;
 vector<Employee> Company::allEmpsOfDepartments  = {};//ALL EMPS FILLED BY A FUNCTION IN COMPANY
 vector<Employee> Company::EmpsOfAllCompany = {};
 vector<Department>  Company::DepsOfAllCompany={};
Company::Company(){
	this->CeoEmp=new Employee("Tareq",35,CEO,50000,1);
    cout<<"ceo in const"<<endl;
	 EmpsOfAllCompany.push_back(*CeoEmp);
	 //MainDeps.clear();
     cout<<"company created successfully!"<<endl;
}

Employee Company::getCeoEmp(){
     return *CeoEmp;
}
void Company::setCeoEmp(Employee CeoEmp){
     this->CeoEmp=&CeoEmp;
     EmpsOfAllCompany.push_back(CeoEmp);//WRONG WE MEED TO MODIFY THE ALREADY SELECTED CEO
}
void Company::setMainDeps(vector<Department> MainDeps){
     this->MainDeps=MainDeps;
     DepsOfAllCompany.insert(DepsOfAllCompany.end(), MainDeps.begin(),MainDeps.end() );
}
vector<Department> Company::getMainDeps(){
     return this->MainDeps;
}
void Company::addMainDepToCompany(Department dep){
 if(find(this->getMainDeps().begin(),this->getMainDeps().end(), dep) == this->getMainDeps().end()){
	MainDeps.push_back(dep);
 }
 if(find(this->DepsOfAllCompany.begin(),this->DepsOfAllCompany.end(), dep) == this->DepsOfAllCompany.end()){
	 DepsOfAllCompany.push_back(dep);
 }
 }

void Company::removeMainDepFromCompany(Department dep){
	auto i=find(this->getMainDeps().begin(),this->getMainDeps().end(), dep);

	 if(i != this->getMainDeps().end()){
		  MainDeps.erase(i);

		  auto i=find(this->DepsOfAllCompany.begin(),this->DepsOfAllCompany.end(), dep);
		  	 if(i != this->DepsOfAllCompany.end()){
		  		this->DepsOfAllCompany.erase(i);
		  		cout<<"Department "<<dep.getDepName()<<" removed successfully from company"<<endl;
		  	    return;
		  		 }
	 }else{
		 cout<<"Department with"<<dep.getDepName()<<"dose not exists in company"<<endl;
			      return;
	 }
}
void allEmpsFun(Department dep,Company *obj ){
	cout<<"at the beging of the allEmpsFun "<<dep.getDepName()<<endl;
	cout << "number of emps in department: " <<dep.getEmpsOfDep().size()<<endl;
	vector<Employee> depart=dep.getEmpsOfDep();
     obj->allEmpsOfDepartments.insert(obj->allEmpsOfDepartments.end(), depart.begin(),depart.end() );//stops here
	//std::copy (dep.getEmpsOfDep().begin(), dep.getEmpsOfDep().end(), back_inserter(obj->allEmps));
	cout<<"***************after copy"<<endl;
	cout<<obj->allEmpsOfDepartments.size()<<"   size of all emps inside the fun"<<endl;
     cout<<dep.isAnySubDeps()<<endl;
    if(dep.isAnySubDeps()==1){
    	cout<<"yes there is subdeps"<<endl;
    	vector<Department> SubDepart=dep.getSubDeps();
    	//for(auto f=dep.getSubDeps().begin();f!=dep.getSubDeps().end();f++){
    	for(auto f=SubDepart.begin();f!=SubDepart.end();f++){
         allEmpsFun((*f),obj);

    	}
    }
    else{
    	cout<<"no there is no SubDep for this Dep"<<endl;
       return ;
    }
}
vector<Employee> Company::allEmployees(){
cout<<"allEmployee function called-at the begining "<<endl;
    int size=(int) MainDeps.size();
     cout<<size<<endl;

    for(int i=0;i<size;i++){
    	 thread th(allEmpsFun,MainDeps.at(i),this);
    	 th.join();


    }
    cout<<"allEmployee function called-at the end "<<endl;
    return this->allEmpsOfDepartments;
}//using threads

void Company::empsWithSameSalary(Company *compObj){
	if(compObj->EmpsOfAllCompany.size()!=0){


		   Hash hashForEmpsWithSameSalary(compObj->EmpsOfAllCompany.size());
		   for(auto i=compObj->EmpsOfAllCompany.begin();i!=compObj->allEmpsOfDepartments.end();i++){
		    hashForEmpsWithSameSalary.insertItem((*i));
		   }
		   hashForEmpsWithSameSalary.displayEmployeesWithSameSalary();
		   return;
	}else{
		cout<<"Company has NO employees "<<endl;
		return;
	}
	/*if(compObj->allEmpsOfDepartments.size()==0){
	      compObj->allEmployees();//CEO can't be in this vector
	   }
	   Hash hashForEmpsWithSameSalary(compObj->allEmpsOfDepartments.size());
	   for(auto i=compObj->allEmpsOfDepartments.begin();i!=compObj->allEmpsOfDepartments.end();i++){
	    hashForEmpsWithSameSalary.insertItem((*i));
	   }
	   hashForEmpsWithSameSalary.displayEmployeesWithSameSalary();*/


}
/*vector<Employee> Company::getEmpsOfAllCompany(){
	return this->EmpsOfAllCompany;
}*/
void Company::addEmpToCompany(Employee emp){//employees who are in company but no in department
	auto i=find(this->EmpsOfAllCompany.begin(), this->EmpsOfAllCompany.end(), emp);
		if(i != this->EmpsOfAllCompany.end()){
			cout<<"employee already exists in Company"<<endl;
			return;
		}else{
			this->EmpsOfAllCompany.push_back(emp);
			cout<<"Employee added successfully to the Company!"<<endl;
			return;
		}

	/*	for(auto i=this->getEmpsOfAllCompany().begin();i!=this->getEmpsOfAllCompany().end();i++){
		if((*i).getEmpId()==emp.getEmpId()){//needs == override
			cout<<"employee already exists in Company"<<endl;
		}
			return;
		}
		this->getEmpsOfAllCompany().push_back(emp);*/

}
void Company::removeEmpFromCompany(Employee emp){//employees who are in company but no in department
	auto i=find(this->EmpsOfAllCompany.begin(), this->EmpsOfAllCompany.end(), emp);
	if(i != this->EmpsOfAllCompany.end()){
		this->EmpsOfAllCompany.erase(i);
	}
}
/*void Company::addEmpToCompany(Employee Emp,Department Dep){
	for(auto i=this->getEmpsOfAllCompany().begin();i!=this->getEmpsOfAllCompany().end();i++){
		if((*i)==Emp){//needs == override
			cout<<"employee already exists in Company"<<endl;
			return;
		}
	}
	for(auto i=this->getMainDeps().begin();i!=this->getMainDeps().end();i++){
			if((*i)==Dep){
                Dep.addEmpToDep(Emp, this,i);//main departments
                cout<<"Employee added successfully!"<<endl;
                return;
			}

	     }

}*/
void Company::empsOfMultiDeps(){

}//using sets or hash or maps
void Company::loop_IN_Deps(){

}//using sets or hash or maps
void Company::floatingEmps(){

}//using sets or hash or maps
Company::~Company(){
	cout<<"Company has deleted successfully, in Company destructor"<<endl;
}




