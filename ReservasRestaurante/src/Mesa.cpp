#include "Mesa.h"

 Mesa::Mesa(string tamano) : tamano(tamano), reservado(false), clienteAsignado(nullptr) {}

    string Mesa::getTamano(){return tamano;}
    Cliente* Mesa::getClienteAsignado(){return clienteAsignado;}

    void Mesa::reservarMesa(Cliente* cliente) {
        reservado = true;
        clienteAsignado = cliente;
    }

    void Mesa::liberarMesa() {
        reservado = false;
        clienteAsignado = nullptr;
    }

    bool Mesa::estaReservado() {
        return reservado;
    }
