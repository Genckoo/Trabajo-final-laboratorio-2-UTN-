#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

class Empleado {
private:
    char nombre[20];
    char usuario[20];
    char contrasena[30];
    char email[30];
    char direccion[30];
    bool estado=false;

public:
    Empleado(const char* nom = "", const char* usr = "", const char* pass = "", const char* mail = "", const char* dir = "")
         {
        strcpy(nombre, nom);
        strcpy(usuario, usr);
        strcpy(contrasena, pass);
        strcpy(email, mail);
        strcpy(direccion, dir);
    }

    const char* getNombre() { return nombre; }
    const char* getUsuario() { return usuario; }
    const char* getContrasena() { return contrasena; }
    const char* getEmail()  { return email; }
    const char* getDireccion()  { return direccion; }
    bool getEstado(){ return estado;}

    void setNombre(const char* nom) { strcpy(nombre, nom); }
    void setUsuario(const char* usr) { strcpy(usuario, usr); }
    void setContrasena(const char* pass) { strcpy(contrasena, pass); }
    void setEmail(const char* mail) { strcpy(email, mail); }
    void setDireccion(const char* dir) { strcpy(direccion, dir); }
    void setEstado(bool est) { estado = est; }

    void mostrar() {
        if(estado){
        cout << "Nombre: " << nombre << endl;
        cout << "Usuario: " << usuario << endl;
        cout << "Email: " << email << endl;
        cout << "Dirección: " << direccion << endl;
        }
    }

    void cargar() {
        cout << "Ingrese Nombre: ";
        cargarCadena(nombre,20);
        cout << "Ingrese Usuario: ";
        cargarCadena(usuario,20);
        cout << "Ingrese Contraseña: ";
        cargarCadena(contrasena,30);
        cout << "Ingrese Email: ";
        cargarCadena(email,30);
        cout << "Ingrese Dirección: ";
        cargarCadena(direccion,30);
        estado=true;
    }
};

class ArchivoEmpleados {
private:
    char Nombre[30];

public:
    ArchivoEmpleados() {
        strcpy(Nombre, "empleados.txt");
    }
    int verificarEmpleado(char*user,char*pass);
    bool registrarEmpleado(Empleado empleado);
    void mostrarempleados();

};

bool ArchivoEmpleados::registrarEmpleado(Empleado empleado){
FILE *p;
p=fopen(Nombre,"ab");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return false;
}
fwrite(&empleado,sizeof(Empleado),1,p);
fclose(p);
return true;
}

int ArchivoEmpleados::verificarEmpleado(char*user,char*pass){
Empleado reg;
FILE *p;
p=fopen(Nombre,"rb");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return -1;
}
while(fread(&reg,sizeof(Empleado),1,p)==1){
    if((strcmp(reg.getUsuario(),user)==0)&&(strcmp(reg.getContrasena(),pass)==0)){
        fclose(p);
        return 1;
    }
}
fclose(p);
return 2;
}

void ArchivoEmpleados::mostrarempleados(){
Empleado reg;
FILE *p;
p=fopen(Nombre,"rb");
if(p==NULL){
    cout<<"no se pudo abrir el archivo"<<endl;
    fclose(p);
    return;
}
while(fread(&reg,sizeof(Empleado),1,p)==1){
        reg.mostrar();
        cout<<"=================="<<endl;
}
fclose(p);
return;
}


#endif // EMPLEADOS_H_INCLUDED
