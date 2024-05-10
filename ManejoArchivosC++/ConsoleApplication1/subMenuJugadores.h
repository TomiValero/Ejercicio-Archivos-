#ifndef SUBMENUJUGADORES_H_INCLUDED
#define SUBMENUJUGADORES_H_INCLUDED

int subMenuJugador()
{
    const int tiemp=0;
    int opc=0;
   while(true){
        system("cls");
        textBoxAnimation(65,5,"***MENU JUGADORES***",2,tiemp);
        cout<<endl;
        boxAnimation(50,8,2,50,8,tiemp);
        textBoxAnimation(51,8,"1. AGREGAR JUGADOR",0,tiemp);
        textBoxAnimation(51,9,"2. LISTAR JUGADOR POR DNI",0,tiemp);
        textBoxAnimation(51,10,"3. LISTAR TODOS LOS JUGADORES",0,tiemp);
        textBoxAnimation(51,11,"4. MODIFICAR FECHA DE INSCRIPCION",0,tiemp);
        textBoxAnimation(51,12,"5. ELIMINAR REGISTRO DE JUGADOR",0,tiemp);
        textBoxAnimation(51,13,"0. MENU PRINCIPAL",0,tiemp);
        textBoxAnimation(51,14,"SELECCIONAR OPCION: ",0,tiemp);
        rlutil::locate(72,15);
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: agregarRegistroArticulo();
                break;
            case 2: buscarDni();
                break;
            case 3: listar1Registro();
                break;
            case 4: modificarFecha();
                break;
            case 5: bajaLogica();
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


#endif // SUBMENUJUGADORES_H_INCLUDED
