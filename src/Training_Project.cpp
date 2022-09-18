//============================================================================
// Name        : Training_Project.cpp
// Author      : Aseel_Abdalnabi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "vector"
#include "../headers/company.h"
#include <thread>
#include <algorithm>
class Company;
class Employee;
class Department;
class Person;
Department * findSubDepartment(Department neededDep, Department parentDep);
Employee* findEmpInSubDep(Employee emp,Department dep);

Department * findDepartment(Department neededDep,Company *compObj){
	auto i=find(compObj->getMainDeps().begin(), compObj->getMainDeps().end(),neededDep );
	if(i != compObj->getMainDeps().end()){
		return &(*i);
	}
	else{
		for(auto j=compObj->getMainDeps().begin();j!= compObj->getMainDeps().end();j++){
		       return findSubDepartment(neededDep,(*j));
		}
	}
	cout<<"Not Found"<<endl;
	return nullptr;
}
Department * findSubDepartment(Department neededDep, Department parentDep){//for sub-department -hirarichy(find department in company)
	vector<Department>::iterator i=find(parentDep.getSubDeps().begin(), parentDep.getSubDeps().end(),neededDep );
    if(i != (parentDep.getSubDeps().end())){//found in direct sub dep
    	return &(*i);
    }else {// not found on direct sub dep--we need to search deeper
    	for(auto i=parentDep.getSubDeps().begin();i!=parentDep.getSubDeps().end();i++){

    	    if((*i).isAnySubDeps()==1){

                 return findSubDepartment(neededDep,(*i));
    	    }

    	}

    }
    cout<<"Not Found"<<endl;
    return nullptr;
}
Employee * findEmployeeInDep(Employee emp,Company *compObj){//for hirarichy
    for( auto i=compObj->getMainDeps().begin();i!=compObj->getMainDeps().end();i++){
    	auto j=find((*i).getEmpsOfDep().begin(),(*i).getEmpsOfDep().end(),emp);
    		if( j != (*i).getEmpsOfDep().end()) {
      		    return &(*j);
    	}
    	else if((*i).isAnySubDeps()==1){
    		return findEmpInSubDep(emp,(*i));

    	}

    }
    cout<<"employee not found in departments of company"<<endl;
    return nullptr;
}
Employee *findEmpInSubDep(Employee emp,Department dep){
	for(auto H=dep.getSubDeps().begin(); H!=dep.getSubDeps().end();H++){
		auto j=find((*H).getEmpsOfDep().begin(),(*H).getEmpsOfDep().end(),emp);
		if( j != (*H).getEmpsOfDep().end()) {
		      		    return &(*j);
		    	}
		    	else if((*H).isAnySubDeps()==1){
		    		return findEmpInSubDep(emp,(*H));
		    	}
	}

	cout<<"employee not found in sub_departments of company"<<endl;
    return nullptr;
}

int main() {
	cout << "started"<<endl;;
	Company *comp=comp->getCompObject();
	cout << "company created"<<endl;;
	//Employee CEOemp("Tareq",35,CEO,50000,1);
	//comp->setCeoEmp(CEOemp);
	cout << "CEO created"<<endl;
//	cout<<"hello"<<endl;
	cout<<comp->getCeoEmp().getAge()<<"   "<<comp->getCeoEmp().getName()<<"   "<<comp->getCeoEmp().getEmpId()<<"   "<<comp->getCeoEmp().getRole()<<"   "<<comp->getCeoEmp().getSalary()<<endl;
	/*Company *comp=comp->getCompObject();
	Department dep1("backend dev",1);
	cout<<dep1.getDepName()<<"  "<<dep1.getDepNum()<<endl;
	Employee emp1("aseel",24,DEVELOPER,200000.0,12);
	Employee emp2("ahmad",24,DEVELOPER,2004.0,50);
	Employee emp3("ali",25,DEVELOPER,200004.0,500);
	Employee emp4("alosh",30,DEVELOPER,50000.0,1);
	Employee emp5("nore",28,HR,5010,111);
	Department dep2("backend dev sup1",50);
	Department dep3("backend dev sup2",51);
	Department dep4("frontend dev ",2);
	Department dep5("frontend dev sup",60);


	dep1.addEmpToDep(emp1);
	dep2.addEmpToDep(emp2);
	dep3.addEmpToDep(emp3);
	dep4.addEmpToDep(emp4);
	dep5.addEmpToDep(emp5);
	dep1.addSubDep(dep2);
	dep1.addSubDep(dep3);
	dep4.addSubDep(dep5);
	cout<<dep1.isAnySubDeps()<<endl;
	cout<<dep4.isAnySubDeps()<<endl;
	comp->addDepToCompany(dep1);
	comp->addDepToCompany(dep4);
	cout<<"------------------------------------------------------------------"<<endl;
	cout<<comp->allEmps.size()<<"  before allEmployees function callig "<<endl;
	vector<Employee> ALL=comp->allEmployees();
	cout<<ALL.size()<<endl;
    //int size=(int) comp->allEmps.size();
    cout<<comp->allEmps.size()<<"  after allEmployees function callig "<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    cout<<comp->getDeps().size()<<endl;
    for(auto i=comp->getDeps().begin();i!=comp->getDeps().end();i++){
       	cout<<"  "<<(*i).getDepName()<<"  "<<(*i).getDepNum()<<endl;
       }

    for(auto i=comp->getDeps().begin();i!=comp->getDeps().end();i++){
    	int j=0;
    	cout<<"  "<<comp->getDeps().at(j).getDepName()<<"  "<<(*i).getDepNum()<<endl;
    	//cout<<j<<endl
        j++;
    	cout<<j<<endl;
    }
	cout<<emp1.getAge()<<" "<<emp1.getEmpId()<<" "<<emp1.getSalary()<<" "<<emp1.getName()<<" "<<emp1.getRole()<<endl;
	cout << "Training project" << endl; // prints Training project
	*/
	return 0;
}
// inserting into a vector
/*
#include <iostream>
#include <vector>

int main ()
{
  std::vector<Employee> myvector ;
  std::vector<Employee>::iterator it;
  Employee emp1("aseel",24,DEVELOPER,200000.0,12);
  it = myvector.begin();
  it = myvector.insert ( it , emp1 );
  cout<<myvector.size()<<endl;
  //myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  //it = myvector.begin();
  Employee emp2("ahmad",24,DEVELOPER,2004.0,50);
  Employee emp3("ali",25,DEVELOPER,200004.0,500);
  std::vector<Employee> anothervector;
  cout<<anothervector.size()<<endl;
  anothervector.insert(anothervector.begin(),emp2);
  cout<<anothervector.size()<<endl;
  anothervector.insert(anothervector.begin(),emp3);
  cout<<anothervector.size()<<endl;//2
  //myvector.insert (myvector.end(),anothervector.begin(),anothervector.end());
  cout<<myvector.size()<<endl;
  cout<<anothervector.size()<<endl;
  vector<Department> emptySubdep={};
  Department dep1("first dep",1,emptySubdep,myvector);
  Department dep2("second dep",2,emptySubdep,anothervector);
  cout<<"department 1 supDeps size: "<<dep1.getSubDeps().size()<<endl;
  cout<<"department 1 empolyees size: "<<dep1.getEmpsOfDep().size()<<endl;
  cout<<"************************************************************"<<endl;
  cout<<"department 2 supDeps size: "<<dep2.getSubDeps().size()<<endl;
    cout<<"department 2 empolyees size: "<<dep2.getEmpsOfDep().size()<<endl;
    Company *EXALT=EXALT->getCompObject();
    cout<<"Exalt deps size: (before)   "<<EXALT->getDeps().size()<<endl;
    EXALT->addDepToCompany(dep1);
    EXALT->addDepToCompany(dep2);
    cout<<"************************************************************"<<endl;
    cout<<"Exalt deps size: (after)   "<<EXALT->getDeps().size()<<endl;
    cout<<"************************************************************"<<endl;
    cout<<"Exalt emps size of first dep: (after)   "<<EXALT->getDeps().at(0).getEmpsOfDep().size()<<endl;
    cout<<"Exalt emps size of second dep: (after)   "<<EXALT->getDeps().at(1).getEmpsOfDep().size()<<endl;
    cout<<EXALT->allEmps.size()<<endl;
   // EXALT->allEmps.insert(EXALT->allEmps.end(), anothervector.begin(),anothervector.end());//,EXALT->getDeps().at(0).getEmpsOfDep().end() );
    //cout<<dep2.getEmpsOfDep().at(0).getName()<<endl;
  //  cout<<myvector.begin();
    //vector<Employee> e1=dep2.getEmpsOfDep();
    //cout<<e1.at(0).getName()<<endl;
  //  EXALT->allEmps.insert(EXALT->allEmps.end(), e1.begin(),e1.end());
    //EXALT->allEmps.insert(EXALT->allEmps.end(), dep2.getEmpsOfDep().begin(),dep2.getEmpsOfDep().end());
    cout<<"size of EXALT->allEmps : "<<EXALT->allEmps.size()<<endl;
    Employee emp4("alosh",30,DEVELOPER,50000.0,1);
    Employee emp5("nore",28,HR,5010,111);
    Department dep3("first_sub1 dep",3);
    //Department dep4("first_sub2 dep",4);
    dep3.addEmpToDep(emp4);
    dep3.addEmpToDep(emp5);
    dep1.addSubDep(dep3);
    cout<<"************************************************************"<<endl;
    cout<<"dep1.subdep.size: "<<dep1.getSubDeps().size()<<endl;
    cout<<"dep1.subdep.emps.size: "<<dep1.getSubDeps().at(0).getEmpsOfDep().size()<<endl;
    cout<<"************************************************************  according to EXALT **************************************"<<endl;
    EXALT->getDeps().at(0).addSubDep(dep3);
    cout<<EXALT->getDeps().at(0).getSubDeps().at(0).getDepName()<<endl;
    //cout<<EXALT->getDeps().at(1).isAnySubDeps()<<endl;
   // EXALT->allEmployees();

    return 0;
}*/
