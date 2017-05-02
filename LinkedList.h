#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	public:
	void push_front(T data);
	void push_back(T data);
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



