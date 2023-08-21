

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);

    background   = new Sprite("Resources/Background.png");    

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
