//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_NODOB_H_
#define P07DIEGODIAZMORON_INCLUDE_NODOB_H_

template <class Key>
class NodoB{
  NodoB(Key dato_, NodoB<Key>* izdo_, NodoB<Key>* dcho_) : dato(dato_), izdo(izdo_), dcho(dcho_){}
  NodoB() : izdo(nullptr), dcho(nullptr){}
  ~NodoB() = default;
  Key getDato() const { return dato; }
 public:
  NodoB<Key> *GetIzdo() const;
  NodoB<Key> *GetDcho() const;
  Key GetDato() const;
 private:
  Key dato;
  NodoB<Key>* izdo;
  NodoB<Key>* dcho;
};
template<class Key>
NodoB<Key> *NodoB<Key>::GetIzdo() const {
  return izdo;
}
template<class Key>
NodoB<Key> *NodoB<Key>::GetDcho() const {
  return dcho;
}
template<class Key>
Key NodoB<Key>::GetDato() const {
  return dato;
}

#endif //P07DIEGODIAZMORON_INCLUDE_NODOB_H_
