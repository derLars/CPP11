/*#############################################################################
 * VariadicFactory.h
 *
 *  Created on: Aug 23, 2015
 *      Author: derlars
 */
//#VariadicFactory.h#######################################################
#ifndef SRC_VARIADICFACTORY_H_
#define SRC_VARIADICFACTORY_H_

#include <vector>
using namespace std;

template<typename Super, typename ... Rest>
class VarFactory;

template<typename Super>
class VarFactory<Super> {
public:
  shared_ptr<Super> getObject(int idx) {
    return 0;
  }
};

template<typename Super, typename T, typename ... Rest>
class VarFactory<Super, T, Rest...> : public VarFactory<Super, Rest...> {
public:
  shared_ptr<Super> getObject(int idx) {
    return idx ? VarFactory<Super, Rest...>::getObject(--idx) : shared_ptr<Super>(new T());
  }
};

#endif /* SRC_VARIADICFACTORY_H_ */

