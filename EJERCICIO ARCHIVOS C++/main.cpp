
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstring>

using namespace std;

#include "rlutil.h"
#include "rlutilPlusPlus.h"
#include "clsFecha.h"
#include "funcionesGlobales.h"
#include "clsTipodeDeporte.h"
#include "clsRegistroTipo.h"
#include "clsEquipo.h"
#include "clsRegistroEquipo.h"
#include "clsDeportes.h"
#include "clsRegistroDepo.h"
#include "clsJugadores.h"
#include "clsRegistro.h"
#include "subMenuJugadores.h"
#include "subMenuDeportes.h"
#include "subMenuEquipos.h"
#include "subMenuTipo.h"
#include "funcionesConfiguracion.h"
#include "subMenuConfiguracion.h"
#include "reportes.h"


int main()
{
    const int tiemp=0;
    int opc=0;
   while(true){
        system("cls");
        textBoxAnimation(65,5,"***MENU PRINCIPAL***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,9,tiemp);
        textBoxAnimation(51,8,"1. MENU JUGADORES",0,tiemp);
        textBoxAnimation(51,9,"2. MENU DEPORTES",0,tiemp);
        textBoxAnimation(51,10,"3. MENU EQUIPOS",0,tiemp);
        textBoxAnimation(51,11,"4. MENU TIPOS DE DEPORTE",0,tiemp);
        textBoxAnimation(51,12,"5. REPORTES",0,tiemp);
        textBoxAnimation(51,13,"6. CONFIGURACION",0,tiemp);
        textBoxAnimation(51,14,"0. FIN DEL PROGRAMA",0,tiemp);
        textBoxAnimation(51,15,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,16);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: subMenuJugador();
                break;
            case 2: subMenuDeporte();
                break;
            case 3: subMenuEquipos();
                break;
            case 4: subMenuTipo();
                break;
            case 5: subMenuReportes();
                break;
            case 6: subMenuConfiguracion();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;


        }
        cout<<endl;
    }
    return 0;
}
