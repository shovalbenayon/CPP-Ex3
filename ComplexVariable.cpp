#include "ComplexVariable.hpp"


namespace solver{
    ComplexExpression operator + (ComplexExpression x, ComplexExpression y){
        ComplexExpression new_expl;
		new_expl.a = x.a + y.a;
		new_expl.b = x.b + y.b;
		new_expl.c = x.c + y.c;

		if (x.x != 0) 
            new_expl.x = x.x; // l1.x = 0 or l2.x = 0 or l1.x = l2.x = 0
		else new_expl.x = y.x;
		return new_expl;
    }
    ComplexExpression operator + (std::complex<double> x, ComplexExpression y){
        return ComplexExpression(x) + y;

    }
    ComplexExpression operator + (ComplexExpression x, std::complex<double> y){
       return x + ComplexExpression(y);
    }

	ComplexExpression operator - (ComplexExpression x, ComplexExpression y){
        ComplexExpression new_exp;
        new_exp.a = x.a - y.a;
        new_exp.b = x.b - y.b;
        new_exp.c = x.c - y.c;

        if(x.x == 0) 
            new_exp.x = y.x;
        else new_exp.x = x.x;

        return new_exp;
    }

    ComplexExpression operator - (std::complex<double> x, ComplexExpression y){
       return ComplexExpression(x) - y;
    }

    ComplexExpression operator - (ComplexExpression x, std::complex<double> y){
        return x - ComplexExpression(y);
    }

	ComplexExpression operator * (ComplexExpression x, ComplexExpression y){
        ComplexExpression new_exp;

		new_exp.a = x.a * y.c + x.c * y.a + x.b * y.b;
		new_exp.b = x.b * y.c + y.b * x.c;
		new_exp.c = x.c * y.c;

		if (x.x != 0) 
            new_exp.x = x.x; 
		else new_exp.x = y.x;
		return new_exp;
    }

    ComplexExpression operator * (ComplexExpression x, std::complex<double> y){
        return x * ComplexExpression(y);

    }

    ComplexExpression operator * (std::complex<double> x, ComplexExpression y){
        return ComplexExpression(x) * y;
    }

	ComplexExpression operator == (ComplexExpression x, ComplexExpression y){
        ComplexExpression new_exp = x - y;
		if (new_exp.a == std::complex<double>(0,0)) {
			if (new_exp.b == std::complex<double>(0,0)) 
                throw std::runtime_error("ERROR! can not divide by zero");
			new_exp.x->comp = -new_exp.c/new_exp.b; // Linear form
			return new_exp;
		}

		std::complex<double> determinant = new_exp.b * new_exp.b - std::complex<double>(4,0) * new_exp.a * new_exp.c; // Polynomial form
		new_exp.x->comp = (-new_exp.b - sqrt(determinant)) / (std::complex<double>(2,0) * new_exp.a); // A single solution is required
		return new_exp;

    }

    ComplexExpression operator == (ComplexExpression x, std::complex<double> y){

        return x == ComplexExpression(y);

    }

	ComplexExpression operator / (ComplexExpression x, std::complex<double> y){
        if(y == std::complex<double>(0,0)) throw std::invalid_argument("Error! cannot divide bt zero");
        x.a /= y;
        x.b /= y;
        x.c /= y;

        return x;

    }
    
	ComplexExpression operator ^ (ComplexExpression x, std::complex<double> y){
        if(y != std::complex<double>(2,0)) throw std::invalid_argument("Error! Only second degree is available");
        
        ComplexExpression new_exp;
        new_exp.a = x.b * x.b;
        new_exp.b = std::complex<double>(2,0) * x.b * x.c;
        new_exp.c = x.c * x.c;

    
       new_exp.x = x.x;

        return new_exp;

    }
};

std::ostream& operator << (std::ostream& os, const std::complex<double> comp) {
	if (real(comp) == 0) os << '0'; // -0 display may occur
	else os << real(comp);
	if (imag(comp) == 0) return os << "+0i"; // +-0i display may occur
	if (imag(comp) > 0) return os << '+' << imag(comp) << 'i';
	return os << imag(comp) << 'i';
}