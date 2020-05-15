#pragma once

#include <vector>
#include <map>
#include <interface/IPlayer.h>
#include "BoardPosition.h"

class Board{
    std::vector<BoardPosition> board_free_pos ={BoardPosition::TOP_LEFT,
                                                BoardPosition::TOP_MIDDLE,
                                                BoardPosition::TOP_RIGHT,
                                                BoardPosition::MIDDLE_LEFT,
                                                BoardPosition::CENTER,
                                                BoardPosition::MIDDLE_RIGHT,
                                                BoardPosition::BOTTOM_LEFT,
                                                BoardPosition::BOTTOM_MIDDLE,
                                                BoardPosition::BOTTOM_RIGHT};
    std::map<BoardPosition, char> board_owners;
public:
    Board();
    std::vector<BoardPosition> FreePossition() const;
    void OccupyPosittion(const BoardPosition& pos, IPlayer& player);
    std::vector<char> CurrentState() const;
    std::map<BoardPosition, char> getOwnersData();
};