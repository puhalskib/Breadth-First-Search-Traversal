#pragma once

#include "Node.h"
#include <time.h>

class Tree {
private:
	Node* root = NULL;
public:
	Tree(char v) {
		root = new Node(v);
	}
	//addNode() function adds children randomly too the tree
	void addNode(char v, int depth) {
		Node* trv = root;
		//generate random seed
		srand(time(NULL));
		for (unsigned int i = 0; i < depth; i++) {
			if (*trv->isLeaf) {
				Node * nNode = new Node(v, trv);
				trv->newChild(nNode);
				return;
			}
			//choose a random child
			trv = trv->getChild(rand());
		}
		Node * nNode = new Node(v, trv);
		trv->newChild(nNode);
	}
};