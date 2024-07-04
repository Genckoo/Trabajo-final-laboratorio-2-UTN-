#ifndef ALMACENAMIENTO_H_INCLUDED
#define ALMACENAMIENTO_H_INCLUDED


class Almacenamiento {
private:
    int idAlmacenamiento;
    char descripcion[20];
    char tamano[20];
    int stock;
    float precio;

public:
    Almacenamiento(){
        strcpy(descripcion,"");
        strcpy(tamano,"");
        idAlmacenamiento=0;
        stock=0;
        precio=0;
    }
    int getIdAlmacenamiento()  { return idAlmacenamiento; }
    const char* getDescripcion()  { return descripcion; }
    const char* getTamano() { return tamano; }
    int getStock()  { return stock; }
    float getPrecio()  { return precio; }

    void setIdAlmacenamiento(int id) { idAlmacenamiento = id; }
    void setDescripcion(const char* desc) { strcpy(descripcion, desc); }
    void setTamano(const char* tam) { strcpy(tamano, tam); }
    void setStock(int s) { stock = s; }
    void setPrecio(float p) { precio = p; }


    void cargar() {
        cout << "Ingrese Descripcion: ";
        cargarCadena(descripcion,20);

        cout << "Ingrese Tamano: ";
       cargarCadena(tamano,10);

        cout << "Ingrese Stock: ";
        cin >> stock;

        cout << "Ingrese Precio: ";
        cin >> precio;
    }
    void mostrar() {
        if(stock>0){
        cout << "Descripcion: " << descripcion <<endl;
        cout << "Tamano: " << tamano << endl;
        cout << "Stock: " << stock << endl;
        cout << "Precio: $" << precio << endl;
        }

    }
     void mostrarsimple() {
        cout <<"Almacenamiento: "<<descripcion << "de "<<tamano<<" "<<precio<<"$"<<endl;
    }
};

class archivoAlmacenamiento{
private:
    char nombre[20];
public:
    archivoAlmacenamiento(const char*nom="almacenamiento.txt"){
    strcpy(nombre,nom);
    }
    bool guardarAlmacenamiento(Almacenamiento obj);
    void cargarAlmacenamiento();
    Almacenamiento ListarAlmacenamiento(int pos);
    int CantRegistros();
    void listarTodosLosAlmacenamientos();
    bool ModificarArchivo(Almacenamiento obj, int pos);
    void modificarStock(int numProd);
    Almacenamiento BuscarProducto(int num);
    Almacenamiento listarAlmaComprado(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool archivoAlmacenamiento::guardarAlmacenamiento(Almacenamiento obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(Almacenamiento),1,p);
fclose(p);
return true;
}

void archivoAlmacenamiento::cargarAlmacenamiento(){
    Almacenamiento alma;
    alma.cargar();
    int id=CantRegistros()+1;
    alma.setIdAlmacenamiento(id);
    if(guardarAlmacenamiento(alma)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


Almacenamiento archivoAlmacenamiento::ListarAlmacenamiento(int pos){
Almacenamiento alma;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return alma;
}
fseek(p,sizeof(Almacenamiento)*pos,0);
fread(&alma,sizeof(Almacenamiento),1,p);
    fclose(p);
    return alma;
}

Almacenamiento archivoAlmacenamiento::listarAlmaComprado(int numproducto){
Almacenamiento reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(Almacenamiento),1,p)==1){
    if(reg.getIdAlmacenamiento()==numproducto){
       fclose(p);
       return reg;
    }
}
reg.setStock(-1);
fclose(p);
return reg;
}

int archivoAlmacenamiento::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Almacenamiento);
}

void archivoAlmacenamiento::listarTodosLosAlmacenamientos() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    Almacenamiento alma = ListarAlmacenamiento(i);
    if(alma.getStock()>0){
    cout<<"Numero de producto: "<<alma.getIdAlmacenamiento()<<endl;
    }
    alma.mostrar();
    cout << "==================" << endl;
}
}

bool archivoAlmacenamiento::ModificarArchivo(Almacenamiento obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Almacenamiento) * pos, 0);
    fwrite(&obj, sizeof(Almacenamiento), 1, p);
    fclose(p);
    return true;
}

Almacenamiento archivoAlmacenamiento::BuscarProducto(int num){
Almacenamiento alma;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivo almacenamiento"<<endl;
    alma.setStock(-1);
    return alma;
}
while(fread(&alma, sizeof(Almacenamiento), 1, p)==1){
    if(alma.getIdAlmacenamiento()==num){
         fclose(p);
        return alma;
    }
}
}

void archivoAlmacenamiento::modificarStock(int numProd) {
    int newStock;
    Almacenamiento alma=BuscarProducto(numProd);
    if (alma.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (alma.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        alma.setStock(newStock);
        if (ModificarArchivo(alma, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void archivoAlmacenamiento::actualizarStockPostVenta(int numProd) {
    Almacenamiento alma=BuscarProducto(numProd);
        alma.setStock(alma.getStock()-1);
        if (ModificarArchivo(alma, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }
  bool archivoAlmacenamiento::verificarOpvalida(int op){
 int cant=CantRegistros();
 Almacenamiento reg;
 for(int i=0;i<cant;i++){
    reg=ListarAlmacenamiento(i);
    if(reg.getIdAlmacenamiento()==op){
        return true;
    }
 }
 return false;
 }
#endif // ALMACENAMIENTO_H_INCLUDED
