#ifndef PERIFERICOS_H_INCLUDED
#define PERIFERICOS_H_INCLUDED
class Perifericos{
private:
    int idPeriferico;
    int stock;
    float precio;
    char descripcion[40];

public:
    Perifericos(){
    idPeriferico=0;
    strcpy(descripcion, "");
    precio=0;
    stock=0;
    }

    int getId(){return idPeriferico;}
    float getPrecio(){return precio;}
    int getStock(){ return stock;}

    void setId(int nId){idPeriferico=nId;}
    void setPrecio(float _precio) {precio=_precio;}
    void setStock(int _stock) {stock=_stock;}

    void mostrar();
    void cargar();

};


    void Perifericos::cargar() {
        cout << "Descripcion del producto: ";
        cargarCadena(descripcion, 40);
        cout << "Ingrese el precio del periferico: ";
        cin >> precio;
        cout << "Ingrese el stock disponible del periferico: ";
        cin >> stock;
    }


    void Perifericos::mostrar(){
        if(stock>0){
        cout<< "Descripcion del producto: "<<descripcion<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }

class ArchivoPerifericos{
private:
    char nombre[30];

public:
    ArchivoPerifericos(const char* nom="Perifericos.txt"){
    strcpy(nombre,nom);
    }

    void cargarPeriferico();
    bool guardarPeriferico(Perifericos obj);
    Perifericos ListarPeriferico(int pos);
    int CantRegistros();
    void listarTodosLosPerifericos();
    bool ModificarArchivo(Perifericos obj, int pos);
    void modificarStock(int numProd);
    Perifericos BuscarProducto(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoPerifericos::guardarPeriferico(Perifericos obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(Perifericos),1,p);
fclose(p);
return true;
}

void ArchivoPerifericos::cargarPeriferico(){
    Perifericos peri;
    peri.cargar();
    int id=CantRegistros()+1;
    peri.setId(id);
    if(guardarPeriferico(peri)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


Perifericos ArchivoPerifericos::ListarPeriferico(int pos){
Perifericos peri;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return peri;
}
fseek(p,sizeof(Perifericos)*pos,0);
fread(&peri,sizeof(peri),1,p);
    fclose(p);
    return peri;
}


int ArchivoPerifericos::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Perifericos);
}

void ArchivoPerifericos::listarTodosLosPerifericos() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    Perifericos arcPeri = ListarPeriferico(i);
    if(arcPeri.getStock()>0){
    cout<<"Numero de producto: "<<arcPeri.getId()<<endl;
    }
    arcPeri.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoPerifericos::ModificarArchivo(Perifericos obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Perifericos) * pos, 0);
    fwrite(&obj, sizeof(Perifericos), 1, p);
    fclose(p);
    return true;
}

Perifericos ArchivoPerifericos::BuscarProducto(int num){
Perifericos peri;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivoGpu"<<endl;
    peri.setStock(-1);
    return peri;
}
while(fread(&peri, sizeof(Perifericos), 1, p)==1){
    if(peri.getId()==num){
         fclose(p);
        return peri;
    }
}
}

void ArchivoPerifericos::modificarStock(int numProd) {
    int newStock;
    Perifericos peri=BuscarProducto(numProd);
    if (peri.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (peri.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        peri.setStock(newStock);
        if (ModificarArchivo(peri, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoPerifericos::actualizarStockPostVenta(int numProd) {
    Perifericos peri=BuscarProducto(numProd);
        peri.setStock(peri.getStock()-1);
        if (ModificarArchivo(peri, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

  bool ArchivoPerifericos::verificarOpvalida(int op){
 int cant=CantRegistros();
 Perifericos reg;
 for(int i=0;i<cant;i++){
    reg=ListarPeriferico(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }
#endif // PERIFERICOS_H_INCLUDED
