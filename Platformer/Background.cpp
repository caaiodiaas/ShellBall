

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);

    tutorial = new Sprite("Resources/BackgroundStart.png");
    regular   = new Sprite("Resources/Background.png");
    backgroundType = TUTORIAL;
    background = tutorial;

}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    delete tutorial;
    delete regular;
    delete background;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    if (backgroundType == REGULAR)
    {
        background = regular;
    }
    else {
        background = tutorial;
    }
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
    background->Draw(window->CenterX(), window->CenterY(), Layer::BACK);

}

// -------------------------------------------------------------------------------
