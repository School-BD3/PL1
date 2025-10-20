#include "root.h"
#include <cmath>

bool calc(double x, double& y, std::string& err) {
    if (x <= 0) {
        err = "log(x) не визначений для x <= 0";
        return false;
    }

    double denom = 1.0 + cos(x);
    if (std::fabs(denom) < 1e-12) {
        err = "Ділення на нуль (1 + cos(x) = 0)";
        return false;
    }

    double A = (x * std::log(x)) / denom + 1.0;

    if (A < -1.0 || A > 1.0) {
        err = "Аргумент asin поза межами [-1, 1]";
        return false;
    }

    y = std::asin(A);
    return true;
}
