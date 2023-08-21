

#include "Engine.h"
#include "Home.h"
#include "ShellBall.h"

// ------------------------------------------------------------------------------

void Home::Init()
{

    tileset = new TileSet("Resources/MainMenu.png", 800, 450, 2, 2);
    anim = new Animation(tileset, 0.6f, true);
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete tileset;
    delete anim;
}

// ------------------------------------------------------------------------------

void Home::Update()
{

    anim->NextFrame();
    // sai do jogo com a tecla ESC
    if (window->KeyPress(VK_ESCAPE))
        window->Close();

    // passa ao primeiro nível com ENTER
    if (window->KeyPress(VK_RETURN))
        Engine::Next<ShellBall>();
}

// ------------------------------------------------------------------------------

void Home::Draw()
{
    anim->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------