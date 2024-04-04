#ifndef MESA_H
#define MESA_H
#include "Cliente.h"
#include <string>
using namespace std;

class Mesa {
private:
    string tamano;
    bool reservado;
    Cliente* clienteAsignado;

public:
    Mesa(string tamano);

    string getTamano();
    Cliente* getClienteAsignado();

    void reservarMesa(Cliente* cliente);

    void liberarMesa();

    bool estaReservado();
};

#endif // MESA_H
