#include <stdio.h>
#include <stdbool.h>
/*I'm working to recreate a standard 9x9 checker in C before I get into scaling it.*/
int main() {
/*correctly completed 9x9*/
int board[9][9] = {
    {1, 3, 2, 5, 7, 9, 4, 6, 8},
    {4, 9, 8, 2, 6, 1, 3, 7, 5},
    {7, 5, 6, 3, 8, 4, 2, 1, 9},
    {6, 4, 3, 1, 5, 8, 7, 9, 2},
    {5, 2, 1, 7, 9, 3, 8, 4, 6},
    {9, 8, 7, 4, 2, 6, 5, 3, 1},
    {2, 1, 4, 9, 3, 5, 6, 8, 7},
    {3, 6, 5, 8, 1, 7, 9, 2, 4},
    {8, 7, 9, 6, 4, 2, 1, 5, 3}
};

/*Incorrect 9x9*/
// int board[9][9] = {
//     {1, 3, 2, 5, 7, 9, 4, 6, 8},
//     {4, 9, 8, 2, 6, 1, 3, 7, 5},
//     {7, 5, 6, 3, 8, 4, 2, 1, 9},
//     {6, 4, 3, 1, 5, 8, 7, 9, 2},
//     {5, 2, 1, 7, 9, 3, 8, 4, 6},
//     {9, 8, 7, 4, 2, 6, 5, 3, 1},
//     {2, 1, 4, 9, 3, 5, 6, 8, 7},
//     {3, 6, 5, 8, 1, 7, 9, 2, 4},
//     {8, 7, 9, 6, 4, 2, 1, 5, 9}
// };

bool row_check = true;
bool column_check = true;
bool block_check = true;

int N = 9;
int sqrtN = pow(N, 1/2);
int start = 0;

/*As this is simply to display my capability to code in C, I'm not investing more of my free time into making it more refined unless I feel inspired to.*/
for(int j = start; j < N; j++)
{
    for(int i = start; i < N; i++)
    {
        if(1 <= board[j][i] <= N && isdigit(board[j][i])) {
            /*checked for #s 1-9 with loading each spot exactly once, now a third loop runs #s 1-9 for comparison between each location and the rest of the row/column*/
            for(int k = start; k < N; k++) {
                /*checks rows 1st*/
                if(k > i && board[j][i] != board[j][k])
                    continue;
                else {
                    if(k <= i){
                        continue;
                    }
                    else {
                    row_check = false;
                    }
                }
                /*checks columns 2nd*/
                if(k > j && board[j][i] != board[k][i]) {
                    continue;
                }
                else {
                    if(k <= j){
                        continue;
                    }
                    else {
                    column_check = false;
                    }
                }
                
            }
            /*checks the 3x3 blocks*/
            for(int x = start; x < sqrtN; x++) {
                for(int y = start; y < sqrtN; y++) {
                    if(x <= i%(sqrtN) && y <= j%(sqrtN)) { /*if x=remainder(i) and y=remainder(j), matches to same square as [j][i]. if <, then already tested*/
                        continue;
                    }
                    else {
                        if(board[j][i] != board[j-j%(sqrtN)+y][i-i%(sqrtN)+x]) { /* w/ matches eliminated,val-val%sqrtN indexes to the current block*/
                            continue;
                        }
                        else {
                            block_check = false;
                        }
                    }
                }
            }
        }
        else {
            printf("Board contains non-valid values\n");
            row_check = false;
            column_check = false;
            block_check = false;
            return;
        }
    }
}

if(row_check == true && column_check == true && block_check == true) {
    printf("Sudoku board completed correctly!\n");
}
else {
    printf("Sudoku board is incorrectly completed.\n");
}
}