//
// Created by diedi on 03/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_NODOB_H_
#define P07DIEGODIAZMORON_INCLUDE_NODOB_H_

template <class Key>
class NodoB{
 public:
  NodoB(Key dato_, NodoB<Key>* izdo_ = nullptr, NodoB<Key>* dcho_ = nullptr) : dato(dato_), izdo(izdo_), dcho(dcho_){}
  NodoB() : izdo(nullptr), dcho(nullptr){}
  ~NodoB() = default;
  NodoB<Key> *GetIzdo() const;
  NodoB<Key> *GetDcho() const;
  NodoB<Key>*& GetIzdo() { return izdo; }
  NodoB<Key>*& GetDcho() { return dcho; }
  void SetIzdo(NodoB<Key> *izdo);
  void SetDcho(NodoB<Key> *dcho);
  void SetDato(Key dato_);
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
template<class Key>
void NodoB<Key>::SetIzdo(NodoB<Key> *izdo) {
  NodoB::izdo = izdo;
}
template<class Key>
void NodoB<Key>::SetDcho(NodoB<Key> *dcho) {
  NodoB::dcho = dcho;
}
template<class Key>
void NodoB<Key>::SetDato(Key dato_) {
  NodoB::dato = dato_;
}

#endif //P07DIEGODIAZMORON_INCLUDE_NODOB_H_
