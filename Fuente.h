#ifndef FUENTE_H_INCLUDED
#define FUENTE_H_INCLUDED
class Fuente{
private:
    int idFuente;
    int stock;
    float precio;
    char descripcion[30];

public:
    Fuente(){
    idFuente=0;
    strcpy(descripcion,"");
    precio=0;
    stock=0;
    }

    int getId(){return idFuente;}
    float getPrecio(){return precio;}
    int getStock(){ return stock;}

    void setId(int nId){idFuente=nId;}
    void setPrecio(float _precio) {precio=_precio;}
    void setStock(int _stock) {stock=_stock;}

    void mostrar();
    void mostrarsimple();
    void cargar();

};


    void Fuente::cargar() {
        cout << "Descripcion del producto: ";
        cargarCadena(descripcion, 30);
        cout << "Ingrese el precio de la fuente: ";
        cin >> precio;
        cout << "Ingrese el stock disponible de la fuente: ";
        cin >> stock;
    }


    void Fuente::mostrar(){
        if(stock>0){
        cout<< "Descripcion del producto: "<<descripcion<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }

     void Fuente::mostrarsimple(){
        cout<<"Fuente: "<<descripcion<<" "<<precio<<"$"<<endl;
    }

class ArchivoFuente{
private:
    char nombre[30];

public:
    ArchivoFuente(const char* nom="Fuentes.txt"){
    strcpy(nombre,nom);
    }

    void cargarFuente();
    bool guardarFuente(Fuente obj);
    Fuente ListarFuente(int pos);
    int CantRegistros();
    void listarTodasLasFuentes();
    bool ModificarArchivo(Fuente obj, int pos);
    void modificarStock(int numProd);
    Fuente BuscarProducto(int num);
    Fuente listarFuenteComprada(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoFuente::guardarFuente(Fuente obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(Fuente),1,p);
fclose(p);
return true;
}

void ArchivoFuente::cargarFuente(){
    Fuente fuente;
    fuente.cargar();
    int id=CantRegistros()+1;
    fuente.setId(id);
    if(guardarFuente(fuente)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


Fuente ArchivoFuente::ListarFuente(int pos){
Fuente fuente;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return fuente;
}
fseek(p,sizeof(Fuente)*pos,0);
fread(&fuente,sizeof(fuente),1,p);
    fclose(p);
    return fuente;
}

Fuente ArchivoFuente::listarFuenteComprada(int numproducto){
Fuente reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(Fuente),1,p)==1){
    if(reg.getId()==numproducto){
       fclose(p);
       return reg;
    }
}
reg.setStock(-1);
fclose(p);
return reg;
}

int ArchivoFuente::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Fuente);
}

void ArchivoFuente::listarTodasLasFuentes() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    Fuente arcFuente = ListarFuente(i);
    if(arcFuente.getStock()>0){
     cout<<"Numero de producto: "<<arcFuente.getId()<<endl;
    }
    arcFuente.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoFuente::ModificarArchivo(Fuente obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Fuente) * pos, 0);
    fwrite(&obj, sizeof(Fuente), 1, p);
    fclose(p);
    return true;
}

Fuente ArchivoFuente::BuscarProducto(int num){
Fuente fuente;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivoFuente"<<endl;
    fuente.setStock(-1);
    return fuente;
}
while(fread(&fuente, sizeof(Fuente), 1, p)==1){
    if(fuente.getId()==num){
         fclose(p);
        return fuente;
    }
}
}

void ArchivoFuente::modificarStock(int numProd) {
    int newStock;
    Fuente fuentecita=BuscarProducto(numProd);
    if (fuentecita.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (fuentecita.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        fuentecita.setStock(newStock);
        if (ModificarArchivo(fuentecita, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoFuente::actualizarStockPostVenta(int numProd) {
    Fuente fuente=BuscarProducto(numProd);
        fuente.setStock(fuente.getStock()-1);
        if (ModificarArchivo(fuente, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

 bool ArchivoFuente::verificarOpvalida(int op){
 int cant=CantRegistros();
 Fuente reg;
 for(int i=0;i<cant;i++){
    reg=ListarFuente(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }
#endif // FUENTE_H_INCLUDED
