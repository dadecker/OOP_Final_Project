/*
David Decker
COP 3331.001
Semester Project
*/

//class Department definition---header file

#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>
#include <iostream>
#include "Department.h"


class Department
{
	private:
		std::string department;
		
		
	
	public:
		Department();
		void setDepartment(std::string department);							
		std::string getDepartment();
		~Department();

			
};

#endif
