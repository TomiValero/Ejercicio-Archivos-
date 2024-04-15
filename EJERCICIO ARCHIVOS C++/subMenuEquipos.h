#ifndef SUBMENUEQUIPOS_H_INCLUDED
#define SUBMENUEQUIPOS_H_INCLUDED
int subMenuEquipos()
{
    const int tiemp=0;
    int opc=0;
    while(true){system("cls");
        textBoxAnimation(65,5,"***MENU EQUIPOS***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,8,tiemp);
        textBoxAnimation(51,8,"1. AGREGAR EQUIPO",0,tiemp);
        textBoxAnimation(51,9,"2. LISTAR EQUIPO POR ID",0,tiemp);
        textBoxAnimation(51,10,"3. LISTAR TODOS LOS EQUIPOS",0,tiemp);
        textBoxAnimation(51,11,"4. MODIFICAR NOMBRE",0,tiemp);
        textBoxAnimation(51,12,"5. ELIMINAR REGISTRO DE EQUIPO",0,tiemp);
        textBoxAnimation(51,13,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,14,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,15);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroArticuloEq();
                break;
            case 2: buscarIDEq();
                break;
            case 3: listar1RegistroEq(1);
                break;
            case 4: modificarNombre();
                break;
            case 5: bajaLogicaEq();
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


#endif // SUBMENUEQUIPOS_H_INCLUDED
