#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <list>

using namespace std;

struct Date
{
    int day, month, year;
};
struct CarDetails
{
    char name[120];
    Date releasedate;
    Date selldate;
};

string create_write_binary();
void firsttask(const string& filename, Date& today);
void secondtask(const string& filename);
void parser(string& date, int arr[]);
int checkisvaliddate(int day, int month, int year);
void printCarDetails(const CarDetails& car);