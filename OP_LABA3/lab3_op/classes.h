#pragma once
#include<iostream>
#include <iomanip>
using namespace std;
struct Time
{
    int hours;
    int minutes;
};

class Train
{
    int num;
    string destination;
    Time destination_t;

public:
    void set_train();
    void print();
    string get_dest();
    int get_num();
    Time dest_t();
};