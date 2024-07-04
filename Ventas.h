#ifndef VENTAS_H_INCLUDED
#define VENTAS_H_INCLUDED


class VentasPcArmada{
private:
    int NumVenta=0;
    char cliente[30];
    CPU procesador;
    Mother placamadre;
    GPU placavideo;
    Fuente fuente;
    Rams ram;
    Almacenamiento espacio;
public:
    void setcliente(const char *n){strcpy(cliente,n);}
    void setNumVenta(int n){NumVenta=n;}
    void setprocesador(CPU obj){procesador=obj;}
    void setmother(Mother obj){placamadre=obj;}
    void setvideo(GPU obj){placavideo=obj;}
    void setfuente(Fuente obj){fuente=obj;}
    void setram(Rams obj){ram=obj;}
    void setalmacenamiento(Almacenamiento obj){espacio=obj;};

    void mostrar(){
    cout<<"COMPRA DE: "<<cliente<<endl;
    cout<<"Numero de venta: "<<NumVenta<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Procesador: ";
    procesador.mostrarsimple();
    cout<<"Motherboard: ";
    placamadre.mostrarsimple();
    cout<<"Placa de video: ";
    placavideo.mostrarsimple();
    cout<<"Fuente: ";
    fuente.mostrarsimple();
    cout<<"Ram: ";
    ram.mostrarsimple();
    cout<<"Almacenamiento: ";
    espacio.mostrarsimple();
    }
};

class archivoVentasPcArmadas{
private:
    char nombre[20];
public:
    archivoVentasPcArmadas(const char *nom="ventaspcarmadas.txt"){
     strcpy(nombre,nom);
    }

    bool GuardarVentaPcArmada(VentasPcArmada obj);
    void listarventas();
    int contarregistros();

};


int archivoVentasPcArmadas::contarregistros(){
VentasPcArmada reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"no se pudo abrir el archivo"<<endl;
    return -1;
}
fseek(p,0,2);
return ftell(p)/sizeof(VentasPcArmada);
}


bool archivoVentasPcArmadas::GuardarVentaPcArmada(VentasPcArmada obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
int Numeroventa=contarregistros()+1;
obj.setNumVenta(Numeroventa);
fwrite(&obj,sizeof(VentasPcArmada),1,p);
fclose(p);
return true;
}


void archivoVentasPcArmadas::listarventas(){
VentasPcArmada reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"no se pudo abrir el archivo"<<endl;
    return;
}
while(fread(&reg,sizeof(VentasPcArmada),1,p)==1){
    reg.mostrar();
}
fclose(p);
return;
}







#endif // VENTAS_H_INCLUDED
