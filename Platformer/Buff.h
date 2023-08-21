#pragma once


#ifndef _SHELLBALL_BUFF_H_
#define _SHELLBALL_BUFF_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites
#include "PowerUp.h"

// ------------------------------------------------------------------------------

class Buff : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima��o do personagem
    uint sideBuff;


public:
    PowerType buffType;
    Buff( uint side);                           // construtor
    ~Buff();                          // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto

};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Buff::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif