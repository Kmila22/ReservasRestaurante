#ifndef RECEPCION_H
#define RECEPCION_H
#include"Cliente.h"
#include"Mesa.h"
#include <vector>
using namespace std;

class Recepcion {
private:
    vector<Mesa*> mesas;
    vector<Cliente*> listaEspera;
    int length;

public:
    Recepcion();
    int getLength();

    void asignarMesa();

    void agregarClienteEspera(Cliente* cliente);

    void eliminarReservas();

    void revisarReservasDisponibles();

    bool verificarLE (Cliente* c1);

    void cancelarReserva(string carnet);

    void mostrarListaE();
};

#endif // RECEPCION_H
