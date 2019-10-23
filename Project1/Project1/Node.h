#pragma once

#include <vector>

using namespace std;

class Node {
private:
	char val;
	vector<Node*> children;
public:
	Node() {
		val = NULL;
	}
	Node(char v) {
		val = v;
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
	void setValue(char v) {
		val = v;
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

