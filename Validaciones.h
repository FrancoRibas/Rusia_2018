#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include "Lista.h"

/*
Validaciones:
El sistema deber� contar con las validaciones necesarias para permitir su correcto funcionamiento. Por ejemplo:
-	No deber�n existir ids duplicados para cada una de las entidades administradas.
-	Se deber� controlar la carga de los archivos.

Si bien los archivos no van a tener errores de sintaxis, puede ocurrir que haya errores en las referencias entre las entidades
por ejemplo:
  -un jugador que pertenezca a un equipo que no existe,
  -un jugador en dos equipos
  -un equipo en dos grupos,
  -un grupo sin todos los equipos,etc.

El grupo deber� identificar y tratar la mayor cantidad de errores posibles.
En caso de encontrar errores el sistema deber� imprimir por pantalla un informe con los errores encontrados
en el momento en que se inicia la aplicaci�n y antes de mostrar el men� principal.
*/


void BuscarErroresGrupo(Lista & listagrupos,Lista & listaEquipo);
bool BuscarEquiposRepetidosEnDiferentesGrupos(Lista & listagrupos);


void BuscarErroresIdJugador(Lista &listaJugadores);


void BuscarErroresIdEquipo(Lista &listaEquipos);


void BuscarErroresIdPartidos(Lista &listaPartidos);
void BuscarEnPartidoEquiposEnfrentados(Lista &listaPartidos);





#endif // VALIDACIONES_H_INCLUDED
