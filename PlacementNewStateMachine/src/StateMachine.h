/*
 * StateMachine.h
 *
 *  Created on: Sep 8, 2015
 *      Author: derlars
 */

#ifndef SRC_STATEMACHINE_H_
#define SRC_STATEMACHINE_H_

#include <memory>
#include <unordered_map>

//#define attach(idx,function) attachByLambda(idx,([this] (){function;}))

template<typename Derived, typename Context>
class StateMachine {
public:
  virtual ~StateMachine() = 0 ;

  //Operator new overloading ---
  void* operator new(size_t size) {
    if (memPtr == 0) {throw std::bad_alloc();}
    return memPtr;
  }

  template<typename T>
  static Derived* changeState() {
    //return new(memPtr) T();
    return new T();
  }

  //Dispatcher ---
  template<typename T,typename F>
  void connectSignalToFunction(int idx, T obj,  F&& f) {
    functionMap.emplace(std::make_pair(idx, std::bind(f, obj)));
   }

  void call(int i) {
    functionMap.find(i)->second();
  }
  // ---

  static std::unique_ptr<Context> context;

  //void attachByLambda(int idx, std::function<void()> ff){
  //  functionMap.emplace(std::make_pair(idx, ff));
  //}

private:
  void* operator new(size_t size, void* ptr) {
    if (memPtr == 0 || memPtr != ptr) {throw std::bad_alloc();}
    return ptr;
  }

  static std::unordered_map<int,std::function<void()>> functionMap;

  static unsigned char memory[];
  constexpr static void* memPtr = memory;
};
template<typename Derived,typename Context>
unsigned char StateMachine<Derived, Context>::memory[sizeof(Derived)];

template<typename Derived,typename Context>
std::unordered_map<int,std::function<void()>> StateMachine<Derived, Context>::functionMap;

template<typename Derived,typename Context>
std::unique_ptr<Context> StateMachine<Derived, Context>::context(new Context());

template<typename Derived,typename Context>
StateMachine<Derived, Context>::~StateMachine() {}
#endif /* SRC_STATEMACHINE_H_ */
