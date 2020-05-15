#pragma once

#include <interface/IPlayer.h>
#include "Renderer.h"
#include "Board.h"

class Controller{
    IPlayer& p1_;
    IPlayer& p2_;
    IRenderer& renderer_;
    Board board_;

public:
    Controller(IPlayer& p1, IPlayer& p2, IRenderer& ren );
    void PlayGame();
};