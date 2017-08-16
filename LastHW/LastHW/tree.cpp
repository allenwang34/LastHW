#include <iostream>
#include <string>
#include<assert.h>
using namespace std;

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
#ifdef _DEBUG

#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)

#define new DEBUG_NEW

#endif


typedef string ItemType;

struct WordNode {
	ItemType m_data;
	WordNode *m_left;
	WordNode *m_right;
	int m_duplicatedNum;
	// You may add additional data members and member functions in WordNode
	WordNode(ItemType dataValue) {
		m_data = dataValue;
		m_left = nullptr;
		m_right = nullptr;
		m_duplicatedNum = 1;
	}
};

class WordTree {

private:
	WordNode *root;
	int CountDistinctNode(WordNode* Node) const;
	int CountTotalInput(WordNode* Node) const;
	void Destory(WordNode*& root);
	friend void print(ostream &out, WordNode* Node);
	void copyWordNode(WordNode*& thisNode, WordNode* otherNode);

public:

	// default constructor            
	WordTree() : root(nullptr)  {};

	// copy constructor
	WordTree(const WordTree& rhs);

	// assignment operator
	const WordTree& operator=(const WordTree& rhs);

	// Inserts v into the WordTree    
	void add(ItemType v);

	// Returns the number of distince words / nodes   
	int distinctWords() const;

	// Returns the total number of words inserted, including duplicate
	// values    
	int totalWords() const;

	// Prints the LinkedList 
	friend ostream& operator<<(ostream &out, const WordTree& rhs);

	// Destroys all the dynamically allocated memory
	// in the tree.
	~WordTree();
};


int WordTree::CountDistinctNode(WordNode* Node) const {
	if (Node == nullptr)
		return 0;
	return 1 + CountDistinctNode(Node->m_left) + CountDistinctNode(Node->m_right);
}


int WordTree::CountTotalInput(WordNode* Node) const {
	if (Node == nullptr)
		return 0;
	if (Node->m_duplicatedNum == 0)
		return 1 + CountTotalInput(Node->m_left) + CountTotalInput(Node->m_right);
	else
		return Node->m_duplicatedNum + CountTotalInput(Node->m_left) + CountTotalInput(Node->m_right);
}

int WordTree::totalWords() const {
	return CountTotalInput(root);
}


int WordTree::distinctWords() const {
	return CountDistinctNode(root);
}

void WordTree::add(ItemType v) {
	WordNode* b = root;
	// Base case: tree is empty
	if (b==nullptr ) {
		root = new WordNode(v);
			return;
	}

	// Otherwise, find its proper position
	while (true) {
		if (v == b->m_data) {
			b->m_duplicatedNum++;
			return;
		}
		// Case: Data is less than current node
		else if (v < b->m_data) {
			// If there's already a node left...
			if (b->m_left!=nullptr) {
				// Then continue down the tree
				b = b->m_left;
					
			}		// Otherwise, no node to left, so insert:
			else {
				b->m_left = new WordNode(v);
				return;
			}

			// Case: Data is greater than / equal to node
		}
		else {
			if (b->m_right!=nullptr) {
				b = b->m_right;
			}
			else {
				b->m_right = new WordNode(v);
				return;
			}
		}
	}
}


void WordTree::copyWordNode(WordNode*& thisNode, WordNode* otherNode) {
	if (otherNode == nullptr)
		thisNode = nullptr;
	else {
		thisNode = new WordNode(otherNode->m_data);
		thisNode->m_duplicatedNum = otherNode->m_duplicatedNum;
		copyWordNode(thisNode->m_left, otherNode->m_left);
		copyWordNode(thisNode->m_right, otherNode->m_right);
	}
}


WordTree::WordTree(const WordTree& rhs) {
	if (rhs.root == nullptr)
		root = nullptr;
	else {
		copyWordNode(root, rhs.root);
	}


}
void print(ostream &out, WordNode* Node) {
	if (Node == nullptr)
		return;

	print(out, Node->m_left);
	out << Node->m_data << " " << Node->m_duplicatedNum << endl;
	print(out, Node->m_right);

}

ostream& operator<<(ostream &out, const WordTree& rhs) {
	print(out, rhs.root);
	return out;
}

const WordTree& WordTree::operator=(const WordTree& rhs) {
	copyWordNode(root, rhs.root);
	return *this;
}


void WordTree::Destory(WordNode*& Node) {
	if (Node != nullptr) {
		Destory(Node->m_left);
		Destory(Node->m_right);
		delete Node;
	}
}

WordTree::~WordTree() {
	Destory(root);
}





int main() {
	WordTree t;

	/*t.add("Skyler");
	t.add("Walter");
	t.add("Walter");
	t.add("Walter");

	assert(t.distinctWords() == 2);
	assert(t.totalWords() == 4);
	cout << "Test Passed!" << endl;*/

	t.add("Skyler");
	t.add("Walter");
	t.add("Walter");
	t.add("Hank");
	t.add("Gus");
	t.add("Walter");
	t.add("Gus");

	//WordTree t2(t);
	WordTree t2 = t;
	cout << t;
	cout << endl;
	cout << t2;


	_CrtDumpMemoryLeaks();
	return 0;

}