
#include <Controller.h>
#include <algorithm>
#include <utility.h>

// decide winner;
// BoardPosition::TOP_LEFT; BoardPosition::TOP_CENTRE; BoardPosition::TOP_LEFT;
std::vector<std::vector<BoardPosition>> corect_answ{
    {BoardPosition::TOP_LEFT, BoardPosition::TOP_MIDDLE,BoardPosition::TOP_RIGHT},
    {BoardPosition::MIDDLE_LEFT, BoardPosition::CENTER,BoardPosition::MIDDLE_RIGHT},
    {BoardPosition::BOTTOM_LEFT,BoardPosition::BOTTOM_MIDDLE, BoardPosition::BOTTOM_RIGHT},
    {BoardPosition::TOP_LEFT, BoardPosition::CENTER, BoardPosition::BOTTOM_RIGHT},              // diagonal 1;
    {BoardPosition::TOP_RIGHT,BoardPosition::CENTER,BoardPosition::BOTTOM_LEFT},                // diagonal 2;
    {BoardPosition::TOP_LEFT,BoardPosition::MIDDLE_LEFT, BoardPosition::BOTTOM_LEFT},
    {BoardPosition::TOP_MIDDLE, BoardPosition::CENTER, BoardPosition::BOTTOM_MIDDLE},
    {BoardPosition::TOP_RIGHT,BoardPosition::MIDDLE_RIGHT,BoardPosition::BOTTOM_RIGHT}};

bool check(std::vector<BoardPosition>& moves){
    if(moves.size() >= 3) {
        for (auto& i: corect_answ) {
            std::sort(i.begin(), i.end());
            bool ret = std::includes(moves.begin(), moves.end(), i.begin(), i.end());
            if (ret) return true;
        }
    }
    return false;
}
 bool check_winner( std::vector<BoardPosition>& moves){
    std::sort(moves.begin(),moves.end());
    return check(moves);
}

 void PrintWinner(IPlayer& p ){
    PrintMessage("Player :",p.Symbol(), " won!!!");
}
// track player moves;
std::vector<BoardPosition> p1_moves;
std::vector<BoardPosition> p2_moves;

Controller::Controller(IPlayer& p1, IPlayer& p2, IRenderer& ren): p1_(p1),p2_(p2), renderer_(ren)  {};
void Controller::PlayGame() {
    int g_turns =0; // track game turns
    while(1) {
        //Ask Player1 to make a move by calling their IPlayer instance.
        auto p1_move = p1_.TakeTurn(board_.FreePossition());

        //Update the board with Player1's move.
        board_.OccupyPosittion(p1_move, p1_);

        //Use the Renderer to print the new state of the board to the screen.
        renderer_.RenderBoard(board_.CurrentState());

        // player one move is stored in a vector;
        p1_moves.push_back(p1_move);

        //Check if Player1 has won the game. If they have, let them know and return.
        if (check_winner(p1_moves)) {
            return PrintWinner(p1_);
        };

        ++g_turns;

        // check for exhausted moves;
        if(g_turns == 9 ) {
            return PrintMessage("DRAW no winner !!!");
        }

            //Ask Player2 to make a move in the same manner as for Player1.
            auto p2_move = p2_.TakeTurn(board_.FreePossition());
            board_.OccupyPosittion(p2_move, p2_);
            renderer_.RenderBoard(board_.CurrentState());
            // player2 moves are stored in a vector;
            p2_moves.push_back(p2_move);
            //Check if Player2 has won the game. If they have, let them know and return.
            if (check_winner(p2_moves)) {
                return PrintWinner(p2_);
            };
            ++g_turns;
    }


};


