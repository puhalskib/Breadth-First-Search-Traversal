#pragma once

#include <vector>

using namespace std;

class Node {
private:
	char val;
	Node* parent = NULL;
	vector<Node*> children;
public:
	Node(char v) {
		val = v;
	}
	Node(char v, Node* p) {
		val = v;
		parent = p;
	}
	Node* getParent() {
		return parent;
	}
	vector<Node*> getChildren() {
		return children;
	}
	Node* getChild(int i) {
		i = i % children.size();
		return children[i];
	}
	char getValue() {
		return val;
	}
	void newChild(Node* nPtr) {
		children.push_back(nPtr);
	}
	bool isLeaf() {
		if (children.empty()) {
			return true;
		}
		else {
			return false;
		}
	}
};

