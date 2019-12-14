//
// Created by mi on 13.12.2019.
//

#ifndef NEWTON_FUNCTION_H
#define NEWTON_FUNCTION_H

#include "head.h"
#include "Complex.h"

class Function {
private:
    std::vector<double> funcCoef, derCoef;
    long polyOrder;
public:
    Function(const long &order);

    void calcDerivative();

    Complex f(const Complex &z0);

    Complex fDer(const Complex &z0);

    Complex newton(const Complex &z0, const double reqPrecision,
                  const long maxSteps);

    void enterPoly();

    void printPoly();

};


#endif //NEWTON_FUNCTION_H
