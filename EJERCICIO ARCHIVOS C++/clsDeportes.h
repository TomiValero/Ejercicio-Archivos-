#ifndef CLSDEPORTES_H_INCLUDED
#define CLSDEPORTES_H_INCLUDED

class Deporte{
private:
    int ID;
    char nombre[30];
    int tipo;
    int anioOrigen;
    bool estado;
public:
    Deporte(int const b=0, const char *n="NO INGRESADO", int const d=0,int const c=0,bool const a=true){
        ID=b;
        strcpy(nombre, n);
        tipo=d;
        anioOrigen=c;
        estado=a;
        }
    int getID(){return ID;}
    int getTipo(){return tipo;}

    int getAnio(){return anioOrigen;}
    bool getEstado(){return estado;}
    const char* getNombre(){return nombre;}


    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(const int c){
        int d;
        if(c>0&&c<21){
            tipo=c;
        }else {
            cout<<"TIPO EQUIVOCADO: INTENTE NUEVAMENTE (ENTRE 1 Y 21)"<<endl;
            cout<<"TIPO: ";
            cin>>d;
            setTipo(d);
        }
    }

    void setAnio(const int c){
        int d;
        Fecha actual;
        int anioAct=actual.getAnio();
        if(c>1799&&c<=anioAct){
            anioOrigen=c;
        }else {
            cout<<"ANIO EQUIVOCADO: INTENTE NUEVAMENTE (ENTRE 1800 Y ANIO ACTUAL)"<<endl;
            cout<<"ANIO: ";
            cin>>d;
            setAnio(d);
        }
    }

    void setEstado(const bool e){estado=e;}
    void setID(int d){ID=d;}
    void Cargar();
    void Mostrar(int aux);

};


void Deporte::Cargar(){
    int d;
    cout<<"ID: ";
    cin>>d;
    setID(d);
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 30);
    cout<<"TIPO: ";
    cin>>d;
    setTipo(d);
    cout<<"ANIO: ";
    cin>>d;
    setAnio(d);
    estado=true;
}

void Deporte::Mostrar(int aux=0){
    if(estado==true){
        if(aux==0){
        cout<<endl;
        boxAnimation(57,12,1,42,10,0);
        rlutil::locate(65,13);
        cout<<"ID DE DEPORTE: ";
        cout<<ID<<endl;
        rlutil::locate(65,14);
        cout<<"NOMBRE DE DEPORTE: ";
        cout<<nombre<<endl;
        rlutil::locate(65,15);
        cout<<"TIPO DE DEPORTE: ";
        buscarIDTip(tipo);
        rlutil::locate(65,21);
        cout<<"ANIO DE DEPORTE: ";
        cout<<anioOrigen<<endl;
        }
        if(aux==2){
        cout<<endl;
        cout<<"----------"<<endl;
        cout<<"ID DE DEPORTE: ";
        cout<<ID<<endl;
        cout<<"NOMBRE DE DEPORTE: ";
        cout<<nombre<<endl;
        cout<<"TIPO DE DEPORTE: ";
        buscarIDTip(tipo,aux);
        cout<<"ANIO DE DEPORTE: ";
        cout<<anioOrigen<<endl;
        cout<<"----------"<<endl;
        }
    }

}

#endif // CLSDEPORTES_H_INCLUDED
