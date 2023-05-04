#pragma once
#include "classes.h"
#include <iomanip>
int checker(int mode);
void create_obj(int triangels_quant, EqTriangle*& triangle1, int& triangle1_size, IsTriangle*& triangle2, int& triangle2_size, RtTriangle*& triangle3, int& triangle3_size);
void output_info(int mode, EqTriangle*& triangle1, int& triangle1_size, IsTriangle*& triangle2, int& triangle2_size, RtTriangle*& triangle3, int& triangle3_size);

