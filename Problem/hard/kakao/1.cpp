#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
// aloc_len은 배열 aloc의 길이입니다.
// bloc_len은 배열 bloc의 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols, int aloc[], size_t aloc_len, int bloc[], size_t bloc_len) {
    int answer = -1;
    return answer;
}

int main()
{
    int board_rows = 3;
    int board_cols = 3; 

    size_t aloc_len = 2 ;
    int aloc[] = {1,0};
    
    size_t bloc_len = 2;
    int bloc[] = {1,2};

    int** board ;

    board = (int**)malloc(sizeof(int*));

    for ( int i = 0 ; i < board_rows ; ++i )
    {
        board[i] = (int*)malloc(sizeof(int));

        for ( int j = 0 ; j < board_cols ; ++j )
        {
            board[i][j] = 1 ;    
        }
    }

    solution( board, board_rows, board_cols, aloc, aloc_len, bloc, bloc_len ) ;

    return 0;
}