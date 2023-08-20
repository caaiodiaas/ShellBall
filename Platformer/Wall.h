

#ifndef _PLATFORMER_PLATFORM_H_
#define _PLATFORMER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites


// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
    Sprite * wall = nullptr;        // sprite da plataforma

public:
    Wall(float posX, float posY);
    ~Wall();

    void OnCollision(Object* obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Wall::Draw()
{ wall->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif