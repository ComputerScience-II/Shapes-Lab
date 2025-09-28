#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;

class Shape {

public:

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual string getName() const = 0;

    
};

class Circle : public Shape {

    double radius;

public:

    Circle(double radius) : radius(radius) {}

    double getArea() const override {

        return 3.14 * radius * radius;

    }

    double getPerimeter() const override {

        return 2 * 3.14 * radius;
    }

    string getName() const override {

        return "Circle";
    }

};

class Rectangle : public Shape {

    double width, height;

public:

    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {

        return width * height;
    }

    double getPerimeter() const override {

        return 2 * (width + height);
    }

    string getName() const override {

        return "Rectangle";
    }


};

class rightTriangle : public Shape {

    double base, height;

public:

    rightTriangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {

        return 0.5 * base * height;
    }

    double getPerimeter() const override {

        return base + height + sqrt(base * base + height * height);
    }

    string getName() const override {

        return "Right Triangle";
    }


};

class square : public Rectangle {

public:

    square(double side) : Rectangle(side, side) {}

    string getName() const override {

        return "Square";
    }

};

class isoscelesTriangle : public rightTriangle {

public:

    isoscelesTriangle(double side) : rightTriangle(side, side) {}

    string getName() const override {

        return "isosceles Triangle";
    }

};

void printShapeInfo(const Shape& shape) {

    cout << "The area of the " << shape.getName() << " is " << shape.getArea() << endl;

}

int main() {

    Rectangle rect(3.0,4.0);

    assert(rect.getArea() == 12.0);
    assert(rect.getPerimeter() == 14.0);

    Circle circ(5.0);

    assert(circ.getArea() == 78.5);
    assert(circ.getPerimeter() == 31.400000000000002);

    rightTriangle tri(3.0,4.0);

    assert(tri.getArea() == 6.0);
    assert(tri.getPerimeter() == 12.0);

    cout << "\n\nNo failures in the tests.\n\n" << endl;

    square sq(4.0);

    assert(sq.getArea() == 16.0);
    assert(sq.getPerimeter() == 16.0);

    isoscelesTriangle isT(5.0);
    
    assert(isT.getArea() == 12.5);
    assert(isT.getPerimeter() == 17.071067811865476);


    printShapeInfo(rect);
    cout << "\n\n";
    printShapeInfo(circ);
    cout << "\n\n";
    printShapeInfo(tri);
    cout << "\n\n";
    printShapeInfo(sq);
    cout << "\n\n";
    printShapeInfo(isT);
    cout << "\n\n";

    

    return 0;




}


