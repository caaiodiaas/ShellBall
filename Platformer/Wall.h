

#ifndef _PLATFORMER_PLATFORM_H_
#define _PLATFORMER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites


// ---------------------------------------------------------------------------------

class Wall : public Object
{
private:
    Sprite * wall = nullptr;        // sprite da plataforma

public:
    Wall(float posX, float posY);
    ~Wall();

    void OnCollision(Object* obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Wall::Draw()
{ wall->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif