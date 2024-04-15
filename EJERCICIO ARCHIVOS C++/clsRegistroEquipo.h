#ifndef CLSREGISTROEQUIPO_H_INCLUDED
#define CLSREGISTROEQUIPO_H_INCLUDED

class ArchivoEquipo{
    private:
        char nombre[30];
    public:
        ArchivoEquipo(const char *nAr){
            strcpy(nombre,nAr);
        }
        void setNombre(const char *n){strcpy(nombre,n);}
        const char *getNombre(){return nombre;}
        bool listarRegistrosEq();
        bool AgregarRegistroEq(Equipo reg);
        int buscarRegistroEq(const int d);
        Equipo leerRegistroEq(int pos);
        bool modificarRegistroEq(int pos, Equipo reg);
        int RegistrosTrue();

};

int ArchivoEquipo::RegistrosTrue(){
    int tam, cant=0;
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&reg,sizeof(Equipo),1,p)==1){
        if(reg.getEstado()==true){
            cant++;
        }
    }
    fclose(p);
    tam=cant;
    return tam;
}



bool ArchivoEquipo::listarRegistrosEq(){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg, sizeof reg,1,p)==1){
        reg.Mostrar();
        cout<<endl;
    }
    fclose(p);
    return true;
}

bool ArchivoEquipo::AgregarRegistroEq(Equipo reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
       cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoEquipo::buscarRegistroEq(const int d){
    Equipo reg;
    FILE *pEmp;
    bool hay=false;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int pos=0;
    while(fread(&reg,sizeof reg,1,pEmp)==1){
        if(d==reg.getID()&& reg.getEstado()==true){
            hay=true;
            return pos;
        }
        pos++;
    }
    if (hay==false) {
        return -1;
    }
    fclose(pEmp);
    return 0;
}

Equipo ArchivoEquipo::leerRegistroEq(int pos){
    Equipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof(Equipo)*pos,0);
    fread(&reg, sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool listar1RegistroEq(int aux=0){
    ArchivoEquipo archi("equipos.dat");
    int j=0, tam=0;
    int tecla=0;
    Equipo reg;
    tam=archi.RegistrosTrue();

    if (tam<=0) {
        cout<<"NO HAY REGISTROS EN ESTE ARCHIVO"<<endl;
        return false;
    }

    Equipo *Mdin;
    Mdin=new Equipo[tam];
    if(Mdin==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA "<<endl;
        return false;
    }

    FILE *pe=fopen(archi.getNombre(),"rb");
    if(pe==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg,sizeof(Equipo),1,pe)==1){
        if(reg.getEstado()==true){
            Mdin[j]=reg;
            j++;
        }
    }
    fclose(pe);

    textBoxAnimation(51,11,"USE LAS FLECHAS (TECLAS) PARA MOVERSE ENTRE LOS REGISTROS",1,0);
    rlutil::msleep(1000);

    for(int i=0;i<tam;){
    system("cls");
    Mdin[i].Mostrar(aux);
    textBoxAnimation(48,20,"<---",1,0);
    textBoxAnimation(103,20,"--->",1,0);
    tecla=rlutil::getkey();
       if(tecla==16){
        i--;
        if(i<0){
            i=0;
        }
       }
       if(tecla==17){
        i++;
       }
    }
    delete[] Mdin;
    return true;
}

int modificarNombre(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int ID, pos;
    char nombreNew[30];
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE ID DEL EQUIPO BUSCADO: ";
    cin>>ID;
    pos=archi.buscarRegistroEq(ID);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY EQUIPOS CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        cout<<"INGRESE NUEVO NOMBRE: ";
        cargarCadena(nombreNew, 30);

        reg=archi.leerRegistroEq(pos);

        reg.setNombre(nombreNew);

        fseek(p,sizeof(Equipo)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"NOMBRE MODIFICADO";
        }
        return 0;
    }
    return 0;
}

int bajaLogicaEq(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    int id, pos;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE ID DEL EQUIPO BUSCADO: ";
    cin>>id;
    pos=archi.buscarRegistroEq(id);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY DEPORTES CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        reg=archi.leerRegistroEq(pos);

        reg.setEstado(false);

        fseek(p,sizeof(Equipo)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"REGISTRO ELIMINADO";
        }
    return 0;
    }
    return 0;
}


bool agregarRegistroArticuloEq(){
    Equipo reg;
    ArchivoEquipo archi("equipos.dat");
    FILE *p=fopen(archi.getNombre(),"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
        int cantRegistros=cantByte/sizeof(Equipo);
        int numID=cantRegistros+1;
        reg.Cargar(numID);
        bool agregar=archi.AgregarRegistroEq(reg);
        if(agregar==true){
            cout<<"REGISTRO AGREGADO";
            return true;
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            return false;
        }
    }

void mostrarArticulosEq(){
        ArchivoEquipo archi("equipos.dat");
        archi.listarRegistrosEq();
}

int buscarIDEq(int d=-1, int aux=0){
    int ID=d;
    int pos;
    FILE *p;
    Equipo reg;
    if(ID==-1){
    cout<<"INGRESE ID BUSCADO: ";
    cin>>ID;
    }
    ArchivoEquipo archi("equipos.dat");
    pos=archi.buscarRegistroEq(ID);
    if(pos!=-1){
        p=fopen(archi.getNombre(),"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
         reg=archi.leerRegistroEq(pos);
        reg.Mostrar(aux);
    } else if (pos==-1) {
        cout<<"NO HAY EQUIPOS CON ESE ID"<<endl;
        return -1;
    }
    fclose(p);
    return 0;
}


#endif // CLSREGISTROEQUIPO_H_INCLUDED
