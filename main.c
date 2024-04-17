#include <stdio.h>
#include <stdlib.h>

/*printBoard - This function is called printBoard and basically what it does is that it prints the tic-tac-toe board.*/

void printBoard(char** board, int size){
    int i, j;
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            board[i][j] = ' ';
            printf("[%c] ",board[i][j]);
        }
        printf("\n");
    }
}

/*printBoardWithChoice - This function is called printBoardWithChoice and basically what it does is that it prints the tic-tac-toe board with the choice of the user.*/

void printBoardWithChoice(char** board, int size){
    int i, j;
    printf("\n");
    for(i=0; i<size; i++){
        for(j=0; j<size; j++){
            if (board[i][j]) {
                printf("[%c] ", board[i][j]);
            }
            else
                printf(" ");
        }
        printf("\n");
    }
}

/*freeBoard - This function is called freeBoard and it deallocates the memory previously allocated by a call to malloc.*/

void freeBoard(char** board, int size){
    int i;
    for (i=0; i<size; i++){
        free(board[i]);
    }
    free(board);
}

/*checkBoardForError - This function is called checkBoardForError and it checks if there is an Illegal input in the tic-tac-toe board.*/

void checkBoardForError(char** board, int size, int rowChoice, int colChoice){
    
    if (rowChoice>size-1 || colChoice>size-1 || rowChoice<0 || colChoice<0) {
        freeBoard(board, size);
        printf("\nInput Error!\n");
        exit(1);
    }
    
    if (board[rowChoice][colChoice] == 'X' || board[rowChoice][colChoice] == 'O') {
        freeBoard(board, size);
        printf("\nInput Error!\n");
        exit(1);
    }
    
}

/*checkBoardForTie - This function is called checkBoardForTie and it checks if there is a tie.*/

void checkBoardForTie(char** board, int size, int counter){
    
    int i, j;
    
    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            if (board[i][j] == 'X' || board[i][j] == 'O') {
                counter++;
            }
        }
    }
    if (counter == size*size) {
        freeBoard(board, size);
        printf("\nTIE\n");
        exit(0);
    }
}

/*checkBoardForWinner - This function is called checkBoardForWinner and basically what it does is that it checks if there is a winner (diagonally, horizontally or vertically) and returns 1\-1 if there is a winner.*/

int checkBoardForWinner(char** board, int size){
    
    int count = 0;
    int i, j;

    for(i=0; i<size; ++i){
        count = 0;
        
        for(j=0; j<size; ++j){
            count = count + ((board[i][j] == 'X')?  1 : (board[i][j] == 'O')? -1 : 0);
        }
        
        if (count == size || count == -size){
            return count / abs(count);
        }
    }

    for(j=0; j<size; ++j){
        count = 0;
        
        for(i=0; i<size; ++i){
            count = count + ((board[i][j] == 'X')?  1 : (board[i][j] == 'O')? -1 : 0);
        }
        
        if (count == size || count == -size){
            return count / abs(count);
        }
    }

    count = 0;
    for(j=0; j<size; ++j){
        count = count + ((board[j][j] == 'X')?  1 : (board[j][j] == 'O')? -1 : 0);
    }
    
    if (count == size || count == -size){
        return count / abs(count);
    }

    count = 0;
    for(j=0; j<size; ++j){
        count = count + ((board[j][size-1-j] == 'X')?  1 : (board[j][size-1-j] == 'O')? -1 : 0);
    }
    
    if (count == size || count == -size){
        return count / abs(count);
    }

    return 0;
}

int main() {
    
    char** board;    /*In this line we initialized a two dimensional array for the tic-tac-toe board.*/
    int boardRows, boardCols, sizeOfBoard;    /*In this line we initialized three integers for the rows and columns of the tic-tac-toe board and for the size of the board which is basically the same as the boardRows\boardCols which is the number of rows\columns.*/
    int rowChoice,colChoice;    /*In this line we initialized two integers that scans the choice of the user.*/
    int i, j;
    char turn;     /*In this line we initialized a char which tells us whose turn is.*/
    int counter = 0;
    
    printf("Enter the dimensions of the board: ");
    if (scanf("%d%d", &boardRows, &boardCols)!=2 || boardRows!=boardCols || boardRows<=2 || boardCols<=2) {
        printf("Input Error!\n");
        return 1;
    }
    
    board = (char**)malloc(sizeof(char*)*boardRows);
    
    if (board == NULL) {
        printf("\nAllocation failed!\n");
        return 1;
    }
    
    for (i=0; i<boardRows; i++) {
        board[i] = (char*)malloc(boardCols*sizeof(char));
        if (board[i] == NULL) {
            printf("\nAllocation failed!\n");
            return 1;
        }
    }
    
    sizeOfBoard = boardRows;
    printBoard(board, sizeOfBoard);
    
    for (i=0; i<boardRows; i++) {
        for (j=0; j<boardCols; j++) {
            board[i][j] = ' ';
        }
    }
    
    while (1) {
        
        printf("\nThe turn of A, type your choice (row col): ");
        turn = 'X';
        
        if (scanf("%d %d", &rowChoice, &colChoice)!=2) {
            freeBoard(board, sizeOfBoard);
            printf("\nInput Error!\n");
            return 1;
        }
        
        checkBoardForError(board, sizeOfBoard, rowChoice, colChoice);
        
        board[rowChoice][colChoice] = turn;
        
        printBoardWithChoice(board, sizeOfBoard);
        
        if(checkBoardForWinner(board, sizeOfBoard) == 1 || checkBoardForWinner(board, sizeOfBoard) == -1) {
            freeBoard(board, sizeOfBoard);
            printf("\nPlayer A won the game!\n");
            return 0;
        }
        
        checkBoardForTie(board, sizeOfBoard, counter);
        
        printf("\nThe turn of B, type your choice (row col): ");
        turn = 'O';
        
        if (scanf("%d %d", &rowChoice, &colChoice)!=2) {
            freeBoard(board, sizeOfBoard);
            printf("\nInput Error!\n");
            return 1;
        }
        
        checkBoardForError(board, sizeOfBoard, rowChoice, colChoice);
        
        board[rowChoice][colChoice] = turn;
        
        printBoardWithChoice(board, sizeOfBoard);
        
        if(checkBoardForWinner(board, sizeOfBoard) == 1 || checkBoardForWinner(board, sizeOfBoard) == -1) {
            freeBoard(board, sizeOfBoard);
            printf("\nPlayer B won the game!\n");
            return 0;
        }
        
        checkBoardForTie(board, sizeOfBoard, counter);
    }
}
