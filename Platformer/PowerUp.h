

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
enum PowerType{SPEED, SLOW};

class PowerUp : public Object
{
private:
    Sprite* powerUp = nullptr;        // sprite da plataforma
    PowerType powerType;
    Player1* player1;
    Player2* player2;
    Player3* player3;
    Player4* player4;

public:
    PowerUp(float posX, float posY, Player1* player1, Player2* player2, Player3* player3, Player4* player4);
    ~PowerUp();

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void PowerUp::Draw()
{
    powerUp->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif
