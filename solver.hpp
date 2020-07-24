#pragma once

#include "RealVariable.hpp"
#include "ComplexVariable.hpp"


namespace solver {
    double solve(RealExpression expression);
    std::complex<double> solve(ComplexExpression expression);
};