#pragma once


#include <interface/IPlayer.h>

class HumanPlayer: public IPlayer{
    char player_symbol;

public:
    explicit HumanPlayer( char symbol);;
    char Symbol() const override ;
    BoardPosition TakeTurn( const  std::vector<BoardPosition>& free_pos) const override ;
};