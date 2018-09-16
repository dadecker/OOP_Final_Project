/*
David Decker
COP 3331.001
Semester Project
*/

//Person base class
//function defintions

#include <iostream>     
#include <stdlib.h>
#include <string> 
#include <iomanip>    
#include "Person.h"

using namespace std;
//construtor
Person::Person()
	{	
		firstName = " ";
		lastName = " ";
		dateOfBirth = " ";
		gender = " ";
		ID = " ";

} 
//set ID function tests the length of the ID number and Error replaces the string if it is not the right lenght
//the function then tests the individual characters, see below
void Person::setID(string idNumber)	
{
	int length = idNumber.length();
	if(length != 6)
	{
		cout << "Invalid ID number. ID must be 6 digits" << endl;
		idNumber = "Error ";
		ID = idNumber;
		return;
	}
	
	char temp[length];
	//the string is entered into a char array element by element
	for(int i = 0; i < length; i++)
	{
		//if the individual elements of the string are not one of the following the 
		//ID number is replaced by "unknown"
   		if(!(idNumber[i] == '0' || idNumber[i] == '1' || idNumber[i] == '2' || idNumber[i] == '3' || idNumber[i] == '4'
   		|| idNumber[i] == '5' || idNumber[i] == '6' || idNumber[i] == '7' || idNumber[i] == '8' || idNumber[i] == '9'))	
		{	

			cout << "Invalid ID number" << endl;
    		idNumber = "Unknown";
    		ID = idNumber;
    		return;
		}
   		
	}
	
	
	ID = idNumber;
}
//setName function makes sure the name is in the allowed length. If not the string is truncated
void Person::setName( string first,  string last)
{
	int firstlength = first.length();
	int lastlength = last.length();
	if(firstlength > 8)
	{
		cout << "first name exceeded maximum length" << endl;
		//Library function to shorten string so it fits the formatt
		first = first.erase(8, firstlength-8);
	}
	if(lastlength > 8)
	{
		cout << "last name exceeded maximum length" << endl;
		last = last.erase(8, lastlength-8);
	}
	
	firstName = first;
	lastName = last;
}
//exhaustive precautions to make sure DOB is accurate. see the following
void Person::setDateOfBirth(string DOB)
{
//get the length of the string enterd for DOB
int length = DOB.length();
char temp[length];
//the string is entered into a char array element by element
for(int i = 0; i < length; i++)
{
   	temp[i]=DOB[i];
}
//Each character in the DOB string is evaluated for acceptable values
//in the next 11 if statements. Each character in the string is evaluated seperatly
if(temp[0] != '1'&& temp[0] != '0')
{
//month test
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(!(temp[1] == '0' || temp[1] == '1' || temp[1] == '2' || temp[1] == '3' || temp[1] == '4'
   || temp[1] == '5' || temp[1] == '6' || temp[1] == '7' || temp[1] == '8' || temp[1] == '9'))	
{
//month test part 2
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[2] != '/')
{
//slash test
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[3] != '1'&& temp[3] != '0' && temp[3] != '2' && temp[3] != '3')
{
//day test	
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(!(temp[4] == '0' || temp[4] == '1' || temp[4] == '2' || temp[4] == '3' || temp[4] == '4'
   || temp[4] == '5' || temp[4] == '6' || temp[4] == '7' || temp[4] == '8' || temp[4] == '9'))	
{
//day test
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[5] != '/')
{
//slash test
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[6] != '1'&& temp[6] != '2')
{
//the rest of the conditions test the year 
	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[6] == '1' && temp[7] != '9')
{

	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(temp[6] == '2' && temp[7] != '0')
{

	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(!(temp[8] == '0' || temp[8] == '1' || temp[8] == '2' || temp[8] == '3' || temp[8] == '4'
   || temp[8] == '5' || temp[8] == '6' || temp[8] == '7' || temp[8] == '8' || temp[8] == '9'))	
{

	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}
if(!(temp[9] == '0' || temp[9] == '1' || temp[9] == '2' || temp[9] == '3' || temp[9] == '4'
   || temp[9] == '5' || temp[9] == '6' || temp[9] == '7' || temp[9] == '8' || temp[9] == '9'))	
{

	cout << "Invalid date of birth" << endl;
    DOB = "Unknown";
    dateOfBirth = DOB;
    return;
}	
dateOfBirth = DOB;
}
//for SetGender function, tests for the string to make sure it is either male or female
void Person::setGender(string sex)
{
	if(sex == "Male" || sex == "Female")
		gender = sex;
	else
	{
		cout << "Invalid entry for gender" << endl;
		gender = "      ";
	}
}

//the following get functions return the value of the data members
string Person::getID()
{
	return ID;
}

string Person::getLastName()
{
	return lastName;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getDateOfBirth()
{
	return dateOfBirth;
}

string Person::getGender()
{
	return gender;
}
//set function to manually set a person object
void Person::setPerson(string idNumber,  std::string first,  std::string last,
						 std::string DOB,  string sex)
{
	Person::setID(idNumber);
	Person::setName(first, last);
	Person::setDateOfBirth(DOB);
	Person::setGender(sex);
}
//virtual function undefined in base class
void Person::setFromStream(char *ptr)
{

}
//virtual function
void Person::printCourse()
{
	
}
//pure virtual function
void Person::print()
{


}
//virtual special case print
void Person::printDepartmentAndCourse()
{
	
}
//virtual destructor
Person::~Person()
{
	
}
