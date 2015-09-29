/*#############################################################################
 * Shape.h
 *
 *  Created on: Aug 22, 2015
 *      Author: derlars
 */

#ifndef SRC_SHAPE_H_
#define SRC_SHAPE_H_

#include <iostream>

using namespace std;

class Shape {
public:

  virtual ~Shape() {
  }

  void virtual doStuff(void) = 0;

  void virtual doOtherStuff(void) {
    cout << "everyone inherits this" << endl;
  }
};

class Rectangle: public Shape {
public:
  Rectangle() {
    cout << "Rectangle created" << endl;
  }
  ~Rectangle() {
    cout << "Rectangle destroyed" << endl;
  }

  void doStuff(void) {
    cout << "Rectangle is doing stuff" << endl;
  }
};

class ShadowedRectangle: public Rectangle {
public:
  ShadowedRectangle() {
    cout << "Shadowed rectangle created" << endl;
    calcShadow();
  }
  ~ShadowedRectangle() {
    cout << "Shadowed rectangle destroyed" << endl;
  }
private:
  void calcShadow() {
    cout << "Shadowed rectangle is doing incredibly heavy math!" << endl;
  }
};

class Square: public Rectangle {
public:
  Square() {
    cout << "Square created" << endl;
  }
  ~Square() {
    cout << "Square destroyed" << endl;
  }

  void doStuff(void) {
    cout << "Square is doing stuff" << endl;
  }
};

class ShadowedSquare: public Square {
public:
  ShadowedSquare() {
    cout << "Shadowed square created" << endl;
    calcShadow();
  }
  ~ShadowedSquare() {
    cout << "Shadowed square destroyed" << endl;
  }
private:
  void calcShadow() {
    cout << "Shadowed square is doing incredibly heavy math!" << endl;
  }
};

class Circle: public Shape {
public:
  Circle() {
    cout << "Circle created" << endl;
  }
  ~Circle() {
    cout << "Circle destroyed" << endl;
  }

  void doStuff(void) {
    cout << "Circle is doing stuff" << endl;
  }
};

class ShadowedCircle: public Circle {
public:
  ShadowedCircle() {
    cout << "Shadowed circle created" << endl;
    calcShadow();
  }
  ~ShadowedCircle() {
    cout << "Shadowed circle destroyed" << endl;
  }
private:
  void calcShadow() {
    cout << "Shadowed circle is doing incredibly heavy math!" << endl;
  }
};

class Triangle: public Shape {
public:
  Triangle() {
    cout << "Triangle created" << endl;
  }
  ~Triangle() {
    cout << "Triangle destroyed" << endl;
  }

  void doStuff(void) {
    cout << "Triangle is doing stuff" << endl;
  }
};

class ShadowedTriangle: public Triangle {
public:
  ShadowedTriangle() {
    cout << "Shadowed triangle created" << endl;
    calcShadow();
  }
  ~ShadowedTriangle() {
    cout << "Shadowed triangle destroyed" << endl;
  }
private:
  void calcShadow() {
    cout << "Shadowed triangle is doing incredibly heavy math!" << endl;
  }
};

class Parallelogram: public Shape {
public:
  Parallelogram() {
    cout << "Parallelogram created" << endl;
  }
  ~Parallelogram() {
    cout << "Parallelogram destroyed" << endl;
  }

  void doStuff(void) {
    cout << "Parallelogram is doing stuff" << endl;
  }
};

class ShadowedParallelogram: public Parallelogram {
public:
  ShadowedParallelogram() {
    cout << "Shadowed parallelogram created" << endl;
    calcShadow();
  }
  ~ShadowedParallelogram() {
    cout << "Shadowed parallelogram destroyed" << endl;
  }
private:
  void calcShadow() {
    cout << "Shadowed parallelogram is doing incredibly heavy math!" << endl;
  }
};

#endif /* SRC_SHAPE_H_ */
//###############################################################################
