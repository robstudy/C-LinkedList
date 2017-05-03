#include <iostream>
using namespace std;

template <class T>
class LinkedList {
	public:
	LinkedList<T>();
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	void remove(T data);
	void print();
	bool search(T data);
	unsigned int list_size();
	T front();
	T back();
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
LinkedList<T>::LinkedList() {
	head = NULL;
	tail = NULL;
	size = 0;
};

template <class T>
void LinkedList<T>::push_front(T data) {

	Node *newNode = new Node(head, NULL, data);

	if (head == NULL) {
		head = newNode;
		tail = newNode;
	} else {
		head->back = newNode;
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
		tail->next = newNode;
		tail = newNode;
	}	
	size++;
};

template <class T>
void LinkedList<T>::pop_front() {
	
	if (size == 0) return;
	head = head->next;
	head->back = NULL;
	delete head->back;
	size--;
};

template <class T>
void LinkedList<T>::pop_back() {
	
	if (size == 0) return;
	tail = tail->back;
	tail->next = NULL;
	delete tail->next;
	size--;
};

template <class T>
void LinkedList<T>::remove(T data) {

	if (size == 0) return;	
	Node *temp = head;
	
	if (head->data == data) {
		head = head->next;
		temp->next = NULL;
		delete temp;
		size--;
		return;
	} else if (tail->data == data) {
		tail = tail->back;
		tail->next = NULL;
		delete tail->next;
		size--;
		return;
	}
	
	while (temp != NULL) {
		if (data == temp->data) {
			temp->back->next = temp->next;
			temp->back = NULL;
			temp->next = NULL;
			delete temp;
			size--;
			return;
		}
		temp = temp->next;
	}
};

template <class T>
void LinkedList<T>::print() {

	Node *temp = head;

	while (temp != NULL) {
		cout << temp->data << endl;
		temp = temp->next;
	}
};

template <class T>
bool LinkedList<T>::search(T data) {

	Node *temp = head;

	while (temp != NULL) {
		if (data == temp->data) return true;
		temp = temp->next;
	}
	
	return false;
};

template <class T>
unsigned int LinkedList<T>::list_size() {
	return size;
};

template <class T>
T LinkedList<T>::front() {
	return head->data;
};

template <class T>
T LinkedList<T>::back() {
	return tail->data;
};
