#ifndef CLSREGISTRO_H_INCLUDED
#define CLSREGISTRO_H_INCLUDED

class ArchivoJugador{
    private:
        char nombre[30];
    public:
        ArchivoJugador(const char *nAr){
            strcpy(nombre,nAr);
        }
        void setNombre(const char *n){strcpy(nombre,n);}
        const char *getNombre(){return nombre;}
        bool listarRegistros();
        bool AgregarRegistro(Jugador reg);
        int buscarRegistro(const int d);
        Jugador leerRegistro(int pos);
        bool modificarRegistro(int pos, Jugador reg);
        int RegistrosTrue();

};

int ArchivoJugador::RegistrosTrue(){
    int tam, cant=0;
    Jugador reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&reg,sizeof(Jugador),1,p)==1){
        if(reg.getEstado()==true){
            cant++;
        }
    }
    fclose(p);
    tam=cant;
    return tam;
}

bool ArchivoJugador::listarRegistros(){
    Jugador reg;
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

bool ArchivoJugador::AgregarRegistro(Jugador reg){
    FILE *p=fopen(nombre,"ab");
    if(p==NULL){
       cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    bool escribio=fwrite(&reg, sizeof reg,1,p);
    fclose(p);
    return escribio;
}

int ArchivoJugador::buscarRegistro(const int d){
    Jugador reg;
    FILE *pEmp;
    bool hay=false;
    pEmp=fopen(nombre,"rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    int pos=0;
    while(fread(&reg,sizeof(Jugador),1,pEmp)==1){
        if(d==reg.getDNI()&& reg.getEstado()==true){
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

Jugador ArchivoJugador::leerRegistro(int pos){
    Jugador reg;
    FILE *p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return reg;
    }
    fseek(p,sizeof(Jugador)*pos,0);
    fread(&reg, sizeof reg,1,p);
    fclose(p);
    return reg;
}

bool listar1Registro(){
    ArchivoJugador archi("jugadores.dat");
    int j=0, tam=0;
    int tecla=0;
    Jugador reg;
    tam=archi.RegistrosTrue();

    if (tam<=0) {
        cout<<"NO HAY REGISTROS EN ESTE ARCHIVO"<<endl;
        return false;
    }

    Jugador *Mdin;
    Mdin=new Jugador[tam];
    if(Mdin==NULL){
        cout<<"ERROR DE ASIGNACION DE MEMORIA "<<endl;
        return false;
    }

    FILE *pe=fopen(archi.getNombre(),"rb");
    if(pe==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return false;
    }

    while(fread(&reg,sizeof(Jugador),1,pe)==1){
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

int modificarFecha(){
    Jugador reg;
    Fecha f;
    ArchivoJugador archi("jugadores.dat");
    int dni, pos;
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE DNI DEL JUGADOR BUSCADO: ";
    cin>>dni;
    pos=archi.buscarRegistro(dni);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY JUGADORES CON ESE DNI"<<endl;
            return 0;
        }
    if(pos!=-1){
        cout<<"INGRESE NUEVA FECHA: ";
        f.Cargar();

        reg=archi.leerRegistro(pos);

        reg.setFechaInscripcion(f);

        fseek(p,sizeof(Jugador)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"FECHA MODIFICADA";
        }
        return 0;
    }
    return 0;
}

int bajaLogica(){
    Jugador reg;
    ArchivoJugador archi("jugadores.dat");
    int dni, pos;
    //reg.setEstado(false);
    FILE *p=fopen(archi.getNombre(),"rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }
    cout<<"INGRESE DNI DEL JUGADOR BUSCADO: ";
    cin>>dni;
    pos=archi.buscarRegistro(dni);
    cout<<endl;
    if (pos==-1) {
            cout<<"NO HAY JUGADORES CON ESE DNI"<<endl;
            return 0;
        }
    if(pos!=-1){
        reg=archi.leerRegistro(pos);

        reg.setEstado(false);

        fseek(p,sizeof(Jugador)*pos,0);
        bool escribio=fwrite(&reg, sizeof reg,1,p);
        fclose(p);
        if(escribio==1){
        cout<<"REGISTRO ELIMINADO";
        }
    return 0;
    }
    return 0;
}


bool agregarRegistroArticulo(){
    Jugador reg;
    int dn, dep, equi, pos=0;
    char texto[30];
    int d;
    Fecha f;
    ArchivoEquipo archi3("equipos.dat");
    ArchivoDeporte archi2("deportes.dat");
    ArchivoJugador archi("jugadores.dat");
    cout<<"DNI: ";
    cin>>dn;
    pos=archi.buscarRegistro(dn);
    if(pos==-1){
            reg.setDNI(dn);
    }
    else{
        cout<<"YA EXISTE UN REGISTRO CON ESE DNI"<<endl;
        return false;
    }
    cout<<"NOMBRE: ";
    cargarCadena(texto, 30);
    reg.setNombre(texto);
    cout<<"APELLIDO: ";
    cargarCadena(texto, 30);
    reg.setApellido(texto);
    cout<<"EMAIL: ";
    cargarCadena(texto, 30);
    reg.setEmail(texto);
    cout<<"TELEFONO: ";
    cargarCadena(texto, 30);
    reg.setTelefono(texto);
    cout<<"CLAUSTRO: ";
    cin>>d;
    reg.setClaustro(d);
    cout<<"ID DEPORTE: ";
    cin>>dep;
    int pos2= archi2.buscarRegistroD(dep);
    if(pos2!=-1){
            reg.setdepo(dep);
    }
    else{
        cout<<"NO EXISTE UN DEPORTE CON ESE ID"<<endl;
        return false;
    }
    cout<<"ID EQUIPO: ";
    cin>>equi;
    int pos3= archi3.buscarRegistroEq(equi);
    if(pos3!=-1){
            reg.setEquipo(equi);
    }
    else{
        cout<<"NO EXISTE UN EQUIPO CON ESE ID"<<endl;
        return false;
    }
    cout<<"FECHA DE INSCRIPCION: "<<endl;
    f.Cargar();
    reg.setFechaInscripcion(f);
    cout<<"MATRICULA: ";
    float m;
    cin>>m;
    reg.setMatricula(m);
    reg.setEstado(true);
    bool agregar=archi.AgregarRegistro(reg);
                if(agregar==true){
                    cout<<"REGISTRO AGREGADO";
                    return true;
                }
                else{
                    cout<<"NO SE PUDO AGREGAR EL REGISTRO"<<endl;
                    return false;
                }
}

void mostrarArticulos(){
        ArchivoJugador archi("jugadores.dat");
        archi.listarRegistros();
}

int buscarDni(){
    int dni;
    int pos;
    FILE *p;
    Jugador reg;
    cout<<"INGRESE DNI BUSCADO: ";
    cin>>dni;
    ArchivoJugador archi("jugadores.dat");
    pos=archi.buscarRegistro(dni);
    if(pos!=-1){
        p=fopen(archi.getNombre(),"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        reg=archi.leerRegistro(pos);
        fclose(p);
        reg.Mostrar();
    } else if (pos==-1) {
        cout<<"NO HAY JUGADORES CON ESE DNI"<<endl;
        return 0;
    }
   
    return 0;
}
#endif // CLSREGISTRO_H_INCLUDED
