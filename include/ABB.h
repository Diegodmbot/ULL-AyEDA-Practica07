//
// Created by diedi on 15/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_ABB_H_
#define P07DIEGODIAZMORON_INCLUDE_ABB_H_

#include "AB.h"

template <class Key>
class ABB: public AB<Key>{
  bool insertar(const Key &k);
  bool buscar(const Key &k) const;
  bool eliminar(const Key& k);
};
template<class Key>
bool ABB<Key>::insertar(const Key &k) {
  return false;
}
template<class Key>
bool ABB<Key>::buscar(const Key &k) const {
  return false;
}
template<class Key>
bool ABB<Key>::eliminar(const Key &k) {
  return false;
}
#endif //P07DIEGODIAZMORON_INCLUDE_ABB_H_
