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
 vector<Department>  Company::DepsOfAllCompany={};
 std::set<std::string> Company::ChildsOfDeps={};
Company::Company(){
	this->CeoEmp=new Employee("Tareq",35,CEO,50000);
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
     //if(find(EmpsOfAllCompany.begin(),EmpsOfAllCompany.end(),)){
     EmpsOfAllCompany[0]=CeoEmp;

}
void Company::setMainDeps(vector<Department> MainDeps){
     this->MainDeps=MainDeps;
     DepsOfAllCompany.insert(DepsOfAllCompany.end(), MainDeps.begin(),MainDeps.end() );
}
vector<Department> *Company::getMainDeps(){
     return &MainDeps;
}
void Company::addMainDepToCompany(Department dep){
		cout<<"in addMainDep "<<endl;
cout<<dep.getDepName()<<endl;
cout<<"size in addMainDepToCompany:"<<this->getMainDeps()->size()<<endl;
 if(find(getMainDeps()->begin(),getMainDeps()->end(), dep) == getMainDeps()->end()){
	 cout<<"in addMainDep after find"<<endl;
	MainDeps.push_back(dep);
	cout<<"in addMainDep after push maindep "<<endl;
 }
/* if(find(this->DepsOfAllCompany.begin(),this->DepsOfAllCompany.end(), dep) == this->DepsOfAllCompany.end()){

	 DepsOfAllCompany.push_back(dep);
 }*/
 }

void Company::removeMainDepFromCompany(Department dep){
	auto i=find(getMainDeps()->begin(),getMainDeps()->end(), dep);

	 if(i != this->getMainDeps()->end()){
		  MainDeps.erase(i);
          cout<<"department has bee deleted successfully"<<endl;
//		  auto i=find(this->DepsOfAllCompany.begin(),this->DepsOfAllCompany.end(), dep);
//		  	 if(i != this->DepsOfAllCompany.end()){
//		  		this->DepsOfAllCompany.erase(i);
//		  		cout<<"Department "<<dep.getDepName()<<" removed successfully from company"<<endl;
//		  	    return;
//		  		 }
	 }else{
		 cout<<"Department with  "<<dep.getDepName()<<"  dose not exists in company"<<endl;
			      return;
	 }
}
void allEmpsFun(Department dep,Company *obj ){
	//cout<<"at the beging of the allEmpsFun "<<dep.getDepName()<<endl;
	//cout << "number of emps in department: " <<dep.getEmpsOfDep()->size()<<endl;
	//vector<Employee> *depart=dep.getEmpsOfDep();
     obj->allEmpsOfDepartments.insert(obj->allEmpsOfDepartments.end(), dep.getEmpsOfDep()->begin(),dep.getEmpsOfDep()->end() );//stops here
	//std::copy (dep.getEmpsOfDep().begin(), dep.getEmpsOfDep().end(), back_inserter(obj->allEmps));
	//cout<<"***************after copy"<<endl;
	//cout<<obj->allEmpsOfDepartments.size()<<"   size of all emps inside the fun"<<endl;
   //  cout<<dep.isAnySubDeps()<<endl;
    if(dep.isAnySubDeps()==1){
    	//cout<<"yes there is subdeps"<<endl;
    	//vector<Department> SubDepart=dep.getSubDeps();
    	for(auto f=dep.getSubDeps()->begin();f!=dep.getSubDeps()->end();f++){
    	//for(auto f=SubDepart.begin();f!=SubDepart.end();f++){
         allEmpsFun((*f),obj);

    	}
    }
    else{
    	//cout<<"no there is no SubDep for this Dep"<<endl;
       return ;
    }
}
vector<Employee> Company::allEmployees(){
	//cout<<"allEmployee function called-at the begining "<<endl;
	if(!(this->allEmpsOfDepartments.empty())){
		allEmpsOfDepartments.clear();
	}
    int size=(int) MainDeps.size();
    // cout<<size<<endl;

    for(int i=0;i<size;i++){
    	 thread th(allEmpsFun,MainDeps.at(i),this);
    	 th.join();


    }
   /* cout<<"Employees of Departments : "<<endl;
    for(auto i=allEmpsOfDepartments.begin();i!=allEmpsOfDepartments.end();i++){
    	 cout<<"Employee name & Employee ID : "<<i->getName()<<"  |  "<<i->getEmpId()<<endl;

    }*/
   // cout<<"allEmployee function called-at the end "<<endl;
    return this->allEmpsOfDepartments;
}//using threads

void Company::empsWithSameSalary(){
	cout<<EmpsOfAllCompany.size()<<endl;
	if(EmpsOfAllCompany.size()!=0){
		cout<<"inside if"<<endl;
		   Hash hashForEmpsWithSameSalary(EmpsOfAllCompany.size());
			cout<<"after hash before"<<endl;

		   for(auto i=EmpsOfAllCompany.begin();i!=EmpsOfAllCompany.end();i++){
		    hashForEmpsWithSameSalary.insertItem((*i));
		    cout<<"-------------------------------------------after insert"<<endl;
		   }
		   cout<<"before display"<<endl;
		   hashForEmpsWithSameSalary.displayEmployeesWithSameSalary();
		   cout<<"after display"<<endl;
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
		cout<<"employee with empID number: "<<emp.getEmpId()<<"is not part of the company"<<endl;
	}
}
vector<Employee> Company::empsOfMultiDeps(){
	vector<Employee>  EmpsOfDeps=allEmployees();
	vector<Employee> empsOfMultiDeps_Results={};
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
}//using sets or hash or maps
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
	vector<Employee> listOfFloatingEmps={};
	vector<Employee> AllEmpsOfDeps=allEmployees();
	for(auto i=this->EmpsOfAllCompany.begin(); i!= this->EmpsOfAllCompany.end();i++){
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
}//using sets or hash or maps
Company::~Company(){
	cout<<"Company has deleted successfully, in Company destructor"<<endl;
}




