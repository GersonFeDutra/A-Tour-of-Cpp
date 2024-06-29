import Vector;   //get Vector’s interface
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
	catch (out_of_range &err) {
		// ... handle range error ...
		cerr << err.what() << '\n';
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

#include <random>
int main()
{
	int result = read_and_sum(std::rand() % 10);
	std::cout << "sum: " << result << '\n';
}
