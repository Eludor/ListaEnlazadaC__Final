/*
	AUTOR: ANTONIO JAVIER MORENO HERNÁNDEZ
*/
#ifndef _LISTA_H_
#define _LISTA_H_

#include "Nodo.h"
#pragma once
//CLASE LISTA//
class Lista
{
private:
	Nodo *raiz;		//Variable que apunta al primer nodo de la lista
	Nodo *final;	//Variable que apunta al ultio nodo de la lista
public:
	//CONSTRUCTORES//
	//Constructor vacio//
	Lista();
	//Constructor con datos de inicializacion//
	Lista(Nodo *_raiz);

	//DESTRUCTOR//
	virtual ~Lista();

	//GETTER Y SETTER//
	Nodo *getRaiz();
	Nodo *getFinal();
	void setRaiz(Nodo *_raiz);
	void setFinal(Nodo *_final);

	//METODOS//
	//Añadir nuevo nodo//
	void addNodo(Nodo *nuevo);
	//Eliminar un nodo por dato//
	bool eliminarNodo(int dato);
	//Ordenar lista de menor a mayor por intercambio//
	void ordenarLista();
	//Mostrar el contenido formateado de la lista//
	String^ toString();
};

#else 
class Lista;
#endif