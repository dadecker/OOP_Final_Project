/*
David Decker
COP 3331.001
Semester Project
*/

//Person base class
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <iostream>
#define MAX 50		
class Course
{	
	private:
		std::string courseName;
		std::string courseName2;
		std::string courseName3;

		
		
	public:
		Course();
		void setCourseName(std::string course);
		void setCourseName2(std::string course);
		void setCourseName3(std::string course);
		std::string getCourseName();
		std::string getCourseName2();
		std::string getCourseName3();
		~Course();

		
};	

#endif
