
#include <Board.h>
#include <algorithm>
#include <utility.h>

Board::Board() {
    //populating map of owners with BoardPos and '@' value;
    int s =-1;
    for (BoardPosition i: board_free_pos) {
        board_owners[i] = 0;
    }
}
std::vector <BoardPosition> Board::FreePossition() const{
    return board_free_pos;
};

void Board::OccupyPosittion(const BoardPosition &pos, IPlayer &player) {
    // check if requested position is not unoccupied;
    auto find= std::find(board_free_pos.begin(), board_free_pos.end(), pos);
    if( find == board_free_pos.end()){
        PrintMessage("Position already occupied by other player");
    }

    board_owners[pos] = player.Symbol();

    // remove free pos from vector;
    board_free_pos.erase(find);


}

std::vector<char> Board::CurrentState() const {
    std::vector<char> ret;
    // populating ret by coping the value of map;
    for( auto i : board_owners){
        ret.push_back(i.second);
    }
    //std::copy(board_owners.begin()->second, board_owners.end()->second, ret.begin());
    return ret;
}

