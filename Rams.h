#ifndef RAMS_H_INCLUDED
#define RAMS_H_INCLUDED
class Rams{
private:
    int idRam;
    int stock;
    int memoria;
    float precio;
    char descripcion[20];

public:
    Rams(){
    idRam=0;
    strcpy(descripcion, "");
    precio=0;
    stock=0;
    }

    int getId(){return idRam;}
    float getPrecio(){return precio;}
    int getStock(){return stock;}
    int getMemoria(){return memoria;}

    void setId(int nId){idRam=nId;}
    void setMemoria(int mem){memoria=mem;}
    void setPrecio(float _precio) {precio=_precio;}
    void setStock(int _stock) {stock=_stock;}

    void mostrar();
    void mostrarsimple();
    void cargar();

};


    void Rams::cargar() {
        cout << "Descripcion del producto: ";
        cargarCadena(descripcion, 20);
        cout << "Ingresar frecuencia de memoria: ";
        cin >>memoria;
        cout << "Ingrese el precio de la RAM: ";
        cin >> precio;
        cout << "Ingrese el stock disponible de la RAM: ";
        cin>>stock;
    }


    void Rams::mostrar(){
        if(stock>0){
        cout<< "Frecuencia de memoria: "<<memoria<<endl;
        cout<< "Descripcion del producto: "<<descripcion<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }

     void Rams::mostrarsimple(){
        cout<<"Rams: "<<descripcion<<"de "<<memoria<<"mhz"<<" "<<precio<<"$"<<endl;
    }

class ArchivoRam{
private:
    char nombre[30];

public:
    ArchivoRam(const char* nom="Ram.txt"){
    strcpy(nombre,nom);
    }

    void cargarRam();
    bool guardarRam(Rams obj);
    Rams ListarRam(int pos);
    int CantRegistros();
    void listarTodasLasRam();
    bool ModificarArchivo(Rams obj, int pos);
    void modificarStock(int numProd);
    Rams BuscarProducto(int num);
    Rams ListarRamComprada(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoRam::guardarRam(Rams obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(Rams),1,p);
fclose(p);
return true;
}

void ArchivoRam::cargarRam(){
    Rams ram;
    ram.cargar();
    int id=CantRegistros()+1;
    ram.setId(id);
    if(guardarRam(ram)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


Rams ArchivoRam::ListarRam(int pos){
Rams ram;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return ram;
}
fseek(p,sizeof(Rams)*pos,0);
fread(&ram,sizeof(Rams),1,p);
    fclose(p);
    return ram;
}

Rams ArchivoRam::ListarRamComprada(int numproducto){
Rams reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(Rams),1,p)==1){
    if(reg.getId()==numproducto){
       fclose(p);
       return reg;
    }
}
fclose(p);
reg.setStock(-1);
return reg;
}

int ArchivoRam::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Rams);
}

void ArchivoRam::listarTodasLasRam() {
int cant = CantRegistros();
for (int i = 0; i < cant; i++) {
    Rams arcRam = ListarRam(i);
    if(arcRam.getStock()>0){
    cout<<"Numero de producto: "<<arcRam.getId()<<endl;
    }
    arcRam.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoRam::ModificarArchivo(Rams obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Rams) * pos, 0);
    fwrite(&obj, sizeof(Rams), 1, p);
    fclose(p);
    return true;
}

Rams ArchivoRam::BuscarProducto(int num){
Rams ram;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivo ram"<<endl;
    ram.setStock(-1);
    return ram;
}
while(fread(&ram, sizeof(Rams), 1, p)==1){
    if(ram.getId()==num){
         fclose(p);
        return ram;
    }
}
}

void ArchivoRam::modificarStock(int numProd) {
    int newStock;
    Rams ram=BuscarProducto(numProd );
    if (ram.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (ram.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        ram.setStock(newStock);
        if (ModificarArchivo(ram, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoRam::actualizarStockPostVenta(int numProd) {
    Rams ram=BuscarProducto(numProd);
        ram.setStock(ram.getStock()-1);
        if (ModificarArchivo(ram, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

  bool ArchivoRam::verificarOpvalida(int op){
 int cant=CantRegistros();
 Rams reg;
 for(int i=0;i<cant;i++){
    reg=ListarRam(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }
#endif // RAMS_H_INCLUDED
