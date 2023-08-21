
#include "ShellBall.h"
#include "Ball.h"
#include "Goal.h"


Goal::Goal(GoalColor color)
{
    tileset = new TileSet("Resources/goal.png", 394, 138, 3, 6);
    anim = new Animation(tileset, 0.120f, false);

    uint SeqPink[9] = { 0,1,2,1,0,1,2,1,0 };
    uint SeqYellow[9] = { 3,4,5,4,3,4,5,4,3 };

    anim->Add(PINK, SeqPink, 9);
    anim->Add(YELLOW, SeqYellow, 9);

    MoveTo(window->CenterX(), window->CenterY(), Layer::UPPER);

    goalColor = color;

}

// ---------------------------------------------------------------------------------

Goal::~Goal()
{
    delete anim;
    delete tileset;
}

// ---------------------------------------------------------------------------------

void Goal::Update()
{
    anim->Select(goalColor);
    anim->NextFrame();
    if (anim->Inactive())
        ShellBall::scene->Delete();
}

// ---------------------------------------------------------------------------------