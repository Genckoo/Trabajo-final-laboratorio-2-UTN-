#ifndef CARRITO_H_INCLUDED
#define CARRITO_H_INCLUDED

class VentasCarrito{
private:
    int NumVenta=0;
    char cliente[30];
    CPU procesador;
    Mother placamadre;
    GPU placavideo;
    Fuente fuente;
    Rams ram;
    Almacenamiento espacio;
    Pcs PcPrearmada;
    Perifericos periferico;
    int precio;
    bool estado=false;
public:
    VentasCarrito() {
        procesador = CPU();
        placamadre = Mother();
        placavideo = GPU();
        fuente = Fuente();
        ram = Rams();
        espacio = Almacenamiento();
        PcPrearmada = Pcs();
        periferico = Perifericos();
        precio=0;
    }

    void setcliente(const char *n){strcpy(cliente,n);}
    void setNumVenta(int n){NumVenta=n;}
    void setprocesador(CPU obj){procesador=obj;}
    void setmother(Mother obj){placamadre=obj;}
    void setvideo(GPU obj){placavideo=obj;}
    void setfuente(Fuente obj){fuente=obj;}
    void setram(Rams obj){ram=obj;}
    void setalmacenamiento(Almacenamiento obj){espacio=obj;};
    void setPcs(Pcs obj){PcPrearmada=obj;}
    void setperifericos(Perifericos obj){periferico=obj;}
    void setprecio(int p){precio=p;}
    void setestado(bool e){estado=e;}

    const char* getcliente(){return cliente;}
    int getNumVenta(){return NumVenta;}
    GPU getvideo(){return placavideo;}
    Pcs getpc(){return PcPrearmada;}
    Mother getmother(){return placamadre;}
    Fuente getfuente(){return fuente;}
    Almacenamiento getalma(){return espacio;}
    Perifericos getperi(){return periferico;}
    CPU getcpu(){return procesador;}
    Rams getram(){return ram;}
    int getprecio(){return precio;}
    bool getestado(){return estado;}

    void mostrar(){
    cout<<"Producto numero "<<NumVenta<<endl;
    if(procesador.getId()!=0){
    procesador.mostrarsimple();
    }
    if(placamadre.getId()!=0){
    placamadre.mostrarsimple();
    }
    if(placavideo.getId()!=0){
    placavideo.mostrarsimple();
    }
    if(fuente.getId()!=0){
    fuente.mostrarsimple();
    }
    if(ram.getId()!=0){
    ram.mostrarsimple();
    }
    if(espacio.getIdAlmacenamiento()!=0){
    espacio.mostrarsimple();
    }
    if(PcPrearmada.getIdPc()!=0){
      PcPrearmada.mostrarsimple();
    }
    if(periferico.getId()!=0){
      periferico.mostrar();
    }
    }
};

class Archivocarrito{
private:
    char nombre[20];
public:
    Archivocarrito(const char *nom="carrito.txt"){
     strcpy(nombre,nom);
    }
    bool cargarcarrito(VentasCarrito obj, const char * nom);
    VentasCarrito Listarcarrito(int pos);
    int contarregistros();
    void  carrito(const char *nom);
    void menucarrito(const char *user);
    void cargarcarrito();
    VentasCarrito BuscarProducto(int num);
    void cargarcompracarrito(const char *user);
    void modificarEstado(VentasCarrito obj, int pos);
    void listarventas();
    void eliminarproductocarrito();
    void dardebajadelcarrito(VentasCarrito reg, int num);
    void actualizarstock(int *compras, int cant);
};

int Archivocarrito::contarregistros(){
FILE *p=fopen(nombre,"rb");
if(p==NULL){
     perror("no se pudo abrir el archivo");
    return -1;
}
fseek(p,0,2);
int tam=ftell(p)/sizeof(VentasCarrito);
return tam;
}

bool Archivocarrito::cargarcarrito(VentasCarrito producto, const char* user){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
     cout<<"no se pudo abrir el archivo carrito"<<endl;
    return false;
}
producto.setNumVenta(contarregistros()+1);
producto.setcliente(user);
fwrite(&producto,sizeof(VentasCarrito),1,p);
fclose(p);
return true;
}

VentasCarrito Archivocarrito::Listarcarrito(int pos){
VentasCarrito reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
fseek(p,sizeof(VentasCarrito)*pos,0);
fread(&reg,sizeof(VentasCarrito),1,p);
    fclose(p);
    return reg;
}

void Archivocarrito::menucarrito(const char *user){
while(true){
   cout<<"1.Finizalir compra"<<endl;
   cout<<"2.Eliminar producto"<<endl;
   cout<<"0.salir"<<endl;
   cout<<"Ingrese la opcion: ";
   int op;
   cin>>op;
   switch (op) {
    case 1:
    cargarcompracarrito(user);
    cout << "Gracias por su compra" << endl;
            cout << "Presione cualquier tecla para continuar...";
                cin.ignore();
                cin.get();
                break;
            case 2:
                eliminarproductocarrito();
                break;
            case 0:
                return;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo." << endl;
        }
   system("cls");
}
}


void Archivocarrito::carrito(const char *user){
VentasCarrito reg;
int cant=contarregistros();
cout<<"Carrito DE "<<user<<endl;
cout<<"---------------------"<<endl;
int total=0;
for(int i=0;i<cant;i++){
    reg=Listarcarrito(i);
    if((strcmp(reg.getcliente(),user)==0)&&reg.getestado()==false && reg.getNumVenta()!=0){
       total=total+reg.getprecio();
       reg.mostrar();
       cout<<"-----------------"<<endl;
    }
}

cout<<"Monto total: "<<total<<endl;
cout<<endl;
cout<<"Opciones: "<<endl;
menucarrito(user);
}

VentasCarrito Archivocarrito::BuscarProducto(int num){
VentasCarrito carrito;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivo ram"<<endl;
    carrito.setNumVenta(-1);
    return carrito;
}
while(fread(&carrito, sizeof(VentasCarrito), 1, p)==1){
    if(carrito.getNumVenta()==num){
         fclose(p);
        return carrito;
    }
}
}

void Archivocarrito::cargarcompracarrito(const char *user){
VentasCarrito reg;
int cant=contarregistros();
int cont=0;
for(int i=0;i<cant;i++){
    reg=Listarcarrito(i);
    if(strcmp(reg.getcliente(),user)==0 && reg.getNumVenta()!=0){
       cont++;
    }
}
int *compras=new int[cont];
int acu=0;
for(int i=0;i<cant;i++){
reg=Listarcarrito(i);
 if(strcmp(reg.getcliente(),user)==0 && reg.getNumVenta()!=0){
     compras[acu]=reg.getNumVenta();
     acu++;
    }
}
for(int i=0;i<cont;i++){
   reg=BuscarProducto(compras[i]);
   reg.setestado(true);
   modificarEstado(reg,reg.getNumVenta()-1);
}
actualizarstock(compras,cont);
delete[] compras;
}

void Archivocarrito::actualizarstock(int *compras, int cantidad){
VentasCarrito reg;
ArchivoGPU archigpu;
ArchivoCPU archicpu;
archivoAlmacenamiento archialma;
ArchivoFuente archifuente;
ArchivoRam archiram;
ArchivoPerifericos archiperi;
ArchivoPc archipc;
ArchivoMother archimother;
for(int i=0;i<cantidad;i++){
    reg=BuscarProducto(compras[i]);
     if(reg.getvideo().getId()!=0){
       archigpu.actualizarStockPostVenta(reg.getvideo().getId());
     }
     if(reg.getcpu().getId()!=0){
       archicpu.actualizarStockPostVenta(reg.getcpu().getId());
     }
     if(reg.getalma().getIdAlmacenamiento()!=0){
       archialma.actualizarStockPostVenta(reg.getalma().getIdAlmacenamiento());
     }
     if(reg.getmother().getId()!=0){
       archimother.actualizarStockPostVenta(reg.getmother().getId());
     }
     if(reg.getram().getId()!=0){
       archiram.actualizarStockPostVenta(reg.getram().getId());
     }
     if(reg.getperi().getId()!=0){
       archiperi.actualizarStockPostVenta(reg.getperi().getId());
     }
     if(reg.getfuente().getId()!=0){
       archifuente.actualizarStockPostVenta(reg.getfuente().getId());
     }
     if(reg.getpc().getIdPc()!=0){
       archipc.actualizarStockPostVenta(reg.getpc().getIdPc());
     }
}
}

void Archivocarrito::modificarEstado(VentasCarrito obj, int pos){
FILE *p;
p = fopen(nombre, "rb+");
if (p==NULL){
   cout<<" error al abrir archivo carrito";
   return;
}
fseek(p, sizeof(VentasCarrito) * pos, 0);
fwrite(&obj,sizeof(VentasCarrito), 1, p);
fclose(p);
return;
}

void Archivocarrito::listarventas(){
int cant=contarregistros();
VentasCarrito reg;
for(int i=0;i<cant;i++){
    reg=Listarcarrito(i);
    if((reg.getestado()==true)&& reg.getNumVenta()!=0){
        cout<<"cliente: "<<reg.getcliente()<<endl;
        reg.mostrar();
        cout<<"---------------"<<endl;
    }

}
}

void Archivocarrito::dardebajadelcarrito(VentasCarrito obj,int pos){
FILE *p;
p=fopen(nombre, "rb+");
if (p==NULL){
   cout<<"error al abrir archivo carrito";
   return;
}
fseek(p, sizeof(VentasCarrito) * pos, 0);
fwrite(&obj,sizeof(VentasCarrito), 1, p);
fclose(p);
return;
}

void Archivocarrito::eliminarproductocarrito(){
cout<<"Seleccione numero producto a dar de baja"<<endl;
int darbaja;
cin>>darbaja;
VentasCarrito reg;
reg=BuscarProducto(darbaja);
int pos=reg.getNumVenta()-1;
reg.setNumVenta(0);
dardebajadelcarrito(reg,pos);
}
#endif // CARRITO_H_INCLUDED
