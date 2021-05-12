
/**********************************
 This is the implementation file
 for the treasuremap.h file.
**********************************/
#include "treasuremap.h"
#include <iostream>
#include <string>

// Constructor: takes file object and reads treasure map from file
TreasureMap::TreasureMap(std::ifstream& inFile) { // if file does not open
    if (inFile.fail()) {
        std::cout << "Error opening file!" << std::endl;
    }
    maxRows = 0, maxCols = 0; // max rows and columns excluding boundaries
    xplor = ""; // 4-element string dictating order of map exploration

        std::string location;
        //inFile >> xplor; //directions
        for (int i = 0; i < 4; i++){
            inFile >> xplor[i];
        }
        inFile >> maxRows >> maxCols; // rows and columns




        //create borders
       for (int i = 0; i < maxRows + 1; i++) {
           for (int j = 0; j <= maxCols + 1; j++) {
               tmap[0][j] = 'X';
               tmap[maxRows + 1][j] = 'X';
           }
           tmap[i][0] = 'X';
           tmap[i][maxCols + 1] = 'X';
       }

       for (int i = 0; i <= maxRows; i++) {
           getline(inFile, location);
           for (int j = 0; j <= maxCols; j++) {
               tmap[i][j] = location[j-1];

           }
       }

    }


// Displays the treasure map and its state
/**************************************
Function: PrintMap()
Input: None
Output: prints out the treasure map and
        its current state
***************************************/
void TreasureMap::PrintMap() {
std::cout << "Current map:" << std::endl;
    for (int i = 1; i <= maxRows ; i++) {
        for (int j = 1; j <= maxCols ; j++) {
           std::cout << " " << tmap[i][j];
        }
        std::cout << std::endl;
    }
}

// returns a pair (row, then column offset from current cell)
/**************************************
Function: getMove(char )
Input: char
Output: reads in the input of the xplor[i] and
        returns an offset pair
***************************************/
std::pair<int,int> TreasureMap::getMove(char direction){
    int row_offset = 0,  col_offset = 0;
    if (direction == '1') {
        row_offset = -1;
        col_offset = -1;
       
    }
    else if (direction == '2') {
        row_offset = -1;
        col_offset = 1;
        
    }
    else if (direction == '3') {
        row_offset = 1;
        col_offset = 1;
       
    }
    else if (direction == '4'){
        row_offset = 1;
       col_offset = -1;
      
}
    return std::make_pair(row_offset, col_offset);

}

// Recursive function that finds the treasure (ints: row, then columns
/**************************************
Function: FindTreasure()
Input: int rows, int cols, bool&
Output: recursively moves through the function to check if a cell is
        a land cell or treasure. if treasure, function ends.
        if land it keeps going until it finds a treasure or exits.
***************************************/
void TreasureMap::FindTreasure(int rows, int cols, bool& treasure) {
    std::pair<int,int> move; // move variable

    if (tmap[rows][cols] == 'L'){ // if map has a L it is a land cell and mark with an *
        std::cout << "Exploring " << rows << ", " << cols << std::endl;
        tmap[rows][cols] = '*';
        PrintMap();  // print out the map

            for (int i = 0; i < 4; i++) { //if cell is not land or treasure, cycle through coordinates until one is reached.
                move = getMove(xplor[i]);
               FindTreasure(rows + move.first,cols + move.second, treasure);
            }
    }


    if (tmap[rows][cols] == 'T') {  //if the map contains a T treasure is found
            std::cout << "Exploring " << rows << ", " << cols << std::endl;
            treasure = true;
        }


    }


