//
// Created by diedi on 15/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_ABB_H_
#define P07DIEGODIAZMORON_INCLUDE_ABB_H_

#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
  bool InsertarRama(NodoB<Key> *nodo,Key k);
  bool BuscarRama(NodoB<Key> *nodo, Key k) const;
  // metodos de la clase AB
  bool insertar(const Key &k);
  bool buscar(const Key &k) const;
  bool eliminar(const Key &k);
};

template<class Key>
bool ABB<Key>::insertar(const Key &k) {
  if(this->GetRoot() == nullptr) {
    AB<Key>::root = new NodoB<int>(k);
    return true;
  }
  else
    return InsertarRama(this->GetRoot(), k);
}

template<class Key>
bool ABB<Key>::InsertarRama(NodoB<Key> *nodo, Key k) {
  if(buscar(k))
    return false;
  if (nodo == nullptr){
    nodo = new NodoB<Key>(k);
    return true;
  }
  else if (k < nodo->GetDato())
    InsertarRama(nodo->GetIzdo(), k);
  else
    InsertarRama(nodo->GetDcho(), k);
  return false;
}

template<class Key>
bool ABB<Key>::buscar(const Key &k) const {
  return BuscarRama(this->GetRoot(), k);
}

template<class Key>
bool ABB<Key>::BuscarRama(NodoB<Key> *nodo, Key k) const{
  if (nodo == nullptr)
    return false ;
  if (k == nodo->GetDato())
    return true ;
  if (k < nodo->GetDato())
    return BuscarRama(nodo->GetIzdo(), k);
  return BuscarRama(nodo->GetDcho(), k);
}

template<class Key>
bool ABB<Key>::eliminar(const Key &k) {
  return false;
}
#endif //P07DIEGODIAZMORON_INCLUDE_ABB_H_
