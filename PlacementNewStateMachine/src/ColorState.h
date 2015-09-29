/*
 * ColorState.h
 *
 *  Created on: Sep 15, 2015
 *      Author: derlars
 */

#ifndef SRC_COLORSTATE_H_
#define SRC_COLORSTATE_H_

#include "StateMachine.h"
#include "Context.h"
#include <iostream>

using namespace std;

class BaseStateColor : public StateMachine<BaseStateColor, Context>{
public:
  BaseStateColor(){
    connectSignalToFunction(GREEN,this,&BaseStateColor::green);
    connectSignalToFunction(YELLOW,this,&BaseStateColor::yellow);
    connectSignalToFunction(BLUE,this,&BaseStateColor::blue);

  }

  virtual ~BaseStateColor(){}

  enum COLOR{GREEN,YELLOW,BLUE};
  virtual void status() = 0;
  virtual void green() = 0;
  virtual void yellow() = 0;
  virtual void blue() = 0;

};

class Yellow;
class Blue;

class Green : public BaseStateColor {
public:
  Green(){context->addToHistory("Green");}
  virtual ~Green(){}

   void status(){cout << "Color is green!" << endl;}
   void green(){}
   void yellow(){changeState<Yellow>();}
   void blue(){changeState<Blue>();}
};

class Yellow : public BaseStateColor {
public:
  Yellow(){context->addToHistory("Yellow");}
  virtual ~Yellow(){}

   void status(){cout << "Color is yellow!" << endl;}
   void green(){changeState<Green>();}
   void yellow(){}
   void blue(){changeState<Blue>();}
};

class Blue : public BaseStateColor {
public:
  Blue(){context->addToHistory("Blue");}
  virtual ~Blue(){}

   void status(){cout << "Color is blue!" << endl;}
   void green(){changeState<Green>();}
   void yellow(){changeState<Yellow>();}
   void blue(){}
};

#endif /* SRC_COLORSTATE_H_ */
