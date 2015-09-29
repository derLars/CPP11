/*#############################################################################
 * VariadicFactory.h
 *
 *  Created on: Aug 23, 2015
 *      Author: derlars
 */
//#VariadicFactory.h#######################################################
#ifndef SRC_VARIADICFACTORYOPTIMIZED_H_
#define SRC_VARIADICFACTORYOPTIMIZED_H_

#include <vector>
using namespace std;

template<typename Super, typename ... Rest>
class VarFactoryOptimized;

template<typename Super>
class VarFactoryOptimized<Super> {
public:
  shared_ptr<Super> getObject(int idx){
    return objectVector[idx]();
  }
protected:
  static vector<function<shared_ptr<Super>()>> objectVector;
};

template<typename Super>
vector<function<shared_ptr<Super>()>> VarFactoryOptimized<Super>::objectVector;

template<typename Super, typename T, typename ... Rest>
class VarFactoryOptimized<Super, T, Rest...> : public VarFactoryOptimized<Super, Rest...> {
public:
  VarFactoryOptimized(){
    VarFactoryOptimized<Super>::objectVector.emplace(VarFactoryOptimized<Super>::objectVector.begin(),([] ()-> shared_ptr<Super> {return shared_ptr<Super>(new T());}));
  }
};

#endif /* SRC_VARIADICFACTORYOPTIMIZED_H_ */

