#include "Fechas.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "Lista.h"
#include "Equipo.h"

using namespace std;

void CargarListaEquipoEnListaFecha(Lista &ListaGrupos,Lista &ListaEquipo,Lista &Listafechas){

    PtrNodoLista cursorEquipo = primero(ListaEquipo);
    PtrNodoLista cursorFechas = primero(Listafechas);

    if(listaVacia(Listafechas)){
        cout<<"Se puede llenar Entonces, hacer todo el proceso de Puntos"<<endl;
    }
    else{
        cout<<"La lista ya esta llena"<<endl;
    }

    ///Escribir en el archivo
}

///Segundo Paso

void cargarListafechas(Lista &Listafechas){
    FILE *f;
    f = fopen("fechas.txt","r++");

    crearLista(Listafechas,Listafechas.compara);

    while(!feof(f)){
        Fecha *eq = new Fecha;

        fscanf(f,"%d;%[^;];\n",&eq->Id,eq->Nombre);

        if(listaVacia(Listafechas)){
            adicionarPrincipio(Listafechas,eq);

        }
        else{
            adicionarFinal(Listafechas,eq);
        }

    }
    fclose(f);
}


void recorrerFechas(Lista &Listafechas){

    PtrNodoLista cursor = primero(Listafechas);

    cout <<"---------------------- Fechas ---------------------- " <<endl;
    cout <<""<<endl;
        while (cursor != fin()) {
            cout <<"Id: " << ((Fecha*)cursor->ptrDato)->Id<<endl;
            cout <<"Nombre Equipo : "<< ((Fecha*)cursor->ptrDato)->Nombre<<endl;
            cursor = siguiente(Listafechas, cursor);
        }
        cout << endl;
}


int ContarEquiposDisponibles(Lista &Listafechas){   //servira para comparar con el control de fechas aver si llego hasta donde se queria
    PtrNodoLista cursor = primero(Listafechas);

    int contadorDeEquipos = 0;

        while (cursor != fin()) {
            contadorDeEquipos++;        //esto solo me dice cuantos equipos hay
            cursor = siguiente(Listafechas, cursor);
        }

    return(contadorDeEquipos);
}


void ControlDeFechas(Lista &Listafechas){   //esta funcion se hace por cada etapa/fecha solamente!!!

    PtrNodoLista cursor = primero(Listafechas);

    int contadorDeEquipos = 0;
    FILE *f;

        while (cursor != fin()) {
            contadorDeEquipos++;        //esto solo me dice cuantos equipos hay
            cursor = siguiente(Listafechas, cursor);
        }
    //cout <<"Hay "<<contadorDeEquipos<<" Equipos"<<endl;
    contadorDeEquipos = contadorDeEquipos / 2;  //es lo que quiero para la prox etapa, entonces empiezo a p

    remove ("ControlDeFechas.txt");
    f = fopen("ControlDeFechas.txt","a");
    fprintf(f,"%d\n",contadorDeEquipos);
    fclose(f);

}


void DescalificarEquipo(Lista &Listafechas){

    //Bajafecha(Listafechas);

}


bool Bajafecha(Lista &Listafechas,int id){

    int idaux,GolesAFavor,GolesEnContra,puntos;

    char nombre[20];

    bool exito = false;

    FILE *faux;

    if(  BuscarIdExistenteFecha(Listafechas,id) != true)
        cout << "este id no hiciste" << endl;

    else{
       faux = fopen("fechasaux.txt","w++");

        PtrNodoLista cursor = primero(Listafechas);


        while (cursor != fin()) {


            if ( ((Fecha*)cursor->ptrDato)->Id == id){
                eliminarNodo(Listafechas,cursor);

                exito = true;

            }
            else{
            idaux = ((Fecha*)cursor->ptrDato)->Id;
            strcpy(nombre,((Fecha*)cursor->ptrDato)->Nombre);
            //GolesAFavor = ((Fecha*)cursor->ptrDato)->Goles_A_Favor;
            //GolesEnContra = ((Fecha*)cursor->ptrDato)->Goles_En_Contra;
            //puntos = ((Fecha*)cursor->ptrDato)->Puntos;

            fprintf(faux,"%d;%s;\n",idaux,nombre);
            }

            cursor = siguiente(Listafechas, cursor);
        }
      fclose(faux);
    remove("fechas.txt");
    rename("fechasaux.txt","fechas.txt");

    }
        return exito;


    }

bool BuscarIdExistenteFecha(Lista &listafecha,int id){

    bool encontrado = false;
        PtrNodoLista cursor = primero(listafecha);
        while (cursor != fin()) {
             if ( ((Fecha*)cursor->ptrDato)->Id == id)
                encontrado = true;
            cursor = siguiente(listafecha, cursor);
        }
        return encontrado;
}





