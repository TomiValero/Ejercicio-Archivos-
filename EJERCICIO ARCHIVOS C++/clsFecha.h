#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha();
        Fecha(int d, int m, int a){
            dia=d;
            mes=m;
            anio=a;
        }
        void Cargar();
        void Mostrar();
        ///sets
        void setDia(int x){if(x>0 && x<32) dia=x;}
        void setMes(int x){if(x>0 && x<13)mes=x;}
        void setAnio(int x){anio=x;}
        ///gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}

};

Fecha::Fecha(){
 time_t tiempo = time(nullptr);
  tm* fecha = localtime(&tiempo);

  setDia(fecha->tm_mday);
  setMes(fecha->tm_mon + 1);
  setAnio(fecha->tm_year + 1900);
}


 void Fecha::Cargar(){
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"ANIO: ";
    cin>>anio;
}

void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
}


#endif // CLSFECHA_H_INCLUDED
