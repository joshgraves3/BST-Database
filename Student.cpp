#include "Student.h"
#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include <typeinfo>
using namespace std;

Student::Student() {}

Student::Student(int sID, string sName, string sLevel, string sMajor, double sGPA,int sAdvisorID){
	ID = sID;
	name = sName;
	level = sLevel;
	major = sMajor;
	GPA = sGPA;
	advisorID = sAdvisorID;
}

Student::Student(int number) {
	ID = number;
}

Student::Student(Student& other) {
	ID = other.ID;
	name = other.name;
	level = other.level;
	major = other.major;
	GPA = other.GPA;
	advisorID = other.advisorID;
}

Student::~Student(){cout << "~Student" << endl;}

bool Student::operator==(const Student& other){
	if (ID == other.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator>(const Student& other){
	if (ID > other.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Student::operator<(const Student& other){
	if (ID < other.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Student::operator=(const Student& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	major = other.major;
	GPA = other.GPA;
	advisorID = other.advisorID;
}

ostream& operator<<(ostream& out, Student& other) {
	if (typeid(out) == typeid(ofstream))
	{
		out << other.ID << endl;
		out << other.name << endl;
		out << other.level << endl;
		out << other.major << endl;
		out << other.GPA << endl;
		out << other.advisorID << endl;
	}
	else
	{
		out << "Student ID: " << other.ID << endl;
		out << "Student Name: " << other.name << endl;
		out << "Student Year: " << other.level << endl;
		out << "Student Major: " << other.major << endl;
		out << "Student GPA: " << other.GPA << endl;
		out << "Student Advisor's ID: " << other.advisorID << endl;
	}
	return out;
}


