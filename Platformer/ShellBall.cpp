
#include "Engine.h"
#include "ShellBall.h"
#include "Resources.h"
#include "Home.h"

// -----------------------------------------------------------------------------

Scene* ShellBall::scene = nullptr;

// -----------------------------------------------------------------------------

void ShellBall::Init()
{
    // cria cena do jogo
    scene = new Scene();

    // pano de fundo do jogo
    backg = new Background();
    scene->Add(backg, STATIC);

    scoreIconA[0] = new Score(200, 30);
    scoreIconA[1] = new Score(250, 30);
    scoreIconA[2] = new Score(300, 30);
    scoreIconA[0]->side = 0;
    scoreIconA[1]->side = 0;
    scoreIconA[2]->side = 0;

    scene->Add(scoreIconA[0], STATIC);
    scene->Add(scoreIconA[1], STATIC);
    scene->Add(scoreIconA[2], STATIC);

    scoreIconB[0] = new Score(500, 30);
    scoreIconB[1] = new Score(550, 30);
    scoreIconB[2] = new Score(600, 30);
    scoreIconB[0]->side = 2;
    scoreIconB[1]->side = 2;
    scoreIconB[2]->side = 2;

    scene->Add(scoreIconB[0], STATIC);
    scene->Add(scoreIconB[1], STATIC);
    scene->Add(scoreIconB[2], STATIC);

    scoreA = 0;
    scoreB = 0;

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

    wall1 = new Wall(15, 50);
    scene->Add(wall1, STATIC);
    wall2 = new Wall(15, window->Height()-50);
    scene->Add(wall2, STATIC);
    wall3 = new Wall(window->Width()-15, 50);
    scene->Add(wall3, STATIC);
    wall4 = new Wall(window->Width() - 15, window->Height() - 50);
    scene->Add(wall4, STATIC);

    powerUp = new PowerUp(player1, player2, player3, player4);
    scene->Add(powerUp, STATIC);

    gameState = RUNNING;

}

// ------------------------------------------------------------------------------

void ShellBall::Update()
{


    // buffs
    if (player1->vel == 150) {
        buffSlowA = new Buff(SLOW, 0);
        scene->Add(buffSlowA, STATIC);
    }
    else {
        if(buffSlowA != nullptr)
            scene->Remove(buffSlowA, STATIC);
    }

    if (player4->vel == 150) {
        buffSlowB = new Buff(SLOW, 1);
        scene->Add(buffSlowB, STATIC);
    }
    else {
        if (buffSlowB != nullptr)
            scene->Remove(buffSlowB, STATIC);
    }

    if (player1->vel == 450) {
        buffSpeedA = new Buff(SPEED, 0);
        scene->Add(buffSpeedA, STATIC);
    }
    else {
        if (buffSpeedA != nullptr)
            scene->Remove(buffSpeedA, STATIC);
    }

    if (player4->vel == 450) {
        buffSpeedB = new Buff(SPEED, 1);
        scene->Add(buffSpeedB, STATIC);
    }
    else {
        if (buffSpeedB != nullptr)
            scene->Remove(buffSpeedB, STATIC);
    }

    // gol lado direito
    if (ball->X() + 15 > window->Width()) {
        ball->Reset();
        player1->Reset();
        player2->Reset();
        player3->Reset();
        player4->Reset();

        scoreA++;
        goal = new Goal(YELLOW);
        scene->Add(goal, STATIC);
        powerUp = new PowerUp(player1, player2, player3, player4);
        scene->Add(powerUp, STATIC);
        backg->backgroundType = TUTORIAL;
    }

    // gol lado esquerdo
    if (ball->X() - 15 < 0) {
        ball->Reset();
        player1->Reset();
        player2->Reset();
        player3->Reset();
        player4->Reset();
        scoreB++;
        goal = new Goal(PINK);
        scene->Add(goal, STATIC);
        powerUp = new PowerUp(player1, player2, player3, player4);
        scene->Add(powerUp, STATIC);
        backg->backgroundType = TUTORIAL;
    }

    if (scoreA == 1) {
        // acende score 1
        scoreIconA[0]->side = 1;
    }
    if (scoreA == 2) {
        // acende score 2
        scoreIconA[1]->side = 1;
    }
    if (scoreA == 3) {
        // acende score 3
        scoreIconA[2]->side = 1;
    }

    if (scoreB == 1) {
        // acende score 1
        scoreIconB[0]->side = 3;
    }
    if (scoreB == 2) {
        // acende score 2
        scoreIconB[1]->side = 3;
    }
    if (scoreB == 3) {
        // acende score 3
        scoreIconB[2]->side = 3;
    }


    // amarelo venceu
    if (scoreA == 3 && gameState == RUNNING) {

        winScreen = new WinScreen(A);
        scene->Remove(player1, MOVING);
        scene->Remove(player2, MOVING);
        scene->Remove(player3, MOVING);
        scene->Remove(player4, MOVING);
        scene->Remove(ball, MOVING);
        scene->Remove(wall1, STATIC);
        scene->Remove(wall2, STATIC);
        scene->Remove(wall3, STATIC);
        scene->Remove(wall4, STATIC);
        scene->Remove(backg, STATIC);

        scene->Add(winScreen, STATIC);
        gameState = FINISHED;
    }

    // rosa venceu
    if (scoreB == 3 && gameState == RUNNING) {

        winScreen = new WinScreen(B);
        scene->Remove(player1, MOVING);
        scene->Remove(player2, MOVING);
        scene->Remove(player3, MOVING);
        scene->Remove(player4, MOVING);
        scene->Remove(ball, MOVING);
        scene->Remove(wall1, STATIC);
        scene->Remove(wall2, STATIC);
        scene->Remove(wall3, STATIC);
        scene->Remove(wall4, STATIC);
        scene->Remove(backg, STATIC);

        scene->Add(winScreen, STATIC);
        gameState = FINISHED;
    }


    // tutorial
    if (window->KeyPress(VK_SPACE) && ball->lastHit == STILL) {
        ball->Start();
        player1->Start();
        player2->Start();
        player3->Start();
        player4->Start();
        backg->backgroundType = REGULAR;
    }

    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // reinicia o jogo
    if (window->KeyPress(VK_RETURN) && gameState == FINISHED) {
        Engine::Next<Home>();
        return;
    }


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

