#include "head.h"
#include "Function.h"
#include "Complex.h"

int main() {

    long maxSteps = 100;
    double reqPrecision = 0.01;
    long order;

    double xRangeMin = -5;
    double xRangeMax = 5;
    double yRangeMin = -5;
    double yRangeMax = 5;

    //number of points in range
    long xResolution = 5;
    long yResolution = 5;

    std::cout << "Enter polynomial order: ";
    std::cin >> order;
    std::cout << std::endl;

    //function
    Function function(order);
    function.printPoly();

    //z0 z0'
    std::vector<std::vector<double>>
            XY(4, std::vector<double>((xResolution+1)*(yResolution+1), 0));
    //
    long posCounter = 0;
    Complex result(0, 0);
    Complex z0(0, 0);
    for (long i = 0; i <= yResolution; ++i) {
        for (long j = 0; j <= xResolution; ++j) {
            z0.setRe(xRangeMin + (xRangeMax - xRangeMin) / xResolution * j);
            z0.setIm(yRangeMin + (yRangeMax - yRangeMin) / yResolution * i);

            result = function.newton(z0, reqPrecision, maxSteps);
            XY[0][posCounter] = z0.getRe();
            XY[1][posCounter] = z0.getIm();
            XY[2][posCounter] = result.getRe();
            XY[3][posCounter] = result.getRe();
            ++posCounter;
        }
    }


    draw(XY,xRangeMin,xRangeMax,yRangeMin,yRangeMax);

    return 0;
}
