#include <iostream>
#include "TPoint.h"
int main()
{
    double result;
    TPoint point1;
    TPoint point2(5, -3);
    TPoint point3(point2);
    point1.ShowPoint("First");
    point2.ShowPoint("Second");
    point3.ShowPoint("Third");
    ++point1;
    point2++;
    point1.ShowPoint("\nFirst "," after incrementation ");
    point2.ShowPoint("Second "," after incrementation ");
    result = point1 - point2;
    cout << "\nYour length between two points is " << result << endl;;
    point3.ShowPoint("\nThird");
    point3.checker();
}

