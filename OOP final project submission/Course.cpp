/*
David Decker
COP 3331.001
Semester Project
*/

//course function definitions

#include <string>
#include <iostream>
#include <iomanip>
#include "Course.h"
#define MAX 50


using namespace std;

Course::Course()
{
	courseName = " ";
}
//the following three set functions make sure course is the approiprate length
//for formating purposes the ##### string is written as 5 spaces for output
void Course::setCourseName(string course)
{
	int length = course.length();
	if(length != 5)
	{
		cout << "Invalid Course ID. ID must be 5 digits" << endl;
		
		courseName = "Error ";
		return;
		;
		
	}
	if(course[0] == '#')	
	{
		courseName = "     ";	
	}
	else
	courseName = course;
}

void Course::setCourseName2(string course)
{
	int length = course.length();
	if(length != 5)
	{
		cout << "Invalid Course ID. ID must be 5 digits" << endl;
		
		courseName2 = "Error ";
		return;
		;
		
	}
	if(course[0] == '#')	
	{
		courseName2 = "     ";	
	}
	else
	courseName2 = course;
}

void Course::setCourseName3(string course)
{
	int length = course.length();
	if(length != 5)
	{
		cout << "Invalid Course ID. ID must be 5 digits" << endl;
		
		courseName3 = "Error ";
		return;
		;
	}
	if(course[0] == '#')	
	{
		courseName3 = "     ";	
	}
	else
		courseName3 = course;
}
// get functions return data member values
string Course::getCourseName()
{
	return courseName;
}
string Course::getCourseName2()
{
	return courseName2;
}
string Course::getCourseName3()
{
	return courseName3;
}
Course::~Course()
{
	
}



