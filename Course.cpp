// The implementation file for Course.h
// It loads students from a text file.
#include <iostream>
#include <cstring>

#include "Course.h"
#include "Student.h"
using namespace std;

// initiaizes a course variable and returns it. The array is empty
// and the number of students is set to 0.
Course initCourse()
{
	Course course;
	course.numStudents = 0;
	return course;
}

// reads a student from the file and calls AddStudent
void readStudent(ifstream &inFile, Course &course)
{
	char firstBuffer[20];
	char lastBuffer[20];
	double gpa;

	while (inFile.getline(firstBuffer, 20, ';'))
	{
		inFile.getline(lastBuffer, 20, ';');
		inFile >> gpa;
		Student transferStudent;
		strcpy(transferStudent.first, firstBuffer);
		strcpy(transferStudent.last, lastBuffer);
		transferStudent.gpa = gpa;
		addStudent(transferStudent, course);
		// strcpy(course.roster[course.numStudents].first, firstBuffer);
		// strcpy(course.roster[course.numStudents].last, lastBuffer);
		// course.roster[course.numStudents].gpa = gpa;
	}
}

// adds a student to the roster, and increment count
// modify this function to add the student sorted by name
// do not use any sorting functions.
// See this example in zyBooks Section 14.7
// [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course)
{
	// cout << student.first;
	// if (course.numStudents == 0)
	// {
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	// }
	// else
	// {

	for (int i = 0; i < course.numStudents; i++)
	{
		if (strcmp(student.last, course.roster[i].last) < 0)
		{

			cout << student.last << " " << course.roster[i].last << endl;
			// 			for (int j = course.numStudents + 1; j > i; j--)
			// 			{
			// 				// course.roster[j] = course.roster[j - 1];
			// 				course.roster[j].gpa = course.roster[j - 1].gpa;
			// 				strcpy(course.roster[j].last, course.roster[j - 1].last);
			// 				strcpy(course.roster[j].first, course.roster[j - 1].first);
			// 			}
			// 		}
			// 		else
			// 		{
			// 			course.roster[i].gpa = student.gpa;
			// 			strcpy(course.roster[i].last, student.last);
			// 			strcpy(course.roster[i].first, student.first);
		}
	}
	// }
	course.numStudents++;

	// if (course.numStudents == 0)
	// {
	// 	course.roster[course.numStudents] = student;
	// }
	// else
	// {
	// 	for (int i = 0; i < course.numStudents; i++)
	// 	{
	// 		if (strcmp(student.last, course.roster[i].last) < 0)
	// 		{
	// 			for (int j = course.numStudents; j >= i; j--)
	// 			{
	// 				strcpy(course.roster[j].first, course.roster[j - 1].first);
	// 				strcpy(course.roster[j].last, course.roster[j - 1].last);
	// 				course.roster[j].gpa = course.roster[j - 1].gpa;
	// 			}
	// 			course.roster[i] = student;
	// 		}
	// 		else
	// 		{
	// 			course.roster[course.numStudents + 1] = student;
	// 		}
	// 	}
	// }
}

// prints a whole Course roster calling student print.
// use a for loop and print all the students
// must call the printStd function in Student.h
void printRoster(Course course)
{
	cout << endl;
	for (int i = 0; i < course.numStudents; i++)
	{
		cout << course.roster[i].first << ";"
			 << course.roster[i].last << ";"
			 << course.roster[i].gpa;
	}
	cout << endl
		 << endl;
}

/*Based on the grade level you are doing: Please read the appropriate
level assignment document.
add code and function comments for the below 2 functions.
Student findStudentHighestGPA(Course course);
*/
void dropStudent(char *lastname, Course &course)
{
	int initRoster = course.numStudents;
	for (int i = 0; i < course.numStudents; i++)
	{
		if (strcmp(lastname, course.roster[i].last) == 0)
		{
			for (int j = i; j < course.numStudents; j++)
			{
				course.roster[j] = course.roster[j + 1];
			}
			course.numStudents--;
		}
	}
	if (initRoster == course.numStudents)
	{
		cout << endl
			 << "Student with the last name " << lastname
			 << " was not found." << endl;
	}
}

Student findStudentHighestGPA(Course course)
{
	Student tempHighestStudent;
	for (int i = 0; i < course.numStudents; i++)
	{
		if (tempHighestStudent.gpa < course.roster[i].gpa)
		{
			tempHighestStudent = course.roster[i];
		}
	}
	return tempHighestStudent;
}
