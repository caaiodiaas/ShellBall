

#ifndef _SHELLBALL_PLAYER1_H_
#define _SHELLBALL_PLAYER1_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------


class Player1 : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    int side;
    int height2;
    int vel;

public:
    Player1();                           // construtor
    ~Player1();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void Reset();
    void Start();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Player1::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif