
#ifndef _PLATFORMER_WINSCREEN_H_
#define _PLATFORMER_WINSCREEN_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------
enum WinType{A,B};

class WinScreen : public Object
{
private:
    WinType winType;
    Sprite* winScreen;                       // fundo estático

public:
    WinScreen(uint winType);                       // construtor
    ~WinScreen();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif