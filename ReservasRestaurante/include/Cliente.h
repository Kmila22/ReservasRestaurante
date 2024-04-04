#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

class Cliente {
protected:
    string nombre;
    string apellido;
    int edad;
    string CI;
    string tipoMesa;
    int posicionLlegada;

public:
    Cliente(string nombre, string apellido, int edad, string CI, string tipoMesa, int posicionLlegada);
    virtual int calcularPrioridad();
    bool operator ==(Cliente b);
    string getTipoMesa();
    string getNombre();
    string getApellido();
    string getCI();
    int getEdad();
    int getPosicion();
};


#endif // CLIENTE_H
