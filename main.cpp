#include "head.h"
#include "Function.h"

void draw(const std::vector<std::vector<double>> &XY,
          Function &function,
          const double xRangeMin, const double xRangeMax,
          const double yRangeMin, const double yRangeMax);

int main() {

    long maxSteps = 100;
    double reqPrecision = 0.01;
    long order;

    //area to take values from
    //yRange is imaginary part range
    double xRangeMin = -5;
    double xRangeMax = 5;
    double yRangeMin = -5;
    double yRangeMax = 5;

    //number of points in range
    long xResolution = 400;
    long yResolution = 400;

//    std::cout << "Enter polynomial order: ";
//    std::cin >> order;
//    std::cout << std::endl;
    order = 4;

    //function
    Function function(order);
    function.printPoly();

    //array consists of Re(z0) Im(z0) Re(z') Im(z')
    //where z0 - initial point, z' - convergence point
    std::vector<std::vector<double>>
            XY(4, std::vector<double>((xResolution + 1) * (yResolution + 1), 0));
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
            XY[3][posCounter] = result.getIm();
            ++posCounter;
        }
    }

    //does graphics
    draw(XY, function, xRangeMin, xRangeMax, yRangeMin, yRangeMax);

    return 0;
}

