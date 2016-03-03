#ifndef PROGRAM_H
#define PROGRAM_H
#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

class Program
{
	public:
		Program();
		~Program();
		void runProgram();
		void choices();
		int advisorCheck(int facultyID);
		int studentCheck(int studentID);
		void changeStudentAdvisor(int studentID, int facultyID);
		void removeAdvisee(int studentID, int facultyID);

		BST<Student>* masterStudent;
		BST<Faculty>* masterFaculty;
};

#endif