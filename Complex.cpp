//
// Created by mi on 13.12.2019.
//

#include "Complex.h"

Complex sumC(const Complex z1, const Complex z2) {
    double re, im;
    re = z1.getRe() + z2.getRe();
    im = z1.getIm() + z2.getIm();
    Complex ans(re, im);
    return ans;
}

Complex prodC(const Complex z1, const Complex z2) {
    double re, im;
    double a = z1.getRe(), b = z1.getIm();
    double c = z2.getRe(), d = z2.getIm();
    re = a * c - b * d;
    im = b * c + a * d;
    Complex ans(re, im);
    return ans;
}

Complex powC(const Complex z, const long power) {
    Complex ans(1,0);
    for (long i = 0; i < power; ++i) {
        ans = prodC(ans, z);
    }
    return ans;
}

Complex divideC(const Complex z1, const Complex z2) {
    double re, im;
    double a = z1.getRe(), b = z1.getIm();
    double c = z2.getRe(), d = z2.getIm();
    re = (a * c + b * d) / (c * c + d * d);
    im = (b * c - a * d) / (c * c + d * d);
    Complex ans(re, im);
    return ans;
}