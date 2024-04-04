#include <iostream>
#include "Cliente.h"
#include"ClienteVIP.h"
#include"Mesa.h"
#include"Recepcion.h"

using namespace std;

int main(){
    Recepcion* r=new Recepcion();

    cout << "  *******-------------------RESTAURANTE-------------------*******"<<'\n';

    int x=0;
    int opcion;
    do{
    cout << "  Seleccione la accion que desea realizar:" <<'\n';
    cout << "     1-Insertar a un nuevo cliente a la lista de espera."<<'\n';
    cout << "     2-Eliminar todas las reservas"<<'\n';
    cout << "     3-Cancelar alguna reservacion."<<'\n';
    cout << "     4-Mostrar lista de espera."<<'\n';
    cout << "     5-Obtener informacion de las recervas."<<'\n';
    cout << "     6-Reservar mesas."<<'\n';
    cout << "     7-Verificar si un cliente esta en la lista de espera."<<'\n';
    cout << "                                                                                ----------------"<<'\n';
    cout << "                                                                                8-Terminar turno"<<'\n';
    cout << "                                                                                ----------------"<<'\n';

    cin >> opcion;
    if(opcion==1){
            cout <<"------------------------------------------------------------------------"<<'\n';
            cout <<"  Usted ha seleccionado insertar un nuevo cliente en la lista de espera"<<'\n';
            cout <<"------------------------------------------------------------------------"<<'\n';
            int tipo=0;
            do{
            cout << "  Especifique la categoria del cliente:" <<'\n'<<"   1-Regular"<<'\n'<<"   2-VIP"<<'\n';
            cin>>tipo;
            }while(tipo!=1&&tipo!=2);
            string s;
            int p=0;
            do{
            cout << "  Que tipo de mesa desea el cliente:"<<'\n'<<"   1-Personal"<<'\n'<<"   2-Normal"<<'\n'<<"   3-Grande"<<'\n';
            int tamanno;
            cin>>tamanno;
            switch(tamanno){
                case 1:s="personal";p=1;break;
                case 2:s="normal";p=1;break;
                case 3:s="grande";p=1;break;
                default:{cout <<'\n'<<"   *************************************************************************************"<<'\n';
                        cout << "  ERROR:La opcion seleccionada no corresponde a ningun tipo de mesa, intentelo de nuevo"<<'\n';
                        cout <<"   *************************************************************************************"<<'\n';
                }
            }
            }while (p==0);
            cout << "  Inserte el nombre y apellido del cliente, la edad y el carnet de identidad."<<'\n';
            string nombre,apellido;
            int edad;
            string CI;
            cin>>nombre;
            cin>>apellido;
            cin>>edad;
            cin>>CI;
            if(tipo==1){
                Cliente* c1=new Cliente(nombre,apellido,edad,CI,s,r->getLength()+1);
                r->agregarClienteEspera(c1);
                }else if(tipo==2){
                    cout << "  Inserte la cantidad de puntos VIP del cliente"<<'\n';
                    int ptos;
                    cin>>ptos;
                    ClienteVIP* c1=new ClienteVIP(nombre,apellido,edad,CI,s,r->getLength()+1,ptos);
                    r->agregarClienteEspera(c1);
                }
                cout <<'\n'<<"************************************************************************************"<<'\n';
                cout <<"El cliente "<<CI<<" - "<<nombre<<" ha sido agregado a la lista de espera"<<'\n';
                cout <<"************************************************************************************"<<'\n';
                cout <<"                                                               Si desea realizar otra operacion inserte 0"<<'\n';
                int k;
                x=0;
                cin>>k;
                if(k==0)x=1;
            }else if(opcion==2){
                    r->eliminarReservas();

                    cout <<"                                                           Si desea realizar otra operacion inserte 0"<<'\n';
                    int k;
                      x=0;
                    cin>>k;
                    if(k==0)x=1;
                }else if(opcion==3){
                        cout <<"-------------------------------------------------"<<'\n';
                        cout <<"  Usted ha seleccionado cancelar una reservacion"<<'\n';
                        cout <<"-------------------------------------------------"<<'\n';
                        cout <<"  Inserte el carnet de identidad del cliente a nombre de quien esta la reservacion que desea cancelar"<<'\n';
                        string s2;
                        cin>>s2;
                        r->cancelarReserva(s2);
                        cout <<"                                                       Si desea realizar otra operacion inserte 0"<<'\n';
                        int k;
                          x=0;
                        cin>>k;
                        if(k==0)x=1;
                    }else if(opcion==8){
                            cout <<'\n'<<"-----------------------------------------------------------------------------------------------------------"<<'\n';
                            cout <<"  Usted ha seleccionado terminar el turno.Esto eliminara las reservaciones, esta seguro de querer hacerlo?"<<'\n';
                            cout <<"-----------------------------------------------------------------------------------------------------------"<<'\n';
                            cout <<"----------"<<'\n';
                            cout <<"  1-Si    "<<'\n';
                            cout <<"----------"<<'\n';
                            int i;
                            cin>>i;
                            if(i==1){
                               x=0;
                            }else {
                               x=1;
                        }
                        }else if(opcion==4){
                                cout <<"                        LISTA DE ESPERA:"<<'\n';
                                cout <<"---------------------------------------------------------------------"<<'\n';
                                r->mostrarListaE();

                                cout <<"                                               Si desea realizar otra operacion inserte 0"<<'\n';
                                int k;
                                  x=0;
                                cin>>k;
                                if(k==0)x=1;
                                }else if(opcion==5){
                                      cout <<"                     Informacion:"<<'\n';
                                      cout <<"---------------------------------------------------------------------"<<'\n';
                                      r->revisarReservasDisponibles();
                                      cout <<"                                         Si desea realizar otra operacion inserte 0"<<'\n';
                                      int k;
                                      cin>>k;
                                      if(k==0)x=1;
                                }else if(opcion==6){
                                         r->asignarMesa();
                                         cout <<"                                         Si desea realizar otra operacion inserte 0"<<'\n';
                                      int k;
                                        x=0;
                                      cin>>k;
                                      if(k==0)x=1;
                                         }else if(opcion==7){
                                            int tipo;
                                           do{
                                              cout << "  Especifique la categoria del cliente:" <<'\n'<<"   1-Regular"<<'\n'<<"   2-VIP"<<'\n';
                                              cin>>tipo;
                                            }while(tipo!=1&&tipo!=2);
                                            cout << "  Inserte el nombre y apellido del cliente, la edad y el carnet de identidad."<<'\n';
                                            string nombre,apellido;
                                            int edad;
                                            string CI;
                                            cin>>nombre;
                                            cin>>apellido;
                                            cin>>edad;
                                            cin>>CI;
                                            if(tipo==1){
                                                Cliente* c1=new Cliente(nombre,apellido,edad,CI,"",0);
                                                 if(r->verificarLE(c1)){
                                                cout<<"El cliente esta en la lista de espera."<<'\n';
                                           }else{
                                                cout<<"El cliente no esta en la lista de espera"<<'\n';
                                           }
                                                }else{
                                                ClienteVIP* c1=new ClienteVIP(nombre,apellido,edad,CI,"",0,0);
                                                 if(r->verificarLE(c1)){
                                            cout<<"El cliente esta en la lista de espera."<<'\n';
                                          }else{
                                              cout<<"El cliente no esta en la lista de espera"<<'\n';
                                          }
                                                }
                                          cout <<"                                         Si desea realizar otra operacion inserte 0"<<'\n';
                                          int k;
                                            x=0;
                                          cin>>k;
                                          if(k==0)x=1;
                                         }else{
                                              cout << "  No se ha seleccionado ninguna opcion, vuelva a intentarlo"<<'\n';
                                              x=1;
                                               }


    }while(x!=0);

    return 0;
}

