#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pelicula.h"

int menu();

int main()
{
	setbuf(stdout,NULL);

	int flag = 0;
    int opcion = 0;

    LinkedList* listaPeliculas = ll_newLinkedList();

    if(listaPeliculas == NULL)
    {
    	exit(1);
    }

    do{

    	opcion = menu();

        switch(opcion)
        {
            case 1:
            	if(!flag)
            	{
            		controller_nameFile(listaPeliculas);
            		printf("El archivo de texto se cargo con exito \n");
            		flag = 1;
            	}
            	break;

            case 2:
            	if(flag)
            	{
            		controller_List(listaPeliculas);
            	}
            	break;

            case 7:
            	if(flag)
            	{
            		controller_saveAsText("datapelis.csv", listaPeliculas);
            		printf("Archivo de texto guardado correctamente\n");
            		flag = 0;
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo de texto de las peliculas previamente \n\n");
            	}
            	break;
            case 8:
            	printf("\nSaliste del programa exitosamente.\n");
            	break;

        }
    }while(opcion != 8);
    return 0;
}

int menu()
{
	 	int opcion;
	    printf("\t***Bienvenido ***\n");
	    printf("1. Cargar Archivo\n");
	    printf("2. Imprimir lista\n");
	    printf("3. Asignar rating\n");
	    printf("4. Asignar genero\n");
	    printf("5. Filtrar por genero\n");
	    printf("6. Ordenar peliculas\n");
	    printf("7. Guardar peliculas\n");
	    printf("8. Salir\n");
	    printf("Elija una opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);
	    while(opcion < 1 || opcion > 8)
	    {
	        printf("Error. Elija una opcion valida: ");
	        fflush(stdin);
	        scanf("%d", &opcion);
	    }
	    return opcion;
}
