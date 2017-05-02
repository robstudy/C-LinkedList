#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	public:
	void push_front(T data);
	void push_back(T data);
	void remove(T data);
	void print();
	bool search(T data);
	unsigned int list_size();
	private:	
	struct Node {
		Node *next;
		Node *back;
		T data;
		Node(Node *n = NULL, Node *b = NULL, T d = NULL):
			next(n),
			back(b),
			data(d){}
	};
	Node *head;
	Node *tail;
	unsigned int size;
};

template <class T>
void LinkedList<T>::push_front(T data) {

	Node *newNode = new Node(head, NULL, data);

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		head = newNode;
	}
	size++;
};

template <class T>
void LinkedList<T>::push_back(T data) {

	Node *newNode = new Node(NULL, tail, data);

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		tail = newNode;
	}	
	size++;
};

template <class T>
unsigned int LinkedList<T>::list_size() {
	return size;
};
