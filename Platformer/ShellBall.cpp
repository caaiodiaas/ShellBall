
#include "Engine.h"
#include "ShellBall.h"
#include "Resources.h"

// -----------------------------------------------------------------------------

Scene* ShellBall::scene = nullptr;

// -----------------------------------------------------------------------------

void ShellBall::Init()
{
    // cria cena do jogo
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background();

    player1 = new Player1();
    scene->Add(player1, MOVING);

    player2 = new Player2();
    scene->Add(player2, MOVING);

    player3 = new Player3();
    scene->Add(player3, MOVING);

    player4 = new Player4();
    scene->Add(player4, MOVING);

    ball = new Ball();
    scene->Add(ball, MOVING);


    Wall* wall = new Wall(15, 50);
    scene->Add(wall, STATIC);
    wall = new Wall(15, window->Height()-50);
    scene->Add(wall, STATIC);
    wall = new Wall(window->Width()-15, 50);
    scene->Add(wall, STATIC);
    wall = new Wall(window->Width() - 15, window->Height() - 50);
    scene->Add(wall, STATIC);

}

// ------------------------------------------------------------------------------

void ShellBall::Update()
{
    // gol lado direito
    if (ball->X() + 15 > window->Width()) {
        ball->Reset();
        player1->Reset();
        player2->Reset();
        player3->Reset();
        player4->Reset();
    }

    // gol lado esquerdo
    if (ball->X() - 15 < 0) {
        ball->Reset();
        player1->Reset();
        player2->Reset();
        player3->Reset();
        player4->Reset();
    }

    if (window->KeyPress(VK_SPACE) && ball->lastHit == STILL) {

       /* boolean waiting = true;
        float timeEnd = gameTime + 1;
        while (waiting) {
            if (timeEnd < gameTime)
                waiting = false;
        }*/

            ball->Start();
            player1->Start();
            player2->Start();
            player3->Start();
            player4->Start();       

    }

    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza cena do jogo
    scene->Update();
    scene->CollisionDetection();

    // visualizar BBox
    if (window->KeyPress('B'))
        viewBBox = ~viewBBox;
}

// ------------------------------------------------------------------------------

void ShellBall::Draw()
{
    scene->Draw();
    if (viewBBox)
    {
        scene->DrawBBox();
    }
}

// ------------------------------------------------------------------------------

void ShellBall::Finalize()
{
    delete scene;
}




// ----------------------------------------------------------------------------

