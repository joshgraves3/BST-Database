#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class Student {

	public:
		Student(int,string,string,string,double,int);
		Student(int);
		Student(Student&);
		Student();
		~Student();
		bool operator>(const Student&);
		bool operator<(const Student&);
		void operator=(const Student&);
		bool operator==(const Student&);
		int ID;
		string name;
		string level;
		string major;
		double GPA;
		int advisorID;	
};

ostream& operator<<(ostream& out, Student& other);

#endif
