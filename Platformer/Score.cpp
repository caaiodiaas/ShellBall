
#include "ShellBall.h"
#include "Ball.h"
#include "Score.h"


Score::Score(float posX, float posY)
{
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqOn[1] = { 1};
    uint SeqOff[1] = { 5};


    anim->Add(1, SeqOn, 1);
    anim->Add(0, SeqOff, 1);

    side = 0;


    MoveTo(posX, posY, 1.0f);

    type = SCORE;
}

// ---------------------------------------------------------------------------------

Score::~Score()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Score::Update()
{
    anim->Select(side);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------