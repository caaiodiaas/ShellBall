
#include "ShellBall.h"
#include "wall.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float posX, float posY)
{

    wall = new Sprite("Resources/Wall.png");
    BBox(new Rect(-16, -50, 16,50));
    MoveTo(posX, posY);

    type = WALL;
}

// ---------------------------------------------------------------------------------

Wall::~Wall()
{
    delete wall;
}

// -------------------------------------------------------------------------------

void Wall::Update()
{

    
}

// -------------------------------------------------------------------------------

void Wall::OnCollision(Object* obj)
{
    Ball* ball = (Ball*)obj;

    if (ball->Y() <= y - 50) {
        ball->MoveTo(ball->X(), ball->Y() - ball->velPositive / 40, Layer::MIDDLE);
        ball->velY = -ball->velY;
    }else
    if (ball->Y() >= y + 50) {
        ball->MoveTo(ball->X(), ball->Y() + ball->velPositive / 40, Layer::MIDDLE);
        ball->velY = -ball->velY;
    }else
    if (ball->X() < x - 16) {
        ball->MoveTo(ball->X() - ball->velPositive / 40, ball->Y(), Layer::MIDDLE);
        ball->velX = -ball->velX;
    }
    else
    if (ball->X() > x + 16) {
        ball->MoveTo(ball->X() + ball->velPositive / 40, ball->Y(), Layer::MIDDLE);
        ball->velX = -ball->velX;
    }

}