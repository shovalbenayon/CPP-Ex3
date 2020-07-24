#pragma once
#include <iostream>
#include <cmath>

namespace solver {
	struct RealVariable{
		double data;
	};
	
	struct RealExpression {
		double a;     // coefficient of x^2
		double b;     // coefficient of x
		double c;     // free coefficient
        struct RealVariable* x; //Store the value of x

		RealExpression() {
            a = 0;
			b = 0;
			c = 0;
		}

		RealExpression(double c) {
            a = 0;
			b = 0;
			this->c = c;
			x = 0;
		}
		RealExpression(RealVariable& x) {
			a = 0;
			b = 1;
			c = 0;
			this->x = &x;
		}

        
	};

	RealExpression operator + (RealExpression x, RealExpression y);
    RealExpression operator + (double x, RealExpression y);
    RealExpression operator + (RealExpression x, double y);

	RealExpression operator - (RealExpression x, RealExpression y);
    RealExpression operator - (double x, RealExpression y);
    RealExpression operator - (RealExpression x, double y);

	RealExpression operator * (RealExpression x, RealExpression y);
    RealExpression operator * (RealExpression x, double y);
    RealExpression operator * (double x, RealExpression y);

	RealExpression operator == (RealExpression x, RealExpression y);
    RealExpression operator == (RealExpression x, double y);

	RealExpression operator / (RealExpression x, double y);

	RealExpression operator ^ (RealExpression x, double y);
	
};