#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pelicula.h"
#include "parser.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;

	eMovie* auxMovie = NULL;

		char id[50];
		char titulo[50];
		char genero[50];
		char rating[20];
		int cant;


		if(pFile != NULL && pArrayList != NULL)
		{

			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,\n]\n", id, titulo, genero, rating);

			do
			{
				cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,\n]\n", id, titulo, genero, rating);


				if(cant < 4)
				{
					break;
				}

				auxMovie = newParametros(id, titulo, genero,rating);

				if(auxMovie!= NULL)
				{
					ll_add(pArrayList,auxMovie);
					retorno = 0;
				}
			}while(!feof(pFile));
		}
	    return retorno;
}
