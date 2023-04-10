#include "functions_binary.h"

struct Date;

struct CarDetails;
string create_write_binary() {
    const string firstFile = "binfile.dat";
    int count = 0, arr[3], point;
    string data;
    bool checker = true;
    ofstream enter;
    enter.open(firstFile, fstream::binary);
    if (enter.is_open()) {
        Date today;
        cout << "File was successfully opened" << endl;
        while (checker) {
            CarDetails car;
            cout << "Enter the name of the car:" << endl;
            cin.getline(car.name, 120);
            do {
                cout << "Enter the date of car`s release (in xx.xx.xxxx format) :" << endl;
                cin >> data;
                parser(data, arr);
                car.releasedate.day = arr[0];
                car.releasedate.month = arr[1];
                car.releasedate.year = arr[2];
                point = checkisvaliddate(car.releasedate.day, car.releasedate.month, car.releasedate.year);
            } while (point);
            point = 0;
            cout << "Enter the date of car`s start selling (in xx.xx.xxxx format) :" << endl;
            do
            {
                cin >> data;
                parser(data, arr);
                car.selldate.day = arr[0];
                car.selldate.month = arr[1];
                car.selldate.year = arr[2];
                point = checkisvaliddate(car.selldate.day, car.selldate.month, car.selldate.year);
                if (car.releasedate.year > car.selldate.year ||
                    (car.releasedate.year == car.selldate.year && car.releasedate.month > car.selldate.month) ||
                    (car.releasedate.year == car.selldate.year && car.releasedate.month == car.selldate.month && car.releasedate.day > car.selldate.day))
                {
                    point = 0;
                    cout << "Selldate can't be lesser than release date. Please enter Selldate again: ";
                }
                else
                {
                    point = 1;
                }
            } while (point == 0);
            point = 0;
            enter.write((char*)(&car), sizeof(car));
            cout << "The info was successfully added to binary file. Enter '1' to add more info and '0' to see the results" << endl;
            cin >> count;
            cin.ignore();
            count == 0 ? checker = false : checker = true;
        }
        enter.close();
    }
    else {
        cout << "Error opening output file" << endl;
    }
    return firstFile;
}
void firsttask(const string& filename, Date& today)
{
    ifstream stream(filename, ios::binary);
    if (!stream)
    {
        cout << "\nError in opening file!";
    }
    else
    {
        CarDetails car;
        list<string> carList;

        const int maxLength = 20;
        string name = car.name;
        if (name.length() > maxLength) {
            name = name.substr(0, maxLength);
        }
        int namePadding = maxLength - name.length();
        int datePadding = 10;
        cout << "A list of cars that were put up to sale in this month:" << endl;
        while (!stream.eof() && stream.read((char*)&car, sizeof(CarDetails)))
        {

            if (car.selldate.year == today.year &&
                car.selldate.month == today.month)
            {
                string carInfo = "Car Info in list:" + string(2, ' ') + car.name
                    + string(2, ' ') + to_string(car.releasedate.day) + "."
                    + to_string(car.releasedate.month) + "." + to_string(car.releasedate.year)
                    + string(2, ' ') + to_string(car.selldate.day) + "."
                    + to_string(car.selldate.month) + "." + to_string(car.selldate.year);
                carList.push_back(carInfo);
                cout << carInfo << endl;
            }
        }
    }
    stream.close();
}
void secondtask(const string& filename)
{
    ifstream stream(filename, ios::binary);
    if (!stream)
    {
        cout << "\nError in opening file!";

    }
    else
    {
        CarDetails car;
        cout << "A list of cars that were created earlier than a year before they were put up for sale:" << endl;
        while (!stream.eof() && stream.read((char*)&car, sizeof(CarDetails)))
        {
            if (car.releasedate.year < car.selldate.year ||
                (car.releasedate.year == car.selldate.year && car.releasedate.month < car.selldate.month) ||
                (car.releasedate.year == car.selldate.year && car.releasedate.month == car.selldate.month && car.releasedate.day <= car.selldate.day))
            {
                {
                    printCarDetails(car);
                }
            }
        }
        stream.close();
    }
}
void parser(string& date, int arr[])
{
    stringstream unparsdate(date);
    size_t dot1_pos = date.find(".");
    size_t dot2_pos = date.rfind(".");

    string dayStr = date.substr(0, dot1_pos);
    string monthStr = date.substr(dot1_pos + 1, dot2_pos - dot1_pos - 1);
    string yearStr = date.substr(dot2_pos + 1);

    arr[0] = stoi(dayStr);
    arr[1] = stoi(monthStr);
    arr[2] = stoi(yearStr);
}
int checkisvaliddate(int day, int month, int year)
{
    int point = 0, Leapyear = 0;
    if (day <= 0)
    {
        printf("Your date is not correct!Rewrite it\n");
        point = 1;
    }
    if ((month <= 0) || (month > 12))
    {
        printf("Your month is not correct!Rewrite it\n");
        point = 1;
    }
    if ((year <= 0) || (year > 2023) || (year < 1822))
    {
        printf("Your year is not correct!Rewrite it\n");
        point = 1;
    }
    if (((year % 4 == 0) && (year % 100 != 0)) || ((year % 100 == 0) && (year % 400 ==
        0))) {
        Leapyear = 1;
    }
    else {
        Leapyear = 0;
    }
    if (((Leapyear == 0) && (month == 2) && (day > 28)) || ((Leapyear == 1) && (month
        == 2) && (day > 29))) {
        printf("\nThis day wasn`t exist!\n");
        point = 1;
    }

    if (((day > 31) && (month == 1 || 3 || 5 || 7 || 8 || 10 || 12)) || ((day > 30) && (month ==
        2 || 4 || 6 || 9 || 11))) {
        printf("\nThis day wasn`t exist!\n");
        point = 1;
    }
    return point;
}
void printCarDetails(const CarDetails& car) {
    const int maxLength = 20;
    string name = car.name;
    int namePadding = 20;
    int datePadding = 15;
    if (name.length() > maxLength) {
        name = name.substr(0, maxLength);
    }
    cout << left << setw(namePadding) << car.name
        << right << setw(datePadding) << car.releasedate.day << "." << car.releasedate.month << "." << car.releasedate.year
        << right << setw(datePadding) << car.selldate.day << "." << car.selldate.month << "." << car.selldate.year
        << endl;
}