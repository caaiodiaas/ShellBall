
#include "ShellBall.h"
#include "powerUp.h"

// ---------------------------------------------------------------------------------

PowerUp::PowerUp(float posX, float posY, Player1* player1, Player2* player2, Player3* player3, Player4* player4)
{

    powerUp = new Sprite("Resources/SmallGray.png");
    BBox(new Rect(-16, -50, 16, 50));
    MoveTo(posX, posY);

    
}

// ---------------------------------------------------------------------------------

PowerUp::~PowerUp()
{
    delete powerUp;
}

// -------------------------------------------------------------------------------

void PowerUp::Update()
{


}

// -------------------------------------------------------------------------------

void PowerUp::OnCollision(Object* obj)
{
    Ball* ball = (Ball*)obj;

    if (ball->lastHit == LEFT) {

    }

}