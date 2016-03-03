#ifndef TREENODE_H
#define TREENODE_H

using namespace std;

template <typename T>
class TreeNode {

	public:
		T data;
		TreeNode* left;
		TreeNode* right;
		TreeNode();
		TreeNode(T& d);
		~TreeNode();

};

template <typename T>
TreeNode<T>::TreeNode() {}

template <typename T>
TreeNode<T>::TreeNode(T& d) {
	//cout << "in TreeNode constructor" << endl;
 	data = d;
 	//cout << data.name << endl;
 	//cout << data.ID << endl;
 	//cout << data.advisees->front->data << endl; //cuts off here if this isn't commented out
 	//cout << "data copied" << endl;
	left = NULL;
	right = NULL;
	//cout << "left and right are NULL" << endl;
	
}

template <typename T>
TreeNode<T>::~TreeNode() {
	cout << "~TreeNode" << endl;
	delete left;
	delete right;
	left = NULL;
	right = NULL;
}

#endif