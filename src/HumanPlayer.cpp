
#include <HumanPlayer.h>
#include <string>
#include <algorithm>
#include "utility.h"

HumanPlayer::HumanPlayer(char symbol): player_symbol(symbol) {}

char HumanPlayer::Symbol() const {
    return player_symbol;
}

BoardPosition HumanPlayer::TakeTurn(const std::vector<BoardPosition> &free_pos) const {
    // print available pos in int;
    std::vector<int> avail_pos; // store value int to compare for max and mon int user input;

    PrintMessage("Player ", player_symbol, " Available positions are: ");
    for( auto& i: free_pos){
        PrintMessage(BoardPositionToInt(i), ' ');
        avail_pos.push_back(BoardPositionToInt(i));
    }
    PrintMessage("\n");
    PrintMessage("Make a selection!");

    // read player choice
    int player_choice = ReadNumber(*std::min_element(avail_pos.begin(), avail_pos.end()), *std::max_element(avail_pos.begin(),avail_pos.end()));

    // check if the selection is valid;;
    auto find_b_pos = std::find(free_pos.begin(), free_pos.end(), NumberToBoardPosition(player_choice));
    while(find_b_pos == free_pos.end()){
        PrintMessage("Position occupied by other user");
        player_choice= ReadNumber(*std::min_element(avail_pos.begin(), avail_pos.end()), *std::max_element(avail_pos.begin(),avail_pos.end()));
        find_b_pos = std::find(free_pos.begin(), free_pos.end(), NumberToBoardPosition(player_choice));
    }

    return *find_b_pos;
};

