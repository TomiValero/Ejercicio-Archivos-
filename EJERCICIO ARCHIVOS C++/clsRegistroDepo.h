#ifndef CLSREGISTRODEPO_H_INCLUDED
#define CLSREGISTRODEPO_H_INCLUDED

class ArchivoDeporte{
    private:
        char nombre[30];
    public:
        ArchivoDeporte(const char *nAr){
            strcpy(nombre,nAr);
        }
        void setNombre(const char *n){strcpy(nombre,n);}
        const char *getNombre(){return nombre;}
        bool listarRegistrosD();
        bool AgregarRegistroD(Deporte reg);
        int buscarRegistroD(const int d);
        Deporte leerRegistroD(int pos);
        bool modificarRegistroD(int pos, Deporte reg);
        int RegistrosTrue();

};

int ArchivoDeporte::RegistrosTrue(){
    int tam, cant=0;
    Deporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&reg,sizeof(Deporte),1,p)==1){
        if(reg.getEstado()==true){
            cant++;
        }
    }
    fclose(p);
    tam=cant;
    return tam;
}
bool ArchivoDeporte::listarRegistrosD(){
    Deporte reg;
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

bool ArchivoDeporte::AgregarRegistroD(Deporte reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
       cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoDeporte::buscarRegistroD(const int d){
    Deporte reg;
    FILE *pEmp;
    bool hay=false;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int pos=0;
    while(fread(&reg,sizeof(Deporte),1,pEmp)==1){
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

Deporte ArchivoDeporte::leerRegistroD(int pos){
    Deporte reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof(Deporte)*pos,0);
    fread(&reg, sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool listar1RegistroD(){
    ArchivoDeporte archi("deportes.dat");
    int j=0, tam=0;
    int tecla=0;
    Deporte reg;
    tam=archi.RegistrosTrue();

    if (tam<=0) {
        cout<<"NO HAY REGISTROS EN ESTE ARCHIVO"<<endl;
        return false;
    }

    Deporte *Mdin;
    Mdin=new Deporte[tam];
    if(Mdin==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA "<<endl;
        return false;
    }

    FILE *pe=fopen(archi.getNombre(),"rb");
    if(pe==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg,sizeof(Deporte),1,pe)==1){
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

int modificarAnioD(){
    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int ID, pos, ani;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE ID DEL DEPORTE BUSCADO: ";
    cin>>ID;
    pos=archi.buscarRegistroD(ID);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY DEPORTES CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        cout<<"INGRESE NUEVO ANIO: ";
        cin>>ani;


        reg=archi.leerRegistroD(pos);

        reg.setAnio(ani);

        fseek(p,sizeof(Deporte)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"ANIO MODIFICADO";
        }
        return 0;
    }
    return 0;
}

int bajaLogicaD(){
    Deporte reg;
    ArchivoDeporte archi("deportes.dat");
    int id, pos;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE ID DEL DEPORTE BUSCADO: ";
    cin>>id;
    pos=archi.buscarRegistroD(id);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY DEPORTES CON ESE ID"<<endl;
            return 0;
        }
    if(pos!=-1){
        reg=archi.leerRegistroD(pos);

        reg.setEstado(false);

        fseek(p,sizeof(Deporte)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"REGISTRO ELIMINADO";
        }
    return 0;
    }
    return 0;
}


bool agregarRegistroArticuloD(){
    Deporte reg;
    int d;
    char nombre[30];
    ArchivoDeporte archi("deportes.dat");
    ArchivoTipo archi2("TipodeDeporte.dat");
    FILE *p=fopen(archi.getNombre(),"ab");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }
    fseek(p,0,2);
    int cantByte=ftell(p);
    fclose(p);
        int cantRegistros=cantByte/sizeof(Deporte);
        int numID=cantRegistros+1;
        reg.setID(numID);
        cout<<"NOMBRE: ";
        cargarCadena(nombre, 30);
        reg.setNombre(nombre);
        cout<<"TIPO: ";
        cin>>d;
        int pos2= archi2.buscarRegistroTip(d);
        if(pos2!=-1){
                reg.setTipo(d);
        }
        else{
            cout<<"NO EXISTE UN TIPO CON ESE ID"<<endl;
            return false;
        }
        cout<<"ANIO: ";
        cin>>d;
        reg.setAnio(d);
        reg.setEstado(true);
        bool agregar=archi.AgregarRegistroD(reg);
        if(agregar==true){
            cout<<"REGISTRO AGREGADO";
            return true;
        }
        else{
            cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
            return false;
        }
    }

void mostrarArticulosD(){
        ArchivoDeporte archi("deportes.dat");
        archi.listarRegistrosD();
}

int buscarID(int d=-1, int aux=0){
    int ID=d;
    int pos;
    FILE *p;
    Deporte reg;
    if(ID==-1){
    cout<<"INGRESE ID BUSCADO: ";
    cin>>ID;
    }
    ArchivoDeporte archi("deportes.dat");
    pos=archi.buscarRegistroD(ID);
    if(pos!=-1){
        p=fopen(archi.getNombre(),"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        reg=archi.leerRegistroD(pos);
        reg.Mostrar(aux);
    } else if (pos==-1) {
        cout<<"NO HAY DEPORTES CON ESE ID"<<endl;
        return -1;
    }
    fclose(p);
    return 0;
}

#endif // CLSREGISTRODEPO_H_INCLUDED
