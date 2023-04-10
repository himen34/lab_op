#include "functions.h"
#include "classes.h"

int main()
{
    int trains_quant;
    cout << "Enter amount of the trains: ";
    trains_quant=checker(0);
    Train* trains = create_obj(trains_quant);
    print_info(trains, trains_quant);
    hourequaler(trains, trains_quant);
    delete[] trains;
    return 0;
}