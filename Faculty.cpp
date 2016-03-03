#include "Faculty.h"
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <typeinfo>
using namespace std;

Faculty::Faculty() {}

Faculty::Faculty(int fID, string fName, string fLevel, string fDept){
	ID = fID;
	name = fName;
	level = fLevel;
	dept = fDept;
	advisees = new LinkedList<int>();
	//cout << "faculty constructor 2" << endl;
}

Faculty::Faculty(int number) {
	ID = number;
	advisees = NULL;
}

Faculty::Faculty(Faculty& other) {
	ID = other.ID;
	name = other.name;
	level = other.level;
	dept = other.dept;
	advisees = other.advisees;
	other.advisees = NULL;
}

bool Faculty::operator>(const Faculty& other){
	if (ID > other.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Faculty::operator<(const Faculty& other){
	if (ID < other.ID)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Faculty::operator=(Faculty& other){
	ID = other.ID;
	name = other.name;
	level = other.level;
	dept = other.dept;
	advisees = other.advisees;
	other.advisees = NULL;
}

bool Faculty::operator==(const Faculty& other) {
	if (ID == other.ID)
	{
		return true;
	}
	return false;
}

void Faculty::add(int d) {

	advisees->insertFront(d);
	//cout << advisees->front->data << endl;
}

Faculty::~Faculty(){
	cout << "~Faculty" << endl;
	if (advisees != NULL)
	{	
		delete advisees;
		advisees = NULL;
	}
}

ostream& operator<<(ostream& out, Faculty& other) {
	if (typeid(out) == typeid(ofstream))
	{
		out << other.ID << endl;
		out << other.name << endl;
		out << other.level << endl;
		out << other.dept << endl;
		if (other.advisees != NULL)
		{
			ListNode<int>* temp = other.advisees->front;
			while (temp != NULL) {
				out << temp->data << endl;
				temp = temp->next;
			}
			temp = NULL;
		}
		out << "***" << endl;
	}
	else 
	{
		out << endl;
		out << "Faculty ID: " << other.ID << endl;
		out << "Faculty Name: " << other.name << endl;
		out << "Faculty Level: " << other.level << endl;
		out << "Faculty Department: " << other.dept << endl;
		if (other.advisees != NULL)
		{
			ListNode<int>* temp = other.advisees->front;
			while (temp != NULL) {
				out << temp->data << ",";
				temp = temp->next;
			}
			temp = NULL;
		}
		out << endl;
	}
	return out;
}

//return list of students and make print function 





