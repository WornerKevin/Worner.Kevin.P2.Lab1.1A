#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pelicula.h"
#include "parser.h"
#include "funciones.h"

/*------------------------------------------------------------------------------------------------*/
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
	int ret = -1;
	FILE* f;
	f = fopen(path, "r");
	if(f != NULL && path != NULL && pArrayList != NULL)
	{
		parser_FromText(f, pArrayList);
		ret = 0;
	}
	fclose(f);
    return ret;
}
int controller_nameFile(LinkedList* pArrayList)
{
	int ret = -1;
	char path[31];

	if(pArrayList != NULL)
	{
			getString(path,"\nIngrese el nombre del archivo que desea cargar: ",
					"\nNombre muy largo\nIngrese el nombre del archivo que desea cargar: ", 30);
			controller_loadFromText(path, pArrayList);
		while(controller_loadFromText(path, pArrayList) == -1)
		{
			getString(path,"\nNombre de archivo inexistente\nIngrese el nombre del archivo que desea cargar: ",
							"\nNombre demasiado largo\nIngrese el nombre del archivo que desea cargar: ", 30);
			controller_loadFromText(path, pArrayList);
		}
	}
	return ret;
}

int controller_List(LinkedList* pArrayList)
{
	int ret = -1;
	eMovie* auxMovie;
	if(pArrayList != NULL)
	{
		printf("\t***PELICULAS***\n");
		printf("   ID       Titulo        Genero      Rating\n");
		for(int i = 0; i < ll_len(pArrayList); i++)
		{
			auxMovie = (eMovie*) ll_get(pArrayList, i);
			pelicula_mostrarUno(auxMovie);
		}
		ret = 0;
	}
    return ret;
}
/*------------------------------------------------------------------------------------------------*/
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
	int todoOk = 0;
	FILE* pFile = fopen(path,"w");
	eMovie* auxMovie;
	int auxId;
	char auxTitulo[50];
	char auxGenero[50];
	float rating;

	if (pFile !=NULL && pArrayList != NULL)
	{
        fprintf(pFile,"ID,TITULO,GENERO,RATING\n");
        for(int i = 1; i < ll_len(pArrayList); i++)
        {
        		auxMovie = ll_get(pArrayList, i);
            		Movie_getId(auxMovie, &auxId);
            		Movie_getTitulo(auxMovie, auxTitulo);
            		Movie_getGenero(auxMovie, auxGenero);
            		Movie_getRating(auxMovie, &rating);

                fprintf(pFile,"%d,%s,%s,%f\n", auxId, auxTitulo, auxGenero,rating);
        }
        todoOk = 1;
        fclose(pFile);
	}
	return todoOk;
}
/*------------------------------------------------------------------------------------------------*/



