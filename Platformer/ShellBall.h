

#ifndef _SHELLBALL_H_
#define _SHELLBALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Scene.h"
#include "Wall.h"
#include "Background.h"
#include "Player1.h"
#include "Player2.h"
#include "Player3.h"
#include "Player4.h"
#include "Ball.h"
#include "Score.h"
#include "WinScreen.h"
#include "PowerUp.h"
#include "PowerUp.h"
#include "Goal.h"
#include "Buff.h"

// ------------------------------------------------------------------------------

enum ObjTypes
{
    PLAYER,                             // jogador
    BALL,                               // bola
    WALL,                               // parede
    SCORE                               // pontos
};

enum GameState {
    RUNNING,
    FINISHED
};

class ShellBall : public Game
{
private:
    Player1 * player1 = nullptr;      // jogador 1
    Player2* player2 = nullptr;      // jogador 2
    Player3* player3 = nullptr;      // jogador 3
    Player4* player4 = nullptr;      // jogador 4
    PowerUp* powerUp = nullptr;
    Score* scoreIconA[3];
    Score* scoreIconB[3];
    Wall* wall1 = nullptr;
    Wall* wall2 = nullptr;
    Wall* wall3 = nullptr;
    Wall* wall4 = nullptr;
    Ball* ball = nullptr;      // jogador 4
    Background * backg = nullptr;   // pano de fundo
    WinScreen* winScreen = nullptr;
    Goal* goal = nullptr;
    Buff* buffSlowA = nullptr;
    Buff* buffSlowB = nullptr;
    Buff* buffSpeedA = nullptr;
    Buff* buffSpeedB = nullptr;
    boolean viewBBox = false;
    GameState gameState;
    int scoreA;
    int scoreB;

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif