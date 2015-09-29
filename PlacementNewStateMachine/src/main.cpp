/*
 * main.cpp
 *
 *  Created on: Sep 8, 2015
 *      Author: derlars
 */

#include "StateMachine.h"

#include "OnOffState.h"

#include "ColorState.h"

int main(int argc, char** argv) {
  unique_ptr<BaseStateOnOff> stateOnOff(new StateOff());
  unique_ptr<BaseStateColor> stateColor(new Green());

  stateOnOff->status();
  stateColor->status();

  stateOnOff->call(BaseStateOnOff::ON);

  stateOnOff->status();
  stateColor->status();

  stateColor->call(BaseStateColor::YELLOW);

  stateOnOff->status();
  stateColor->status();

  stateOnOff->call(BaseStateOnOff::OFF);

  stateOnOff->status();
  stateColor->status();

  stateColor->call(BaseStateColor::BLUE);

  stateOnOff->status();
  stateColor->status();

  //state->call(7);
  stateOnOff->context->printHistory();
  stateColor->context->printHistory();

  return 1;
}


