#pragma once
#include "shape.hpp"

class Circle : public Shape
{
public:
	Circle(Point p, int rad); // constructor
	Point center() const override
	{
		return x;
	}
	void move(Point to) override
	{
		x = to;
	}
	void draw() const override;
	void rotate(int) override
	{
	} // nice simple algorithm
private:
	Point x; // center
	int r;   // radius
};
