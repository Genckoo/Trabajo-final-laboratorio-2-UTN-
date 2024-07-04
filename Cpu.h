#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

class CPU{
private:
    int idCPU;
    int stock;
    float precio;
    char descripcion[20];
    int marca;

public:
    CPU(){
    idCPU=0;
    strcpy(descripcion, "");
    precio=0;
    stock=0;
    marca=0;
    }

    int getId(){return idCPU;}
    float getPrecio(){return precio;}
    int getStock(){ return stock;}
    int getmarca(){return marca;}

    void setId(int nId){idCPU=nId;}
    void setPrecio(float _precio){precio=_precio;}
    void setStock(int _stock){stock=_stock;}
    void setmarca(int m){marca=m;}
    void mostrar();
    void mostrarsimple();
    void cargar();

};


    void CPU::cargar() {
        cout<< "Marca del CPU(1.AMD--2.INTEL): ";
        cin>>marca;
        cout << "Descripcion del producto: ";
        cargarCadena(descripcion, 20);
        cout << "Ingrese el precio del CPU: ";
        cin >> precio;
        cout << "Ingrese el stock disponible: ";
        cin >> stock;
    }


    void CPU::mostrar(){
        if(stock>0){
        cout<< "Descripcion del producto: "<<descripcion<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }

    void CPU::mostrarsimple(){
        cout<<"Procesador: "<<descripcion<<" "<<precio<<"$"<<endl;
    }


class ArchivoCPU{
private:
    char nombre[30];

public:
    ArchivoCPU(const char* nom="Cpu.txt"){
    strcpy(nombre,nom);
    }

    void CargarCPU();
    bool guardarCPU(CPU obj);
    CPU ListarCPU(int pos);
    int CantRegistros();
    void listarTodosLosCPU();
    bool ModificarArchivo(CPU obj, int pos);
    void modificarStock(int numProd);
    CPU BuscarProducto(int num);
    CPU listarCpuComprada(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoCPU::guardarCPU(CPU obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(CPU),1,p);
fclose(p);
return true;
}

void ArchivoCPU::CargarCPU(){
    CPU cpu;
    cpu.cargar();
    int id=CantRegistros()+1;
    cpu.setId(id);
    if(guardarCPU(cpu)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


CPU ArchivoCPU::ListarCPU(int pos){
CPU cpu;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return cpu;
}
fseek(p,sizeof(CPU)*pos,0);
fread(&cpu,sizeof(cpu),1,p);
    fclose(p);
    return cpu;
}

CPU ArchivoCPU::listarCpuComprada(int numproducto){
CPU reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(CPU),1,p)==1){
    if(reg.getId()==numproducto){
     fclose(p);
      return reg;
    }
}
reg.setStock(-1);
fclose(p);
return reg;
}

int ArchivoCPU::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(CPU);
}

void ArchivoCPU::listarTodosLosCPU() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "Error al abrir el archivo o el archivo está vacío" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    CPU arcCPU = ListarCPU(i);
    if(arcCPU.getStock()>0){
    cout<<"Numero de producto: "<<arcCPU.getId()<<endl;
    }
    arcCPU.mostrar();
    cout << "==================" << endl;
}
}

bool ArchivoCPU::ModificarArchivo(CPU obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(CPU) * pos, 0);
    fwrite(&obj, sizeof(CPU), 1, p);
    fclose(p);
    return true;
}

CPU ArchivoCPU::BuscarProducto(int num){
CPU cpu;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivo cpu"<<endl;
    cpu.setStock(-1);
    return cpu;
}
while(fread(&cpu, sizeof(CPU), 1, p)==1){
    if(cpu.getId()==num){
         fclose(p);
        return cpu;
    }
}
}

void ArchivoCPU::modificarStock(int numProd) {
    int newStock;
    CPU cpu=BuscarProducto(numProd);
    if (cpu.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (cpu.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        cpu.setStock(newStock);
        if (ModificarArchivo(cpu, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoCPU::actualizarStockPostVenta(int numProd){
    CPU cpu=BuscarProducto(numProd);
        cpu.setStock(cpu.getStock()-1);
        if (ModificarArchivo(cpu, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }

 bool ArchivoCPU::verificarOpvalida(int op){
 int cant=CantRegistros();
 CPU reg;
 for(int i=0;i<cant;i++){
    reg=ListarCPU(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }
#endif // CPU_H_INCLUDED
