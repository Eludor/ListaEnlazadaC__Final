//
// App.xaml.cpp
// Implementación de la clase App.
//

#include "pch.h"
#include "MainPage.xaml.h"

using namespace ListasEnlazadasC__;

using namespace Platform;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml::Media::Animation;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// La plantilla Aplicación vacía está documentada en http://go.microsoft.com/fwlink/?LinkId=234227

/// <summary>
/// Inicializa el objeto de aplicación Singleton. Esta es la primera línea de código creado
/// ejecutado y, como tal, es el equivalente lógico de main() o WinMain().
/// </summary>
App::App()
{
	InitializeComponent();
	Suspending += ref new SuspendingEventHandler(this, &App::OnSuspending);
}

/// <summary>
/// Se invoca cuando la aplicación la inicia normalmente el usuario final. Otros puntos de entrada
/// de entrada cuando la aplicación se inicie para abrir un archivo específico, para mostrar
/// resultados de la búsqueda, etc.
/// </summary>
/// <param name="e">Información detallada acerca de la solicitud y el proceso de inicio.</param>
void App::OnLaunched(LaunchActivatedEventArgs^ e)
{
#if _DEBUG
	if (IsDebuggerPresent())
	{
		DebugSettings->EnableFrameRateCounter = true;
	}
#endif

	auto rootFrame = dynamic_cast<Frame^>(Window::Current->Content);

	// No repetir la inicialización de la aplicación si la ventana tiene contenido todavía,
	// solo asegurarse de que la ventana está activa.
	if (rootFrame == nullptr)
	{
		// Crear un marco para que actúe como contexto de navegación y asociarlo con
		// una clave SuspensionManager
		rootFrame = ref new Frame();

		// TODO: Cambiar este valor a un tamaño de caché adecuado para la aplicación.
		rootFrame->CacheSize = 1;

		if (e->PreviousExecutionState == ApplicationExecutionState::Terminated)
		{
			// TODO: Restaurar el estado de sesión guardado solo si es apropiado, programando
			// los pasos de inicio finales una vez completada la restauración.
		}

		// Poner el marco en la ventana actual.
		Window::Current->Content = rootFrame;
	}

	if (rootFrame->Content == nullptr)
	{
#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
		// Quita la navegación de transición en el inicio.
		if (rootFrame->ContentTransitions != nullptr)
		{
			_transitions = ref new TransitionCollection();
			for (auto transition : rootFrame->ContentTransitions)
			{
				_transitions->Append(transition);
			}
		}

		rootFrame->ContentTransitions = nullptr;
		_firstNavigatedToken = rootFrame->Navigated += ref new NavigatedEventHandler(this, &App::RootFrame_FirstNavigated);
#endif

		// Cuando no se restaura la pila de navegación para navegar a la primera página,
		// configurar la nueva página al pasar la información requerida como parámetro
		// parámetro.
		if (!rootFrame->Navigate(MainPage::typeid, e->Arguments))
		{
			throw ref new FailureException("Failed to create initial page");
		}
	}

	// Asegurarse de que la ventana actual está activa.
	Window::Current->Activate();
}

#if WINAPI_FAMILY==WINAPI_FAMILY_PHONE_APP
/// <summary>
/// Restaura las transiciones de contenido después de iniciar la aplicación.
/// </summary>
void App::RootFrame_FirstNavigated(Object^ sender, NavigationEventArgs^ e)
{
	auto rootFrame = safe_cast<Frame^>(sender);

	TransitionCollection^ newTransitions;
	if (_transitions == nullptr)
	{
		newTransitions = ref new TransitionCollection();
		newTransitions->Append(ref new NavigationThemeTransition());
	}
	else
	{
		newTransitions = _transitions;
	}

	rootFrame->ContentTransitions = newTransitions;

	rootFrame->Navigated -= _firstNavigatedToken;
}
#endif

/// <summary>
/// Se invoca al suspender la ejecución de la aplicación. El estado de la aplicación se guarda
/// sin saber si la aplicación se terminará o se reanudará con el contenido
/// de la memoria aún intacto.
/// </summary>
void App::OnSuspending(Object^ sender, SuspendingEventArgs^ e)
{
	(void) sender;	// Parámetro sin usar
	(void) e;		// Parámetro sin usar

	// TODO: Guardar el estado de la aplicación y detener toda actividad en segundo plano
}