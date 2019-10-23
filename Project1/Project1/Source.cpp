#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <queue>

using namespace std;

Node breadthFirstSearch(Tree t, char c) {
	queue<Node*> q;
	q.push(t.getRoot());
	
	while (!q.empty()) {
		Node* v = q.front();
		q.pop();
		if (v->getValue() == c) {
			return *v;
		}
		for (int i = 0; i < v->getChildren().size(); i++) {
			q.push(v->getChild(i));
		}
	}
	return NULL;
}
void printPath(Node* p) {
	while (p->getParent() != NULL) {
		cout << p->getValue() << "->";
		p = p->getParent();
	}
	cout << p->getValue() << "\n";
}
char randAlphaNumberic() {
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	return alphanum[rand() % 62];
}


int main() {
	//generate random seed
	srand(time(NULL));

	Tree t('i');

	t.addNode('f', t.breadthFirstSearchPtr('i'));
	t.addNode('a', t.breadthFirstSearchPtr('f'));
	t.addNode('6', t.breadthFirstSearchPtr('a'));
	t.addNode('k', t.breadthFirstSearchPtr('f'));
	t.addNode('p', t.breadthFirstSearchPtr('i'));
	t.addNode('s', t.breadthFirstSearchPtr('p'));
	t.printTree(t.getRoot(), 0);

	char c;
	while (true) {
		cout << "Enter a value to search: ";
		cin >> c;
		printPath(&breadthFirstSearch(t, c));
	}
	int input,n, depth;
	char cInput;

	//get root char
	cout << "\n\nEnter a root char: ";
	cin >> cInput;
	Tree myTree(cInput);

	/*
	myTree.addNode('z', 0);
	myTree.addNode('b', 0);
	myTree.addNode('c', 0);
	myTree.addNode('d', 1);

	myTree.addNode('e', 1);
	myTree.addNode('f', 1);

	myTree.addNode('a', 1);

	myTree.addNode('h', 1);
	myTree.addNode('i', 2);

	myTree.addNode('j', 2);

	myTree.addNode('k', 1);

	myTree.addNode('x', 3);

	myTree.printTree(myTree.getRoot(), 0);

	printPath(&breadthFirstSearch(myTree, 'z'));
	*/

	
	do {
		cout << "\n1:Add a node \n2:Display Tree \n3:Search Tree \n4:Add Random node at random depth N times \n5:Exit\n";
		cin >> input;
		switch (input) {
		case 1:
			cout << "Enter a char: ";
			cin >> cInput;
			cout << "Enter a depth: ";
			cin >> depth;
			myTree.addNode(cInput, depth);
			break;
		case 2:
			myTree.printTree(myTree.getRoot(), 0);
			break;
		case 3:
			cout << "Enter a char to search: ";
			cin >> cInput;
			printPath(&breadthFirstSearch(myTree, cInput));
			break;
		case 4:
			cout << "Enter how many nodes to add: ";
			cin >> n;
			cout << "Enter max depth: ";
			cin >> depth;
			for (int i = 0; i < n; i++) {
				myTree.addNode(randAlphaNumberic(), rand() % depth);
			}
			break;
		default:
			cout << "please choose options 1-5";
			break;
		}
	} while (input != 5);



	cout << endl;
	system("pause");
	return 0;
}
