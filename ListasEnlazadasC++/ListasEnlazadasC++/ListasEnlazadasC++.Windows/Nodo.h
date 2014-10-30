/*
	AUTOR: ANTONIO JAVIER MORENO HERNÁNDEZ
*/
#ifndef _NODO_H_
#define _NODO_H_

#include "pch.h"
using namespace Platform;

//CLASE NODO//
class Nodo
{
private:
	int dato;				//Variable int que nos dará el orden de la lista
	String^ contenido;		//Variable String^ que almacenaremos el contenido del nodo
	Nodo *sig;				//Variable Nodo que apunta al siguiente nodo de la lista
	Nodo *ant;				//Variable Nodo que apunta al nodo anterior de la lista
public:
	//CONSTRUCTORES//
	//Constructor vacio//
	Nodo();				
	//Constructor con datos de inicializacion//
	Nodo(int _dato, String^ _contenido, Nodo *_sig, Nodo *_ant);

	//DESTRUCTOR//
	virtual ~Nodo();

	//GETTER Y SETTER//
	int getDato();
	String^ getContenido();
	Nodo * getSiguiente();
	Nodo * getAnterior();
	void setDato(int _dato);
	void setContenido(String^ _contenido);
	void setSiguiente(Nodo *_sig);
	void setAnterior(Nodo *_ant);
};

#else 
class Nodo;
#endif

