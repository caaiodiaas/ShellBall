
#include "ShellBall.h"
#include "powerUp.h"

// ---------------------------------------------------------------------------------

PowerUp::PowerUp(Player1* p1, Player2* p2, Player3* p3, Player4* p4)
{

    tileset = new TileSet("Resources/pokeball.png", 32, 32, 4, 12);
    anim = new Animation(tileset, 0.120f, true);

    uint SeqA[4] = { 0,1,2,3 };
    uint SeqB[4] = { 4,5,6,7 };

    anim->Add(SPEED, SeqA, 4);
    anim->Add(SLOW, SeqB, 4);


    BBox(new Circle(15));


    player1 = p1;
    player2 = p2;
    player3 = p3;
    player4 = p4;

    if (randX(mt) >= 0) {
        powerType = SPEED;
        MoveTo(window->CenterX(), window->CenterY() + 150, Layer::MIDDLE);

    }
    else {
        powerType = SLOW;
        MoveTo(window->CenterX(), window->CenterY() - 150, Layer::MIDDLE);
    }



}

// ---------------------------------------------------------------------------------

PowerUp::~PowerUp()
{
    delete tileset;
    delete anim;
}

// -------------------------------------------------------------------------------

void PowerUp::Update()
{   
    anim->Select(powerType);
    anim->NextFrame();
    if(powerType == USED)
        ShellBall::scene->Delete();
}

// -------------------------------------------------------------------------------

void PowerUp::OnCollision(Object* obj)
{
    Ball* ball = (Ball*)obj;

    if (ball->lastHit == LEFT) {
        if (powerType == SLOW) {
            player4->vel = 150;
            player3->vel = 150;
        }
        if (powerType == SPEED) {
            player1->vel = 450;
            player2->vel = 450;
        }
    }

    if (ball->lastHit == RIGHT) {
        if (powerType == SLOW) {
            player1->vel = 150;
            player2->vel = 150;
        }
        if (powerType == SPEED) {
            player3->vel = 450;
            player4->vel = 450;
        }
    }

    powerType = USED;
    
}