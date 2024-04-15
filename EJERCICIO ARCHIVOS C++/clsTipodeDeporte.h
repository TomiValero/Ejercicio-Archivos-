#ifndef CLSTIPODEDEPORTE_H_INCLUDED
#define CLSTIPODEDEPORTE_H_INCLUDED

class Tipo{
private:
    int ID;
    char nombre[30];
    int nivel;
    bool estado;
public:
    Tipo(int const b=0, const char *n="NO INGRESADO", int const c=0,bool const a=true){
        ID=b;
        strcpy(nombre, n);
        nivel=c;
        estado=a;
    }
    int getID(){return ID;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}
    const char* getNombre(){return nombre;}


    void setNombre(const char *n){strcpy(nombre,n);}
    void setNivel(const int c){
        int d;
        if(c>=1&&c<=8){
            nivel=c;
        }else {
            cout<<"NIVEL EQUIVOCADO: INTENTE NUEVAMENTE (ENTRE 1 Y 8)"<<endl;
            cout<<"NIVEL: ";
            cin>>d;
            setNivel(d);
        }
    }

    void setEstado(const bool e){estado=e;}
    void setID(int d){ID=d;}
    void Cargar(int aux);
    void Mostrar(int aux);

};


void Tipo::Cargar(int aux=-1){
    int d;
    if(aux==-1){
        cout<<"ID: ";
        cin>>d;
        setID(d);
    } else setID(aux);
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 24);
    cout<<"NIVEL: ";
    cin>>d;
    setNivel(d);
    estado=true;
}

void Tipo::Mostrar(int aux=0){
    if(estado==true){
        if(aux==0){
        cout<<endl;
        boxAnimation(57,16,1,42,4,0);
        rlutil::locate(65,17);
        cout<<"ID DE TIPO: ";
        cout<<ID<<endl;
        rlutil::locate(65,18);
        cout<<"NOMBRE DE TIPO: ";
        cout<<nombre<<endl;
        rlutil::locate(65,19);
        cout<<"NIVEL DE TIPO: ";
        cout<<nivel<<endl;
        }
        if(aux==2){
        cout<<endl;
        cout<<"------------"<<endl;
        cout<<"ID DE TIPO: ";
        cout<<ID<<endl;
        cout<<"NOMBRE DE TIPO: ";
        cout<<nombre<<endl;
        cout<<"NIVEL DE TIPO: ";
        cout<<nivel<<endl;
        cout<<"------------"<<endl;
        }
    }

}

#endif // CLSTIPODEDEPORTE_H_INCLUDED
