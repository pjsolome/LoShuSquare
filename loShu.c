#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//Function that checks for lo shu square
bool checkLoShu(int square[3][3]) {
    //Calculate rows
    int topRow = square[0][0] + square[0][1] + square[0][2];
    int midRow = square[1][0] + square[1][1] + square[1][2];
    int botRow = square[2][0] + square[2][1] + square[2][2];

    //Calculate columns
    int leftCol = square[0][0] + square[1][0] + square[2][0];
    int midCol = square [0][1] + square[1][1] + square[2][1];
    int rightCol = square[0][2] + square[1][2] + square [2][2];

    //Calculate Diagonals
    int firstDiag = square[0][0] + square[1][1] + square[2][2];
    int secDiag = square[0][2] + square[1][1] + square[2][0];

    //Compare sums 
    if(topRow == midRow && botRow == midRow && leftCol == rightCol && rightCol == midCol && firstDiag == secDiag && firstDiag == topRow && secDiag == rightCol) {
        return true;
    } else {
        return false;
    }
}

//Main function
int main() {
    //Test array that is Lo Shu Square
    int isLoShu[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };
    if(checkLoShu(isLoShu) == true) {
        printf("This is a Lo Shu Square!\n");
    } else {
        printf("This is not a Lo Shu Square\n");
    }

    //Test array that is NOT Lo Shu Square
    int notLoShu[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if(checkLoShu(notLoShu) == true) {
        printf("This is a Lo Shu Square!\n");
    } else {
        printf("This is not a Lo Shu Square\n");
    }

    //Loop to find random Lo Shu Square
    int count = 0;
    int randArray[3][3] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int randCol;
    int randRow;
    bool goodLoShu = false;
    time_t t;
    srand((unsigned) time(&t));

    while(goodLoShu == false) {
        //Initialize random array
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(randArray[j][k] != 0) {
                    randArray[j][k] = 0;
                }
            }
        }

        for(int i = 1; i < 10; i++){
            randCol = rand() % 3;
            randRow = rand() % 3;
            if(randArray[randCol][randRow] == 0){
                randArray[randCol][randRow] = i;
            } else {
                i--;
            }
        }

        //Check if Lo Shu Square
        if(checkLoShu(randArray) == true){
            goodLoShu = true;
        } else if(checkLoShu(randArray) == false){
            goodLoShu = false;
            count++;
        }
    }

    //Print how many squares it took to find Lo Shu Square
    printf("Generated %d squares\n", count);

    //Print successful Lo Shu Square
    printf("[%d %d %d]\n", randArray[0][0], randArray[0][1], randArray[0][2]);
    printf("[%d %d %d]\n", randArray[1][0], randArray[1][1], randArray[1][2]);
    printf("[%d %d %d]\n", randArray[2][0], randArray[2][1], randArray[2][2]);
}