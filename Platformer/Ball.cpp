

#include "ShellBall.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

void Ball::Reset() {
    MoveTo(window->CenterX(), window->CenterY(), Layer::MIDDLE);
    velX = 0;
    velY = 0;
    lastHit = STILL;
}

void Ball::Start() {
    velPositive = 150;
    lastHit = NEUTRAL;
    if (randX(mt) >= 0) {
        velX = 150;
    }
    else {
        velX = -150;
    }

    if (randY(mt) >= 0) {
        velY = 150;
    }
    else {
        velY = -150;
    }
}

Ball::Ball()
{
    tileset = new TileSet("Resources/pokeball.png", 32, 32, 4, 12);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqRight[4] = { 4,5,6,7 };
    uint SeqLeft[4] = { 8,9,10,11 };
    uint SeqNeutral[4] = { 0,1,2,3 };
    uint SeqStill[1] = { 0 };

    width2 = int(30 / 2);
    height2 = int(30 / 2);

    Reset();

    anim->Add(RIGHT, SeqRight, 4);
    anim->Add(LEFT, SeqLeft, 4);
    anim->Add(NEUTRAL, SeqNeutral, 4);
    anim->Add(STILL, SeqStill,1);

    lastHit = STILL;

    MoveTo(window->CenterX(), window->CenterY(), Layer::MIDDLE);

    BBox(new Circle(15));

    type = BALL;
}

// ---------------------------------------------------------------------------------

Ball::~Ball()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Ball::OnCollision(Object* obj)
{


}

// ---------------------------------------------------------------------------------

void Ball::Update()
{


    Translate(velX * gameTime, velY * gameTime);

    if (y + height2 > window->Height()) {
        MoveTo(x, y - 6, Layer::MIDDLE);
        velY = -velY;
    }

    if (y - height2 < 0) {
        MoveTo(x, y + 6, Layer::MIDDLE);
        velY = -velY;
    }


    anim->Select(lastHit);
    anim->NextFrame();

}

// ---------------------------------------------------------------------------------