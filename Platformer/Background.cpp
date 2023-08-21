/**********************************************************************************
// Background (C�digo Fonte)
// 
// Cria��o:     21 Abr 2012
// Atualiza��o: 12 Mar 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Plano de fundo do jogo
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
