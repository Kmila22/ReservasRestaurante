#include "Recepcion.h"
#include <iostream>
#include <algorithm>

    Recepcion::Recepcion() {
        length=0;
        for (int i = 0; i < 5; ++i) {
            mesas.push_back(new Mesa("grande"));
        }
        for (int i = 0; i < 4; ++i) {
            mesas.push_back(new Mesa("normal"));
        }
        for (int i = 0; i < 6; ++i) {
            mesas.push_back(new Mesa("personal"));
        }
    }
    int Recepcion::getLength(){return length;}

    void Recepcion::asignarMesa() {
        // Buscar una mesa libre y asignarla al primer cliente en la lista de espera cuyo tipo de mesa coincida
        for (Mesa* mesa : mesas) {
            if (!mesa->estaReservado()) {
                for (int i=0;i<listaEspera.size();i++) {
                    if (listaEspera[i]->getTipoMesa()== mesa->getTamano()) {
                        mesa->reservarMesa(listaEspera[i]);
                        cout << "Mesa asignada a: " << listaEspera[i]->getNombre() << " " << listaEspera[i]->getApellido() << endl;
                        listaEspera.erase(listaEspera.begin()+i);
                    }
                }
            }
        }
        if(mesas.empty()){
           cout << "No hay mesas disponibles para los clientes en espera." << endl;
           return;
        }else if(listaEspera.empty()){
            cout << "No hay clientes en la lista de espera." << endl;
            return;
        }


    }

    void Recepcion::agregarClienteEspera(Cliente* cliente) {
        listaEspera.push_back(cliente);
        length++;
        cout << "Cliente añadido a la lista de espera: " << cliente->getNombre() << " " << cliente->getApellido() << endl;
        sort(listaEspera.begin(),listaEspera.end(),[](Cliente* a, Cliente* b){
             return a->calcularPrioridad()< b->calcularPrioridad();
             });
    }

    void Recepcion::eliminarReservas() {
        for (Mesa* mesa : mesas) {
            mesa->liberarMesa();
        }
        cout << "Todas las reservas han sido eliminadas." << endl;
    }

    void Recepcion::revisarReservasDisponibles() {
        for (int i = 0; i < mesas.size(); i++) {
            cout << "Mesa " << i+1 << ": ";
            if (mesas[i]->estaReservado()) {
                cout << "Reservada para " << mesas[i]->getClienteAsignado()->getNombre() << " " << mesas[i]->getClienteAsignado()->getApellido() << endl;
            } else {
                cout << "Libre" << endl;
            }
        }
    }

    bool Recepcion::verificarLE (Cliente* c1){
        for(Cliente* c:listaEspera){
            if(*c==*c1){
                return true;
            }
        }
        return false;
    }


    void Recepcion::cancelarReserva(string carnet) {
        for (Mesa* mesa : mesas) {
            if (mesa->estaReservado() && mesa->getClienteAsignado()->getCI() == carnet) {
                mesa->liberarMesa();
                cout << "La reserva para el cliente con carnet " << carnet << " ha sido eliminada." << endl;
                return;
            }
        }
        cout << "No se encontró ninguna reserva para el cliente con carnet " << carnet << "." << endl;
    }

    void Recepcion::mostrarListaE(){
                for (Cliente* c : listaEspera){
                    cout << c->getNombre()+"   "+c->getApellido()+"   "+c->getCI() <<endl;
                }
            }
