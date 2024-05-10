#ifndef CLSJUGADORES_H_INCLUDED
#define CLSJUGADORES_H_INCLUDED

class Jugador{
private:
    int DNI;
    char nombre[30];
    char apellido[30];
    char email[30];
    char telefono[30];
    int claustro;
    int depo;
    int equipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
public:
Jugador(int a=0, const char *no ="NO INGRESADO", const char *ap ="NO INGRESADO", const char *em ="NO INGRESADO", const char *te ="NO INGRESADO", int b=0, int c=0, int d=0, Fecha aux=Fecha(0,0,0), float e=0) {
         DNI=a;
        strcpy(nombre, no);
        strcpy(apellido, ap);
        strcpy(email, em);
        strcpy(telefono, te);
        claustro=b;
        depo=c;
        equipo=d;
        fechaInscripcion=aux;
        matricula=e;
        estado=true;
        }
    Jugador(Fecha aux){
        fechaInscripcion=aux;
        estado=true;
    }

    int getDNI(){return DNI;}
    int getClaustro(){return claustro;}
    int getdepo(){return depo;}
    int getEquipo(){return equipo;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}
    const char* getNombre(){return nombre;}
    const char* getApellido(){return apellido;}
    const char* getEmail(){return email;}
    const char* getTelefono(){return telefono;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}


    void setFechaInscripcion(Fecha f){
            Fecha actual;
            bool band=true;
            int diaAct, mesAct, anioAct;
            diaAct=actual.getDia();
            mesAct=actual.getMes();
            anioAct=actual.getAnio();
            if(anioAct==f.getAnio()){
                if(mesAct>f.getMes()){
                    fechaInscripcion=f;
                } else if (mesAct==f.getMes()){
                    if(diaAct>=f.getDia()){
                        fechaInscripcion=f;
                    }else band=false;
                }else band=false;
            }else if (anioAct>f.getAnio()){
                fechaInscripcion=f;
                }else band=false;
            if(band==false){
                cout<<"FECHA INCORRECTA: INTENTE NUEVAMENTE(ANTES DE LA FECHA ACTUAL)"<<endl;
                cout<<"FECHA: ";
                Fecha nueva;
                nueva.Cargar();
                setFechaInscripcion(nueva);
            }
        }

    void setNombre(const char *n){strcpy(nombre,n);}
    void setApellido(const char *a){strcpy(apellido, a);}
    void setEmail(const char *e){strcpy(email,e);}
    void setTelefono(const char *t){strcpy(telefono,t);}
    void setClaustro(const int c){
        int d;
        if(c>0&&c<5){
            claustro=c;
        }else {
            cout<<"CLAUSTRO EQUIVOCADO: INTENTE NUEVAMENTE (ENTRE 1 Y 4)"<<endl;
            cout<<"CLAUSTRO: ";
            cin>>d;
            setClaustro(d);
        }
    }
    void setEquipo(const int c){equipo=c;}
    void setdepo(const int c){depo=c;}
    void setMatricula(const float c){
        float d;
        if(c>=0){
            matricula=c;
        } else {
            cout<<"MATRICULA EQUIVOCADA: INTENTE NUEVAMENTE (MAYOR A 0)"<<endl;
            cout<<"MATRICULA: ";
            cin>>d;
            setMatricula(d);
            }
    }
    void setEstado(const bool e){estado=e;}
    void setDNI(int d){DNI=d;}
    void Cargar();
    void Mostrar(int aux);

};

void Jugador::Cargar(){
    int d;
    Fecha f;
    cout<<"DNI: ";
    cin>>d;
    setDNI(d);
    cout<<"NOMBRE: ";
    cargarCadena(nombre, 30);
    cout<<"APELLIDO: ";
    cargarCadena(apellido,30);
    cout<<"EMAIL: ";
    cargarCadena(email,30);
    cout<<"TELEFONO: ";
    cargarCadena(telefono,30);
    cout<<"CLAUSTRO: ";
    cin>>d;
    setClaustro(d);
    cout<<"ID DEPORTE: ";
    cin>>d;
    setdepo(d);
    cout<<"EQUIPO: ";
    cin>>d;
    setEquipo(d);
    cout<<"FECHA DE INSCRIPCION: "<<endl;
    f.Cargar();
    setFechaInscripcion(f);
    cout<<"MATRICULA: ";
    float m;
    cin>>m;
    setMatricula(m);
    estado=true;
}

void Jugador::Mostrar(int aux=0){
    if(estado==true){
        if(aux==0){
        boxAnimation(57,2,1,42,28,0);
        rlutil::locate(65,3);
        cout<<"DNI: ";
        cout<<DNI<<endl;
        rlutil::locate(65,4);
        cout<<"Fecha Inscripcion: "<<endl;
        rlutil::locate(65,5);
        fechaInscripcion.Mostrar();
        rlutil::locate(65,6);
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        rlutil::locate(65,7);
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        rlutil::locate(65,8);
        cout<<"EMAIL: ";
        cout<<email<<endl;
        rlutil::locate(65,9);
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
        rlutil::locate(65,10);
        cout<<"CLAUSTRO: ";
        cout<<claustro<<endl;
        rlutil::locate(65,11);
        cout<<"DEPORTE: ";
        buscarID(depo);
        rlutil::locate(65,23);
        cout<<"EQUIPO: ";
        buscarIDEq(equipo);
        rlutil::locate(65,29);
        cout<<"MATRICULA: ";
        cout<<matricula<<endl;
        }
        if(aux==2){
        cout<<"DNI: ";
        cout<<DNI<<endl;
        cout<<"Fecha Inscripcion: "<<endl;
        fechaInscripcion.Mostrar();
        cout<<"NOMBRE: ";
        cout<<nombre<<endl;
        cout<<"APELLIDO: ";
        cout<<apellido<<endl;
        cout<<"EMAIL: ";
        cout<<email<<endl;
        cout<<"TELEFONO: ";
        cout<<telefono<<endl;
        cout<<"CLAUSTRO: ";
        cout<<claustro<<endl;
        cout<<"DEPORTE: ";
        buscarID(depo,aux);
        cout<<"EQUIPO: ";
        buscarIDEq(equipo,aux);
        cout<<"MATRICULA: ";
        cout<<matricula<<endl;
        }
    }

}


#endif // CLSJUGADORES_H_INCLUDED
