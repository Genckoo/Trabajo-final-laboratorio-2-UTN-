#ifndef ARCHIVOCLIENTES_H_INCLUDED
#define ARCHIVOCLIENTES_H_INCLUDED


class Cliente {
private:
    int idCliente;
    char usuario[30];
    char nombre[30];
    char direccion[30];
    char telefono[15];
    char email[30];
    char contrasena[30];
    int dni;
    bool estado=true;

public:

    Cliente(int d=0, int id = 0, const char* usr = "", const char* nom = "", const char* dir = "", const char* tel = "", const char* mail = "", const char* pass = "")
        {
        dni=d;
        idCliente=id;
        strcpy(usuario, usr);
        strcpy(nombre, nom);
        strcpy(direccion, dir);
        strcpy(telefono, tel);
        strcpy(email, mail);
        strcpy(contrasena, pass);
    }

    int getdni(){return dni;}
    void setdni(int d){dni=d;}

    int getIdCliente() { return idCliente; }
    void setIdCliente(int id) { idCliente = id; }

    const char* getUsuario() {return usuario; }
    void setUsuario(const char* usr) { strcpy(usuario, usr); }

    const char* getNombre() { return nombre; }
    void setNombre(const char* nom) { strcpy(nombre, nom); }

    const char* getDireccion() { return direccion; }
    void setDireccion(const char* dir) { strcpy(direccion, dir); }

    const char* getTelefono() { return telefono; }
    void setTelefono(const char* tel) { strcpy(telefono, tel); }

    const char* getEmail() { return email; }
    void setEmail(const char* mail) { strcpy(email, mail); }

    const char* getContrasena() { return contrasena; }
    void setContrasena(const char* pass) { strcpy(contrasena, pass); }


    void cargar() {
        cout << "Ingrese Nombre: ";
        cargarCadena(nombre, 30);
        cout<<"Ingrese Dni: ";
        cin>>dni;
        cout << "Ingrese Direccion: ";
        cargarCadena(direccion, 30);
        cout << "Ingrese Telefono: ";
        cargarCadena(telefono,15);
        cout << "Ingrese Email: ";
        cargarCadena(email,30);
        cout << "Ingrese Contraseña: ";
        cargarCadena(contrasena,30);
        estado=true;
    }


void mostrarDetalles() {
    if(estado){
        cout << "ID del Cliente: " << idCliente << endl;
        cout << "Usuario: " << usuario << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Dirección: " << direccion << endl;
        cout << "Telefono: " << telefono << endl;
        cout << "Email: " << email << endl;
        }
    }
};


class ArchivoClientes {
private:
    char Nombre[30];

public:
    ArchivoClientes() {
        strcpy(Nombre,"clientes.txt");
    }
    bool registrarCliente(Cliente);
    void MostrarArchivo();
    int ContarUsuarios();
    int verificarCliente(char *nom,char *pass);
    bool existeUsuario(const char* usr) const;
};

bool ArchivoClientes::registrarCliente(Cliente newusuario){
FILE *p;
p=fopen(Nombre,"ab");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return false;
}
fwrite(&newusuario,sizeof(Cliente),1,p);
fclose(p);
return true;
}


void ArchivoClientes::MostrarArchivo(){
Cliente reg;
FILE *p;
p=fopen(Nombre,"rb");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return;
}
while(fread(&reg,sizeof(Cliente),1,p)==1){
    reg.mostrarDetalles();
    cout<<"-----------"<<endl;
}
fclose(p);
return;
}

int ArchivoClientes::ContarUsuarios(){
FILE *p;
p=fopen(Nombre,"rb");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return -1;
}
fseek(p,0,2);
return ftell(p)/sizeof(Cliente);
}

int ArchivoClientes::verificarCliente(char *user,char *pass){
Cliente reg;
FILE *p;
p=fopen(Nombre,"rb");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return -1;
}
while(fread(&reg,sizeof(Cliente),1,p)==1){
    if((strcmp(reg.getUsuario(),user)==0)&&(strcmp(reg.getContrasena(),pass)==0)){
        fclose(p);
        return 1;
    }
}
fclose(p);
return 2;
}

bool ArchivoClientes::existeUsuario(const char*usr)const{
    Cliente reg;
    FILE* p=fopen(Nombre,"rb");
    if(p==nullptr){
        cout<<"No se pudo abrir el archivo para verificar la existencia del usuario."<<endl;
        return false;
    }
    while(fread(&reg,sizeof(Cliente),1, p)==1){
        if(strcmp(reg.getUsuario(),usr)==0) {
            fclose(p);
            return true;
        }
    }
    fclose(p);
    return false;
}

void submenuClientes(char*user,char*pass){
    ArchivoGPU archigpu;;
    ArchivoFuente archifuente;;
    ArchivoCPU archicpu;;
    ArchivoMother archimother;
    ArchivoPerifericos archiperi;
    ArchivoRam archiram;
    ArchivoPc archipc;
    archivoAlmacenamiento archialma;
    Archivocarrito archicarrito;
    void armarpc(char *user);
    while(true){
     int op;
    int opc;
    cout << "BIENVENIDO A TECNOGAMER "<<user<<endl;
    cout << "========================" <<endl;
    cout << "VER PRODUCTOS:  " << endl;
    cout << "1.COMPUTADORAS PRE ARMADAS" <<endl;
    cout << "2.PLACAS DE VIDEO" <<endl;
    cout << "3.PROCESADORES" <<endl;
    cout << "4.FUENTES" <<endl;
    cout << "5.MOTHERBOARD" <<endl;
    cout << "6.MEMORIAS RAM" <<endl;
    cout << "7.PERIFERICOS" <<endl;
    cout << "8.ALMACENAMIENTO" <<endl;
    cout << "9.ARMAR PC" <<endl;
    cout << "10.CARRITO DE COMPRAS" <<endl;
    cout<<"0.volver al menu de inicio"<<endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    system("cls");
    switch (opc) {
        case 1:
            archipc.listarTodaslasPcs();
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            while(archipc.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Pcs regpc=archipc.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setPcs(regpc);
            carrito.setprecio(regpc.getPrecio());
            archicarrito.cargarcarrito(carrito,user);
            }

         break;
        case 2:
            archigpu.listarTodasLasGraficas();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archigpu.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            GPU reggpu=archigpu.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setvideo(reggpu);
            carrito.setprecio(reggpu.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
        break;
        case 3:
            archicpu.listarTodosLosCPU();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archicpu.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            CPU regcpu=archicpu.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setprocesador(regcpu);
            carrito.setprecio(regcpu.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 4:
            archifuente.listarTodasLasFuentes();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archifuente.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Fuente regfuente=archifuente.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setfuente(regfuente);
            carrito.setprecio(regfuente.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 5:
            archimother.listarTodasLasMother();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archimother.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Mother regmother=archimother.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setmother(regmother);
            carrito.setprecio(regmother.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 6:
            archiram.listarTodasLasRam();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archiram.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Rams regram=archiram.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setram(regram);
            carrito.setprecio(regram.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 7:
            archiperi.listarTodosLosPerifericos();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archiperi.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Perifericos regperi=archiperi.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setperifericos(regperi);
            carrito.setprecio(regperi.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 8:
            archialma.listarTodosLosAlmacenamientos();
            cout<<"ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
            cin>>op;
             while(archialma.verificarOpvalida(op)==false&&op!=0){
             cout<<"Opcion invalida----- "<<endl;
             cout<<"Ingrese numero de producto para agregarlo al carrito o 0 para salir: "<<endl;
             cin>>op;
            }
            if(op!=0){
            Almacenamiento regalma=archialma.BuscarProducto(op);
            VentasCarrito carrito;
            carrito.setalmacenamiento(regalma);
            carrito.setprecio(regalma.getPrecio());
            archicarrito.cargarcarrito(carrito, user);
            }
            break;
        case 9: armarpc(user);
             break;
        case 10:
            archicarrito.carrito(user);
            break;
        case 0:return;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }

}


#endif // ARCHIVOCLIENTES_H_INCLUDED
