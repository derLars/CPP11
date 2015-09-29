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
#include "ClassCollection.h"
#include "VariadicFactoryOptimized.h"
typedef VarFactoryOptimized<ClassCollectionSuperClass,C1,C2,C3,C4,C5,C6,C7,C8,C9,C10 ,C11,C12,C13,C14,C15,C16,C17,C18,C19,C20,C21,C22,C23,C24,C25,C26,C27,C28,C29,C30,C31,C32,C33,C34,C35,C36,C37,C38,C39,C40,C41,C42,C43,C44,C45,C46,C47,C48,C49,C50> Factory;
using namespace std;

int main(int argc, char** argv) {
  Timer timer;
  Factory factory;
  shared_ptr<ClassCollectionSuperClass> obj;

  timer.start();
  for (int i = 0; i < 1000000; i++) {
    obj = factory.getObject(0);
  }
  cout << "optimized; 1000000; first; " << timer.getTime() << "s" << endl;
  timer.start();
  for (int i = 0; i < 1000000; i++) {
    obj = factory.getObject(49);
  }
  cout << "optimized; 1000000; last; " << timer.getTime() << "s" << endl;

  timer.start();
  for (int i = 0; i < 5000000; i++) {
    obj = factory.getObject(0);
  }
  cout << "optimized; 5000000; first; " << timer.getTime() << "s" << endl;
  timer.start();
  for (int i = 0; i < 5000000; i++) {
    obj = factory.getObject(49);
  }
  cout << "optimized; 5000000; last; " << timer.getTime() << "s" << endl;

  timer.start();
  for (int i = 0; i < 10000000; i++) {
    obj = factory.getObject(0);
  }
  cout << "optimized; 10000000; first; " << timer.getTime() << "s" << endl;
  timer.start();
  for (int i = 0; i < 10000000; i++) {
    obj = factory.getObject(49);
  }
  cout << "optimized; 10000000; last; " << timer.getTime() << "s" << endl;

  timer.start();
  for (int i = 0; i < 50000000; i++) {
    obj = factory.getObject(0);
  }
  cout << "optimized; 50000000; first; " << timer.getTime() << "s" << endl;
  timer.start();
  for (int i = 0; i < 50000000; i++) {
    obj = factory.getObject(49);
  }
  cout << "optimized; 50000000; last; " << timer.getTime() << "s" << endl;

  timer.start();
  for (int i = 0; i < 100000000; i++) {
    obj = factory.getObject(0);
  }
  cout << "optimized; 100000000; first; " << timer.getTime() << "s" << endl;
  timer.start();
  for (int i = 0; i < 100000000; i++) {
    obj = factory.getObject(49);
  }
  cout << "optimized; 100000000; last; " << timer.getTime() << "s" << endl;

   return 1;
}

