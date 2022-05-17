//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_AB_H_
#define P07DIEGODIAZMORON_INCLUDE_AB_H_

#include "NodoB.h"
#include <iostream>
#include <queue>

template<typename Key>
class AB {
 public:
  NodoB<Key> *GetRoot() const;
  virtual bool insertar(const Key &k) = 0;
  virtual bool buscar(const Key &k) const = 0;
  virtual bool eliminar(const Key &k) = 0;
  void inorden() const;
  void inorden(NodoB<Key> *nodo) const;
  const int TamRama(NodoB<Key> *nodo);
  void Write();
 protected:
  NodoB<Key> *root;
};

template<class Key>
const int AB<Key>::TamRama(NodoB<Key> *nodo) {
  if (nodo == NULL) return 0;
  return (1 + TamRama(nodo->GetIzdo()) + TamRama(nodo->GetDcho()));
}

template<typename Key>
void AB<Key>::inorden() const {
  inorden(root);
}

template<typename Key>
void AB<Key>::inorden(NodoB<Key> *nodo) const {
  if (root != nullptr) {
    inorden(nodo->GetIzdo());
    std::cout << nodo->GetDato() << " ";
    inorden(nodo->GetDcho());
  }
}
template<typename Key>
void AB<Key>::Write() {
  int k = 0;
  std::queue<NodoB<Key> *> cola, colaAux;
  cola.push(root);
  while (!cola.empty()) {
    std::cout << "Nivel " << k << ": ";
    while (!cola.empty()) {
      if (cola.front() != nullptr) {
        std::cout << "[" << cola.front()->GetDato() << "]";
        colaAux.push(cola.front()->GetIzdo());
        colaAux.push(cola.front()->GetDcho());
      } else
        std::cout << "[.]";

      cola.pop();
    }
    cola = colaAux;
    while (!colaAux.empty()) {
      colaAux.pop();
    }
    k++;
    std::cout << "\n\n";
  }
}
template<typename Key>
NodoB<Key> *AB<Key>::GetRoot() const {
  return root;
}

#endif //P07DIEGODIAZMORON_INCLUDE_AB_H_
