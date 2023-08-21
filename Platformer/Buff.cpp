
#include "ShellBall.h"
#include "Ball.h"
#include "Buff.h"

Buff::Buff( uint side)
{
    tileset = new TileSet("Resources/buffs.png", 32, 32, 2, 2);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqSpeed[1] = { 0 };
    uint SeqSlow[1] = { 1 };
    uint SeqNull[1] = {};

    anim->Add(SPEED, SeqSpeed, 1);
    anim->Add(SLOW, SeqSlow, 1);
    anim->Add(USED, SeqNull, 0);

    sideBuff = side;

    buffType = USED;

    MoveTo(1000, 1000, Layer::UPPER);

}

// ---------------------------------------------------------------------------------

Buff::~Buff()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Buff::Update()
{
    if (buffType == SLOW)
    {
        if (sideBuff == 0)
        {
            MoveTo(100, 30, Layer::UPPER);
        }
        else {
            MoveTo(700, 30, Layer::UPPER);
        }

    }
    else if (buffType == SPEED) {
        if (sideBuff == 0)
        {
            MoveTo(50, 30, Layer::UPPER);
        }
        else {
            MoveTo(750, 30, Layer::UPPER);
        }
    }
    else if (buffType == USED) {

            MoveTo(1000, 1000, Layer::UPPER);

    }
    anim->Select(buffType);
    anim->NextFrame();

}

// ---------------------------------------------------------------------------------