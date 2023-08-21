/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);

    background   = new Sprite("Resources/Sky.png");    

}

// ---------------------------------------------------------------------------------

Background::~Background()
{

    delete background;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}

// -------------------------------------------------------------------------------
