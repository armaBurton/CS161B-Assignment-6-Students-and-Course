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

		strcpy(course.roster[course.numStudents].first, firstBuffer);
		strcpy(course.roster[course.numStudents].last, lastBuffer);
		course.roster[course.numStudents].gpa = gpa;

		course.numStudents++;
	}
}

// adds a student to the roster, and increment count
// modify this function to add the student sorted by name
// do not use any sorting functions.
// See this example in zyBooks Section 14.7 [https://learn.zybooks.com/zybook/PCCCS161BSpring23/chapter/14/section/7]
void addStudent(Student student, Course &course)
{
	course.roster[course.numStudents].gpa = student.gpa;
	strcpy(course.roster[course.numStudents].last, student.last);
	strcpy(course.roster[course.numStudents].first, student.first);
	course.numStudents++;
}

// prints a whole Course roster calling student print.
// use a for loop and print all the students
// must call the printStd function in Student.h
void printRoster(Course course)
{
	for (int i = 0; i < course.numStudents; i++)
	{
		cout << course.roster[i].first << ";"
			 << course.roster[i].last << ";"
			 << course.roster[i].gpa;
	}
}

/*Based on the grade level you are doing: Please read the appropriate level assignment document.
add code and function comments for the below 2 functions.
void dropStudent(char *lastname, Course &course);
Student findStudentHighestGPA(Course course);
*/