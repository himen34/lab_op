#pragma once
#include "classes.h"
#include<iostream>
#include <iomanip>
using namespace std;
//створення масиву об'єктів
Train* create_obj(int quantity);
//виведення масиву об'єктів
void print_info(Train* obj, int quantity);
//перевірка часу відправлення
void hourequaler(Train* obj, int quantity);
//правильність вводу
int checker( int mode);