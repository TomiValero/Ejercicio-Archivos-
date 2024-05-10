#ifndef SUBMENUCONFIGURACION_H_INCLUDED
#define SUBMENUCONFIGURACION_H_INCLUDED

int subMenuConfiguracion()
{
    const int tiemp=0;
    int opc=0;
    while(true){system("cls");
        textBoxAnimation(65,5,"***MENU CONFIGURACION***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,55,12,tiemp);
        textBoxAnimation(51,8,"1. COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES",0,tiemp);
        textBoxAnimation(51,9,"2. COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES",0,tiemp);
        textBoxAnimation(51,10,"3. COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS",0,tiemp);
        textBoxAnimation(51,11,"4. COPIA DE SEGURIDAD DEL ARCHIVO DE TIPOS DE DEPORTE",0,tiemp);
        textBoxAnimation(51,12,"5. RESTAURAR EL ARCHIVO DE JUGADORES",0,tiemp);
        textBoxAnimation(51,13,"6. RESTAURAR EL ARCHIVO DE DEPORTES",0,tiemp);
        textBoxAnimation(51,14,"7. RESTAURAR EL ARCHIVO DE EQUIPOS",0,tiemp);
        textBoxAnimation(51,15,"8. RESTAURAR EL ARCHIVO DE TIPOS DE DEPORTE",0,tiemp);
        textBoxAnimation(51,16,"9. ESTABLECER DATOS DE INICIO",0,tiemp);
        textBoxAnimation(51,17,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,18,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,19);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: copiaJugadores();
                break;
            case 2: copiaDeportes();
                break;
            case 3: copiaEquipos();
                break;
            case 4: copiaTipo();
                break;
            case 5: restauracionJugadores();
                break;
            case 6: restauracionDeportes();
                break;
            case 7: restauracionEquipos();
                break;
            case 8: restauracionTipo();
                break;
            case 9: restauracionIncioJugadores();
                    restauracionInicoDeportes();
                    restauracionInicioEquipos();
                    restauracionInicioTipo();
                break;
            case 0: return 0;
                break;
            default: cout<<"OPCION INCORRECTA"<<endl;
                break;


        }
        cout<<endl;
    rlutil::getkey();
    }
    return 0;
}


#endif // SUBMENUCONFIGURACION_H_INCLUDED
