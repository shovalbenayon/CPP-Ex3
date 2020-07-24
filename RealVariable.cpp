#include "RealVariable.hpp"
using namespace std;


namespace solver{
    RealExpression operator + (RealExpression x, RealExpression y){
        RealExpression new_exp;
        new_exp.a = x.a + y.a;
        new_exp.b = x.b + y.b;
        new_exp.c = x.c + y.c;

        if(x.x == 0) 
            new_exp.x = y.x;
        else new_exp.x = x.x;

        return new_exp;
    }
    RealExpression operator + (double x, RealExpression y){
        return RealExpression(x) + y;

    }
    RealExpression operator + (RealExpression x, double y){
        return x + RealExpression(y);
    }

	RealExpression operator - (RealExpression x, RealExpression y){
        RealExpression new_exp;
        new_exp.a = x.a - y.a;
        new_exp.b = x.b - y.b;
        new_exp.c = x.c - y.c;

         if(x.x == 0) 
            new_exp.x = y.x;
        else new_exp.x = x.x;

        return new_exp;
    }
    RealExpression operator - (double x, RealExpression y){
        return RealExpression(x) - y;
    }
    RealExpression operator - (RealExpression x, double y){
        return x - RealExpression(y);
    }

	RealExpression operator * (RealExpression x, RealExpression y){
        RealExpression new_exp;

		new_exp.a = x.a * y.c + x.c * y.a + x.b * y.b;
		new_exp.b = x.b * y.c + y.b * x.c;
		new_exp.c = x.c * y.c;

		if (x.x != 0) 
            new_exp.x = x.x; 
		else new_exp.x = y.x;
		return new_exp;
    }
    RealExpression operator * (RealExpression x, double y){
    
        return x*RealExpression(y);

    }
    RealExpression operator * (double x, RealExpression y){

         return y*RealExpression(x);
    }

	RealExpression operator == (RealExpression x, RealExpression y){
        RealExpression new_exp = x - y;
		if (new_exp.a == 0) {
			if (new_exp.b == 0) 
                throw std::runtime_error("ERROR! can not divide by zero");
			new_exp.x->data = -new_exp.c/new_exp.b; // Linear form
			return new_exp;
		}

		double determinant = new_exp.b * new_exp.b - 4 * new_exp.a * new_exp.c; // Polynomial form
		if (determinant < 0) 
            throw std::runtime_error("ERROR! there is no real solution");
		new_exp.x->data = (-new_exp.b + sqrt(determinant)) / (2 * new_exp.a); // A single solution is required
		return new_exp;

    }
    RealExpression operator == (RealExpression x, double y){

        return x == RealExpression(y);

    }

	RealExpression operator / (RealExpression x, double y){
        if(y == 0) throw std::invalid_argument("Error! cannot divide bt zero");
        x.a /= y;
        x.b /= y;
        x.c /= y;

        return x;

    }
    
	RealExpression operator ^ (RealExpression x, double y){
        if(y != 2) throw std::invalid_argument("Error! Only second degree is available");
        
        RealExpression new_exp;
        new_exp.a = x.b * x.b;
        new_exp.b = 2 * x.b * x.c;
        new_exp.c = x.c * x.c;

        new_exp.x = x.x;

        return new_exp;

    }
}; 