

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

// ------------------------------------------------------------------------------

enum ObjTypes
{
    PLAYER,                             // jogador
    BALL,                               // bola
    WALL                               // parede
};

class ShellBall : public Game
{
private:
    Player1 * player1 = nullptr;      // jogador 1
    Player2* player2 = nullptr;      // jogador 2
    Player3* player3 = nullptr;      // jogador 3
    Player4* player4 = nullptr;      // jogador 4
    Ball* ball = nullptr;      // jogador 4
    Background * backg = nullptr;   // pano de fundo
    boolean viewBBox = false;

public:
    static Scene * scene;           // gerenciador de cena

    void Init();                    // inicialização
    void Update();                  // atualização
    void Draw();                    // desenho
    void Finalize();                // finalização
};

// ---------------------------------------------------------------------------------

#endif