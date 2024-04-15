#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
/*Generar un archivo con los deportes que tengan un nivel de dificultad 5.

Cada registro debe tener el ID de deporte, el nombre del deporte y el tipo de deporte*/

class DeportePunto1{
private:
    int ID;
    char nombre[30];
    int tipo;
    bool estado;
public:
    void mostrar(){
        cout<<endl;
        cout<<"----------"<<endl;
        cout<<"ID DE DEPORTE: ";
        cout<<ID<<endl;
        cout<<"NOMBRE DE DEPORTE: ";
        cout<<nombre<<endl;
        cout<<"TIPO DE DEPORTE: ";
        buscarIDTip(tipo,2);
        cout<<"----------"<<endl;
    }

    int getID(){return ID;}
    int getTipo(){return tipo;}
    bool getEstado(){return estado;}
    const char* getNombre(){return nombre;}


    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(const int c){tipo=c;}
    void setEstado(const bool e){estado=e;}
    void setID(int d){ID=d;}
};
int nivel(Deporte reg){
    Tipo obj;
    int tipos = reg.getTipo();
    int nivel=0;

    FILE *pEmp=fopen("TipodeDeporte.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }

    while(fread(&obj, sizeof (Tipo),1,pEmp)==1){
            if(tipos==obj.getID()){
                nivel=obj.getNivel();
            }
    }
    fclose(pEmp);
    return nivel;
}

void punto1(){
    Deporte reg;
    DeportePunto1 obj;
    int dificultad=0;

    FILE *pEmp=fopen("deportespunto1.dat","wb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *p=fopen("deportes.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&reg, sizeof (Deporte),1,p)==1){
            dificultad=nivel(reg);
            if(dificultad==5){
                obj.setID(reg.getID());
                obj.setNombre(reg.getNombre());
                obj.setTipo(reg.getTipo());
                obj.setEstado(reg.getEstado());
                fwrite(&obj, sizeof (DeportePunto1),1,pEmp);
            }
    }
    fclose(pEmp);
    fclose(p);

}

void mostrarPunto1(){
  DeportePunto1 p1;

 FILE *pEmp=fopen("deportespunto1.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&p1, sizeof (DeportePunto1),1,pEmp)==1){
            p1.mostrar();
            }
    fclose(pEmp);
}

void punto2(){
    Jugador reg;
    int meses[12]={0};
    Fecha aux;
    int mes=0;
    int anio=0;
    FILE *pEmp=fopen("jugadores.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }

    while(fread(&reg, sizeof (Jugador),1,pEmp)==1){
            aux=reg.getFechaInscripcion();
            anio=aux.getAnio();
            mes=aux.getMes();
            if(anio==2023){
                meses[mes-1]++;
            }
        }
    fclose(pEmp);

    int maxi=meses[0];
    int mesmax=1;

    for(int i=1;i<12;i++){
        if(meses[i]>maxi){
            maxi=meses[i];
            mesmax=i+1;
        }
    }
cout<<"El mes de este anio con mas jugadores es el mes: "<<mesmax<<endl;

}

int tamanio(){
    DeportePunto1 p1;
    int Tam=0;

 FILE *pEmp=fopen("deportespunto1.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return -1;
    }
     while(fread(&p1, sizeof (DeportePunto1),1,pEmp)==1){
            Tam++;
            }

    fclose(pEmp);
    return Tam;
}

void cargarVec(DeportePunto1 *vec,int tam){
    DeportePunto1 p1;
    int i=0;

 FILE *pEmp=fopen("deportespunto1.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
     while(fread(&p1, sizeof (DeportePunto1),1,pEmp)==1){
            vec[i]=p1;
            i++;
            }

    fclose(pEmp);
}

void listar1Punto3(DeportePunto1 *vec, int tam){
    for(int i=0; i<tam; i++){
        vec[i].mostrar();
        cout<<endl;
    }
}

void punto3(){
    int tam=tamanio();

    if (tam<=0) {
        cout<<"No hay registros en el archivo o se produjo un error al obtener el número de registros."<<endl;
        return;
    }

     DeportePunto1 *vec;
    vec=new DeportePunto1[tam];
    if(vec==NULL){
        cout<<"ERROR DE MEMORIA"<<endl;
        return;
    }

    cargarVec(vec,tam);
    listar1Punto3(vec,tam);

    delete[] vec;
}

int subMenuReportes()
{   const int tiemp=0;
    int opc;
    while(true){
        system("cls");
        textBoxAnimation(65,5,"***MENU REPORTES***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,6,tiemp);
        textBoxAnimation(51,8,"1. PUNTO 1",0,tiemp);
        textBoxAnimation(51,9,"2. PUNTO 2",0,tiemp);
        textBoxAnimation(51,10,"3. PUNTO 3",0,tiemp);
        textBoxAnimation(51,11,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,12,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,13);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: punto1();
                    system("pause");
                    mostrarPunto1();
                break;
            case 2: punto2();
                break;
            case 3: punto3();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;


        }
        cout<<endl;
        system("pause");
    }
    return 0;
}

#endif // REPORTES_H_INCLUDED
