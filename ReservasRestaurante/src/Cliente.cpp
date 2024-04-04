#include "Cliente.h"

Cliente::Cliente(string nombre, string apellido, int edad, string CI, string tipoMesa, int posicionLlegada)
        : nombre(nombre), apellido(apellido), edad(edad), CI(CI), tipoMesa(tipoMesa), posicionLlegada(posicionLlegada) {}

    int Cliente::calcularPrioridad() {
        return posicionLlegada;
    }

    bool Cliente::operator ==(Cliente b){
        return this->CI==b.getCI();
    }

    string Cliente::getTipoMesa(){return tipoMesa;}
    string Cliente::getNombre(){return nombre;}
    string Cliente::getApellido(){return apellido;}
    string Cliente::getCI(){return CI;}
    int Cliente::getEdad(){return edad;}
    int Cliente::getPosicion(){return posicionLlegada;}
