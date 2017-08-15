#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;

struct WordNode {
	ItemType m_data;
	WordNode *m_left;
	WordNode *m_right;
	// You may add additional data members and member functions in WordNode
	WordNode(ItemType dataValue) {
		m_data = dataValue;
		m_left = nullptr;
		m_right = nullptr;
	}
};

class WordTree {

private:
	WordNode *root;

public:

	// default constructor            
	WordTree() : root(nullptr) { };

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


void WordTree::add(ItemType v) {
	WordNode* b = root;

	// Base case: tree is empty
	if (b==nullptr ) {
		b->m_data = v;
			return;
	}

	// Otherwise, find its proper position
	while (true) {
		// Case: Data is less than current node
		if (v < b->m_data) {
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










int main() {

}