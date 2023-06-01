#include "BasicFunctions.h"
void ProgRunner(string type) {
	if (type == "float") {
		CDoubleLinkedList<float> List;
		CDoubleLinkedList<float>::Iterator iter2 = List.begin();
		listrunner(List, iter2);
	}
	if (type == "char") {
		CDoubleLinkedList<char> List;
		CDoubleLinkedList<char>::Iterator iter2 = List.begin();
		listrunner(List, iter2);
	}
	else if (type == "int") {
		CDoubleLinkedList<int> List;
		CDoubleLinkedList<int>::Iterator iter2 = List.begin();
		listrunner(List, iter2);
	}
	else if (type == "string") {
		CDoubleLinkedList<string> List;
		CDoubleLinkedList<string>::Iterator iter2 = List.begin();
		listrunner(List, iter2);
	}
	else if (type == "double") {
		CDoubleLinkedList<double> List;
		CDoubleLinkedList<double>::Iterator iter2 = List.begin();
		listrunner(List, iter2);
	}
	else {
		cout << "List can`t be created with this type" << endl;
	}
}
int checker() {
	int number;
	bool valid_input = false;
	do {
		cin >> number;
			if (number >= 1 && number <= 10) valid_input = true;
		if (!valid_input) {
			cout << "Error! Rewrite a value: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!valid_input);
	return number;
}
