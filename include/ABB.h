//
// Created by diedi on 15/05/2022.
//

#ifndef P07DIEGODIAZMORON_INCLUDE_ABB_H_
#define P07DIEGODIAZMORON_INCLUDE_ABB_H_

#include "AB.h"

template<class Key>
class ABB : public AB<Key> {
  bool InsertarRama(NodoB<Key>* &nodo, Key k);
  bool BuscarRama(NodoB<Key> *nodo, Key k) const;
  bool EliminarRama(NodoB<Key>* &nodo, Key k);
  void sustituye(NodoB<Key>* &eliminado,NodoB<Key>* &sust);
  // metodos de la clase AB
  bool insertar(const Key &k);
  bool buscar(const Key &k) const;
  bool eliminar(const Key &k);
};

template<class Key>
bool ABB<Key>::insertar(const Key &k) {
  if (this->GetRoot() == nullptr) {
    AB<Key>::root = new NodoB<int>(k);
    return true;
  } else
    return InsertarRama( AB<Key>::root, k);
}

template<class Key>
bool ABB<Key>::InsertarRama(NodoB<Key>* &nodo, Key k) {
  if(buscar(k))
    return false;
  if (nodo == nullptr)
    nodo = new NodoB<Key>(k);
  else if (k < nodo->GetDato())
    InsertarRama(nodo->GetIzdo(), k);
  else
    InsertarRama(nodo->GetDcho(), k);
  return true;
}

template<class Key>
bool ABB<Key>::buscar(const Key &k) const {
  return BuscarRama(this->GetRoot(), k);
}

template<class Key>
bool ABB<Key>::BuscarRama(NodoB<Key> *nodo, Key k) const {
  if (nodo == nullptr)
    return false;
  if (k == nodo->GetDato())
    return true;
  if (k < nodo->GetDato())
    return BuscarRama(nodo->GetIzdo(), k);
  return BuscarRama(nodo->GetDcho(), k);
}

template<class Key>
bool ABB<Key>::eliminar(const Key &k) {
  return EliminarRama( AB<Key>::root, k);
}
template<class Key>
bool ABB<Key>::EliminarRama(NodoB<Key>* &nodo, Key k) {
  if(!buscar(k))
    return false;
  if (nodo == nullptr) return false;
  if (k < nodo->GetDato())
    EliminarRama(nodo->GetIzdo(), k);
  else if (k > nodo->GetDato())
    EliminarRama(nodo->GetDcho(), k);
  else {
    NodoB<Key> *Eliminado = nodo;
    if (nodo->GetDcho() == nullptr)
      nodo = nodo->GetIzdo();
    else if (nodo->GetIzdo() == nullptr)
      nodo = nodo->GetDcho();
    else
      sustituye(Eliminado, nodo->GetIzdo());
    delete (Eliminado);
  }
  return true;
}
template<class Key>
void ABB<Key>::sustituye(NodoB<Key> *&eliminado, NodoB<Key> *&sust) {
  if (sust->GetDcho() != nullptr)
    sustituye(eliminado, sust->GetDcho());
  else {
    eliminado->SetDato(sust->GetDato());
    eliminado = sust;
    sust = sust->GetIzdo();
  }
}

#endif //P07DIEGODIAZMORON_INCLUDE_ABB_H_
