#pragma once


#ifndef _SHELLBALL_BUFF_H_
#define _SHELLBALL_BUFF_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites
#include "PowerUp.h"

// ------------------------------------------------------------------------------

class Buff : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // animação do personagem
    uint sideBuff;


public:
    PowerType buffType;
    Buff( uint side);                           // construtor
    ~Buff();                          // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto

};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Buff::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif