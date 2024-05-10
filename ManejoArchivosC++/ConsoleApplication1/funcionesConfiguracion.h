#ifndef FUNCIONESCONFIGURACION_H_INCLUDED
#define FUNCIONESCONFIGURACION_H_INCLUDED



void copiaJugadores(){
    Jugador reg;
    FILE *pEmp=fopen("jugadores.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pBkp=fopen("jugadores.bkp","wb");
        if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pEmp)==1){
       fwrite(&reg, sizeof reg,1,pBkp);
    }
    cout<<"COPIA REALIZADA CON EXITO"<<endl;
    fclose(pBkp);
    fclose(pEmp);
    return;
}

void copiaDeportes(){
    Deporte reg;
    FILE *pEmp=fopen("deportes.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pBkp=fopen("deportes.bkp","wb");

        if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pEmp)==1){
       fwrite(&reg, sizeof reg,1,pBkp);
    }
    cout<<"COPIA REALIZADA CON EXITO"<<endl;
    fclose(pBkp);
    fclose(pEmp);
    return;
}

void copiaEquipos(){
    Equipo reg;
    FILE *pEmp=fopen("equipos.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pBkp=fopen("equipos.bkp","wb");

        if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pEmp)==1){
       fwrite(&reg, sizeof reg,1,pBkp);
    }
    cout<<"COPIA REALIZADA CON EXITO"<<endl;
    fclose(pBkp);
    fclose(pEmp);
    return;
}

void copiaTipo(){
    Tipo reg;
    FILE *pEmp=fopen("TipodeDeporte.dat","rb");
    if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pBkp=fopen("TipodeDeporte.bkp","wb");

        if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pEmp)==1){
       fwrite(&reg, sizeof reg,1,pBkp);
    }
    cout<<"COPIA REALIZADA CON EXITO"<<endl;
    fclose(pBkp);
    fclose(pEmp);
    return;
}

void restauracionJugadores(){
    Jugador reg;
    FILE *pBkp=fopen("jugadores.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("jugadores.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionDeportes(){
    Deporte reg;
    FILE *pBkp=fopen("deportes.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("deportes.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionEquipos(){
    Equipo reg;
    FILE *pBkp=fopen("equipos.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("equipos.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionTipo(){
    Tipo reg;
    FILE *pBkp=fopen("TipodeDeporte.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("TipodeDeporte.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionIncioJugadores(){
    Jugador reg;
    FILE *pBkp=fopen("jugadoresInicio.dat","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("jugadores.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    fclose(pEmp);
    fclose(pBkp);
}

void restauracionInicoDeportes(){
    Deporte reg;
    FILE *pBkp=fopen("deportesInicio.dat","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("deportes.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO BKP"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    cout<<"RESTAURACION DE INICO REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionInicioEquipos(){
    Equipo reg;
    FILE *pBkp=fopen("equiposIni.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("equipos.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
    //cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

void restauracionInicioTipo(){
    Tipo reg;
    FILE *pBkp=fopen("TipodeDeporteIni.bkp","rb");
    if(pBkp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    FILE *pEmp=fopen("TipodeDeporte.dat","wb");
        if(pEmp==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
        }
    while(fread(&reg, sizeof reg,1,pBkp)==1){
       fwrite(&reg, sizeof reg,1,pEmp);
    }
   // cout<<"RESTAURACION REALIZADA CON EXITO"<<endl;
    fclose(pEmp);
    fclose(pBkp);
    return;
}

#endif // FUNCIONESCONFIGURACION_H_INCLUDED
