
#include "ShellBall.h"
#include "wall.h"

// ---------------------------------------------------------------------------------

Wall::Wall(float posX, float posY)
{

    wall = new Sprite("Resources/SmallGray.png");
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

    if (ball->Y() + ball->height2 - 6 < y - 50 && ball->Y() - ball->height2 < y - 50) {
        ball->MoveTo(ball->X(), ball->Y() - 6);
        ball->velY = -ball->velY;
    }
    else if (ball->X() - ball->width2 + 6 > x + 16 && ball->X() + ball->width2 > x + 16) {
        ball->MoveTo(ball->X() + 6, ball->Y());
        ball->velX = -ball->velX;
    }
    else    if (ball->Y() - ball->height2 + 6 > y + 50 && ball->Y() + ball->height2 > y + 50) {
        ball->MoveTo(ball->X(), ball->Y() + 6);
        ball->velY = -ball->velY;
    }
    else     if (ball->X() + ball->width2 - 6 < x - 16 && ball->X() - ball->width2 < x - 16) {
        ball->MoveTo(ball->X() - 6, ball->Y());
        ball->velX = -ball->velX;
    }

}