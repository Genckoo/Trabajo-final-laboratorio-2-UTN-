#ifndef PCS_H_INCLUDED
#define PCS_H_INCLUDED

class Pcs{
private:
    int idPc;
    char cpu[30];
    char gpu[30];
    char fuente[30];
    char ram[30];
    char almacenamiento[30];
    char motherboard[30];
    int stock;
    float precio;
    char gama[30];

public:
    Pcs(){
        strcpy(cpu, "");
        strcpy(gpu, "");
        strcpy(fuente, "");
        strcpy(ram, "");
        strcpy(almacenamiento, "");
        strcpy(motherboard, "");
        stock=0;
        precio=0;
        strcpy(gama,"");
    }

    int getIdPc() const { return idPc; }
    const char* getCpu(){ return cpu; }
    const char* getGpu() { return gpu; }
    const char* getFuente(){ return fuente; }
    const char* getRam(){ return ram; }
    const char* getAlmacenamiento(){ return almacenamiento; }
    const char* getMotherboard(){ return motherboard; }
    int getStock(){ return stock; }
    float getPrecio(){ return precio; }
    const char* getGama(){return gama;}


    void setIdPc(int id) { idPc = id; }
    void setCpu(const char* c) { strcpy(cpu, c); }
    void setGpu(const char* g) { strcpy(gpu, g); }
    void setFuente(const char* f) { strcpy(fuente, f); }
    void setRam(const char* r) { strcpy(ram, r); }
    void setAlmacenamiento(const char* a) { strcpy(almacenamiento, a); }
    void setMotherboard(const char* m) { strcpy(motherboard, m); }
    void setStock(int s) { stock = s; }
    void setPrecio(float p) { precio = p; }
    void setGama(const char* g){strcpy(gama,g);}


    void cargar() {
        cout << "Ingrese CPU: ";
        cargarCadena(cpu,30);

        cout << "Ingrese GPU: ";
       cargarCadena(gpu,30);

        cout << "Ingrese Fuente: ";
        cargarCadena(fuente,30);

        cout << "Ingrese RAM: ";
        cargarCadena(ram,30);

        cout << "Ingrese Almacenamiento: ";
        cargarCadena(almacenamiento,30);

        cout << "Ingrese Motherboard: ";
        cargarCadena(motherboard,30);

        cout << "Ingrese Stock: ";
        cin >> stock;
        cin.ignore();

        cout << "Ingrese Precio: ";
        cin >> precio;
        cin.ignore();

        cout << "Ingrese la gama: ";
        cargarCadena(gama,30);

    }


    void mostrar(){
        if(stock>0){
        cout << "ID de la PC: " << idPc << endl;
       cout << "CPU: " << cpu << endl;
        cout << "GPU: " << gpu << endl;
        cout << "Fuente: " << fuente << endl;
        cout << "RAM: " << ram << endl;
        cout << "Almacenamiento: " << almacenamiento << endl;
        cout << "Motherboard: " << motherboard << endl;
        cout << "Stock: " << stock << endl;
        cout << "Precio: $" << precio << endl;
        cout << "GAMA: " << gama << endl;
        }

    }

    void mostrarsimple(){
    cout<<"Pc de gama "<<gama<<endl;
    cout<<"Procesador: "<<cpu<<endl;
    cout<<"Placa de video: "<<gpu<<endl;
    cout<<"Ram: "<<ram<<endl;
    cout<<"Precio: "<<precio<<"$"<<endl;

    }
};


class ArchivoPc{
private:
    char nombre[30];

public:
    ArchivoPc(const char* nom="Pcs.txt"){
    strcpy(nombre,nom);
    }
    bool guardarPc(Pcs pc);
    void cargarpc();
    Pcs ListarPc(int pos);
    int CantRegistros();
    void listarTodaslasPcs();
    bool ModificarArchivo(Pcs obj, int pos);
    void modificarStock(int numProd);
    Pcs BuscarProducto(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);

};

bool ArchivoPc::guardarPc(Pcs obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
     cout<<"error al abrir el archivo"<<endl;
    return false;
}
fwrite(&obj,sizeof(Pcs),1,p);
fclose(p);
return true;
}

void ArchivoPc::cargarpc(){
    Pcs pc;
    pc.cargar();
    int id=CantRegistros()+1;
    pc.setIdPc(id);
    if(guardarPc(pc)){
        cout<<"Nueva Pc cargada con exito"<<endl;
    }else{
    cout<<"No se pudo cargar la Pc"<<endl;
    }
}

Pcs ArchivoPc::ListarPc(int pos){
Pcs pc;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return pc;
}
fseek(p,sizeof(Pcs)*pos,0);
fread(&pc,sizeof(Pcs),1,p);
    fclose(p);
    return pc;
}


int ArchivoPc::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(Pcs);
}

void ArchivoPc::listarTodaslasPcs() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    Pcs pc;
    pc=ListarPc(i);
    if(pc.getStock()>0){
    cout << "Producto numero " <<pc.getIdPc()<< endl;
    }
    pc.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoPc::ModificarArchivo(Pcs obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(Pcs) * pos, 0);
    fwrite(&obj, sizeof(Pcs), 1, p);
    fclose(p);
    return true;
}

Pcs ArchivoPc::BuscarProducto(int num){
Pcs pc;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivoGpu"<<endl;
    pc.setStock(-1);
    return pc;
}
while(fread(&pc, sizeof(Pcs), 1, p)==1){
    if(pc.getIdPc()==num){
         fclose(p);
        return pc;
    }
}
}

void ArchivoPc::modificarStock(int numProd) {
    int newStock;
    Pcs pc=BuscarProducto(numProd);
    if (pc.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (pc.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        pc.setStock(newStock);
        if (ModificarArchivo(pc, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoPc::actualizarStockPostVenta(int numProd) {
    Pcs pc=BuscarProducto(numProd);
        pc.setStock(pc.getStock()-1);
        if (ModificarArchivo(pc, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

bool ArchivoPc::verificarOpvalida(int op){
 int cant=CantRegistros();
 Pcs reg;
 for(int i=0;i<cant;i++){
    reg=ListarPc(i);
    if(reg.getIdPc()==op){
        return true;
    }
 }
 return false;
 }
#endif // PCS_H_INCLUDED
