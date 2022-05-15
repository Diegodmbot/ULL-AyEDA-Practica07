//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_AB_H_
#define P07DIEGODIAZMORON_INCLUDE_AB_H_

#include "NodoB.h"
#include <iostream>

template <typename Key>
class AB {
 public:
  virtual bool insertar(const Key &k) = 0;
  virtual bool buscar(const Key &k) const = 0;
  virtual bool eliminar(const Key& k) = 0;
  void inorden() const;
  void inorden(NodoB<Key> *nodo) const;
  friend std::ostream &operator<<(std::ostream &os, const AB<Key> &ab) {
    if (ab.root == nullptr)
      os << "[.]";
    else
    {
      os << "[";
      ab.root->GetDato();
      os << "]";
    }
    return os;
  }
 protected:
  NodoB<Key> *root;
};

template<typename Key>
void AB<Key>::inorden() const {
  inorden(root);
}

template<typename Key>
void AB<Key>::inorden(NodoB<Key> *nodo) const {
  if(root == nullptr) return;
  inorden(nodo->GetIzdo());
  std::cout << nodo->GetDato() << " ";
  inorden(nodo->GetDcho());
}

#endif //P07DIEGODIAZMORON_INCLUDE_AB_H_
