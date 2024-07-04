using namespace std;
#include <iostream>
#include<cstring>

#include"claseFecha.h"
#include "Empleados.h"
#include "gpu.h"
#include "Fuente.h"
#include "Pcs.h"
#include "Cpu.h"
#include "almacenamiento.h"
#include "Mother.h"
#include "Perifericos.h"
#include "Rams.h"
#include "carrito.h"
#include"ArchivoClientes.h"
#include "Ventas.h"
#include "armadopc.h"
#include "Menus.h"

void registro();
void iniciarsesion();


int main() {
setlocale (LC_ALL, "Spanish");
    while(true){
    int opc;
    cout << "BIENVENIDO A TECNOGAMER" <<endl;
    cout << "========================" <<endl;
    cout << "1. Para Registrarse por primera vez" << endl;
    cout << "2. Para Iniciar Sesion" <<endl;
    cout << "3. Para entrar como visitante" <<endl;
    cout << "0. salir"<<endl;
    cout << "Ingrese su opción: ";
    cin >> opc;
    ArchivoEmpleados archiempleado;
    Empleado empleado;
    system("cls");
    switch (opc) {
        case 1:
            registro();
            break;
        case 2:
            iniciarsesion();
            break;
        case 3:
             MenuVisitante();
            break;
        case 0:
            return 0;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }

}

void registro() {
    Cliente cliente;
    ArchivoClientes archicliente;
    cout<<"COMPLETE LOS DATOS PARA REGISTRARSE"<<endl;
    cout<<"=================================="<<endl;
    char usuario[30];
    do{
        cout<<"Ingrese Usuario: ";
        cargarCadena(usuario,30);
        if(archicliente.existeUsuario(usuario)){
            cout<<"El usuario ya existe. Por favor, elija un nombre de usuario diferente."<<endl;
        }
    } while(archicliente.existeUsuario(usuario));
    cliente.cargar();
    cliente.setUsuario(usuario);
    cliente.setIdCliente(archicliente.ContarUsuarios()+1);
    if(archicliente.registrarCliente(cliente)) {
        cout<<"Bienvenido a TecnoGamers "<<cliente.getUsuario()<<endl;
    }else{
        cout<<"Error en el registro. Intente nuevamente."<<endl;
    }
}

void iniciarsesion(){
int verificarC=0;
int verificarE=0;
Cliente cliente;
ArchivoClientes archicliente;
ArchivoEmpleados archiempleado;
Empleado empleado;
do{
cout<<"INICIAR SESION"<<endl;
cout<<"================="<<endl;
cout<<"USUARIO: ";
char nombre[30];
cargarCadena(nombre,30);
cout<<"CONTRASENIA: ";
char contra[30];
cargarCadena(contra,30);
verificarC=archicliente.verificarCliente(nombre,contra);
verificarE=archiempleado.verificarEmpleado(nombre,contra);
if(verificarC==1){
    system("cls");
    submenuClientes(nombre,contra);
}
else if(verificarE==1){
system("cls");
submenuEmpleados();
}
else if(verificarC==2 && verificarE==2){
    cout<<"CONTRASEÑA O USUARIO INCORRECTA"<<endl;
    system("pause");
    system("cls");
}
}while(verificarE!=1 && verificarC!=1);
}


