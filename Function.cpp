//
// Created by mi on 13.12.2019.
//

#include "Function.h"
#include "Complex.h"

Function::Function(const long &order) {
    funcCoef.resize(order);
    derCoef.resize(order - 1);
    polyOrder = order;
    funcCoef[0] = -1;
    funcCoef[1] = 0;
    funcCoef[2] = 0;
    funcCoef[3] = 1;
    calcDerivative();
}

void Function::calcDerivative() {
    for (long i = 0; i < polyOrder - 1; ++i) {
        derCoef[i] = funcCoef[i + 1] * (i + 1);
    }
}

void Function::enterPoly() {
    for (long i = 0; i < polyOrder; ++i) {
        std::cout << "Enter x^" << i << " coefficient: " << std::endl;
        std::cin >> funcCoef[i];
    }
}

void Function::printPoly() {
    std::string sign;
    std::cout << "Polynomial: " << std::endl;
    for (long i = 0; i < polyOrder; ++i) {
        if (funcCoef[i] >= 0) {
            sign = "+";
        } else {
            sign = "-";
        }
        std::cout << " " + sign + " " << std::abs(funcCoef[i]) << " * x^" << i << "";
    }

    std::cout << std::endl << "Derivative: " << std::endl;
    for (long i = 0; i < polyOrder - 1; ++i) {
        if (funcCoef[i] >= 0) {
            sign = "+";
        } else {
            sign = "-";
        }
        std::cout << " " + sign + " " << std::abs(derCoef[i]) << " * x^" << i << "";
    }
    std::cout << std::endl;
}

Complex Function::f(const Complex &z0) {
    Complex out(0, 0);
    for (long i = 0; i < polyOrder; ++i) {
        Complex coef(funcCoef[i], 0);
        Complex coefProdZ = prodC(coef, powC(z0, i));
        out = sumC(out, coefProdZ);
    }
    return out;
}

Complex Function::fDer(const Complex &z0) {
    Complex out(0, 0);
    for (long i = 0; i < polyOrder - 1; ++i) {
        Complex coef(derCoef[i], 0);
        out = sumC(out, prodC(coef, powC(z0, i)));
    }
    return out;
}

Complex Function::newton(const Complex &z0, const double reqPrecision,
                         const long maxSteps) {
    long N = 0;
    Complex z = z0;
    //std::cout << "Z0 = ";
    // z.print();

    while (true) {
        if (fDer(z).getRe() == 0 && fDer(z).getIm() == 0) {
            //std::cout << "Derivative in z0 equal to zero. Ans is set to 0 + 0i" << std::endl;
            return Complex(0, 0);
        }
        if (f(z).absC() <= reqPrecision) {
            //std::cout << "Required precision achieved in " << N <<
            //          " steps. current root z = ";
            // z.print();

            return z;
        }
        if (N >= maxSteps) {
            //std::cout << "MaxSteps achieved. Current root x = ";
            //z.print();
            return z;
        }
        z = sumC(z,
                 prodC(Complex(-1, 0),
                       divideC(f(z), fDer(z))
                 )
        );
        ++N;
    }
}

