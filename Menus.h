#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void MenuVisitante(){
    ArchivoGPU obj;
    ArchivoFuente obj1;
    ArchivoCPU obj2;
    ArchivoMother obj3;
    ArchivoPerifericos obj4;
    ArchivoRam obj5;
    ArchivoPc objpc;
    archivoAlmacenamiento objalma;
    void armarpc();
    while(true){
     int opc;
    cout << "BIENVENIDO A TECNOGAMER "<<endl;
    cout << "========================" <<endl;
    cout << "REGISTRESE PARA TENER USO COMPLETO DE LA INTERFAZ" <<endl;
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
    cout<<"0.volver al menu de inicio"<<endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    system("cls");
    switch (opc) {
        case 1:
            objpc.listarTodaslasPcs();
            break;
        case 2:
            obj.listarTodasLasGraficas();
            break;
        case 3:
            obj2.listarTodosLosCPU();
            break;
        case 4:
            obj1.listarTodasLasFuentes();
            break;
        case 5:
            obj3.listarTodasLasMother();
            break;
        case 6:
            obj5.listarTodasLasRam();
            break;
        case 7:
            obj4.listarTodosLosPerifericos();
            break;
        case 8:
            objalma.listarTodosLosAlmacenamientos();
            break;
        case 9: armarpc();
            break;
        case 0:
            return ;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }
}


void agregarProducto(){
ArchivoGPU gpu;
ArchivoFuente fuente;
ArchivoCPU cpu;
ArchivoMother moth;
ArchivoRam ram;
ArchivoPerifericos peri;
archivoAlmacenamiento alma;
ArchivoPc archiopc;
while(true){
    int opc;
    cout<<"TIPO DE PRODUCTO A AGREGAR:"<<endl;
    cout << "1.COMPUTADORAS PRE ARMADAS" <<endl;
    cout << "2.PLACAS DE VIDEO" <<endl;
    cout << "3.PROCESADORES" <<endl;
    cout << "4.FUENTES" <<endl;
    cout << "5.MOTHERBOARD" <<endl;
    cout << "6.MEMORIAS RAM" <<endl;
    cout << "7.PERIFERICOS" <<endl;
    cout << "8.ALMACENAMIENTO" <<endl;
    cout<<"0.volver al menu principal"<<endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    system("cls");
    switch (opc) {
        case 1:
            archiopc.cargarpc();
            break;
        case 2:
            gpu.cargarGPU();
            break;
        case 3:
            cpu.CargarCPU();
            break;
        case 4:
            fuente.cargarFuente();
            break;
        case 5:
            moth.CargarMother();
            break;
        case 6:
            ram.cargarRam();
            break;
        case 7:
            peri.cargarPeriferico();
            break;
        case 8:
            alma.cargarAlmacenamiento();
            break;
        case 0:
            return;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }
}

void menuModStock(){
ArchivoGPU gpu;
ArchivoFuente fuentecita;
ArchivoCPU cpu;
ArchivoMother moth;
ArchivoPerifericos peri;
ArchivoRam ram;
ArchivoPc pc;
archivoAlmacenamiento alma;
while(true){
    int opc;
    cout<<"TIPO DE PRODUCTO AL QUE QUIERAS MODIFICAR STOCK:"<<endl;
    cout<<endl;
    cout << "1.COMPUTADORAS PRE ARMADAS" <<endl;
    cout << "2.PLACAS DE VIDEO" <<endl;
    cout << "3.PROCESADORES" <<endl;
    cout << "4.FUENTES" <<endl;
    cout << "5.MOTHERBOARD" <<endl;
    cout << "6.MEMORIAS RAM" <<endl;
    cout << "7.PERIFERICOS" <<endl;
    cout << "8.ALMACENAMIENTO" <<endl;
    cout<<"0.volver al menu principal"<<endl;
    cout<<endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    system("cls");
    switch (opc) {
        case 1:
            int numProd8;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            pc.listarTodaslasPcs();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd8;
            while(pc.verificarOpvalida(numProd8)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd8;
            }
            pc.modificarStock(numProd8);
            break;
        case 2:
            int numProd;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            gpu.listarTodasLasGraficas();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd;
            while(gpu.verificarOpvalida(numProd)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd;
            }
            gpu.modificarStock(numProd);
            break;
        case 3:
            int numProd3;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            cpu.listarTodosLosCPU();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd3;
            while(cpu.verificarOpvalida(numProd3)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd3;
            }
            cpu.modificarStock(numProd3);
            break;
        case 4:
            int numProd2;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            fuentecita.listarTodasLasFuentes();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd2;
            while(fuentecita.verificarOpvalida(numProd2)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd2;
            }
            fuentecita.modificarStock(numProd2);
            break;
        case 5:
            int numProd4;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            moth.listarTodasLasMother();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd4;
            while(pc.verificarOpvalida(numProd4)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd4;
            }
            moth.modificarStock(numProd4);
            break;
        case 6:
            int numProd5;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            ram.listarTodasLasRam();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd5;
            while(pc.verificarOpvalida(numProd5)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd5;
            }
            ram.modificarStock(numProd5);
            break;
        case 7:
            int numProd6;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            peri.listarTodosLosPerifericos();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd6;
            while(pc.verificarOpvalida(numProd6)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd6;
            }
            peri.modificarStock(numProd6);
            break;
        case 8:
            int numProd7;
            cout<<"Estos son los productos de esta seccion"<<endl;
            cout<<"======================================="<<endl;
            alma.listarTodosLosAlmacenamientos();
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd7;
            while(pc.verificarOpvalida(numProd7)==false){
            cout<<"Opcion invalida"<<endl;
            cout<<"Cual producto desea modificar en stock?, ingresar numero del producto: ";
            cin>>numProd7;
            }
            alma.modificarStock(numProd7);
            break;
        case 0:
            return;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }
}
archivoVentasPcArmadas archi;
ArchivoClientes archiclientes;
Archivocarrito archicarrito;
void submenuEmpleados(){
while(true){
    int opc;
    cout << "ADMINISTRACION DE TECNOGAMERS "<<endl;
    cout << "========================" <<endl;
    cout << "1.VENTAS" <<endl;
    cout << "2.CLIENTES" <<endl;
    cout << "3.MODIFICAR STOCK" <<endl;
    cout << "4.AGREGAR EQUIPO O PRODUCTO" <<endl;
    cout<<"0.volver al menu de inicio"<<endl;
    cout << "Ingrese su opcion: ";
    cin >> opc;
    int cont=0;
    system("cls");
    switch (opc) {
        case 1:
            archi.listarventas();
            cout<<"-----------------"<<endl;
            cout<<"COMPRAS POR CARRITO"<<endl;
            archicarrito.listarventas();
            break;
        case 2:
            archiclientes.MostrarArchivo();
            break;
        case 3:
            menuModStock();
            break;
        case 4:
            agregarProducto();
            break;
        case 5:
            break;
        case 0:return;
               return;
            break;
        default:
            break;
    }
    system("pause");
    system("cls");
    }

}
#endif // MENUS_H_INCLUDED
