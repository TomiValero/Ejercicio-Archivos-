#ifndef CLSEQUIPO_H_INCLUDED
#define CLSEQUIPO_H_INCLUDED

class Equipo{
private:
    int ID;
    char nombre[30];
    int nivel;
    bool estado;
public:
    Equipo(int const b=0, const char *n="NO INGRESADO", int const c=0,bool const a=true){
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
        if(c>=1&&c<=3){
            nivel=c;
        }else {
            cout<<"NIVEL EQUIVOCADO: INTENTE NUEVAMENTE (1 PRINCIPIANTE - 2 INTERMEDIO - 3 AVANZADO)"<<endl;
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


void Equipo::Cargar(int aux=-1){
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

void Equipo::Mostrar(int aux=0){
    if(estado==true){
        if(aux==0){
        cout<<endl;
        boxAnimation(57,24,1,42,4,0);
        rlutil::locate(65,25);
        cout<<"ID DE EQUIPO: ";
        cout<<ID<<endl;
        rlutil::locate(65,26);
        cout<<"NOMBRE DE EQUIPO: ";
        cout<<nombre<<endl;
        rlutil::locate(65,27);
        cout<<"NIVEL DE EQUIPO: ";
        cout<<nivel<<endl;
        }
        if(aux==1){
        cout<<endl;
        boxAnimation(57,18,1,42,4,0);
        rlutil::locate(65,19);
        cout<<"ID DE EQUIPO: ";
        cout<<ID<<endl;
        rlutil::locate(65,20);
        cout<<"NOMBRE DE EQUIPO: ";
        cout<<nombre<<endl;
        rlutil::locate(65,21);
        cout<<"NIVEL DE EQUIPO: ";
        cout<<nivel<<endl;
        }
        if(aux==2){
        cout<<endl;
        cout<<"----------"<<endl;
        cout<<"ID DE EQUIPO: ";
        cout<<ID<<endl;
        cout<<"NOMBRE DE EQUIPO: ";
        cout<<nombre<<endl;
        cout<<"NIVEL DE EQUIPO: ";
        cout<<nivel<<endl;
        cout<<"----------"<<endl;
        }
    }

}


#endif // CLSEQUIPO_H_INCLUDED
