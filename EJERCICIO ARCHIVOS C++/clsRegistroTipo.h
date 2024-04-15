#ifndef CLSREGISTROTIPO_H_INCLUDED
#define CLSREGISTROTIPO_H_INCLUDED

class ArchivoTipo{
    private:
        char nombre[30];
    public:
        ArchivoTipo(const char *nAr){
            strcpy(nombre,nAr);
        }
        void setNombre(const char *n){strcpy(nombre,n);}
        const char *getNombre(){return nombre;}
        bool listarRegistrosTip();
        bool AgregarRegistroTip(Tipo reg);
        int buscarRegistroTip(const int d);
        Tipo leerRegistroTip(int pos);
        bool modificarRegistroTip(int pos, Tipo reg);
        int RegistrosTrue();

};

int ArchivoTipo::RegistrosTrue(){
    int tam, cant=0;
    Tipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&reg,sizeof(Tipo),1,p)==1){
        if(reg.getEstado()==true){
            cant++;
        }
    }
    fclose(p);
    tam=cant;
    return tam;
}

bool ArchivoTipo::listarRegistrosTip(){
    Tipo reg;
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

bool ArchivoTipo::AgregarRegistroTip(Tipo reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
       cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoTipo::buscarRegistroTip(const int d){
    Tipo reg;
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

Tipo ArchivoTipo::leerRegistroTip(int pos){
    Tipo reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof(Tipo)*pos,0);
    fread(&reg, sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool listar1RegistroTip(){
    ArchivoTipo archi("TipodeDeporte.dat");
    int j=0, tam=0;
    int tecla=0;
    Tipo reg;
    tam=archi.RegistrosTrue();
    if (tam<=0) {
        cout<<"NO HAY REGISTROS EN ESTE ARCHIVO"<<endl;
        return false;
    }

    Tipo *Mdin;
    Mdin=new Tipo[tam];
    if(Mdin==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA "<<endl;
        return false;
    }

    FILE *pe=fopen(archi.getNombre(),"rb");
    if(pe==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg,sizeof(Tipo),1,pe)==1){
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
        Mdin[i].Mostrar();
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


int modificarNivel(){
    Tipo reg;
    ArchivoTipo archi("TipodeDeporte.dat");
    int ID, pos, niv;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return 0;
    }
    cout<<"INGRESE ID DEL TIPO BUSCADO: ";
    cin>>ID;
    pos=archi.buscarRegistroTip(ID);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY TIPOS CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        cout<<"INGRESE NUEVO NIVEL: ";
        cin>>niv;


        reg=archi.leerRegistroTip(pos);

        reg.setNivel(niv);

        fseek(p,sizeof(Tipo)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"NIVEL MODIFICADO";
        }
        return 0;
    }
    return 0;
}

int bajaLogicaTip(){
    Tipo reg;
    ArchivoTipo archi("TipodeDeporte.dat");
    int id, pos;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return 0;
    }
    cout<<"INGRESE ID DEL TIPO BUSCADO: ";
    cin>>id;
    pos=archi.buscarRegistroTip(id);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY TIPOS CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        reg=archi.leerRegistroTip(pos);

        reg.setEstado(false);

        fseek(p,sizeof(Tipo)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"REGISTRO ELIMINADO";
        }
    return 0;
    }
    return 0;
}


void agregarRegistroArticuloTip(){
    Tipo reg;
    ArchivoTipo archi("TipodeDeporte.dat");
    FILE *p=fopen(archi.getNombre(),"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
        int cantRegistros=cantByte/sizeof(Tipo);
        int numID=cantRegistros+1;
        reg.Cargar(numID);
        bool agregar=archi.AgregarRegistroTip(reg);
        if(agregar==true){
            cout<<"REGISTRO AGREGADO";
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
        }
    }

void mostrarArticulosTip(){
        ArchivoTipo archi("TipodeDeporte.dat");
        archi.listarRegistrosTip();
}

int buscarIDTip(int d=-1, int aux=0){
    int ID=d;
    int pos;
    FILE *p;
    Tipo reg;
    if(ID==-1){
    cout<<"INGRESE ID BUSCADO: ";
    cin>>ID;
    }
    ArchivoTipo archi("TipodeDeporte.dat");
    pos=archi.buscarRegistroTip(ID);
    if(pos!=-1){
        p=fopen(archi.getNombre(),"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -1;
        }
        reg=archi.leerRegistroTip(pos);
        reg.Mostrar(aux);
    } else if (pos==-1) {
        cout<<"NO HAY TIPOS CON ESE ID"<<endl;
        return -1;
    }
    fclose(p);
    return 0;
}


#endif // CLSREGISTROTIPO_H_INCLUDED
