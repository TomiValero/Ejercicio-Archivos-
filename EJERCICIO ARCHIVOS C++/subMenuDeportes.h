#ifndef SUBMENUDEPORTES_H_INCLUDED
#define SUBMENUDEPORTES_H_INCLUDED

int subMenuDeporte()
{
    const int tiemp=0;
    int opc=0;
    while(true){system("cls");
        textBoxAnimation(65,5,"***MENU DEPORTES***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,8,tiemp);
        textBoxAnimation(51,8,"1. AGREGAR DEPORTE",0,tiemp);
        textBoxAnimation(51,9,"2. LISTAR DEPORTE POR ID",0,tiemp);
        textBoxAnimation(51,10,"3. LISTAR TODOS LOS DEPORTES",0,tiemp);
        textBoxAnimation(51,11,"4. MODIFICAR ANIO DE ORIGEN",0,tiemp);
        textBoxAnimation(51,12,"5. ELIMINAR REGISTRO DE DEPORTE",0,tiemp);
        textBoxAnimation(51,13,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,14,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,15);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroArticuloD();
                break;
            case 2: buscarID();
                break;
            case 3: listar1RegistroD();
                break;
            case 4: modificarAnioD();
                break;
            case 5: bajaLogicaD();
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



#endif // SUBMENUDEPORTES_H_INCLUDED
