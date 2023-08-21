

#ifndef _SHELLBALL_PLAYER4_H_
#define _SHELLBALL_PLAYER4_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------


class Player4 : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    int side;
    int height2;


public:
    int vel;
    Player4();                           // construtor
    ~Player4();                          // destrutor

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
    void Reset();
    void Start();
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Player4::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif