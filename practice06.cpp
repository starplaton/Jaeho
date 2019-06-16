#include <iostream>
#include <math.h>

using namespace std;

class Shape {
public:
	void setvalues(double h, double w) { height = h; width = w; }
	virtual double area() = 0;
	virtual double perimeter() = 0;
protected :
	double height, width;
};
class IsoTriangle : public Shape {
public:
	void setvalues(double h, double w) { height = h; width = w; }
	virtual double area() { return height * width*0.5; }
	virtual double perimeter() { return width+2* sqrt(0.25*width*width + height*height); }
//protected:
	double height, width;
};
class Rectangle : public Shape {
public:
	void setvalues(double h, double w) { height = h; width = w; }
	virtual double area() { return height * width; }
	virtual double perimeter() { return height * 2 + width * 2; }
//protected:
	double height, width;
};
class House : public IsoTriangle, public Rectangle {};

int main() {
	House H;
	H.IsoTriangle::setvalues(3, 5);
	H.Rectangle::setvalues(4, 8);
	IsoTriangle *Iso; Rectangle *Rec;
	Iso = &H; Rec = &H;
	cout << "Area = " << Iso->area() + Rec->area() << endl;
	if (Iso->width < Rec->width) {
		cout << "Perimeter = " << Iso->perimeter() + Rec->perimeter() - 2*Iso->width << endl;
	}
	else {
		cout << "Perimeter = " << Iso->perimeter() + Rec->perimeter() - 2 * Rec->width << endl;
	}

	return 0;
}