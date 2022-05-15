#include <iostream>
#include "../include/ABB.h"
#include "../include/ABE.h"

typedef  int keyType;

int main() {
  std::cout << "Seleccione tipo de arbol:" << std::endl;
  std::cout << "1. ABB" << std::endl;
  std::cout << "2. ABE" << std::endl;
  int opcion;
  std::cin >> opcion;
  AB<keyType> *arbol;
  switch (opcion) {
    case 1:
      arbol = new ABB<keyType>();
      break;
    case 2:
      arbol = new ABE<keyType>();
      break;
    default:
      std::cout << "Opcion invalida" << std::endl;
      return 0;
  }
  while(true){
    std::cout << "Seleccione operacion:" << std::endl;
    std::cout << "1. Insertar clave" << std::endl;
    std::cout << "2. Eliminar clave" << std::endl;
    std::cout << "3. Buscar clave" << std::endl;
    std::cout << "4. Mostrar arbol inorden" << std::endl;
    std::cout << "5. Salir" << std::endl;
    int opcion;
    std::cin >> opcion;
    keyType clave;
    switch (opcion) {
      case 1:
        std::cout << "Ingrese clave: ";
        std::cin >> clave;
        arbol->insertar(clave);
        break;
      case 2:
        std::cout << "Ingrese clave: ";
        std::cin >> clave;
        arbol->eliminar(clave);
        break;
      case 3:
        std::cout << "Ingrese clave: ";
        std::cin >> clave;
        std::cout << "Clave " << clave << ": " << arbol->buscar(clave) << std::endl;
        break;
      case 4:
        arbol->inorden();
        break;
      case 5:
        return 0;
      default:
        std::cout << "Opcion invalida" << std::endl;
    }
    // mostrar arbol
    std::cout << arbol << std::endl;
  }
}
