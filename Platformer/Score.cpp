
#include "ShellBall.h"
#include "Ball.h"
#include "Score.h"


Score::Score(float posX, float posY)
{
    tileset = new TileSet("Resources/ScoreSheet.png", 45, 34, 2, 4);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqOnA[1] = { 0 };
    uint SeqOffA[1] = { 1 };
    uint SeqOnB[1] = { 2 };
    uint SeqOffB[1] = { 3 };


    anim->Add(1, SeqOnA, 1);
    anim->Add(0, SeqOffA, 1);
    anim->Add(3, SeqOnB, 1);
    anim->Add(2, SeqOffB, 1);



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