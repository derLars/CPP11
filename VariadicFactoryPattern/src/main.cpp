/*#############################################################################
 * main.cpp
 *
 * Object factory pattern
 * influenced by C++11
 *
 * Simple example of an object factory with focus on reusability and minimum codesize
 *
 *  Created on: Aug 23, 2015
 *      Author: derlars
 */
//#main.cpp################################################################
#include <memory>
#include "Timer.h"

#include "VariadicFactory.h"

#include "Shape.h"
typedef VarFactory<Shape, Square, Rectangle, Circle, Triangle> Factory;

using namespace std;

int main(int argc, char** argv) {
  Factory factory;

  shared_ptr<Shape> shape = factory.getObject(2);
  shape->doStuff();

  shape = factory.getObject(0);
  shape->doStuff();

  return 1;
}

