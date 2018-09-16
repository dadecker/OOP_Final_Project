/*
David Decker
COP 3331.001
Semester Project
*/

//class Student function definitions
#include "Student.h"
#include "Department.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;
//constructor 
Student::Student()
:Person()
{
	degree = " ";
	grade = ' ';
	graduate = false;
	courseReady = false;
}

//set degree function tests for only the acceptable values for degrees
//if the degree is a graduate degree the set graduate function is called and 
//the bool variable graduate is set as true
void Student::setDegree(string degreeWork)
{
	if(degreeWork == "Masters" || degreeWork == "Bachelors" || degreeWork == "Doctorate")
		degree = degreeWork;
	else
		{
			cout << "Not a valid selection for Degree " << endl;
			degree = "Unknown";
		}
	
	if(degreeWork == "Masters"|| degreeWork == "Doctorate")
		setGraduate(true);
	
	if(degreeWork == "Bachelors")
		setGraduate(false);
		setCourseReady(false);
	
}
//set grade makes sure the char character entered is a-f capital or lowercase only
void Student::setGrade(char letter)
{
	if(letter == 'A' || letter == 'B' || letter == 'C' || letter == 'D' || letter == 'F'
		 || letter == 'a' || letter == 'b' || letter == 'c' || letter == 'd' || letter == 'f')
		grade = letter;
	else	
	{
		cout << "Invalid Grade selected " << endl;
		grade = 'U';
	}
	
	
}
//the following get functions return the value of thier indicated data member
string Student::getDegree()
{

	return degree;
}

char Student::getGrade()
{
	return grade;
}

void Student::setGraduate(bool grad)
{
	graduate = grad;
}

bool Student::getGraduate()
{
	return graduate;
}
void Student::setCourseReady(bool ready)
{
	courseReady = ready;
}

bool Student::getCourseReady()
{
	return courseReady;
}
//specifically formatted student print function
void Student::print()
{
 	cout << left << setw(8) << getID() << setw(9) << getLastName() << setw(9) << getFirstName()
	<< setw(12) << getDateOfBirth() << setw(7) << getGender() << setw(10) << degree << setw(24) << getDepartment() << endl;
 	
}
//different format for printing
void Student::printByDepartment(string depart)
{
	if((this-> getDepartment()) == depart)
		this->print();
		
		
}
//third format for printing. Not used in demonstration. Prints only if the argument matches the course name
void Student::printByCourse(string courseName)
{
	if((this->getCourseName()) == courseName || this->getCourseName2() == courseName || this->getCourseName3() == courseName)
	{
		cout << left << setw(7) << courseName << setw(8) << getID() << setw(9) << getFirstName() << setw(9) << getLastName()
		 << setw(3) << static_cast<char>(grade);
	}
		
}
//fourth format for printing
void Student::printDepartmentAndCourse()
{
	cout << left << setw(25) << getDepartment() << setw(7)  << getCourseName() << setw(7)  
	<< getCourseName2()<< setw(7) << getCourseName3() << endl;
}
//fifth printing format
void Student::printCourse()
{
	cout << left << setw(8) << getID() << setw(9) << getFirstName()  << setw(9) << getLastName() << setw(7)   << getCourseName() 
	<< setw(7)  << getCourseName2()<< setw(7) << getCourseName3() << endl;
}
//manual function that can be used to initialize an object
void Student::setStudent(string idNumber, string first,  string last,
						 string DOB,  string sex,  string degreework,  char letter, string depart, string course)
{
	//Person::setPerson(idNumber, first, last, DOB, sex, depart);
	Person::setName(last, first);
	Person::setID(idNumber);
	Person::setDateOfBirth(DOB);
	Person::setGender(sex);
	Student::setDegree(degreework);
	Student::setGrade(letter);
	Department::setDepartment(depart);
	Course::setCourseName(course);
}

//main functionality for taking information from stream is provided by the following function
//each line is stored character by character in the char arrary then used to create a string.
//the string is then used to set the data member values of the student object
void Student::setFromStream(char *ptr)
{
	char temp[20];//temporary string
	int k=0; 

	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;//advance pointer
		++k;//advance temp array index
	}
	temp[k]='\n';//add a null character so array can be converted to string
	string str1c(temp, k);//library function creates string of the index length
	setCourseName(str1c);//function sets courseName data member value
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n';//add a null character 
	string str2c(temp, k);
	setCourseName2(str2c);//function for data member courseName2
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n';//add a null character 
	string str3c(temp, k);
	setCourseName3(str3c);//function for coursename3 
	k = 0;
	++ptr;
	while(*ptr != ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k]='\n';//add a null character 
	string str1(temp, k);
	setID(str1);//sets value for ID
	k = 0;
	++ptr;
	while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str2(temp, k);// last name held in str2
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
	setName(str3, str2);//setName function takes two arguments, first and last name
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
	setDateOfBirth(str4);//function sets dateOfBirth variable
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
	setGender(str5);//sets gender
	k = 0;
	++ptr;

		while(*ptr !=  ' ')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	temp[k] = '\n';
	string str6(temp, k);
	setDegree(str6);//sets the name of the degree being worked on
	k = 0;
	++ptr;
	//sets grade
	//type cast *ptr to char 
	setGrade((char)*ptr);
					 
	//reposition pointer 	
	ptr++;
	ptr++;
			
	while(*ptr !=  ' ' && *ptr != '\0')
	{
		temp[k] = *ptr;
		ptr++;
		++k;
	}
	
	temp[k] = '\n';
			
	string str7(temp, k);
	k = 0;
	//department can be two words. this function tests to see if the end of a line
	//has been reached or just a white space. 
	if((*ptr) != '\0')
	{
		ptr++;

		while(*ptr != '\0')//extracts characters until end of line is reached
		{
			temp[k] = *ptr;
			ptr++;
			++k;
		}
			
		temp[k] = '\n';
		string str8(temp, k);
		str7 += " "; //adds a white space to the end of the first word in the department
		string str9 = str7 + str8;//string class overloaded operator concatenates the strings
		setDepartment(str9);//department variable is set
		
	}
	else
		setDepartment(str7);//if the department is only one word long this command is executed		
}
//destructor
Student::~Student()
{
	
}

						
