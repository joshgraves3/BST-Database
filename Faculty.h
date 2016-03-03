#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include <iostream>
#include "LinkedList.h"
#include "ListNode.h"
using namespace std;

class Faculty {

	public:
		Faculty(int,string,string,string);
		Faculty(int);
		Faculty(Faculty& other);
		Faculty();
		~Faculty();
		bool operator>(const Faculty&);
		bool operator<(const Faculty&);
		void operator=(Faculty&);
		bool operator==(const Faculty&);
		void add(int d);

		int ID;
		string name;
		string level;
		string dept;
		LinkedList<int>* advisees;
	
};

ostream& operator<<(ostream& out, Faculty& other); 
#endif