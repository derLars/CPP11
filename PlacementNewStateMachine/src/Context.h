/*
 * Context.h
 *
 *  Created on: Sep 24, 2015
 *      Author: derlars
 */

#ifndef SRC_CONTEXT_H_
#define SRC_CONTEXT_H_
#include <iostream>
using namespace std;

class Context{
public:
  Context(){
    cout << "Context created" << endl;
  }

  void addToHistory(string s){
    history.append(s + " ");
  }

  void printHistory(){
    cout << history << endl;
  }

  string history;
private:

};


#endif /* SRC_CONTEXT_H_ */
