/**********************************************************************************
// WinScreen (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "WinScreen.h"

// ---------------------------------------------------------------------------------

WinScreen::WinScreen(uint winType)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::UPPER);

    if (winType == A) {
        winScreen = new Sprite("Resources/YellowWins.png");
    }
    else {
        winScreen = new Sprite("Resources/PinkWins.png");
    }

}

// ---------------------------------------------------------------------------------

WinScreen::~WinScreen()
{
    delete winScreen;
}

// -------------------------------------------------------------------------------

void WinScreen::Update()
{
}

// -------------------------------------------------------------------------------

void WinScreen::Draw()
{
    // desenha pano de fundo
    winScreen->Draw(window->CenterX(), window->CenterY(), Layer::UPPER);

}

// -------------------------------------------------------------------------------
