#include <iostream>
#include <string>
using namespace std;

typedef string ItemType;

struct WordNode {
	ItemType m_data;
	WordNode *m_left;
	WordNode *m_right;
	// You may add additional data members and member functions in WordNode
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