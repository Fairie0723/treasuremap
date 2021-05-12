

#include <iostream>
#include "treasuremap.h"

/**************************************
Function: main()
Input: None
Output: Reads in the files from the text
        and instantiates the objects.
***************************************/
int main() {

std::ifstream inFile("treasuremap.txt");  // read in file
TreasureMap map(inFile);
map.PrintMap(); // call PrintMap
int rows = 1,  cols = 1;
bool treasure = false;  // treasure is false
std::cout << "Start Position: " << rows << ", " << cols << std::endl;
map.FindTreasure(rows, cols, treasure);  //call FindTreasure function
if (treasure)
    std::cout << "Treasure Found!" << std::endl; // if treasure == true
else
    std::cout << "No treasure!" << std::endl; // else no treasure is found.

return 0;
}
