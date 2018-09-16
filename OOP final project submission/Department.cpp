/*
David Decker
COP 3331.001
Semester Project
*/

//class Department function defintions

#include <string>
#include <iostream>
#include "Department.h"
#include "Teacher.h"
#include "Student.h"

using namespace std;

Department::Department()
{
	department = " ";	
}	

//verifies that the department entered is valid
void Department::setDepartment(string depart)
{
	int test = depart.length();
	
	if(!(depart == "Art History" || depart == "Biology" || depart == "Computer Science" || depart == "Mechanical Engineering"))
	{
		cout << "Invalid department entered" << endl;
		depart = "Invalid";
	}
	
	department = depart;	
}
//get function returns department variable value
string Department::getDepartment()
{
	return department;
}

Department::~Department()
{
	
}
