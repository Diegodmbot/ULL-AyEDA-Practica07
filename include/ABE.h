//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_ABE_H_
#define P07DIEGODIAZMORON_INCLUDE_ABE_H_

#include "../../P07DiegoDiazMoron/include/AB.h"

template<class Key>
class ABE : public AB<Key> {
  void InsertaEquil(const Key &k);
  void InsertaEquilRama(const Key &k, NodoB<Key> *nodo);
  // Metodos de la clase AB
  bool insertar(const Key &k);
  bool buscar(const Key &k) const;
  bool eliminar(const Key &k);
};

template<class Key>
bool ABE<Key>::insertar(const Key &k) {
  bool output = true;
  if (buscar(k)) {
    output = false;
  }
  InsertaEquil(k);
  return output;
}

template<class Key>
void ABE<Key>::InsertaEquil(const Key &k) {
  if (AB<Key>::root == nullptr)
    AB<Key>::root = new NodoB<int>(k);
  else InsertaEquilRama(k, AB<Key>::root);
}

template<class Key>
void ABE<Key>::InsertaEquilRama(const Key &k, NodoB<Key> *nodo) {
  if ((AB<Key>::TamRama(nodo->GetIzdo())) <= (AB<Key>::TamRama(nodo->GetDcho()))) {
    if (nodo->GetIzdo() != nullptr) {
      InsertaEquilRama(k, nodo->GetIzdo());
    } else
      nodo->SetIzdo(new NodoB<int>(k));
  } else {
    if (nodo->GetDcho() != nullptr) {
      InsertaEquilRama(k, nodo->GetDcho());
    } else
      nodo->SetDcho(new NodoB<int>(k));
  }
}

template<class Key>
bool ABE<Key>::buscar(const Key &k) const {
  if (this->GetRoot() == nullptr)  return false;
  std::queue<NodoB<Key> *> cola;
  cola.push(this->GetRoot());
  while (!cola.empty()) {
    if (cola.front()->GetDato() == k) {
      return true;
    } else {
      if (cola.front()->GetIzdo() != nullptr) {
        cola.push(cola.front()->GetIzdo());
      }
      if (cola.front()->GetDcho() != nullptr) {
        cola.push(cola.front()->GetDcho());
      }
      cola.pop();
    }
  }
  return false;
}
template<class Key>
bool ABE<Key>::eliminar(const Key &k) {
  return false;
}
#endif //P07DIEGODIAZMORON_INCLUDE_ABE_H_
