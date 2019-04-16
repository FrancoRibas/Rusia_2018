#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

#include "Lista.h"

typedef struct {
    int         Id;                 //(entero): campo identificador del equipo.
    char        Nombre[40];             //(cadena): nombre del equipo.
}Fecha;

void CargarListaEquipoEnListaFecha(Lista &ListaGrupos,Lista &ListaEquipo,Lista &Listafechas);

void cargarListafechas(Lista &Listafechas);

void recorrerFechas(Lista &Listafechas);

int ContarEquiposDisponibles(Lista &Listafechas);

void ControlDeFechas(Lista &Listafechas);

void DescalificarEquipo(Lista &Listafechas);

bool Bajafecha(Lista &Listafechas,int id);

bool BuscarIdExistenteFecha(Lista &listafecha,int id);

#endif // FECHAS_H_INCLUDED
