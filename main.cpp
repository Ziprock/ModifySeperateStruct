#include <iostream>
#include <limits>
#include <data.h>
#include <input.h>
#include <output.h>

// 4 file system
// main file entry point - includes input and output h
// data file that holds game struct(s) - no includes, just its own header
// input file gets input and also change/update struct in data - includes data.h
// output file reads data and uses it to output/render to screen - includes data.h

int main()
{

Game game;
input in;
output out;
  

// Simulate a few frames
    for (int i = 0; i < 89; i++) {
        in.update(game);   // modifies state
        out.render(game);  // reads state
    }

    for (int i = 0; i < 5; i++) {
        in.updateDown(game);   // modifies state
        out.render(game);  // reads state
    }

//reset
        std::cout<<"\nBefore Reset!\n";
        out.render(game);  // reads state
        std::cout<<"Reset!\n";
        in.updateReset(game);   // modifies state
        out.render(game);  // reads state

// this loop can modify value to any integer
while (true) {
    int x;
    out.render(game);  // reads state
    while (!(std::cin >> x)) {
        std::cout << "\n\n\nNot a simple integer.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Try again: ";
    }
    in.updateInsert(x, game);
}
    return 0;
}
