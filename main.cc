#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

void uppercase(string &input) {
	for (unsigned int i = 0; i < input.size(); i++)
		input[i] = toupper(input[i]);
};

int main() {

	LinkedList<int> ll;
	string input;
	int digit;
	
	cout << "Test linked list with ints.\nCommands:"
		<< " PUSH, PUSHFRONT, REMOVE, POP, POPFRONT, PRINT, FRONT, BACK, SEARCH, QUIT\n";

	while (cin) {
		cin.clear();
		cin >> input;
		uppercase(input);
		if (input == "PUSH") {
			cin >> digit;
			ll.push_back(digit);
		} else if (input == "PUSHFRONT") {
			cin >> digit;
			ll.push_front(digit);
		} else if (input == "REMOVE") {
			cin >> digit;
			ll.remove(digit);
		} else if (input == "POP") {
			ll.pop_back();
		} else if (input == "POPFRONT") {
			ll.pop_front();
		} else if (input == "PRINT") {
			ll.print();
		} else if (input == "FRONT") {
			cout << ll.front() << endl;	
		} else if (input == "BACK") {
			cout << ll.back() << endl;	
		} else if (input == "SEARCH") {
			cin >> digit;
			if (ll.search(digit)) cout << digit << " in list.\n";
			else cout << digit << " not in list.\n";	
		}else if (input == "QUIT") {
			exit(EXIT_SUCCESS);
		}
	}

	return 0;
}
