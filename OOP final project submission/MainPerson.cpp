/*
David Decker
COP 3331.001
Semester Project
*/
//main function that runs the program. Also provides some formatting and a small 


#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Department.h"
#include "Course.h"
#define MAX 50

using namespace std;

int main() 
{
	
	int menuSelection;
	//following variables used for reading and formatting input text
	//Vector of person pointers used to demonstrate polymorphism
	vector< Person *> people(MAX);
	//array of teacher and student object that the person pointer points at 	
	Student students[MAX];
	Teacher teachers[MAX];
	string str, id, firstName, lastName, DOB, gender, degree, department;
	//char arrays hold the text being read
	char temp[100];
	char temp2[20];
	char letter;
	//used to hold iteration integer values
	int i, j, k;
	//begin interface. Allows user to select options
	cout << "Please enter a selection" << endl;
	cout << "1) Directory by student" << endl;
	cout << "2) Dierctory by teacher" << endl;
	cout << "3) Directory by department" << endl;
	cout << "4) Directory by course" << endl;
	
	
	cin >> menuSelection;
	
	if(menuSelection == 1)
	{
		int subMenu;
		cout << "For type of student directory:" << endl;
		cout << "1) All Student information" << endl;
		cout << "2) Courses by student" << endl;
		
		cin >> subMenu;
		//instantiates an ifstream object, to open given file and read the contents only
		ifstream inFile("Students.txt", ios::in);
		//makes sure file can be opened
		if(!inFile)
		{
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		i = 0;		
		//takes in a line of the test file and each line is processed. 
		//The file is temporaily stored in a char array
		while(!inFile.getline(temp, 100).eof())
		{
		
			char *ptr = temp;
			char temp[20];
			 
			//set person pointer to array of student objects To perform
			//****POLYMORPHISM****
			people[i] = &students[i];
			//**POLYMORPHISM**
			//uses student version of the setFromStream function
			//creates student objects from data in file
			people[i]->setFromStream(ptr);
			i++;
		}
			if(subMenu == 1)
			{
				cout << "Student directory: " << endl;
				cout << endl;
				//following formats and prints the header
				cout << left << setw(8) << "ID" << setw(18) << "Name" << setw(12) << "Birth Date"  
					<< setw(7) << "Gender" << setw(10) << "Degree" <<  "Department" << endl;
				cout << endl;
				//cycles thru and prints the student objects using polymorphism 
				//and the info is formatted using the student print function definition
				for(int r = 0; r <i-1; r++)
				{
				people[r]->print();
				}
			}
			else if(subMenu == 2)
			{
				cout << "Student Course directory: " << endl;
				cout << endl;
				cout << left << setw(8) << "ID" << setw(18) << "Name"  << setw(21)  << "Courses" << endl;
				cout << endl;
				//same as above
				for(int q = 0; q < i-1; q++)
				{
					people[q]->printCourse();		
				}		
			}	
		
	}
	//identical as above except creates teacher objects and reads information from a different file
	else if(menuSelection == 2)
	{
			int subMenu;
		cout << "For type of teacher directory:" << endl;
		cout << "1) All teacher information" << endl;
		cout << "2) Courses by teacher" << endl;
		
		cin >> subMenu;
		
		ifstream inFile("Teachers.txt", ios::in);
		
		if(!inFile)
		{
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		i = 0;		
		while(!inFile.getline(temp, 100).eof())
		{

			char *ptr = temp;
			char temp[20];
			 
			//set person pointer to array of teacher objects To perform
			//****POLYMORPHISM****
			people[i] = &teachers[i];
			//**POLYMORPHISM**
			//uses teacher version of the setFromStream function
			people[i]->setFromStream(ptr);
			i++;
		}
			if(subMenu == 1)
			{
				cout << "Teacher Directory: " << endl;
				cout << endl;
				cout << left << setw(8) << "ID" << setw(18) << "Name" << setw(12) << "Birth Date"  
					<< setw(20) << "Position" <<  "Department" << endl;

				cout << endl;
				//uses functionality of teacher print function
				for(int r = 0; r <i-1; r++)
				{
					people[r]->print();
				}
			}
			else if(subMenu == 2)
			{
				cout << "Teacher Course directory: " << endl;
				cout << endl;
				cout << left << setw(8) << "ID" << setw(18) << "Name"  << setw(21)  << "Courses" << endl;
				cout << endl;
				for(int q = 0; q < i-1; q++)
				{
					people[q]->printCourse();
				}
			}
	}
	//the following is arranged to print information based on depatment chosen
	else if(menuSelection == 3)
	{
		int subMenuSelection, sub2;
		cout << "Select Department: " << endl;
		cout << endl;
		cout << "1) Art History " << endl;
		cout << "2) Biology" << endl;
		cout << "3) Computer Science " << endl;
		cout << "4) Mechanical Engineering " << endl;
		
		cin >> subMenuSelection;
		//fufills grading criteria presented on the pdf
		cout << "Select to view Department by:  Teachers, Students or Courses: " << endl;
		cout << "1) Students " << endl;
		cout << "2) Teachers " << endl;
		cout << "3) Courses " << endl;
		
		
		cin >> sub2;
		
		ifstream inFile("Departments.txt", ios::in);
		
		if(!inFile)
		{
			cerr << "File could not be opened" << endl;
			exit(EXIT_FAILURE);
		}
		i = 0;		
		if(sub2 == 1)
		{
			//header for selection of students by department
			cout << "Students by department: " << endl;
			cout << endl;
			cout << left << setw(8) << "ID" << setw(18) << "Name" << setw(12) << "Birth Date"  
				<< setw(7) << "Gender" << setw(10) << "Degree" <<  "Department" << endl;
			cout << endl;

		}
		else if(sub2 == 2)
		{
			cout << "Teachers by department: " << endl;
			cout << endl;
			//formats and prints the header for the file to be displayed
			cout << left << setw(8) << "ID" << setw(18) << "Name" << setw(12) << "Birth Date"  
				<<  setw(20) << "Position" << setw(10) << "Department" << endl;
			cout << endl;

		}
		else if(sub2 == 3)
		{
			cout << "Courses by Department: " << endl;
			cout << endl;
			cout << left << setw(25) << "Department" << "Courses" << endl;
			cout << endl;
		}
		while(!inFile.getline(temp, 100).eof())
		{
			char *ptr = temp;
			int k=0; 
			//functionlity only for department and course text files, contained in main
			//used to distinguish student info in text file from teacher info, just reads the first string
			while(*ptr != ' ')
			{
				temp[k] = *ptr;
				ptr++;
				++k;
			}
			temp[k]='\n';//add a null character 
			//creates string from temp array created
			string sort(temp, k);		
			k = 0;//resets temp array to element 0
			++ptr; //advances pointer
			i = 0;
			//creates either student or teacher objects based on user selection
			if(sub2 == 1)
			{
				if(sort == "Student")
				{	
					students[i].setFromStream(ptr);
					if(subMenuSelection == 1)
						students[i].printByDepartment("Art History");
					else if(subMenuSelection == 2)
						students[i].printByDepartment("Biology");
					else if(subMenuSelection == 3)
						students[i].printByDepartment("Computer Science");
					else if(subMenuSelection == 4)
						students[i].printByDepartment("Mechanical Engineering");
					++i;
				}
			}
			else if(sub2 == 2)
			{
				if(sort == "Teacher")
				{
					teachers[i].setFromStream(ptr);
					if(subMenuSelection == 1)
						teachers[i].printByDepartment("Art History");
					else if(subMenuSelection == 2)
						teachers[i].printByDepartment("Biology");
					else if(subMenuSelection == 3)
						teachers[i].printByDepartment("Computer Science");
					else if(subMenuSelection == 4)
						teachers[i].printByDepartment("Mechanical Engineering");	
					++i;	
				}
			}
			
		}	
		//uses a fixed list to print depatment courses. 
		//Does not use text file or objects due to structure of program
		if(sub2 == 3)
		{
			if(subMenuSelection == 1)
				cout << "Art History: AH100 AH200 AH220" << endl;
			else if(subMenuSelection == 2)
				cout << "Biology: BO101 BO300 BO400" << endl;
			else if(subMenuSelection == 3)
				cout << "Computer Science: CS101 CS200 CS220" << endl;
			else if(subMenuSelection == 4)
				cout << "Mechanical Engineering: ME200 ME250 ME300" << endl;
		}				
		

	}
	//final menu sorts by course
	else if(menuSelection == 4)
	{
		
		int courseSelection;
			//provides a menu for the user
			cout << "Students and teachers listed by course:" << endl;
			cout << "1) AH220 " << endl;
			cout << "2) CS101" << endl;
			cout << "3) CS200" << endl;
			cout << "4) BO101" << endl;
		
			cin >> courseSelection;
			string courseSelected;
			
			//sets the string value associated with the user's selection	
			if(courseSelection == 1)
				courseSelected = "AH220";
			else if(courseSelection == 2)
				courseSelected = "CS101";
			else if(courseSelection == 3)
				courseSelected = "CS200";
			else if(courseSelection == 4)
				courseSelected = "BO101";
			else
				cout << "Invalid Course Selection" << endl;
				
			ifstream inFile("Courses.txt", ios::in);
			
			if(!inFile)
			{
				cerr << "File could not be opened" << endl;
				exit(EXIT_FAILURE);
			}
			
			i=0;
			bool printConditionS = true;
			bool printConditionT = true;
			while(!inFile.getline(temp, 100).eof())
			{
				//initilize the pointer to array temp which will hold each line of text
				//same as option three, the following line of code extracts the first string
				char *ptr = temp;
				int k=0; 

				while(*ptr != ' ')
				{
					temp[k] = *ptr;
					ptr++;
					++k;
				}
				temp[k]='\n';//add a null character 
				string sort(temp, k);		
				k = 0;
				++ptr;
				
			
				if(sort == "Student")
				{			
					if(printConditionS)//bool value used so following header only prints once
					{	
						//following formats and prints the header
						cout << "Students in course " << courseSelected << " : " << endl;
						cout << left << setw(7) << "Course" << setw(8) << "ID" << setw(18) << "Name"	 << setw(3) << "Grade";
						cout << endl;
						cout << endl;
					}
					//special function prints for this particular format
					students[i].setFromStream(ptr);
					students[i].printByCourse(courseSelected);
	
					++i;
					printConditionS = false;//bool value used so following header only prints once
				}
				else if(sort == "Teacher")
				{
					if(printConditionT)//bool value used so following header only prints once
					{
						
						cout << endl;
						cout << endl;
						cout << "Teachers in course " << courseSelected << " : " << endl;
						cout << left << setw(7) << "Course" << setw(8) << "ID" << setw(18) << "Name" << setw(20) << "Position";
						cout << endl;
						cout << endl;
					}
					teachers[i].setFromStream(ptr);
					teachers[i].printByCourse(courseSelected);
					
					++j;
					printConditionT = false;//second bool value used to prevent reprint of header	
				}
								
			}

		
	}
	
}

