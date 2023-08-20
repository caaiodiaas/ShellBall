

#ifndef _SHELLBALL_BALL_H_
#define _SHELLBALL_BALL_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

// ------------------------------------------------------------------------------
enum LastHit { STILL, RIGHT, LEFT  };

class Ball : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites da bola


public:
    random_device rd;               // gerador não determinístico
    mt19937 mt{ rd() };             // gerador mersenne twister

    uniform_int_distribution<int> randX{ -1,0 };
    uniform_int_distribution<int> randY{ -1,0 };
    LastHit lastHit;
    Animation* anim = nullptr;         // animação da bola
    int height2;
    int width2;
    float velX;
    float velY;

    Ball();                           // construtor
    ~Ball();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void Reset();
    void Start();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Ball::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif