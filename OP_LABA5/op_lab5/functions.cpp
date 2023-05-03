#include "functions.h"
int checker(int mode) {
    int number;
    bool valid_input = false;
    do {
        cin >> number;
        switch (mode) {
        case 0:
            if (number > 2) valid_input = true;
            break;
        case 1:
            if (number >= 0 && number <= 23) valid_input = true;
            break;
        case 2:
            if (number >= 0 && number <= 59) valid_input = true;
            break;
        default:
            valid_input = false;
            break;
        }
        if (!valid_input) {
            cout << "Помилка! Перезапишiть змiнну: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!valid_input);
    return number;
}
void create_obj(int triangels_quant, EqTriangle*& triangle1, int& triangle1_size, IsTriangle*& triangle2, int& triangle2_size, RtTriangle*& triangle3, int& triangle3_size) {
    int temp_quant = rand() % (triangels_quant / 2) + 1;
    triangels_quant -= temp_quant;
    triangle1 = new EqTriangle[temp_quant];
    triangle1_size = temp_quant;
    temp_quant = rand() % (triangels_quant - 1) + 1;
    triangle2 = new IsTriangle[temp_quant];
    triangle2_size = temp_quant;
    triangels_quant -= temp_quant;
    triangle3 = new RtTriangle[triangels_quant];
    triangle3_size = triangels_quant;;
}
void output_info(int mode,EqTriangle*& triangle1, int& triangle1_size, IsTriangle*& triangle2, int& triangle2_size, RtTriangle*& triangle3, int& triangle3_size) {
    double flag1=0,flag2=0,flag3;
    for (int i = 0; i < triangle1_size; i++) {
        if (mode == 0) {
            triangle1[i].printTriangle();
            cout << endl;
        }
        else {
            flag1 += triangle1[i].square();
        }
    }
    
    for (int i = 0; i < triangle2_size; i++) {
        if (mode == 0) {
            triangle2[i].printTriangle();
            cout << endl;
        }
        else {
            flag2 += triangle2[i].perimetr();
        }
    }

    for (int i = 0; i < triangle3_size; i++) {
        if (mode == 0) {
            triangle3[i].printTriangle();
            cout << endl;
        }
        else{
            flag1 += triangle3[i].square();
        }
    }
    if (mode == 1) {
        cout << "Сума площ для рiвностороннiх та прямокутних трикутникiв:" << flag1<<endl;
        cout << "Сума периметрiв для рiвнобедренних трикутникiв:" << flag2 << endl;
    }
}  
