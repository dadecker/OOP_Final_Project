/*
David Decker
COP 3331.001
Semester Project
*/

//class student header file

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Department.h"
#include "Course.h"




#include <string>
#include <iostream>
//inherits access to all public members of Person, Department and Course
class Student : public Person, public Department, public Course
{
	protected:
		std::string degree;
		char grade;
		bool graduate;
		bool courseReady;

		
	public:
		Student();
		std::string getDegree();
		void setDegree( std::string degreework);
		void setGrade(char letter);
		void setGraduate(bool grad);
		void setCourseReady(bool ready);
		char getGrade();
		bool getCourseReady();
		bool getGraduate();
		void setFromStream(char *ptr);
		void setStudent(std::string idNumber,  std::string first,  std::string last,
						 std::string DOB,  std::string sex, std::string degreework,  char letter, 
						 std::string depart, std::string course);
		void print();
		void printDepartmentAndCourse();
		void printByDepartment(std::string depart);
		void printByCourse(std::string courseName);
		void printCourse();
		~Student();
		
		
};

#endif
