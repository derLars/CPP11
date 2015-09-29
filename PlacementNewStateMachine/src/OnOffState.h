/*
 * BaseState.h
 *
 *  Created on: Sep 8, 2015
 *      Author: derlars
 */

#ifndef SRC_ONOFFSTATE_H_
#define SRC_ONOFFSTATE_H_

#include "StateMachine.h"
#include "Context.h"

#include <iostream>

class BaseStateOnOff : public StateMachine<BaseStateOnOff, Context>{
public:
  BaseStateOnOff(){
    connectSignalToFunction(ON,this,&BaseStateOnOff::turnOn);
    connectSignalToFunction(OFF,this,&BaseStateOnOff::turnOff);
  }
  virtual ~BaseStateOnOff() {}

  enum ONOFF{ON,OFF};

  virtual void status() = 0;
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;

  virtual void cheese(int i) {
    cout << "The cheese is " << i << " years old!" << endl;
  }
};

class StateOff;

class StateOn : public BaseStateOnOff {
public:
  StateOn() {context->addToHistory("StateOn");}
  virtual ~StateOn() {}

  void status() {std::cout << "StateOn" << std::endl;}
  void turnOn() {}
  void turnOff() {changeState<StateOff>();}
};

class StateOff : public BaseStateOnOff {
public:
  StateOff(){context->addToHistory("StateOff");}
  virtual ~StateOff() {};

  void status() {std::cout << "StateOff" << std::endl;}
  void turnOn() {changeState<StateOn>();}
  void turnOff(){}
};

#endif /* SRC_ONOFFSTATE_H_ */
