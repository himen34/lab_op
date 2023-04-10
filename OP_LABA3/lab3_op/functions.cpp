#include "functions.h"
class Train;
Train* create_obj(int quantity)
{
	int num, hour, minute;
	string destination;
	Train* trains = new Train[quantity];
	for (int i = 0; i < quantity; i++) {
		cout << "Enter information for train " << i + 1 << ":" << endl;
		trains[i].set_train();
	}
	return trains;
}

void print_info(Train* obj,int quantity)
{
	for (int i = 0; i < quantity; i++) {
		obj[i].print();
		cout << endl;
	}
}
void hourequaler(Train* obj, int quantity)
{
	int hour1, hour2,counter=0;
	cout << "Enter the range of hours :" << endl;
	hour1 = checker(1);
	hour2 = checker(1);
	cout << "Available trains :" << endl;
	for (int i = 0; i < quantity; i++) {
		if (obj[i].dest_t().hours >= hour1 && obj[i].dest_t().hours < hour2)
		{
			obj[i].print();
			cout << endl;
			counter++;
		}
	}
	if (counter == 0)
	{
		cout << "There is not an available trains."<<endl;
	}
}
int checker(int mode) {
	int number;
	bool valid_input = false;
	do {
		cin >> number;
		switch (mode) {
		case 0:
			if (number > 0) valid_input = true;
			break;
		case 1:
			if (number >= 0 && number <= 23) valid_input = true;
			break;
		case 2:
			if (number >= 0 && number <= 59) valid_input = true;
			break;
		default:
			valid_input = false;
			break;
		}
		if (!valid_input) {
			cout << "Error! Rewrite a value: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!valid_input);
	return number;
}