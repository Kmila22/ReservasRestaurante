#ifndef CLIENTEVIP_H
#define CLIENTEVIP_H
#include "Cliente.h"

class ClienteVIP : public Cliente {
private:
    int ptosVIP;

public:
     bool operator ==(ClienteVIP b);

    ClienteVIP(string nombre, string apellido, int edad, string carnetIdentidad, string tipoMesa, int posicionLlegada, int ptosVIP);
    int calcularPrioridad() override ;
};



#endif // CLIENTEVIP_H
