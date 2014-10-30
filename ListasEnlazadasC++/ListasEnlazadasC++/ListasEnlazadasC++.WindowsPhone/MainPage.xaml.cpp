//
// MainPage.xaml.cpp
// Implementación de la clase MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"

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
}

/// <summary>
/// Se invoca cuando esta página se va a mostrar en un objeto Frame.
/// </summary>
/// <param name="e">Datos de evento que describen cómo se llegó a esta página. La propiedad Parameter
/// se usa normalmente para configurar la página.</param>
void MainPage::OnNavigatedTo(NavigationEventArgs^ e)
{
	(void) e;	// Parámetro sin usar

	// TODO: Preparar la página que se va a mostrar aquí.

	// TODO: Si la aplicación contiene varias páginas, asegúrese de
	// controlar el botón para retroceder del hardware registrándose en el
	// evento Windows::Phone::UI::Input::HardwareButtons.BackPressed.
	// Si usa NavigationHelper, que se proporciona en algunas plantillas,
	// el evento se controla automáticamente.
}
