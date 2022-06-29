/*
 * Controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Kevin Worner
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//LOAD
int controller_loadFromText(char* path , LinkedList* pArrayList);
int controller_nameFile(LinkedList* pArrayList);
//SAVE
int controller_saveAsText(char* path , LinkedList* pArrayList);
//LIST
int controller_List(LinkedList* pArrayList);
#endif /* CONTROLLER_H_ */
