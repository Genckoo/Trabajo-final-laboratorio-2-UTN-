#ifndef GPU_H_INCLUDED
#define GPU_H_INCLUDED

class GPU {
private:
    int IdGPU;
    char descripcion[20];
    char gama[10];
    float precio;
    int stock;

public:
    GPU(){
    IdGPU=0;
    precio=0;
    stock=0;
    strcpy(gama,"");
    }

    int getId(){return IdGPU;}
    float getPrecio(){return precio;}
    int getStock(){ return stock;}
    const char* getGama(){return gama;}

    void setGama(const char* g){strcpy(gama,g);}
    void setId(int nId){IdGPU=nId;}
    void setPrecio(float _precio) {precio=_precio;}
    void setStock(int _stock) {stock=_stock;}

    void mostrar();
    void mostrarsimple();
    void cargar();

};


    void GPU::cargar() {
        cout << "Ingrese la descripcion de la GPU: ";
        cargarCadena(descripcion, 30);
        cout<< "Ingrese la gama de la GPU: ";
        cargarCadena(gama,10);
        cout<< "Ingrese el precio de la GPU: ";
        cin>> precio;
        cout<< "Ingrese el stock disponible de la GPU: ";
        cin>> stock;
    }


    void GPU::mostrar()  {
        if(stock>0){
        cout<<"Descripcion de la GPU: "<<descripcion<<endl;
        cout<<"Gama de la GPU (1- Baja, 2 - Media, 3 - Alta): "<<gama<<endl;
        cout<< "Precio: $" << precio << endl;
        cout<< "Stock: " << stock << endl;
    }
    }
    void GPU::mostrarsimple(){
        cout<<"Placa de video: "<<descripcion<<" "<<precio<<"$"<<endl;

    }

class ArchivoGPU{

private:
    char nombre[30];

public:
    ArchivoGPU(const char* nom="Gpu.txt"){
    strcpy(nombre,nom);
    }

    void cargarGPU();
    bool guardarGPU(GPU obj);
    GPU ListarGpu(int pos);
    int CantRegistros();
    void listarTodasLasGraficas();
    bool ModificarArchivo(GPU obj, int pos);
    void modificarStock(int numProd);
    GPU BuscarProducto(int num);
    GPU listarGpuComprada(int num);
    void actualizarStockPostVenta(int num);
    bool verificarOpvalida(int op);
};

bool ArchivoGPU::guardarGPU(GPU obj){
FILE *p;
p=fopen(nombre,"ab");
if(p==NULL){
    return false;
}
fwrite(&obj,sizeof(GPU),1,p);
fclose(p);
return true;
}

void ArchivoGPU::cargarGPU(){
    GPU gpu;
    gpu.cargar();
    int id=CantRegistros()+1;
    gpu.setId(id);
    if(guardarGPU(gpu)){
        cout<<"Componente cargado con exito"<<endl;
    }else{
    cout<<"No se pudo cargar el componente"<<endl;
    }

}


GPU ArchivoGPU::ListarGpu(int pos){
GPU gpu;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return gpu;
}
fseek(p,sizeof(GPU)*pos,0);
fread(&gpu,sizeof(gpu),1,p);
    fclose(p);
    return gpu;
}

GPU ArchivoGPU::listarGpuComprada(int numproducto){
GPU reg;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
     cout<<"ERROR AL ABRIR EL ARCHIVO";
     return reg;
}
while(fread(&reg,sizeof(GPU),1,p)==1){
    if(reg.getId()==numproducto){
       fclose(p);
       return reg;
    }
}
reg.setStock(-1);
fclose(p);
return reg;
}


int ArchivoGPU::CantRegistros(){
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL)return -1;
fseek(p,0,2);
return ftell(p)/sizeof(GPU);
}

void ArchivoGPU::listarTodasLasGraficas() {
int cant = CantRegistros();
if (cant < 0) {
    cout << "no hay stock de este producto" << endl;
return;
}
for (int i = 0; i < cant; i++) {
    GPU gpu = ListarGpu(i);
    if(gpu.getStock()>0){
    cout << "Producto numero " <<gpu.getId()<< endl;
    }
    gpu.mostrar();
    cout << "==================" << endl;
}
}

//modificar stocks=============================================
bool ArchivoGPU::ModificarArchivo(GPU obj, int pos) {
    FILE *p;
    p = fopen(nombre, "rb+");
    if (p == NULL) return false;
    fseek(p, sizeof(GPU) * pos, 0);
    fwrite(&obj, sizeof(GPU), 1, p);
    fclose(p);
    return true;
}

GPU ArchivoGPU::BuscarProducto(int num){
GPU gpu;
FILE *p;
p=fopen(nombre,"rb");
if(p==NULL){
    cout<<"error al abrir archivoGpu"<<endl;
    gpu.setStock(-1);
    return gpu;
}
while(fread(&gpu, sizeof(GPU), 1, p)==1){
    if(gpu.getId()==num){
         fclose(p);
        return gpu;
    }
}
gpu.setStock(-1);
return gpu;
}

void ArchivoGPU::modificarStock(int numProd) {
    int newStock;
    GPU gpu=BuscarProducto(numProd);
    if (gpu.getStock() == -1) {
        cout << "Error al abrir el archivo" << endl;
    } else if (gpu.getStock() == -2) {
        cout << "Producto no encontrado" << endl;
    } else {
        cout<<"Ingresar nueva cantidad de stock: ";
        cin>>newStock;
        gpu.setStock(newStock);
        if (ModificarArchivo(gpu, numProd-1)) {
            system("cls");
            cout << "Modificacion exitosa" << endl;
        } else {
            cout << "Error al modificar el archivo" << endl;
        }
    }
}

void ArchivoGPU::actualizarStockPostVenta(int numProd) {
    GPU gpu=BuscarProducto(numProd);
        gpu.setStock(gpu.getStock()-1);
        if (ModificarArchivo(gpu, numProd-1)==false) {
            system("cls");
            cout << "Error al actualizar stock" << endl;
        }
    }
 bool ArchivoGPU::verificarOpvalida(int op){
 int cant=CantRegistros();
 GPU reg;
 for(int i=0;i<cant;i++){
    reg=ListarGpu(i);
    if(reg.getId()==op){
        return true;
    }
 }
 return false;
 }

#endif // GPU_H_INCLUDED
