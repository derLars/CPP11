/*
 * Timer.h
 *
 *  Created on: Sep 26, 2015
 *      Author: derlars
 */

#ifndef SRC_TIMER_H_
#define SRC_TIMER_H_
#include <chrono>

using namespace std::chrono;

class Timer{
public:
  void start(){
    startTime = system_clock::now();
  }

  double getTime(){
    checkpoint = system_clock::now();
    return ((duration<double>)(checkpoint-startTime)).count();
  }

private:
  time_point<system_clock> startTime;
  time_point<system_clock> checkpoint;
};

#endif /* SRC_TIMER_H_ */
