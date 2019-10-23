#include <iostream>
#include "Node.h"
#include "Tree.h"

using namespace std;

int main() {
	Tree myTree('a');

	myTree.addNode('z', 0);
	myTree.addNode('b', 1);
	myTree.addNode('c', 1);
	myTree.addNode('d', 1);

	myTree.addNode('e', 1);
	myTree.addNode('f', 1);

	myTree.addNode('g', 1);

	myTree.addNode('h', 1);
	myTree.addNode('i', 2);

	myTree.addNode('j', 2);

	myTree.addNode('k', 1);

	myTree.printTree(myTree.getRoot(), 0);



	cout << endl;
	system("pause");
	return 0;
}