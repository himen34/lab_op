#ifndef LAB1_FUNCTIONS_H
#define LAB1_FUNCTIONS_H
#endif //LAB1_FUNCTIONS_H
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//функція для створення та запису у файл
string create_makenote(short mode); 

//функція для зашифрування рядків 
string encrypter(string &g);

//функція для перезапису парних рядків
string checkevenstring(string& firstfile);

//функція для видалення літери, яку ми вводимо з клавіатури
void eraseletter(string &filename);

//функція для зчитування та виведення вмісту файлу
void readFile(string &filename);

//функція для вибору '0' або '1'
short picker();

//функція для компактного запису функцій 
void programprogress(short mode);
