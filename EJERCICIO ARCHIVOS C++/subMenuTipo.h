#ifndef SUBMENUTIPO_H_INCLUDED
#define SUBMENUTIPO_H_INCLUDED

int subMenuTipo()
{
    const int tiemp=0;
    int opc=0;
    while(true){system("cls");
        textBoxAnimation(62,5,"***MENU TIPOS DE DEPORTE***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,8,tiemp);
        textBoxAnimation(51,8,"1. AGREGAR TIPO",0,tiemp);
        textBoxAnimation(51,9,"2. LISTAR TIPO POR ID",0,tiemp);
        textBoxAnimation(51,10,"3. LISTAR TODOS LOS TIPOS",0,tiemp);
        textBoxAnimation(51,11,"4. MODIFICAR NIVEL",0,tiemp);
        textBoxAnimation(51,12,"5. ELIMINAR REGISTRO DE TIPO",0,tiemp);
        textBoxAnimation(51,13,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,14,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,15);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroArticuloTip();
                break;
            case 2: buscarIDTip();
                break;
            case 3: listar1RegistroTip();
                break;
            case 4: modificarNivel();
                break;
            case 5: bajaLogicaTip();
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


#endif // SUBMENUTIPO_H_INCLUDED
