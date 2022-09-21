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
	auto i=find(compObj->getMainDeps()->begin(), compObj->getMainDeps()->end(),neededDep );
	if(i != compObj->getMainDeps()->end()){
		return &(*i);
	}
	Department * RequiredDepartment=nullptr;
	for(auto j=compObj->getMainDeps()->begin();j!= compObj->getMainDeps()->end();j++){
		RequiredDepartment =findSubDepartment(neededDep,(*j));
	       if (RequiredDepartment != nullptr)//something wrong here
	       {
	    	   return RequiredDepartment;
	   	   }
	}
	cout<<"Not Found"<<endl;
	return nullptr;
}
Department * findSubDepartment(Department neededDep, Department parentDep){//for sub-department -hirarichy(find department in company)
	vector<Department>::iterator i=find(parentDep.getSubDeps()->begin(), parentDep.getSubDeps()->end(),neededDep );
    if(i != (parentDep.getSubDeps()->end())){//found in direct sub dep
    	return &(*i);
    }
    Department * RequiredDepartment=nullptr;
    for(auto i=parentDep.getSubDeps()->begin();i!=parentDep.getSubDeps()->end();i++){

    	  if((*i).isAnySubDeps()==1){
    		  RequiredDepartment  = findSubDepartment(neededDep,(*i));
    		  if(RequiredDepartment!=nullptr){
    			  return RequiredDepartment;
    		  }
    	    }

    	}


    cout<<"Not Found"<<endl;
    return nullptr;
}
Employee * findEmployeeInDep(Employee emp,Company *compObj){//for hirarichy
	Employee * RequiredEmployee=nullptr;
	for( auto i=compObj->getMainDeps()->begin();i!=compObj->getMainDeps()->end();i++){
    	auto j=find((*i).getEmpsOfDep()->begin(),(*i).getEmpsOfDep()->end(),emp);
    		if( j != (*i).getEmpsOfDep()->end()) {
      		    return &(*j);
    	}
    	else if((*i).isAnySubDeps()==1){
    		 RequiredEmployee= findEmpInSubDep(emp,(*i));
    		 if(RequiredEmployee!=nullptr){
    			 return RequiredEmployee;
    		 }

    	}

    }
    cout<<"employee not found in departments of company"<<endl;
    return nullptr;
}
Employee *findEmpInSubDep(Employee emp,Department dep){
	Employee * RequiredEmployee=nullptr;
	for(auto H=dep.getSubDeps()->begin(); H!=dep.getSubDeps()->end();H++){
		auto j=find((*H).getEmpsOfDep()->begin(),(*H).getEmpsOfDep()->end(),emp);
		if( j != (*H).getEmpsOfDep()->end()) {
		      		    return &(*j);
		    	}
		    	else if((*H).isAnySubDeps()==1){
		    		RequiredEmployee=findEmpInSubDep(emp,(*H));
		    		if(RequiredEmployee!=nullptr){
		    			return RequiredEmployee;
		    		}
		    	}
	}

	cout<<"employee not found in sub_departments of company"<<endl;
    return nullptr;
}
Employee *findEmployeeInCompany(Employee emp,Company *compObj){
	auto i=find(compObj->EmpsOfAllCompany.begin(),compObj->EmpsOfAllCompany.end(),emp);
	if(i != compObj->EmpsOfAllCompany.end()){
		cout<<"employee found in EmpsOfAllCompany"<<endl;
		return &(*i);
	}
	else{
		cout<<"employee not found in company"<<endl;
		return nullptr;
	}
}
int main() {
	cout << "started"<<endl;;
	Company *comp=comp->getCompObject();
	cout << "company created"<<endl;;
	//
	//comp->setCeoEmp(CEOemp);
	cout << "CEO created"<<endl;
//	cout<<"hello"<<endl;
	cout<<comp->getCeoEmp().getAge(comp)<<"   "<<comp->getCeoEmp().getName(comp)<<"   "<<comp->getCeoEmp().getEmpId()<<"   "<<comp->getCeoEmp().getRole(comp)<<"   "<<comp->getCeoEmp().getSalary(comp)<<endl;
	Employee CEOemp("Aseel",24,CEO,500500);
	//cout<<comp->getCeoEmp().getAge(comp)<<"   "<<comp->getCeoEmp().getName(comp)<<"   "<<comp->getCeoEmp().getEmpId()<<"   "<<comp->getCeoEmp().getRole(comp)<<"   "<<comp->getCeoEmp().getSalary(comp)<<endl;
	cout<<"*************************************************************************************"<<endl;
	comp->setCeoEmp(CEOemp);///set aseel as the CEO
	cout<<comp->getCeoEmp().getAge(comp)<<"   "<<comp->getCeoEmp().getName(comp)<<"   "<<comp->getCeoEmp().getEmpId()<<"   "<<comp->getCeoEmp().getRole(comp)<<"   "<<comp->getCeoEmp().getSalary(comp)<<endl;
		//comp->getCeoEmp().
	comp->getCeoEmp().setSalary(53120,comp);
	//comp->getCeoEmp().setRole(HR,comp);
	comp->getCeoEmp().setName("aseeooool",comp);
	CEOemp.setName("ASEEEEEOLLLL");
	cout<<CEOemp.getName()<<endl;
	CEOemp.setAge(50);
	cout<<CEOemp.getAge()<<endl;
	//comp->getCeoEmp().setEmpId(2, comp);
	cout<<"*************************************************************************************"<<endl;

	cout<<comp->getCeoEmp().getAge(comp)<<"   "<<comp->getCeoEmp().getName(comp)<<"   "<<comp->getCeoEmp().getEmpId()<<"   "<<comp->getCeoEmp().getRole(comp)<<"   "<<comp->getCeoEmp().getSalary(comp)<<endl;
	cout<<"*************************************************************************************"<<endl;
Department dep1("backend");
Department dep2("frontend");
Department dep3("HR");
Department dep4("UI/UX");
Department dep45("backend");
cout<<"*******************************------------------------------******************************************************"<<endl;
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->addMainDepToCompany(dep1);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->addMainDepToCompany(dep2);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->addMainDepToCompany(dep3);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->addMainDepToCompany(dep4);
cout<<"size : hehhe "<<comp->getMainDeps()->size()<<endl;
cout<<comp->getMainDeps()->front().getDepName()<<endl;
	//	at[0].getDepName()<<endl;

cout<<comp->getMainDeps()->size()<<endl;
cout<<"******************************"<<endl;
//cout<<comp->getMainDeps()->front().getDepName()<<endl;
vector<Department> vd=*comp->getMainDeps();
for(auto j=vd.begin();j!=vd.end();j++){
	cout<<(*j).getDepName()<<endl;
}
cout<<"******************************"<<endl;
comp->removeMainDepFromCompany(dep1);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->removeMainDepFromCompany(dep2);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->removeMainDepFromCompany(dep3);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
comp->removeMainDepFromCompany(dep4);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
cout<<"***************************************************************************************"<<endl;
cout<<"size of vd "<<vd.size()<<endl;
comp->setMainDeps(vd);
cout<<"size :"<<comp->getMainDeps()->size()<<endl;
cout<<comp->getMainDeps()->at(1).getDepName()<<endl;
//Employee(std::string Name,float Age ,ROLE Role,int Salary);
cout<<"******************************"<<endl;
Employee emp1("ahmad",21.5,HR,20123);
Employee emp2("SAMI",25.5,HR,20100);
Employee emp3("faris",30,MANAGER,50000);
Employee emp4("	MALAK",24,MANAGER,50050);
cout<<emp1.getAge()<<" "<<emp1.getEmpId()<<" "<<emp1.getName()<<" "<<emp1.getRole()<<" "<<emp1.getSalary()<<endl;
emp1.setAge(20);emp1.setName("ADAM");emp1.setRole(NO_ROLE);emp1.setSalary(54444);
cout<<emp1.getAge()<<" "<<emp1.getEmpId()<<" "<<emp1.getName()<<" "<<emp1.getRole()<<" "<<emp1.getSalary()<<endl;
cout<<"******************************"<<endl;
comp->addEmpToCompany(emp1);
comp->addEmpToCompany(emp2);
comp->addEmpToCompany(emp3);
comp->addEmpToCompany(emp4);
cout<<comp->EmpsOfAllCompany.size()<<endl;
cout<<"******************************"<<endl;
comp->removeEmpFromCompany(emp1);
comp->removeEmpFromCompany(emp2);
cout<<comp->EmpsOfAllCompany.size()<<endl;
cout<<"******************************"<<endl;
Department dep9("dep9");
Department dep8("dep8");
Department dep6("dep6");
Department dep7("dep7");
vector<Department> departs;
departs.push_back(dep6);
departs.push_back(dep7);
Department dep5("dep5");
//cout<<departs.size()<<endl;
dep5.setSubDeps(departs);
//cout<<dep5.getSubDeps().at(0).getDepNum()<<endl;
//cout<<dep5.isAnySubDeps()<<endl;
cout<<"******************************************************"<<endl;
cout<<dep5.getSubDeps()->size()<<endl;

cout<<dep5.isAnySubDeps()<<endl;
cout<<"******************************************************"<<endl;
for(auto i=dep5.getSubDeps()->begin();i!=dep5.getSubDeps()->end();i++){
	cout<<"name of dep: "<<(*i).getDepName()<<endl;
}
comp->getMainDeps()->at(0).addSubDep(dep5);
comp->getMainDeps()->at(1).addSubDep(dep8);
comp->getMainDeps()->at(2).addSubDep(dep9);
cout<<comp->getMainDeps()->at(0).isAnySubDeps()<<endl;
cout<<comp->getMainDeps()->at(1).isAnySubDeps()<<endl;
cout<<comp->getMainDeps()->at(2).isAnySubDeps()<<endl;
cout<<"*****************************************************"<<endl;
cout<<" the getSubDeps(comp) use "<<comp->getMainDeps()->at(0).getSubDeps(comp)->at(0).getSubDeps(comp)->size()<<endl;
cout<<" the getSubDeps(comp) required use "<<comp->getMainDeps()->at(0).getSubDeps(comp)->at(0).getDepName()<<endl;
cout<<comp->getMainDeps()->at(1).getDepName()<<endl;
cout<<comp->getMainDeps()->at(2).getDepName()<<endl;
cout<<comp->getMainDeps()->at(1).getSubDeps(comp)->at(0).getDepName()<<endl;
//cout<<comp->getMainDeps()->at(1).getSubDeps(comp)->at(1).getDepName()<<endl;
cout<<comp->getMainDeps()->at(2).getSubDeps(comp)->at(0).getDepName()<<endl;
//cout<<comp->getMainDeps()->at(2).getSubDeps(comp)->at(1).getDepName()<<endl;
cout<<"******************************************************"<<endl;
Department dep10("dep10");
Department dep11("dep11");
vector<Department> dept;
dept.push_back(dep10);
dept.push_back(dep11);
cout<<"******************************************************"<<endl;
//comp->getMainDeps()->at(3).addSubDep(dep9,comp);
dep4.addSubDep(dep10,comp);
cout<<comp->getMainDeps()->at(3).isAnySubDeps()<<endl;
cout<<comp->getMainDeps()->at(3).getDepName()<<endl;
cout<<"...............................................here..............................................."<<endl;
cout<<comp->getMainDeps()->at(3).getSubDeps()->size()<<endl;//1
cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->size()<<endl;//1
cout<<dep4.isAnySubDeps()<<endl;//1
cout<<dep4.getSubDeps(comp)->size()<<endl;//1
cout<<dep4.getSubDeps()->size()<<endl;//1
cout<<"******************************************************"<<endl;
dep4.RemoveSubDep(dep10, comp);
cout<<"...............................................here..............................................."<<endl;
cout<<comp->getMainDeps()->at(3).getSubDeps()->size()<<endl;//0
cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->size()<<endl;//0
cout<<dep4.isAnySubDeps()<<endl;//0
cout<<dep4.getSubDeps(comp)->size()<<endl;//0
cout<<dep4.getSubDeps()->size()<<endl;//0

cout<<"...............................................here..............................................."<<endl;



cout<<dep4.isAnySubDeps()<<endl;//0
cout<<comp->getMainDeps()->at(3).isAnySubDeps()<<endl;//0
cout<<"******************************************************"<<endl;
//dep4.setSubDeps(dept, comp);
comp->getMainDeps()->at(3).setSubDeps(dept);
cout<<dep4.isAnySubDeps()<<endl;//0
cout<<comp->getMainDeps()->at(3).isAnySubDeps()<<endl;//1
cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->size()<<endl;//2
//Employee(std::string Name,float Age ,ROLE Role,int Salary);
Employee emp10("emp10",60.0,HR,51511);
Employee emp11("emp11",60.0,MANAGER,511);
Employee emp12("emp12",60.0,HR,51511);
Employee emp13("emp13",60.0,HR,51511);
Employee emp14("emp14",60.0,HR,51511);
Employee emp15("emp15",60.0,HR,51511);
Employee emp16("emp16",60.0,HR,51511);
Employee emp17("emp17",60.0,HR,51511);
cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->at(0).getDepName()<<endl;
cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->at(1).getDepName()<<endl;
cout<<"******************************//////////////////////////////////****************************"<<endl;
//cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->at(0).getDepName()<<endl;
//cout<<comp->getMainDeps()->at(3).getSubDeps(comp)->at(1).getDepName(comp)<<endl;
cout<<findEmployeeInCompany(emp4,comp)->getName()<<endl;
//cout<<findEmployeeInCompany(emp4,comp)->getName(comp)<<endl;
cout<<"******************************//////////////////////////////////****************************"<<endl;
emp4.setName("malooka",comp);
cout<<findEmployeeInCompany(emp4,comp)->getName()<<endl;
cout<<emp4.getName()<<endl;
cout<<emp4.getName(comp)<<endl;
cout<<"******************************//////////////////////////////////****************************"<<endl;
vector<Employee> emp18;
emp18.push_back(emp10);
emp18.push_back(emp11);
comp->getMainDeps()->at(0).setEmpsOfDep(emp18);
cout<<comp->getMainDeps()->at(0).getEmpsOfDep()->size()<<endl;//2
for(auto i=comp->getMainDeps()->at(0).getEmpsOfDep()->begin();i!=comp->getMainDeps()->at(0).getEmpsOfDep()->end();i++){

	cout<<(*i).getName()<<endl;

}
cout<<"...............................................here..............................................."<<endl;


comp->getMainDeps()->at(0).removeEmpFromDep(emp10);
comp->getMainDeps()->at(0).removeEmpFromDep(emp11);
for(auto i=comp->getMainDeps()->at(0).getEmpsOfDep()->begin();i!=comp->getMainDeps()->at(0).getEmpsOfDep()->end();i++){

	cout<<(*i).getName()<<endl;

}
cout<<"...............................................here..............................................."<<endl;

dep1.addEmpToDep(emp10, comp);
dep1.addEmpToDep(emp11, comp);
//comp->getMainDeps()->at(0).addEmpToDep(emp10);
//comp->getMainDeps()->at(0).addEmpToDep(emp11);
for(auto i=comp->getMainDeps()->at(0).getEmpsOfDep()->begin();i!=comp->getMainDeps()->at(0).getEmpsOfDep()->end();i++){

	cout<<(*i).getName()<<endl;

}
cout<<"...............................................here..............................................."<<endl;

cout<<dep1.getEmpsOfDep(comp)->size()<<endl;//0
cout<<comp->getMainDeps()->at(0).getEmpsOfDep(comp)->size()<<endl;//0

cout<<"...............................................here..............................................."<<endl;
dep1.removeEmpFromDep(emp10, comp);
dep1.removeEmpFromDep(emp11, comp);
cout<<"...............................................here..............................................."<<endl;
cout<<dep1.getEmpsOfDep(comp)->size()<<endl;//0
cout<<comp->getMainDeps()->at(0).getEmpsOfDep(comp)->size()<<endl;//0
cout<<"...............................................here..............................................."<<endl;



//for(auto i=comp->getMainDeps()->at(0).getEmpsOfDep()->begin();i!=comp->getMainDeps()->at(0).getEmpsOfDep()->end();i++){
//
//	cout<<(*i).getName()<<endl;
//
//}
//cout<<comp->getMainDeps()->at(0).getEmpsOfDep().at(0).getName()<<endl;//emp10
//cout<<comp->getMainDeps()->at(0).getEmpsOfDep().at(1).getName()<<endl;//emp11

//.getDepName()<<endl;
	/*
	Company *comp=comp->getCompObject();
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
