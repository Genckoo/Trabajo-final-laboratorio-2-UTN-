#ifndef MOTHER_H_INCLUDED
#define MOTHER_H_INCLUDED

class Mother{
private:
    int idMOTHER;
    int stock;
    float precio;
    char descripcion[20];
    int marca;

public:
    Mother(){
    idMOTHER=0;
    strcpy(descripcion, "");
    precio=0;
    stock=0;
    marca=0;
    }

    int getId(){return idMOTHER;}
    float getPrecio(){return precio;}
    int getStock(){ return stock;}
    int getmarca(){return marca;}

    void setId(int nId){idMOTHER=nId;}
    void setPrecio(float _precio){precio=_precio;}
    void setStock(int _stock){stock=_stock;}
    void mostrar();
    void mostrarsimple();
    void cargar();

};


    void Mother::cargar() {
        cout<<"Marca del producto(1.AMD---2.INTEL): "<<endl;
        cin>>marca;
        cout << "Descripcion del producto: ";
        cargarCadena(descripcion, 20);
        cout << "Ingrese el precio de la MOTHER: ";
        cin >> precio;
        cout << "Ingrese el stock disponible de la MOTHER: ";
        cin >> stock;
    }


    void Mother::mostrar(){
        if(stock>0){
        cout<< "Descripcion del producto: "<<descripcion<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }

     void Mother::mostrarsimple(){
        cout<<"Motherboard: "<<descripcion<<" "<<precio<<"$"<<endl;
    }

class ArchivoMother{
private:
    char nombre[30];

public:
    ArchivoMother(const char* nom="Mother.txt"){
    strcpy(nombre,nom);
    }

    void CargarMother();
    bool guardarMother(Mother obj);
    Mother ListarMother(int pos);
    int CantRegistros();
    void listarTodasLasMother();
    bool ModificarArchivo(Mother obj, int pos);
    void modificarStock(int numProd);
    Mother BuscarProducto(int num);
    Mother listarMotherComprada(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoMother::guardarMother(Mother obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(Mother),1,p);
fclose(p);
return true;
}

void ArchivoMother::CargarMother(){
    Mother mother;
    mother.cargar();
    int id=CantRegistros()+1;
    mother.setId(id);
    if(guardarMother(mother)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


Mother ArchivoMother::ListarMother(int pos){
Mother mother;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return mother;
}
fseek(p,sizeof(Mother)*pos,0);
fread(&mother,sizeof(mother),1,p);
    fclose(p);
    return mother;
}

Mother ArchivoMother::listarMotherComprada(int numproducto){
Mother reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(Mother),1,p)==1){
    if(reg.getId()==numproducto){
       fclose(p);
       return reg;
    }
}
reg.setStock(-1);
fclose(p);
return reg;
}

int ArchivoMother::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Mother);
}

void ArchivoMother::listarTodasLasMother() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    Mother arcMot = ListarMother(i);
    if(arcMot.getStock()>0){
    cout<<"Numero de producto: "<<arcMot.getId()<<endl;
    }
    arcMot.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoMother::ModificarArchivo(Mother obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Mother) * pos, 0);
    fwrite(&obj, sizeof(Mother), 1, p);
    fclose(p);
    return true;
}

Mother ArchivoMother::BuscarProducto(int num){
Mother mother;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivo mother"<<endl;
    mother.setStock(-1);
    return mother;
}
while(fread(&mother, sizeof(Mother), 1, p)==1){
    if(mother.getId()==num){
         fclose(p);
        return mother;
    }
}
}

void ArchivoMother::modificarStock(int numProd) {
    int newStock;
    Mother moth=BuscarProducto(numProd);
    if (moth.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (moth.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        moth.setStock(newStock);
        if (ModificarArchivo(moth, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoMother::actualizarStockPostVenta(int numProd) {
    Mother mother=BuscarProducto(numProd);
        mother.setStock(mother.getStock()-1);
        if (ModificarArchivo(mother, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

 bool ArchivoMother::verificarOpvalida(int op){
 int cant=CantRegistros();
 Mother reg;
 for(int i=0;i<cant;i++){
    reg=ListarMother(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }
#endif // MOTHER_H_INCLUDED
