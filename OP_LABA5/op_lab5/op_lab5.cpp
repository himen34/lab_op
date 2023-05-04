#include <iostream>
#include <time.h>
#include "functions.h"
#include "classes.h"
using namespace std;
int main()
{
    setlocale(0, "russian");
    srand(time(0));
    int triangels_quant;
    cout << "¬ведiть кiлькiсть трикутникiв(хоча б 3): ";
    EqTriangle* triangle1 = nullptr;
    IsTriangle* triangle2 = nullptr;
    RtTriangle* triangle3 = nullptr;
    int triangle1_size, triangle2_size, triangle3_size;
    triangels_quant = checker(0);
    create_obj(triangels_quant, triangle1, triangle1_size, triangle2, triangle2_size, triangle3, triangle3_size);
    output_info(0,triangle1,triangle1_size, triangle2,triangle2_size,triangle3, triangle3_size);
    output_info(1, triangle1, triangle1_size, triangle2, triangle2_size, triangle3, triangle3_size);
}


