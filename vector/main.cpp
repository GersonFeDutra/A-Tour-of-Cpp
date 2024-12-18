//import Vector;   //get Vector’s interface // import support is not complete
#include "vector.hpp"
#include <cmath> // get the standard-library math function interface including sqrt()
#include <iostream>
#include <stdexcept>


void test()
{
	try {
		Vector v(-27);
	}
	catch (std::length_error &err) {
		// handle negative size
	}
	catch (std::bad_alloc &err) {
		// Ouch! this program is not designed to handle memory exhaustion
		std::terminate(); // terminate the program
	}
}

void f(Vector &v)
{
	// ...
	try {                // exceptions here are handled by the handler defined below
		v[v.size()] = 7; // try to access beyond the end of v
	}
	catch (std::out_of_range &err) {
		// ... handle range error ...
		std::cerr << err.what() << '\n';
	}
	// ...
}


// get the standard-librar y math function interface including sqrt()
double sqrt_sum(Vector &v)
{
	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
		sum += std::sqrt(v[i]);
	return sum;
}


double read_and_sum(int s)
{
	Vector v(s);
	for (int i = 0; i != v.size(); ++i)
		// make a vector of s elements
		std::cin >> v[i]; // read into elements
	double sum = 0;
	for (int i = 0; i != v.size(); ++i)
		sum += v[i]; // take the sum of the elements
	return sum;
}

void fct(int n)
{
	Vector v(n);
	// ... use v ...
	{
		Vector v2(2 * n);
		// ... use v and v2 ...
	} // v2 is destroyed here

	// ... use v ..
} // v is destroyed here

Vector read(std::istream &is)
{
	Vector v;
	for (double d; is >> d;) // read floating-point values into d
		v.push_back(d);      // add d to v
	return v;
}

#ifdef DEBUG
#define print_log(S) std::cerr << S;
#else
#define print_log(S)
#endif

Vector f()
{
	Vector x(1000);
	Vector y(2000);
	Vector z(3000);

	print_log("z = x\n");
	z = x;            // we get a copy (x might be used later in f())
	print_log("y = move(x)\n");
	y = std::move(x); // we get a move (move assignment)

	// ... better not use x here ...

	print_log("return z\n");
	return z;         // we get a move
}

#include <random>
int main()
{
	Vector v = f();
/*
	int result = read_and_sum(std::rand() % 10);
	std::cout << "sum: " << result << '\n';

	Vector v = read(std::cin); // no copy of Vector elements here

	Vector v1 {1, 2, 3, 4, 5};      // v1 has 5 elements
	Vector v2 {1.23, 3.45, 6.7, 8}; // v2 has 4 elements
*/
}
