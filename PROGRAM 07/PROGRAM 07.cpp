



#include <iostream>

#include <vector>

using namespace std;


class Shape {

public:

    virtual void draw() const = 0;

    virtual ~Shape() = default;

};


class Circle : public Shape {

public:

    void draw() const override {

        cout << "Drawing Circle" << endl;

    }

};


class Rectangle : public Shape {

public:

    void draw() const override {

        cout << "Drawing Rectangle" << endl;

    }

};


int main() {

    vector<Shape*> shapes{new Circle(), new Rectangle()};

    for (const auto shape : shapes) shape->draw();

    for (auto shape : shapes) delete shape;

}

