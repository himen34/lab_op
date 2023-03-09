#define LAB2_FUNCTIONS_H
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <errno.h>
using namespace std;

//функція для створення та запису у файл
const char* create_makenote_c(short mode);

//функція для зашифрування рядків 
char* encrypt_c(char* line);

//функція для перезапису парних рядків
const char* checkevenchars_c(const char* filename);

//функція для видалення літери, яку ми вводимо з клавіатури
void erase_letter_c(const char* filename);

//функція для зчитування та виведення вмісту файлу
void readFile_c(const char* filename);

//функція для компактного запису функцій 
void programprogress_c(short mode);