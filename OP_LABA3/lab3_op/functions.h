#pragma once
#include "classes.h"
#include<iostream>
#include <iomanip>
using namespace std;
//��������� ������ ��'����
Train* create_obj(int quantity);
//��������� ������ ��'����
void print_info(Train* obj, int quantity);
//�������� ���� �����������
void hourequaler(Train* obj, int quantity);
//����������� �����
int checker( int mode);