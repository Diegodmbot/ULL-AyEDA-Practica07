//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_ABE_H_
#define P07DIEGODIAZMORON_INCLUDE_ABE_H_

#include "../../P07DiegoDiazMoron/include/AB.h"

template <class Key>
class ABE : public AB<Key> {
  bool insertar(const Key &k);
  bool buscar(const Key &k) const;
  bool eliminar(const Key& k);
};

template<class Key>
bool ABE<Key>::insertar(const Key &k) {
  return false;
}
template<class Key>
bool ABE<Key>::buscar(const Key &k) const {
  return false;
}
template<class Key>
bool ABE<Key>::eliminar(const Key &k) {
  return false;
}
#endif //P06DIEGODIAZMORON_INCLUDE_ABE_H_
// TODO: no insertar valores repetidos
