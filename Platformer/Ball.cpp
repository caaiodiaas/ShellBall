

#include "ShellBall.h"
#include "Ball.h"

// ---------------------------------------------------------------------------------

void Ball::Reset() {
    MoveTo(window->CenterX(), window->CenterY(), 0.0f);
    velX = 0;
    velY = 0;
    lastHit = STILL;
}

void Ball::Start() {
    if (randX(mt) >= 0) {
        velX = 150;
        lastHit = LEFT;
    }
    else {
        velX = -150;
        lastHit = RIGHT;
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
    tileset = new TileSet("Resources/GravityGuy.png", 32, 48, 5, 10);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqRight[4] = { 1,2,3,4 };
    uint SeqLeft[4] = { 5,6,7,8 };
    uint SeqStill[1] = { 0 };

    width2 = int(30 / 2);
    height2 = int(30 / 2);

    Reset();

    anim->Add(RIGHT, SeqRight, 4);
    anim->Add(LEFT, SeqLeft, 4);
    anim->Add(STILL, SeqStill,1);

    lastHit = STILL;

    MoveTo(window->CenterX(), window->CenterY(), 0.0f);

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
        velY = -velY;
    }

    if (y - height2 < 0) {
        velY = -velY;
    }


    anim->Select(lastHit);
    anim->NextFrame();

}

// ---------------------------------------------------------------------------------