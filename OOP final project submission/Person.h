/*
David Decker
COP 3331.001
Semester Project
*/

//Person base class
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
// abstract base class
class Person
{
	private:
		std::string ID;
		std::string firstName;
		std::string lastName;
		std::string dateOfBirth;
		std::string gender;

	public:
		Person();
		void setID(std::string idNumber);
		void setName( std::string first,  std::string last);
		void setDateOfBirth( std::string DOB);
		void setGender( std::string sex);
		std::string getID();
		std::string getFirstName();
		std::string getLastName();
		std::string getDateOfBirth();
		std::string getGender();
		void setPerson(std::string idNumber,  std::string first,  std::string last,
						 std::string DOB, std::string sex);
		virtual void setFromStream(char *ptr);
		virtual void printDepartmentAndCourse();	 
		virtual void printCourse();
		//pure virtual declaration makes the class abstract
		virtual void print() = 0;
		virtual ~Person();
			
	
};

#endif
