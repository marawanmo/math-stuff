#include <iostream>

class Vector
{
public:

	float x, y;
	Vector(){}
	Vector(float X, float Y) 
	{
		x = X;
		y = Y;
	}

	// voeg een vector toe aan een andere vector
	Vector operator+(const Vector& v) const
	{
		Vector b; 
		b.x = x + v.x; 
		b.y = y + v.y; 
		return b;
	}
	//substract een vector met een adere vector
	Vector operator-(const Vector& v)
	{
		Vector b;
		b.x = x - v.x;
		b.y = y - v.y;
		return b;
	}
	// krijg de length van een vector (door stelling van pythagoras)
	float Length() const
	{
		float length;
		length = sqrt(x * x + y * y);
		return length;
	}
	//krijg de length van een vector sqaured
	float LengthSqr() const
	{
		float length;
		length = x * x + y * y;
		return length;
	}
	
	//multiply een vector met een scalar 
	Vector operator*(float s) const
	{
		Vector scaled;
		scaled.x = x * s;
		scaled.y = y * s;
		return scaled;
	}
	
	// devide een vector met een scalar
	Vector operator/(float s) const
	{
		Vector scaled;
		scaled.x = x / s;
		scaled.y = y / s;
		return scaled;
	}

	Vector Normilized() const
	{
		Vector normilized; 
		normilized = (*this) / Length();
		return normilized;
	}
};
class Point
{
public: 
	float x, y;
	Point(){}
	Point(float X, float Y)
	{
		x = X;
		y = Y; 
	}
	Point addVector(Vector v)
	{
		Point p2;
		p2.x = this->x + v.x;
		p2.y = this->y + v.y;

		return p2;
	}
};

// krijg de vector die je van punt b naar a brengt
Vector operator-(Point a, Point b)
{
	Vector v;
	v.x = a.x - b.x;
	v.y = a.y - b.y;
	return v;
}

float sameFacing(const Vector& a, const Vector& b)
{
	return a.x * b.x + a.y * b.y;
	
}

int main()
{
	Vector r(4,12);
	Vector d(4,1);
	std::cout << sameFacing(d, r); 
	
}