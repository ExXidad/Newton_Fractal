//
// Created by mi on 13.12.2019.
//

#ifndef NEWTON_COMPLEX_H
#define NEWTON_COMPLEX_H

#include "head.h"

class Complex {
private:
    double Re;
    double Im;
public:
    Complex(const double re, const double im) {
        Re = re;
        Im = im;
    }

    void print();

    void enterNumber();

    double absC();


    double getRe() const {
        return Re;
    }

    void setRe(double re) {
        Re = re;
    }

    double getIm() const {
        return Im;
    }

    void setIm(double im) {
        Im = im;
    }
};

Complex sumC(const Complex z1, const Complex z2);

Complex prodC(const Complex z1, const Complex z2);

Complex powC(const Complex z, const long power);

Complex divideC(const Complex z1, const Complex z2);

#endif //NEWTON_COMPLEX_H
