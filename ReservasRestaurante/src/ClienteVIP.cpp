#include "ClienteVIP.h"

     bool ClienteVIP::operator ==(ClienteVIP b){
        return this->CI==b.getCI();
    }

    ClienteVIP::ClienteVIP(string nombre, string apellido, int edad, string carnetIdentidad, string tipoMesa, int posicionLlegada, int ptosVIP)
        : Cliente(nombre, apellido, edad, carnetIdentidad, tipoMesa, posicionLlegada), ptosVIP(ptosVIP) {}

    int ClienteVIP::calcularPrioridad() {
        return posicionLlegada - ptosVIP;
    }
