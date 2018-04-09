//
//  SudokuHeader.h
//  Sodoku
//
//  Created by M78的星际人士 on 4/9/18.
//  Copyright © 2018 M78的星际人士. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

template <typename T>
class Puzzle {
    
public:
    Puzzle(string fileName);        // constructor
    void print();                // prints Sodoku
    void play();                // function to play Sodoku
    void checkEmpty(int x, int y);        // checks for emptiness
    int checkValid(int x, int y, T input);    // checks validity
    void add(int x, int y, T input);    // adds piece into board
    int checkWin();                // checks if win
private:
    vector<T> vec;
    vector <vector <T> > Sudoku;        // 2D vector
};

// function to check for win
template <typename T>
int Puzzle<T>::checkWin(){
    int i, j;
    
    for(i = 0; i < 9; i++){  // if any spots are equal to 0, then it is not game over yet
        for(j = 0; j < 9; j++){
            if(Sudoku[i][j] == 0 || Sudoku[i][j] == '0')
                return 0;   // code to indicate incomplete game
        }
    }
    
    cout << "Congrats, you successfully solved the Sudoku board!" << endl;
    return 1;                        // win
}

// function to play Sudoku
template <typename T>
void Puzzle<T>::play() {
    int row, column, win = 0;
    
    print();
    do {
        do {
            cout << "Which row would you like to play your input?: ";    // ask for valid row input
            cin >> row;
        } while(row <= 0 || row > 9);                        // repeat if invalid
        
        do {
            cout << "Which column would you like to play your input?: ";    // ask for valid column input
            cin >> column;
        } while(column <= 0 || column > 9);                    // repeat if invalid
        
        checkEmpty(row, column);                        // check if empty space
        print();                                // print board
        win = checkWin();                            // check if there is a win
    }while(win == 0);
}


// adds piece into board
template <typename T>
void Puzzle<T>::add(int x, int y, T input){
    Sudoku[x][y] = input;
}

// checks if input is valid
template <typename T>
int Puzzle<T>::checkValid(int x, int y, T input) {
    int xmod, ymod, m, n;
    for(int i = 0; i < 9; i++) {
        if(Sudoku[x][i] == input) {  // if there is a piece in the row
            cout << "Error. Already a " << input << " in the row.\n"; // with same value, reject
            return 0;
        }
    }
    for(int j = 0; j < 9; j++) { // if there is a piece in the column
        if(Sudoku[j][y] == input) { // with same value, reject
            cout << "Error. Already a " << input << " in the column.\n";
            return 0;
        }
    }
    
    xmod = x % 3;                // use the mod as a "code" to determine where the square is
    ymod = y % 3;
    
    switch(xmod) {                // depending on the row & column input, change it to check the square it belongs to
        case 1: m = x - 1;
            break;
        case 2: m = x - 2;
            break;
        default: m = x;
            break;
    }
    
    switch(ymod) {
        case 1: n = y - 1;
            break;
        case 2: n = y - 2;
            break;
        default: n = y;
            break;
    }
    
    for(int k = m; k < m + 3; k++) {  // check the square for same input
        for(int l = n; l < n + 3; l++) {
            if(Sudoku[k][l] == input) {
                cout << "Error. Already a " << input << " in the square.\n";
                return 0;
            }
        }
    }
    
    return 1;    // accept
}

// checks if empty
template <typename T>
void Puzzle<T>::checkEmpty(int x, int y) {
    T input;
    if(Sudoku[x-1][y-1] == 0 || Sudoku[x-1][y-1] == '0') {        // check if it is "empty"
        cout << "What value would you like to add?: ";
        cin >> input;                        // ask for input
        if(checkValid(x - 1, y - 1, input)) {            // if the input is valid
            add(x - 1, y - 1, input);                // add it into the board
        }
    } else {
        cout << "That spot is taken."<< endl;            // if the space is not empty, say that it is taken
    }
}


// print the Sudoku board
template <typename T>
void Puzzle<T>::print() {
    for(int i = 0; i < 9; i++) {                            // for every row
        cout << "-------------------------------------" << endl << "| ";
        for(int j = 0; j < 9; j++) {                        // for every column
            if(Sudoku[i][j] == 0) {
                cout << "  | ";
            } else {
                cout << Sudoku[i][j] << " | ";
            }
        }
        cout << endl;
    }
    cout << "-------------------------------------" << endl << endl;
}

// non default constructor
template <typename T>
Puzzle<T>::Puzzle(string fileName) {
    vector<T> tempVec;            // temporary vector
    T value;
    
    ifstream inFile;            // open the file
    inFile.open(fileName.c_str());
    
    while(!inFile.eof()){            // while not end of file
        for(int i = 0; i < 9; i++) {    // reads in a line
            inFile >> value;    // set value as what is read from inFile
            tempVec.push_back(value);    // put into temporary vector
        }
        Sudoku.push_back(tempVec);        // set sodoku board using temp vector
        tempVec.clear();            // clears the tempVec
    }
}


