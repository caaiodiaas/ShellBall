

#ifndef _PLATFORMER_POWERUP_H_
#define _PLATFORMER_POWERUP_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites
#include "ShellBall.h"
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;


// ---------------------------------------------------------------------------------
enum PowerType{SPEED, SLOW, USED};

class PowerUp : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites da bola
    Animation* anim = nullptr;         // animação da bola
        random_device rd;               // gerador não determinístico
    mt19937 mt{ rd() };             // gerador mersenne twister

    uniform_int_distribution<int> randX{ -1,0 };
    uniform_int_distribution<int> randY{ -1,0 };

    Player1* player1;
    Player2* player2;
    Player3* player3;
    Player4* player4;

public:
    PowerType powerType;
    PowerUp(Player1* player1, Player2* player2, Player3* player3, Player4* player4);
    ~PowerUp();

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void PowerUp::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
