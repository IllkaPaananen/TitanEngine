#include <iostream>
#include <conio.h>

#include "CScreen.h"
#include "CGame.h"

using namespace std;


int main() {

    setlocale(LC_ALL, "Russian");

    try {
        CScreen screen;
        screen.cursor_show(false);
        screen.text_attr((WORD)0x0a);
        screen.cls();
        CGame game(screen, 80, 24, 120);

        game.logo();

        game.read_top10();
        game.top10(false);
        game.pak(18);

        do {
            game.game_loop();
            game.top10(true);

        } while (game.once_more());

        game.goodbye();
    }
    catch(CSScreenException& ex) {
        cerr << "*** " << ex.what() << endl;
    }

    return 0;
}
