
#include "ShellBall.h"
#include "Player2.h"

// ---------------------------------------------------------------------------------
void Player2::Reset()
{
    MoveTo(200.0f, window->CenterY(), Layer::MIDDLE);
    vel = 0;
    side = 2;
}
void Player2::Start()
{
    vel = 300;
}
Player2::Player2()
{
    tileset = new TileSet("Resources/pokeplayer.png", 46, 72, 7, 14);
    anim = new Animation(tileset, 0.12f, true);

    uint SeqUp[3] = { 1,2,3 };
    uint SeqDown[3] = { 4,5,6 };
    uint SeqStill[1] = { 0 };

    height2 = int(60 / 2);
    vel = 0;


    anim->Add(1, SeqDown, 3);
    anim->Add(0, SeqUp, 3);
    anim->Add(2, SeqStill, 1);

    side = 2;

    MoveTo(200.0f, window->CenterY(), Layer::MIDDLE);

    BBox(new Rect(-16, -height2, 16, height2));

    type = PLAYER;
}

// ---------------------------------------------------------------------------------

Player2::~Player2()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Player2::OnCollision(Object* obj)
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

    ball->lastHit = LEFT;
}

// ---------------------------------------------------------------------------------

void Player2::Update()
{


    if (y + height2 > 370)
        MoveTo(x, 370 - height2, Layer::MIDDLE);

    if (y - height2 < 80)
        MoveTo(x, 80 + height2, Layer::MIDDLE);


    if (window->KeyDown('T')) {
        side = 1;
        Translate(0, -vel * gameTime);
    }
    else    if (window->KeyDown('G')) {
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