#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main() {
	Tree myTree('a');
	
	myTree.printTree(myTree.getRoot(), 0);



	cout << endl;
	system("pause");
	return 0;
}