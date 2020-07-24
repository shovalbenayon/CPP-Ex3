#pragma once
#include <complex>
#include <iostream>
#include <cmath>

namespace solver {
	struct ComplexVariable{
		std::complex<double> comp;
	};
	
	struct ComplexExpression {
		std::complex<double> a;     // coefficient of x^2
		std::complex<double> b;     // coefficient of x
		std::complex<double> c;     // free coefficient
        struct ComplexVariable* x; //Store the value of x

		ComplexExpression() {
            a = 0;
			b = 0;
			c = 0;
		}

		ComplexExpression(std::complex<double> c) {
            a = 0;
			b = 0;
			this->c = c;
			x = 0;
		}
		ComplexExpression(ComplexVariable& x) {
			a = 0;
			b = 1;
			c = 0;
			this->x = &x;
		}

        
	};

	ComplexExpression operator + (ComplexExpression x, ComplexExpression y);
    ComplexExpression operator + (std::complex<double> x, ComplexExpression y);
    ComplexExpression operator + (ComplexExpression x, std::complex<double> y);

	ComplexExpression operator - (ComplexExpression x, ComplexExpression y);
    ComplexExpression operator - (std::complex<double> x, ComplexExpression y);
    ComplexExpression operator - (ComplexExpression x, std::complex<double> y);

	ComplexExpression operator * (ComplexExpression x, ComplexExpression y);
    ComplexExpression operator * (ComplexExpression x, std::complex<double> y);
    ComplexExpression operator * (std::complex<double> x, ComplexExpression y);

	ComplexExpression operator == (ComplexExpression x, ComplexExpression y);
    ComplexExpression operator == (ComplexExpression x, std::complex<double> y);

	ComplexExpression operator / (ComplexExpression x, std::complex<double> y);

	ComplexExpression operator ^ (ComplexExpression x, std::complex<double> y);
	
};
std::ostream& operator << (std::ostream& os, const std::complex<double> comp);