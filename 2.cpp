#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Figure {
public:
    virtual double get_square() const = 0;
    virtual ~Figure();
};

class Rectangle : public Figure {
private:
    double w, h;

public:
    Rectangle(double w, double h) : w(w), h(h) {}

    double get_square() const override {
        return w * h;
    }

    static Figure* make(const std::string& str) {
        std::istringstream iss(str);
        double w, h;
        iss >> w >> h;
        return new Rectangle(w, h);
    }
};

class Square : public Figure {
private:
    double a;

public:
    Square(double a) : a(a) {}

    double get_square() const override {
        return a * a;
    }

    static Figure* make(const std::string& str) {
        std::istringstream iss(str);
        double a;
        iss >> a;
        return new Square(a);
    }
};

class Circle : public Figure {
private:
    double r;

public:
    Circle(double r) : r(r) {}

    double get_square() const override {
        return M_PI * r * r;
    }

    static Figure* make(const std::string& str) {
        std::istringstream iss(str);
        double r;
        iss >> r;
        return new Circle(r);
    }
};
