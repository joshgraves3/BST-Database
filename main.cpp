#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "Program.h"
#include <iostream>
#include <ostream>
using namespace std;

int main(int argc, char** argv) {

	/*BST<Faculty>* two = new BST<Faculty>();
	//cout << "magical" << endl;
	Faculty* copy = new Faculty(25, "Me", "Student", "CS");
	Faculty* linstead = new Faculty(24, "Erik", "Assistant", "CS");
	
	//cout << "linstead created" << endl;
	linstead->add(12);

	//cout << "chicken" << endl;
	two->insert(*linstead);
	two->insert(*copy);
	//cout << "linstead inserted" << endl;

	two->printInOrder();

	//cout << "copy created" << endl;
	//cout << two->search(copy) << endl;
	//two->printInOrder();
	delete copy;
	//cout << "******copy deleted" << endl;
	delete two;
	//cout << "******tree deleted" << endl;
	delete linstead;*/

	

	Program* one = new Program();
	one->runProgram();

	

	return 0;
}

