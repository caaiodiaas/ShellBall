

#include "Engine.h"
#include "Resources.h"
#include "Home.h"

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nCmdShow)
{
    // cria engine
    Engine* engine = new Engine();

    // configura a janela do jogo
    engine->window->Mode(WINDOWED);
    engine->window->Size(800, 450);
    engine->window->Color(25, 25, 25);
    engine->window->Title("ShellBall");
    engine->window->Icon(IDI_ICON);
    engine->graphics->VSync(true);

    // inicia o jogo
    engine->Start(new Home());

    // destrói engine e jogo
    delete engine;
}

// ----------------------------------------------------------------------------

