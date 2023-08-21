#pragma once


#ifndef _SHELLBALL_GOAL_H_
#define _SHELLBALL_GOAL_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------
enum GoalColor{PINK, YELLOW};

class Goal : public Object
{
private:
    TileSet* tileset = nullptr;        // folha de sprites do personagem
    Animation* anim = nullptr;         // anima��o do personagem


public:
    GoalColor goalColor;
    Goal(GoalColor color);                           // construtor
    ~Goal();                          // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Goal::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif