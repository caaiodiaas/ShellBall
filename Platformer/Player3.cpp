
#include "ShellBall.h"
#include "Player3.h"

// ---------------------------------------------------------------------------------
void Player3::Reset()
{
    MoveTo(600.0f, window->CenterY(), Layer::MIDDLE);
    vel = 0;
    side = 2;
}
void Player3::Start()
{
    vel = 300;
}
Player3::Player3()
{
    tileset = new TileSet("Resources/pokeplayer.png", 46, 72, 7, 14);
    anim = new Animation(tileset, 0.12f, true);

    uint SeqUp[3] = { 8,9,10 };
    uint SeqDown[3] = { 11,12,13 };
    uint SeqStill[1] = { 7 };

    height2 = int(60 / 2);
    vel = 0;


    anim->Add(1, SeqDown, 3);
    anim->Add(0, SeqUp, 3);
    anim->Add(2, SeqStill, 1);

    side = 2;

    MoveTo(600.0f, window->CenterY(), Layer::MIDDLE);

    BBox(new Rect(-16, -height2, 16, height2));

    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player3::~Player3()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player3::OnCollision(Object* obj)
{
    Ball* ball = (Ball*)obj;

    if (ball->Y() <= y - height2) {
        ball->MoveTo(ball->X(), ball->Y() - ball->velPositive / 40, Layer::MIDDLE);
        ball->velY = -ball->velY;
    }
    else
    if (ball->Y() >= y + height2) {
        ball->MoveTo(ball->X(), ball->Y() + ball->velPositive / 40, Layer::MIDDLE);
        ball->velY = -ball->velY;
    }
    else
    if (ball->X() < x - 17) {
        ball->MoveTo(ball->X() - ball->velPositive / 40, ball->Y(), Layer::MIDDLE);
        ball->velX = -ball->velX;
    }
    else
    if (ball->X() > x + 17) {
        ball->MoveTo(ball->X() + ball->velPositive / 40, ball->Y(), Layer::MIDDLE);
        ball->velX = -ball->velX;
    }
    if (ball->velX < 400 && ball->velX > -400) {
        ball->velPositive = ball->velPositive * 1.1f;
        ball->velX = ball->velX * 1.1f;
        ball->velY = ball->velY * 1.1f;
    }

    ball->lastHit = RIGHT;
}

// ---------------------------------------------------------------------------------

void Player3::Update()
{


    //Translate(0, -12);

    if (y + height2 > 370)
        MoveTo(x, 370 - height2, Layer::MIDDLE);

    if (y - height2 < 80)
        MoveTo(x, 80 + height2, Layer::MIDDLE);


    if (window->KeyDown('O')) {
        side = 1;
        Translate(0, -vel * gameTime);
    }
    else    if (window->KeyDown('L')) {
        side = 0;
        Translate(0, vel * gameTime);
    }
    else {
        side = 2;
    }


    anim->Select(side);
    anim->NextFrame();

}

// ---------------------------------------------------------------------------------