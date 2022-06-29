/*
 * Pelicula.c
 *
 *  Created on: 29 jun. 2022
 *      Author: Kevin Worner
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pelicula.h"
#include "funciones.h"

eMovie* Movie_new()
{
	eMovie* newMovie = (eMovie*) malloc(sizeof(eMovie));

	return newMovie;
}
/*-----------------------------------------------------------------------------------------------*/
eMovie* newParametros(char* idStr,char* tituloStr,char* generoStr,char* ratingStr)
{
	eMovie* newMovie = Movie_new();
	int auxId;
	int auxRating;

	if(newMovie != NULL)
	{
		auxId = atoi(idStr);
		auxRating = atof(ratingStr);
		Movie_setId(newMovie, auxId);
		Movie_setTitulo(newMovie, tituloStr);
		Movie_setGenero(newMovie, generoStr);
		Movie_setRating(newMovie, auxRating);

	}
	return newMovie;
}
/*-----------------------------------------------------------------------------------------------*/
void Movie_delete(eMovie* this)
{
	free(this);
}
/*-----------------------------------------------------------------------------------------------*/
//SETTERS
int Movie_setId(eMovie* this,int id)
{
	int ret = -1;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
/*------------------------------------------------------------------------------------------------*/
int Movie_setTitulo(eMovie* this,char* titulo)
{
	int ret = -1;
	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		ret = 0;
	}

	return ret;
}
/*-------------------------------------------------------------------------------------------------*/
int Movie_setGenero(eMovie* this,char* genero)
{
	int ret = -1;
	if(this != NULL && genero != NULL)
	{
		strcpy(this->genero, genero);
		ret = 0;
	}
	return ret;
}
int Movie_setRating(eMovie* this,float rating)
{
	int ret = -1;
	if(this != NULL)
	{
		this->rating = rating;
		ret = 0;
	}
	return ret;
}
//GETTERS
int Movie_getId(eMovie* this,int* id)
{
	int ret = -1;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Movie_getTitulo(eMovie* this,char* titulo)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(titulo, this->titulo);
		ret = 0;
	}
	return ret;
}
/*-----------------------------------------------------------------------------------------------*/
int Movie_getGenero(eMovie* this,char* genero)
{
	int ret = -1;
	if(this != NULL)
	{
		strcpy(genero, this->genero);
		ret = 0;
	}
	return ret;
}
int Movie_getRating(eMovie* this,float* rating)
{
	int ret = -1;
	if(this != NULL)
	{
		*rating = this->rating;
		ret = 0;
	}
	return ret;
}
int pelicula_mostrarUno(eMovie* pelicula)
{
	int ret = -1;
	int id;
	char titulo[50];
	char genero[30];
	float rating;

	if(pelicula != NULL)
	{
			Movie_getId(pelicula, &id);
			Movie_getTitulo(pelicula, titulo);
			Movie_getGenero(pelicula, genero);
			Movie_getRating(pelicula, &rating);

			printf("  %4d  %30s   %30s  %2.f\n", id, titulo, genero, rating);

		ret = 0;
	}
    return ret;
}
