/*
David Decker
COP 3331.001
Semester Project
*/

//class teacher definition header file

#ifndef TEACHER_H
#define TEACHER_H

#include "Department.h"
#include "Student.h"
#include <string>
#include <iostream>
//inherits all functions of Student
class Teacher : public Student
{
	private:
		std::string type;

	public:
		Teacher();
		void setType(std::string type);
		std::string getType();
		void setFromStream(char *ptr);
		void setTeacher(std::string idNumber,  std::string first,  std::string last,
						 std::string DOB,  std::string sex, std::string type, std::string depart);
		
		void print();
		void printDepartmentAndCourse();
		void printByDepartment(std::string depart);
		void printByCourse(std::string courseName);
		void printCourse();
		~Teacher();	
		
};

#endif
