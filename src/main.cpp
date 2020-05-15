
#include <HumanPlayer.h>
#include <Renderer.h>
#include <Controller.h>

int main(){
    HumanPlayer x('X');
    HumanPlayer o ('O');
    Renderer rend;
    Controller game(x,o,rend);
    game.PlayGame();


}