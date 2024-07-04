#ifndef ARMADOPC_H_INCLUDED
#define ARMADOPC_H_INCLUDED

void actualizarstock(int *v);
void armadoCPU(int *v, int marca);
void armadoMother(int *v, int marca);
void armadoGPU(int *V);
void armadoFUENTE(int *v);
void armadoRam(int *v);
void armadoAlmacenamiento(int *v);
void armadoFinal(int *v,char *user);
void armadoFinal(int *v);
void armarpc(char *user){
int  opmarca;
int Varmada[6]={0};
cout<<"ELIJA MARCA DE PC:"<<endl;
cout<<"1.AMD---2.INTEL"<<endl;
cin>>opmarca;
system("cls");
while(true){
cout<<"ARMADO DE PC:"<<endl;
cout<<"============="<<endl;
cout<<"1.PROCESADOR"<<endl;
cout<<"2.MOTHERBOARD"<<endl;
cout<<"3.PLACA DE VIDEO"<<endl;
cout<<"4.FUENTE"<<endl;
cout<<"5.RAMS"<<endl;
cout<<"6.ALMACENAMIENTO"<<endl;
cout<<"7.Detalles de PC/COMPRA"<<endl;
cout<<"0.Salir de armado de Pc"<<endl;
int op;
cout<<"SELECCIONE OPCION DE COMPONENTE: ";
cin>>op;
 switch(op){
    case 1:
         system("cls");
         armadoCPU(Varmada,opmarca);
   break;
    case 2:
          system("cls");
         armadoMother(Varmada,opmarca);
   break;
    case 3:
      system("cls");
      armadoGPU(Varmada);
   break;
    case 4:
     system("cls");
    armadoFUENTE(Varmada);
   break;
    case 5:
    system("cls");
    armadoRam(Varmada);
   break;
    case 6:
    system("cls");
    armadoAlmacenamiento(Varmada);
   break;
    case 7:
    system("cls");
    armadoFinal(Varmada,user);
    system("pause");
   break;
     case 0: return;
     break;
    default:
     break;

 }
system("cls");
}
}

void armarpc(){
int  opmarca;
int Varmada[6]={0};
cout<<"ELIJA MARCA DE PC:"<<endl;
cout<<"1.AMD---2.INTEL"<<endl;
cin>>opmarca;
system("cls");
while(true){
cout<<"ARMADO DE PC:"<<endl;
cout<<"============="<<endl;
cout<<"1.PROCESADOR"<<endl;
cout<<"2.MOTHERBOARD"<<endl;
cout<<"3.PLACA DE VIDEO"<<endl;
cout<<"4.FUENTE"<<endl;
cout<<"5.RAMS"<<endl;
cout<<"6.ALMACENAMIENTO"<<endl;
cout<<"7.Detalles de PC/COMPRA"<<endl;
cout<<"0.Salir de armado de Pc"<<endl;
int op;
cout<<"SELECCIONE OPCION DE COMPONENTE: ";
cin>>op;
 switch(op){
    case 1:
         system("cls");
         armadoCPU(Varmada,opmarca);
   break;
    case 2:
          system("cls");
         armadoMother(Varmada,opmarca);
   break;
    case 3:
      system("cls");
      armadoGPU(Varmada);
   break;
    case 4:
     system("cls");
    armadoFUENTE(Varmada);
   break;
    case 5:
    system("cls");
    armadoRam(Varmada);
   break;
    case 6:
    system("cls");
    armadoAlmacenamiento(Varmada);
   break;
    case 7:
    system("cls");
    armadoFinal(Varmada);
    system("pause");
   break;
     case 0: return;
     break;
    default:
     break;

 }
system("cls");
}
}

void armadoCPU(int *v, int marca){
 ArchivoCPU archi;
 int cant;
 CPU reg;
 cant=archi.CantRegistros();
 cout<<"PROCESADORES:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarCPU(i);
    if(reg.getmarca()==marca && reg.getStock()!=0){
        cout<<"Numero de producto: "<<reg.getId()<<endl;
        reg.mostrar();
        cout<<"------------"<<endl;
    }
 }
cout<<endl;
int opcpu;
cout<<"Escriba el numero de producto: "<<endl;
cin>>opcpu;
reg=archi.listarCpuComprada(opcpu);
while(reg.getStock()==-1 || reg.getmarca()!=marca){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opcpu;
reg=archi.listarCpuComprada(opcpu);
 }
 v[0]=opcpu;
}
void armadoMother(int *v,int marca){
 ArchivoMother archi;
 int cant;
 Mother reg;
 cant=archi.CantRegistros();
  cout<<"MOTHERBOARD AMD:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarMother(i);
    if(reg.getmarca()==marca && reg.getStock()!=0){
        cout<<"Numero de producto: "<<reg.getId()<<endl;
        reg.mostrar();
        cout<<"------------"<<endl;
    }
 }
 cout<<endl;
 int opmother;
 cout<<"Escriba el numero de producto: "<<endl;
 cin>>opmother;
 reg=archi.listarMotherComprada(opmother);
while(reg.getStock()==-1 || reg.getmarca()!=marca){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opmother;
reg=archi.listarMotherComprada(opmother);
 }
 v[1]=opmother;
}

void armadoGPU(int *v){
ArchivoGPU archi;
 int cant;
 GPU reg;
 cant=archi.CantRegistros();
  cout<<"PLACAS DE VIDEO:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarGpu(i);
    if(reg.getStock()!=0){
    cout<<"Numero de producto: "<<reg.getId()<<endl;
    reg.mostrar();
    cout<<"------------"<<endl;
    }
 }
 cout<<endl;
 int opgpu;
 cout<<"Escriba el numero de producto: "<<endl;
 cin>>opgpu;
 reg=archi.listarGpuComprada(opgpu);
while(reg.getStock()==-1){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opgpu;
reg=archi.listarGpuComprada(opgpu);
 }
 v[2]=opgpu;
}

void armadoFUENTE(int *v){
ArchivoFuente archi;
 int cant;
 Fuente reg;
 cant=archi.CantRegistros();
  cout<<"FUENTES:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarFuente(i);
    if(reg.getStock()!=0){
    cout<<"Numero de producto: "<<reg.getId()<<endl;
    reg.mostrar();
    cout<<"------------"<<endl;
    }
 }
 cout<<endl;
 int opfuente;
 cout<<"Escriba el numero de producto: "<<endl;
 cin>>opfuente;
 reg=archi.listarFuenteComprada(opfuente);
while(reg.getStock()==-1){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opfuente;
reg=archi.listarFuenteComprada(opfuente);
 }
 v[3]=opfuente;
}

void armadoRam(int *v){
ArchivoRam archi;
 int cant;
 Rams reg;
 cant=archi.CantRegistros();
  cout<<"RAMS:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarRam(i);
    if(reg.getStock()!=0){
    cout<<"Numero de producto: "<<reg.getId()<<endl;
    reg.mostrar();
    cout<<"------------"<<endl;
    }
 }
 cout<<endl;
 int opram;
 cout<<"Escriba el numero de producto: "<<endl;
 cin>>opram;
 reg=archi.ListarRamComprada(opram);
while(reg.getStock()==-1){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opram;
reg=archi.ListarRamComprada(opram);
 }
 v[4]=opram;
}

void armadoAlmacenamiento(int *v){
archivoAlmacenamiento archi;
 int cant;
 Almacenamiento reg;
 cant=archi.CantRegistros();
  cout<<"ALMACENAMIENTO:"<<endl;
 cout<<"________________"<<endl;
 for(int i=0;i<cant;i++){
    reg=archi.ListarAlmacenamiento(i);
    if(reg.getStock()!=0){
    cout<<"Numero de producto: "<<reg.getIdAlmacenamiento()<<endl;
    reg.mostrar();
    cout<<"------------"<<endl;
    }
 }
 cout<<endl;
 int opalma;
 cout<<"Escriba el numero de producto: "<<endl;
 cin>>opalma;
 reg=archi.listarAlmaComprado(opalma);
while(reg.getStock()==-1){
cout<<"Opcion invalida, ingrese un numero de producto valido:"<<endl;
cin>>opalma;
reg=archi.listarAlmaComprado(opalma);
 }
 v[5]=opalma;
 system("pause");


}

void armadoFinal(int *v,  char *user){
archivoVentasPcArmadas archi;
VentasPcArmada PcArmada;
int MontoTotal=0;
int contador=0;
ArchivoCPU archicpu;
CPU regcpu=archicpu.listarCpuComprada(v[0]);
if(v[0]==0){
    cout<<"Procesador: Falta elegir"<<endl;
}else{
regcpu.mostrarsimple();
MontoTotal+=regcpu.getPrecio();
contador++;
PcArmada.setprocesador(regcpu);
}

cout<<"--------------"<<endl;

ArchivoMother archimother;
Mother regmother=archimother.listarMotherComprada(v[1]);
if(v[1]==0){
     cout<<"Motherboard: Falta elegir"<<endl;
}else{
regmother.mostrarsimple();
MontoTotal+=regmother.getPrecio();
contador++;
PcArmada.setmother(regmother);
}

cout<<"--------------"<<endl;

ArchivoGPU archigpu;
GPU reggpu=archigpu.listarGpuComprada(v[2]);
if(v[2]==0){
   cout<<"Placa de video: Falta elegir"<<endl;
}else{
reggpu.mostrarsimple();
MontoTotal+=reggpu.getPrecio();
contador++;
PcArmada.setvideo(reggpu);
}

cout<<"--------------"<<endl;

ArchivoFuente archifuente;
Fuente regfuente=archifuente.listarFuenteComprada(v[3]);
if(v[3]==0){
cout<<"Fuente: Falta elegir"<<endl;
}else{
regfuente.mostrarsimple();
MontoTotal+=regfuente.getPrecio();
contador++;
PcArmada.setfuente(regfuente);
}

cout<<"--------------"<<endl;

ArchivoRam archiram;
Rams regram=archiram.ListarRamComprada(v[4]);
if(v[4]==0){
    cout<<"Rams: Falta elegir"<<endl;
}else{
regram.mostrarsimple();
MontoTotal+=regram.getPrecio();
contador++;
PcArmada.setram(regram);
}

cout<<"--------------"<<endl;

archivoAlmacenamiento archialma;
Almacenamiento regalma=archialma.listarAlmaComprado(v[5]);
if(v[5]==0){
 cout<<"Almacenamiento: Falta elegir"<<endl;
}else{
regalma.mostrarsimple();
MontoTotal+=regalma.getPrecio();
contador++;
PcArmada.setalmacenamiento(regalma);
}

cout<<"--------------"<<endl;

cout<<"TOTAL: "<<MontoTotal<<endl;
if(contador==6){
cout<<" ¿Finizalizar compra?(1.FINALIZAR COMPRA--2.NO)"<<endl;
int opfin=0;
cin>>opfin;
if(opfin==1){
cout<<"Gracias por su compra"<<endl;
PcArmada.setcliente(user);
archi.GuardarVentaPcArmada(PcArmada);
actualizarstock(v);
}
}
}

void armadoFinal(int *v){
archivoVentasPcArmadas archi;
VentasPcArmada PcArmada;
int MontoTotal=0;
int contador=0;
ArchivoCPU archicpu;
CPU regcpu=archicpu.listarCpuComprada(v[0]);
if(v[0]==0){
    cout<<"Procesador: Falta elegir"<<endl;
}else{
regcpu.mostrarsimple();
MontoTotal+=regcpu.getPrecio();
contador++;
PcArmada.setprocesador(regcpu);
}

cout<<"--------------"<<endl;

ArchivoMother archimother;
Mother regmother=archimother.listarMotherComprada(v[1]);
if(v[1]==0){
     cout<<"Motherboard: Falta elegir"<<endl;
}else{
regmother.mostrarsimple();
MontoTotal+=regmother.getPrecio();
contador++;
PcArmada.setmother(regmother);
}

cout<<"--------------"<<endl;

ArchivoGPU archigpu;
GPU reggpu=archigpu.listarGpuComprada(v[2]);
if(v[2]==0){
   cout<<"Placa de video: Falta elegir"<<endl;
}else{
reggpu.mostrarsimple();
MontoTotal+=reggpu.getPrecio();
contador++;
PcArmada.setvideo(reggpu);
}

cout<<"--------------"<<endl;

ArchivoFuente archifuente;
Fuente regfuente=archifuente.listarFuenteComprada(v[3]);
if(v[3]==0){
cout<<"Fuente: Falta elegir"<<endl;
}else{
regfuente.mostrarsimple();
MontoTotal+=regfuente.getPrecio();
contador++;
PcArmada.setfuente(regfuente);
}

cout<<"--------------"<<endl;

ArchivoRam archiram;
Rams regram=archiram.ListarRamComprada(v[4]);
if(v[4]==0){
    cout<<"Rams: Falta elegir"<<endl;
}else{
regram.mostrarsimple();
MontoTotal+=regram.getPrecio();
contador++;
PcArmada.setram(regram);
}

cout<<"--------------"<<endl;

archivoAlmacenamiento archialma;
Almacenamiento regalma=archialma.listarAlmaComprado(v[5]);
if(v[5]==0){
 cout<<"Almacenamiento: Falta elegir"<<endl;
}else{
regalma.mostrarsimple();
MontoTotal+=regalma.getPrecio();
contador++;
PcArmada.setalmacenamiento(regalma);
}

cout<<"--------------"<<endl;

cout<<"TOTAL: "<<MontoTotal<<endl;
system("pause");
}

void actualizarstock(int *compra){
ArchivoCPU archicpu;
archicpu.actualizarStockPostVenta(compra[0]);
ArchivoMother archimother;
archimother.actualizarStockPostVenta(compra[1]);
ArchivoGPU archigpu;
archigpu.actualizarStockPostVenta(compra[2]);
ArchivoFuente archifuente;
archifuente.actualizarStockPostVenta(compra[3]);
ArchivoRam archiram;
archiram.actualizarStockPostVenta(compra[4]);
archivoAlmacenamiento archialma;
archialma.actualizarStockPostVenta(compra[5]);

}
#endif // ARMADOPC_H_INCLUDED
