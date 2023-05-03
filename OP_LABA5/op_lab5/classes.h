#pragma once
#include<iostream>
#include <iomanip>
#include <cmath>
using namespace std;
class Triangle
{
protected:
    int a,b,c;
public:
    Triangle() {
    };
    virtual void printTriangle() = 0;
};
class EqTriangle : public Triangle {
public:
    EqTriangle();
    double square() ;
    void printTriangle() override;
};
class IsTriangle : public Triangle {
public:
    IsTriangle();
    int perimetr() ;
    void printTriangle() override;
};
class RtTriangle : public Triangle {
public:
    RtTriangle();
    double square() ;
    void printTriangle() override;
};

