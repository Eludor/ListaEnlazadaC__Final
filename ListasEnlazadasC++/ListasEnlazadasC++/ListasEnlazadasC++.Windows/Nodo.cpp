#include "pch.h"
#include "Nodo.h"
/*
	AUTOR: ANTONIO JAVIER MORENO HERNÁNDEZ
*/
//CONSTRUCTORES//
Nodo::Nodo()
{
}

Nodo::Nodo(int _dato, String^ _contenido, Nodo *_sig, Nodo *_ant)
{
	this->dato = _dato;
	this->contenido = _contenido;
	this->sig = _sig;
	this->ant = _ant;
}

//DESTRUCTOR//
Nodo::~Nodo()
{ 
	delete[] contenido;
}

//GETTER Y SETTER//
int Nodo::getDato()
{
	return this->dato;
}

String^ Nodo::getContenido()
{
	return this->contenido;
}

Nodo * Nodo::getSiguiente()
{
	return this->sig;
}

Nodo * Nodo::getAnterior()
{
	return this->ant;
}

void Nodo::setDato(int _dato)
{
	this->dato = _dato;
}

void Nodo::setContenido(String^ _contenido)
{
	this->contenido = _contenido;
}

void Nodo::setSiguiente(Nodo *_sig)
{
	this->sig = _sig;
}

void Nodo::setAnterior(Nodo *_ant)
{
	this->ant = _ant;
}
