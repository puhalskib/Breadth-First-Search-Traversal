#pragma once

#include "Node.h"
#include <time.h>
#include <iostream>

class Tree {
private:
	Node* root = NULL;
public:
	Tree(char v) {
		root = new Node(v);
	}
	Node* getRoot() {
		return root;
	}
	//addNode() function adds children randomly too the tree
	void addNode(char v, int depth) {
		Node * trv = new Node();
		trv = root;
		//generate random seed
		srand(time(NULL));
		for (int i = 0; i < depth; i++) {
			if (trv->isLeaf()) {
				trv->newChild(new Node(v));
				trv = nullptr;
				delete trv;
				return;
			}
			//choose a random child
			trv = trv->getChild(rand());
		}
		trv->newChild(new Node(v));
		trv = nullptr;
		delete trv;
	}
	//prints the tree recursively using tabs to distinguish children
	void printTree(Node* r, int tabs) {
		//print tabs
		for (int i = 0; i < tabs; i++) {
			std::cout << "\t";
		}
		std::cout << r->getValue() << "\n";
		for (unsigned int i = 0; i < r->getChildren().size(); i++) {
			printTree(r->getChild(i), tabs + 1);
		}
	}
};