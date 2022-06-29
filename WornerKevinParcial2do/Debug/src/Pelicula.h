/*
 * Pelicula.h
 *
 *  Created on: 29 jun. 2022
 *      Author: Kevin Worner
 */

#ifndef PELICULA_H_
#define PELICULA_H_

struct{
	int id;
	char titulo[50];
	char genero[30];
	float rating;
}typedef eMovie;

eMovie* Movie_new();
eMovie* newParametros(char* idStr,char* tituloStr,char* generoStr,char* ratingStr);
void Movie_delete(eMovie* this);
//SETTERS
int Movie_setId(eMovie* this,int id);
int Movie_setTitulo(eMovie* this,char* titulo);
int Movie_setGenero(eMovie* this,char* genero);
int Movie_setRating(eMovie* this,float rating);
//GETTERS
int Movie_getId(eMovie* this,int* id);
int Movie_getTitulo(eMovie* this,char* titulo);
int Movie_getGenero(eMovie* this,char* genero);
int Movie_getRating(eMovie* this,float* rating);


int pelicula_mostrarUno(eMovie* pelicula);

#endif /* PELICULA_H_ */
