#ifndef CLASEFECHA_H_INCLUDED
#define CLASEFECHA_H_INCLUDED

#include <iostream>
#include <ctime>
using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(int d = 1, int m = 1, int a = 1900) {
        dia = d;
        mes = m;
        anio = a;
    }
    void Cargar();
    void Mostrar();
    bool ValidarFecha();
};

void Fecha::Cargar() {
    cout << "DIA: ";
    cin >> dia;
    cout << "MES: ";
    cin >> mes;
    cout << "ANIO: ";
    cin >> anio;

    while (ValidarFecha()==false) {
        cout << "La fecha ingresada no es válida, por favor ingrese una fecha válida" << endl;
        cout << "DIA: ";
        cin >> dia;
        cout << "MES: ";
        cin >> mes;
        cout << "ANIO: ";
        cin >> anio;
    }
}

bool Fecha::ValidarFecha() {
    time_t ahora = time(0);
    tm* tiempo_actual = localtime(&ahora);
    if (anio > (tiempo_actual->tm_year + 1900) || anio < 0) {
        return false;
    }
    if (anio == (tiempo_actual->tm_year + 1900)) {
        if (mes > (tiempo_actual->tm_mon + 1) || mes < 1) {
            return false;
        }
        if (mes == (tiempo_actual->tm_mon + 1)) {
            if (dia > tiempo_actual->tm_mday || dia < 1 ||dia>31) {
                return false;
            }
        }
    }

    return true;
}

void Fecha::Mostrar() {
    cout << dia << "/" << mes << "/" << anio;
}

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}



#endif // CLASEFECHA_H_INCLUDED
