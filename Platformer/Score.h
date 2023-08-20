#ifndef _PLATFORMER_PLATFORM_H_
#define _PLATFORMER_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites


// ---------------------------------------------------------------------------------

class Score : public Object
{
private:
    Sprite* sprite;        // sprite da plataforma

public:
    Score(Image* img);
    ~Score();

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Score::Draw()
{
    sprite->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif