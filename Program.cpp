#include "Program.h"
#include "BST.h"
#include <cstdlib>
#include <stdlib.h>
#include <sstream>

using namespace std;

Program::Program(){

	masterStudent = new BST<Student>();
	masterFaculty = new BST<Faculty>();
	ifstream reader("serialization.txt");
	string line;
	int counter = 0;
	int numStudents;
	string studentArray[6];
	string facultyArray[4];
	int index = 0;
	while (getline(reader,line)) {
		if (counter == 0)
		{
			numStudents = atoi(line.c_str());
			numStudents *= 6;
		}
		else if (counter <= numStudents && counter != 0)
		{
			if (index < 6)
			{
				studentArray[index++] = line.c_str();
				if (index == 6)
				{
					Student* newStudent = new Student(atoi(studentArray[0].c_str()), studentArray[1], studentArray[2], studentArray[3], 
						atoi(studentArray[4].c_str()), atoi(studentArray[5].c_str()));
					masterStudent->insert(*newStudent);
					delete newStudent;
					index = 0;				
				}
			}
		}
		else if (counter > numStudents)
		{
			Faculty* newFaculty;
			if (index < 4)
			{
				facultyArray[index] = line.c_str();
				if (index == 3)
				{
					newFaculty = new Faculty(atoi(facultyArray[0].c_str()), facultyArray[1], facultyArray[2], facultyArray[3]);
				}
				index++;
			}
			else if (index == 4)
			{
				if (line == "***")
				{
					index = 0;
					masterFaculty->insert(*newFaculty);
					delete newFaculty;
				}
				else
				{
					newFaculty->add(atoi(line.c_str()));
				}
			}
		}
		counter++;
	}
	reader.close();
}

Program::~Program(){cout << "~Program" << endl;}

void Program::choices(){
	cout << "1. Print all students and their information (sorted by ascending id #)" << endl;
	cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
	cout << "3. Find and display student information given the students id"<< endl;
	cout << "4. Find and display faculty information given the faculty id"<< endl;
	cout << "5. Given a student’s id, print the name and info of their faculty advisor"<< endl;
	cout << "6. Given a faculty id, print ALL the names and info of his/her advisees."<< endl;
	cout << "7. Add a new student"<< endl;
	cout << "8. Delete a student given the id"<< endl;
	cout << "9. Add a new faculty member"<< endl;
	cout << "10. Delete a faculty member given the id."<< endl;
	cout << "11. Change a student’s advisor given the student id and the new faculty id."<< endl;
	cout << "12. Remove an advisee from a faculty member given the ids"<< endl;
	cout << "13. Rollback" << endl;
	cout << "14. Exit" << endl;
}

void Program::runProgram(){


	int choice = 0;
	while(choice != 14){
		choices();
		cin >> choice;
		switch(choice){
			case 1:
				masterStudent->printInOrder();
				break;
			case 2:
				masterFaculty->printInOrder();
				break;
			case 3: {
				int number = 0;
				cout << "Please enter an ID number to search for: ";
				cin >> number;
				Student* searchStudent = new Student(number);
				cout << masterStudent->search(*searchStudent)->data << endl;
				delete searchStudent;
				break;
			}
			case 4: {
				int number = 0;
				cout << "Please enter a faculty ID to search for: ";
				cin >> number;
				Faculty* searchFaculty = new Faculty(number);
				cout << masterFaculty->search(*searchFaculty)->data << endl;
				delete searchFaculty;
				break;
			}
			case 5: {
				cout << "Enter ID of the student you wish to view: " << endl;
				int temp_ID;
				cin >> temp_ID;
				Student* temp = new Student(temp_ID);
				Faculty* temp_Faculty = new Faculty(masterStudent->search(*temp)->data.advisorID);
				cout << masterFaculty->search(*temp_Faculty)->data << endl;
				delete temp;
				delete temp_Faculty;
				break;
			}
			case 6: {
				cout << "Enter ID of the Faculty you wish to view: " << endl;
				int temp_ID;
				cin >> temp_ID;
				Faculty* temp = new Faculty(temp_ID);
				ListNode<int>* faculty_advisees = masterFaculty->search(*temp)->data.advisees->front;
				while(faculty_advisees != NULL){
					temp_ID = faculty_advisees->data;
					Student* temp = new Student(temp_ID);
					cout << masterStudent->search(*temp)->data << endl;
					faculty_advisees = faculty_advisees->next;
					delete temp;
				}
				break;
			}
			case 7: {
				if (masterFaculty->size == 0)
				{
					cout << "You must enter a faculty member before you can add a student." << endl;
				}
				else
				{
					int id;
					string sname;
					string slevel;
					string smajor;
					double sgpa;
					int sfacultyid;
					cout << "Enter students info:" << endl;
					cout << "ID: ";
					cin >> id;
					cout << "Name: ";
					cin.ignore();
					getline(cin, sname);
					cout << "Level: ";
					cin >> slevel;
					cout << "Major: ";
					cin.ignore();
					getline(cin, smajor);
					cout << "GPA: ";
					cin >> sgpa;
					cout << "Faculty ID: ";
					cin >> sfacultyid;
					cout << sfacultyid << endl;
					sfacultyid = advisorCheck(sfacultyid);
					
					Faculty* searchFaculty = new Faculty(sfacultyid);
					masterFaculty->search(*searchFaculty)->data.add(id);
					Student* newStudent = new Student(id, sname, slevel, smajor, sgpa, sfacultyid);
					masterStudent->insert(*newStudent);
					delete newStudent;
				}
				break;
			}
			case 8: {
				cout << "Enter the ID of the student that you want to delete: ";
				int number;
				cin >> number;
				Student* deleteStudent = new Student(number);
				int fac = masterStudent->search(*deleteStudent)->data.advisorID;
				Faculty* changeFac = new Faculty(fac);
				cout << masterFaculty->search(*changeFac)->data.advisees->front->data;
				masterFaculty->search(*changeFac)->data.advisees->remove(number);
				masterStudent->deleteNode(*deleteStudent);
				delete deleteStudent;
				delete changeFac;
				break;
			}
			case 9: {
				int id;
				string fname;
				string flevel;
				string fdept;
				cout << "Enter faculty's info:" << endl;
				cout << "ID: ";
				cin >> id;
				cout << "Name: ";
				cin.ignore();
				getline(cin,fname);
				cout << "Level: ";
				cin >> flevel;
				cout << "Department: ";
				cin >> fdept;
				Faculty* newFaculty = new Faculty(id, fname, flevel, fdept);
				masterFaculty->insert(*newFaculty);
				delete newFaculty;
				break;
			}
			case 10: {
				cout << "Enter Faculty ID you wish to delete" << endl;
				int number;
				cin >> number;
				Faculty* deleteFaculty = new Faculty(number);
				ListNode<int>* facultyAdvisees = masterFaculty->search(*deleteFaculty)->data.advisees->front;
				while(facultyAdvisees != NULL)
				{
					int stID;
					int fID;
					stID = studentCheck(facultyAdvisees->data);
					cout << "Enter the faculty id: ";
					cin >> fID;
					fID = advisorCheck(fID);
					changeStudentAdvisor(stID, fID);
					facultyAdvisees = facultyAdvisees->next;
				}

				masterFaculty->deleteNode(*deleteFaculty);
				delete deleteFaculty;
				break;
			}
			case 11: {
				int idNumS;
				int idNumF;
				cout << "Enter the ID of the student you would like to move: ";
				cin >> idNumS;
				idNumS = studentCheck(idNumS);
				cout << "Enter the ID of the faculty that you would like to switch the student to: ";
				cin >> idNumF;
				idNumF = advisorCheck(idNumF);
				changeStudentAdvisor(idNumS, idNumF);
				break;
			}
			case 12: {
				int idNumS;
				int idNumF;
				cout << "Enter the ID of the student you would like to move: ";
				cin >> idNumS;
				idNumS = studentCheck(idNumS);
				cout << "Enter the ID of the faculty that you would like to switch the student to: ";
				cin >> idNumF;
				idNumF = advisorCheck(idNumF);
				removeAdvisee(idNumS, idNumF);
				break;
			}
			case 13:
				break;
			case 14: {
				ofstream writer("serialization.txt");
				writer << masterStudent->size << endl;
				masterStudent->serializePreOrder(writer);
				masterFaculty->serializePreOrder(writer);
				delete masterStudent;
				cout << "masterStudent deleted" << endl;
				delete masterFaculty;
				cout << "masterFaculty deleted" << endl;
				writer.close();
				break;
			}
		}
	}
}

int Program::studentCheck(int studentID) {
	Student* searchStudent = new Student(studentID);
	if (masterStudent->search(*searchStudent) == NULL)
	{
		delete searchStudent;
		cout << "Not a Student member. Try again: " << endl;
		cin >> studentID;
		advisorCheck(studentID);
	}
	else
	{
		delete searchStudent;
	}
	return studentID;
}

int Program::advisorCheck(int facultyID) {
	Faculty* searchFaculty = new Faculty(facultyID);
	if (masterFaculty->search(*searchFaculty) == NULL)
	{
		delete searchFaculty;
		cout << "Not a faculty member. Try again: " << endl;
		cin >> facultyID;
		cout << facultyID << endl;
		advisorCheck(facultyID);
	}
	else
	{
		cout << "***" << facultyID << endl;
		delete searchFaculty;
		cout << "searchFaculty deleted" << endl;
		cout << facultyID << endl;
	}
	return facultyID;
}

void Program::changeStudentAdvisor(int studentID, int facultyID) {

	Student* change = new Student(studentID);
	Faculty* changePrev = new Faculty(masterStudent->search(*change)->data.advisorID);
	masterFaculty->search(*changePrev)->data.advisees->remove(studentID);
	masterStudent->search(*change)->data.advisorID = facultyID;
	Faculty* changeFac = new Faculty(facultyID);
	masterFaculty->search(*changeFac)->data.add(studentID);
	delete change;
	delete changeFac;
	delete changePrev;

}

void Program::removeAdvisee(int studentID, int facultyID) {

	Student* changeStudent = new Student(studentID);
	masterStudent->search(*changeStudent)->data.advisorID = -1;
	Faculty* changeFac = new Faculty(facultyID);
	masterFaculty->search(*changeFac)->data.advisees->remove(studentID);
	delete changeFac;
	delete changeStudent;

}







