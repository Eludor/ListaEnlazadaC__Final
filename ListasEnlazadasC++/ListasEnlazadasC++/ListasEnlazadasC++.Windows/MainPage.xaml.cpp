/*
	AUTOR: ANTONIO JAVIER MORENO HERNÁNDEZ
*/
//
// MainPage.xaml.cpp
// Implementación de la clase MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "Lista.h"


using namespace ListasEnlazadasC__;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// La plantilla de elemento Página en blanco está documentada en http://go.microsoft.com/fwlink/?LinkId=234238

MainPage::MainPage()
{
	InitializeComponent();
	Lista *listado = new Lista(new Nodo(5, "contenido 5", NULL, NULL));
	listado->addNodo(new Nodo(0, "contenido 0", NULL, NULL));
	listado->addNodo(new Nodo(1, "contenido 1", NULL, NULL));
	listado->addNodo(new Nodo(3, "contenido 3", NULL, NULL));
	listado->addNodo(new Nodo(2, "contenido 2", NULL, NULL));

	textoSalida->Text=listado->toString();

	listado->ordenarLista();
	
	listado->eliminarNodo(5);

	textoSalida->Text += "\n" + listado->toString();
	listado->~Lista();
}
