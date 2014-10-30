#include "pch.h"
#include "Lista.h"
/*
	AUTOR: ANTONIO JAVIER MORENO HERNÁNDEZ
*/

//CONSTRUCTORES//
Lista::Lista()
{
}

Lista::Lista(Nodo *_raiz)
{
	this->raiz = _raiz;
	this->final = _raiz;
}

//DESTRUCTOR//
Lista::~Lista()
{
	while (getRaiz() != NULL)
	{
		Nodo *aux = getRaiz();
		aux->setAnterior(NULL);
		setRaiz(getRaiz()->getSiguiente());
		aux->~Nodo();
	}
	delete[] raiz;
	delete[] final;
}

//GETTER Y SETTER//
Nodo *Lista::getRaiz()
{
	return this->raiz;
}

Nodo *Lista::getFinal()
{
	return this->final;
}

void Lista::setRaiz(Nodo *_raiz)
{
	this->raiz = _raiz;
}

void Lista::setFinal(Nodo *_final)
{
	this->final = _final;
}

//METODOS//
//Funcion añadir nodo//
void Lista::addNodo(Nodo *nuevo)
{
	if (getRaiz() == NULL)
	{
		setRaiz(nuevo);
	}
	else{
		Nodo* aux = getFinal();
		aux->setSiguiente(nuevo);
		nuevo->setAnterior(aux);
	}
	setFinal(nuevo);
}

//Funcion eliminar nodo//
bool Lista::eliminarNodo(int dato)
{
	bool encontrado = false;
	Nodo *aux = getRaiz();

	while (aux != NULL){
		if (aux->getDato() == dato){
			encontrado = true;
			break;
		}
		aux = aux->getSiguiente();
	}
	if (encontrado){
		Nodo *ant = aux->getAnterior();
		Nodo *sig = aux->getSiguiente();

		if (ant != NULL) ant->setSiguiente(sig);
		if (sig != NULL) sig->setAnterior(ant);
		aux->~Nodo();

		if (sig == NULL) setFinal(ant);
		else if (sig->getSiguiente() == NULL) setFinal(sig);

		if (ant == NULL) setRaiz(sig);
	}

	return encontrado;
}

//Funcion ordenar lista//
void Lista::ordenarLista()
{
	Nodo *aux = getRaiz();

	while (aux != NULL)
	{
		Nodo *aux2 = aux->getSiguiente();
		while (aux2 != NULL)
		{
			if (aux->getDato() > aux2->getDato())
			{
				int datoAux = aux->getDato();
				String^ contenidoAux = aux->getContenido();

				aux->setDato(aux2->getDato());
				aux->setContenido(aux2->getContenido());

				aux2->setDato(datoAux);
				aux2->setContenido(contenidoAux);
			}
			aux2 = aux2->getSiguiente();
		}
		aux = aux->getSiguiente();
	}
}

//Funcion mostrar datos formateados//
String^ Lista::toString()
{
	String^ salida = "";
	Nodo* aux = getRaiz();

	while (aux != NULL)
	{
		salida += aux->getDato() + " - " + aux->getContenido() + "\n";
		aux = aux->getSiguiente();
	}

	return salida;
}