#include "solver.hpp"


namespace solver{
    double solve(RealExpression expression){
        return expression.x->data;
    }
    std::complex<double> solve(ComplexExpression expression){
        return expression.x->comp;
    }
};

