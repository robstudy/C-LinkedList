#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	public:
	LinkedList();
	void addFront(T data);
	void addBack(T data);
	private:	
	struct Node {
		Node *next;
		Node *back;
		T data;
	};
	Node *head;
	Node *tail;
	unsigned int size;
};



