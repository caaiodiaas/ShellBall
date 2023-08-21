
#ifndef _PLATFORMER_WINSCREEN_H_
#define _PLATFORMER_WINSCREEN_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------
enum WinType{A,B};

class WinScreen : public Object
{
private:
    WinType winType;
    Sprite* winScreen;                       // fundo est�tico

public:
    WinScreen(uint winType);                       // construtor
    ~WinScreen();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif