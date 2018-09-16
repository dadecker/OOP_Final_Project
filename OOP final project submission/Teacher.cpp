/*
David Decker
COP 3331.001
Semester Project
*/

//class Teacher function definitions
#include "Teacher.h"
#include "Department.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

Teacher::Teacher()
:Student()
{
	type = " ";
}
//sets the type of teacher only to the specific strings. Also makes sure that a teaching assistant is
//a graduate student. sets value of bool courseReady ehich can be used to determine if the person can teach a course
void Teacher::setType(string position)
{   
	if(position == "Lecturer" ||position == "Adjunct" ||position == "Professor" ||position == "Teaching Assistant" || position == "Research Assistant")
	{	
		type = position;
		setCourseReady(true); 
	}
	else if(position == "Teaching Assistant")
	{
		if(getGraduate())
		{
			type = position;
			setCourseReady(true);
		}
		else
			cout << "Student must be a graduate to be a teaching assistant" << endl;
	}
	else if(position == "Research Assistant")
	{		
		if(getGraduate())
		{
			type = position;
			setCourseReady(false);
		}
		else
			cout << "Student must be a graduate to be research assistant" << endl;
	}
	else
	{
		cout << "Invalid Postition selected" << endl;
		type = "ERROR";	
	}
}
//get function returns type
string Teacher::getType()
{
	return type;						
}
//manually initlizes teacher object
void Teacher::setTeacher(string idNumber,  string first,  string last,
						 string DOB,  string sex,  string type, string depart)
{
	//calls setperson and set type functions
	Person::setPerson(idNumber, first, last, DOB, sex);
	Teacher::setType(type);
}						
//primary functionality provided by this function to use information from the text file
//nearly identical to student setFromStream. see student copy for details
void Teacher::setFromStream(char *ptr)
{
	char temp[20];
	int k=0; 
	
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n'; 
	string str1c(temp, k);
	setCourseName(str1c);
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n'; 
	string str2c(temp, k);
	setCourseName2(str2c);
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n';
	string str3c(temp, k);
	setCourseName3(str3c);
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n';//string must be null terminated to assign to a new string in the following line
	string str1(temp, k);
	setID(str1);
	k = 0;
	++ptr;
	while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str2(temp, k);
	k = 0;
	++ptr;

	while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str3(temp, k);
	setName(str3, str2);
	k = 0;
	++ptr;
		
	while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str4(temp, k);
	setDateOfBirth(str4);
	k = 0;
	++ptr;

	while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str5(temp, k);
	
	//condition used to determine if the type is one word or two words
	if(str5 == "Lecturer" || str5 == "Adjunct" || str5 == "Professor")
	setType(str5);
	k = 0;
	++ptr;
	
	if(str5 == "Teaching" || str5 == "Research")
	{
		//an additional string is created if the type is two words
		while(*ptr != ' ')
		{
			temp[k] = *ptr;
			ptr++;
			++k;
		}
			
		temp[k] = '\n';
		string strx(temp, k);
		str5 += " ";
		string strxx = str5 + strx;
		setType(strxx);
		k = 0;
		++ptr;
				
	}
	
	while(*ptr !=  ' ' && *ptr != '\0')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	
	temp[k] = '\n';
	string str7(temp, k);
	k = 0;
	if((*ptr) != '\0')
	{
		ptr++;

		while(*ptr != '\0')
		{
			temp[k] = *ptr;
			ptr++;
			++k;
		}
			
		temp[k] = '\n';
		string str8(temp, k);
		str7 += " ";
		string str9 = str7 + str8;
		setDepartment(str9);
		
	}
	else
		setDepartment(str7);

}

//print function formatted for teacher objects
void Teacher::print()
{
	cout << left << setw(8) << getID() << setw(9) << getLastName() << setw(9) << getFirstName()
	<< setw(12) << getDateOfBirth() << setw(20) << type << getDepartment() << endl;
 	
}
//specially formatted print function, takes a string as an argument to determine what info to print
void Teacher::printByDepartment(string depart)
{
	if((this->getDepartment()) == depart)
		this->print();
}
//third format for print function
void Teacher::printCourse()
{
	cout << left << setw(8) << getID() << setw(9) << getFirstName()  << setw(9) << getLastName() << setw(7)   << getCourseName() 
	<< setw(7)  << getCourseName2()<< setw(7) << getCourseName3() << endl;
}
//forth print format
void Teacher::printDepartmentAndCourse()
{
	cout << left << setw(25) << getDepartment() << setw(7)  << getCourseName() << setw(7)  
	<< getCourseName2()<< setw(7) << getCourseName3() << endl;
}
//fifth print format
void Teacher::printByCourse(string courseName)
{
	if((this->getCourseName()) == courseName || this->getCourseName2() == courseName || this->getCourseName3() == courseName)
	{
		cout << left << setw(7) << courseName << setw(8) << getID() << setw(9) << getLastName() << setw(9) << getFirstName()
		<< setw(20) << type;
	}
		
}

Teacher::~Teacher()
{
	
}

