#include "classes.h"
#include "functions.h"
void Train::set_train() {
    cout << "Enter train number: ";
    num=checker(0);
    cout << "Enter destination: ";
    cin >> destination;
    cout << "Enter destination hour of departure: ";
    destination_t.hours = checker(1);
    cout << "Enter destination minute of departure: ";
    destination_t.minutes = checker(2);
}

void Train::print() {
    cout << "\nTrain number: " << num << endl;
    cout << "Destination: " << destination << endl;
    if (destination_t.minutes < 10) {
        cout << "Destination time: " << destination_t.hours << ":" << destination_t.minutes<<"0"<< endl;
    }
    else {
        cout << "Destination time: " << destination_t.hours << ":"<< destination_t.minutes << endl;
    }
}

string Train::get_dest() {
    return destination;
}

int Train::get_num() {
    return num;
}

Time Train::dest_t() {
    return destination_t;
}