

#include "Engine.h"
#include "Home.h"
#include "ShellBall.h"

// ------------------------------------------------------------------------------

void Home::Init()
{
    backg = new Sprite("Resources/Home.png");
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete backg;
}

// ------------------------------------------------------------------------------

void Home::Update()
{
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
    backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}

// ------------------------------------------------------------------------------