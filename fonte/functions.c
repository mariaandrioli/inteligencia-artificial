#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

void printResult(int initialI, int initialJ, int size, int *sequence) {
	printf("%d %d %d\n", initialI, initialJ, size);

	for (int i = 0; i < size; i++)
		printf("%d \n", sequence[i]);
}

int *makeSequence(int size) {
  int *sequence;
  sequence = malloc(size*sizeof(int));
  return sequence;
}

int **alocateMatrix(int lines, int columns) {
    int **aux;
    aux = malloc(lines*sizeof(int*));

    for (int i = 0; i < lines; i++){
        aux[i] = malloc(columns*sizeof(int));
    }

    return aux;
}

void findStart(int **tabuleiro, int linhas, int colunas, int *resultI, int *resultJ, int cores){
    int quantity = 1;
    int **board_aux = alocateMatrix(linhas, colunas);

    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            board_aux[i][j] = cores+1;

    for (int i = 0; i < linhas; i++)
    {
       for (int j = 0; j < colunas; j++)
       {
           if (board_aux[i][j] != 0){ 
                board_aux[i][j] = -biggerGroup(tabuleiro, linhas-1, colunas-1, board_aux, tabuleiro[i][j], quantity, i, j);            
           }
       }
    }

    int maior = board_aux[0][0];
    for (int i = 0; i < linhas; i++)
    {
       for (int j = 0; j < colunas; j++)
       {
           if (board_aux[i][j] <  maior) // coloquei pra pegar o primeiro que achar
           {
                maior = board_aux[i][j];
                *resultI = i;
                *resultJ = j;
           }

       }
    }
    free(board_aux);
}

int biggerGroup(int **tabuleiro, int M, int N, int **board_aux, int color, int quantity, int i, int j){
    if(i == 0){
        if ((tabuleiro[M][j] == color) && (board_aux[M][j] > 0)){ //vizinho cima
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[M][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, M, j);
        }
        if ((tabuleiro[i+1][j] == color) && (board_aux[i+1][j] > 0)){ //vizinho baixo
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i+1][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i+1, j);
        }
    }
    else if(i == M){
        if ((tabuleiro[0][j] == color) && (board_aux[0][j] > 0)){  //vizinho baixo
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[0][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, 0, j);
        }
        if ((tabuleiro[i-1][j] == color) && (board_aux[i-1][j] > 0)){  //vizinho cima
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i-1][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i-1, j);
        }
    }
    else{
        if ((tabuleiro[i-1][j] == color) && (board_aux[i-1][j] > 0)){  //vizinho cima
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i-1][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i-1, j);
        }
        if ((tabuleiro[i+1][j] == color) && (board_aux[i+1][j] > 0)){  //vizinho baixo
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i+1][j] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i+1, j);
        }
    }

    //casos do j tratados
    if(j == 0){
        if((tabuleiro[i][N] == color) && (board_aux[i][N] > 0)){ //vizinho esquerda
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][N] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, N);
        }
        if((tabuleiro[i][j+1] == color) && (board_aux[i][j+1] > 0)){ //vizinho direita
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][j+1] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, j+1);
        }
    }

    else if(i == N){
        if((tabuleiro[i][0] == color) && (board_aux[i][0] > 0)){ //vizinho direita
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][0] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, 0);
        }
        if((tabuleiro[i][j-1] == color) && (board_aux[i][j-1] > 0)){ //vizinho esquerda
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][j-1] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, j-1);
        }
    }
    else{
        if((tabuleiro[i][j-1] == color) && (board_aux[i][j-1] > 0)){//vizinho esquerda
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][j-1] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, j-1);
        }
        if((tabuleiro[i][j+1] == color) && (board_aux[i][j+1] > 0)){ //vizinho baixo
            if (board_aux[i][j] != 0) board_aux[i][j] = -1;
            board_aux[i][j+1] = 0;
            quantity += biggerGroup(tabuleiro, M, N, board_aux, color, 1, i, j+1);
        }
    }
    return(quantity);
}

int playGame(int **tabuleiro, int initialI, int initialJ, int colors, int M, int N, int *sequence){
    int **board_aux = alocateMatrix(M, N);
    int **painted_board = alocateMatrix(M, N);
    int aux, color, painted, quantity, maior, currentI, nextJ, nextI, currentJ = initialJ;
    currentI = initialI;
    aux = 0;
    quantity = 0;
    painted = 0;

    sequence[aux] = tabuleiro[initialI][initialJ];
    aux++;

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            board_aux[i][j] = colors+1;
        }
    }
    quantity = biggerGroup(tabuleiro, M-1, N-1, board_aux, tabuleiro[initialI][initialJ], 1, initialI, initialJ);
    
    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(board_aux[i][j] <= 0){
                painted_board[i][j] = -1;
                painted++;
            }
        }
    }

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            board_aux[i][j] = colors+1;
        }
    }

    for (int i = 0; i < M; ++i){
        for (int j = 0; j < N; ++j){
            printf("%d ", painted_board[i][j]);
        }
        puts("");
    }

    while(painted < (M*N)){
        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                board_aux[i][j] = colors+1;
            }
        }

        quantity = biggerGroup(tabuleiro, M-1, N-1, board_aux, tabuleiro[currentI][currentJ], 1, currentI, currentJ);

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if(isOnBorder(i, j, M-1, N-1, board_aux, painted_board))
                    board_aux[i][j] = -biggerGroup(tabuleiro, M-1, N-1, board_aux, tabuleiro[i][j], 1, i, j);
            }
        }

        maior = board_aux[0][0];
        nextI = 0;
        nextJ = 0;

        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if((board_aux[i][j] <= maior) && ((i != currentI || j != currentJ))){
                    printf("entrou com i = %d j = %d\n", i, j);
                    maior = board_aux[i][j];
                    nextI = i;
                    nextJ = j;
                }
            }
        }
        
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", board_aux[i][j]);
            puts("");
        }
        
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", tabuleiro[i][j]);
            puts("");
        }

        color = tabuleiro[nextI][nextJ];
        aux++;
        sequence[aux] = color;

        for (int i = 0; i < M; ++i){
            for (int j = 0; j < N; ++j){
                board_aux[i][j] = colors+1;
            }
        }
        quantity = biggerGroup(tabuleiro, M-1, N-1, board_aux, tabuleiro[currentI][currentJ], 1, currentI, currentJ);
        quantity += biggerGroup(tabuleiro, M-1, N-1, board_aux, tabuleiro[nextI][nextJ], 1, nextI, nextJ);
        printf("paited %d currentI %d currentJ %d nextI %d nextJ %d\n", painted, currentI, currentJ, nextI, nextJ);

        colorize(tabuleiro, M, N, nextI, nextJ, board_aux, color, painted_board);
        currentI = nextI;
        currentJ = nextJ;
        printf("paited %d currentI %d currentJ %d nextI %d nextJ %d\n", painted, currentI, currentJ, nextI, nextJ);
        
        puts("painted board:");
        painted = 0;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++){
                printf("%d ", painted_board[i][j]);
                if(painted_board[i][j] == -1)
                    painted++;
            }

            puts("");
        }
    }

    free(board_aux);
    return(aux);
}

int isOnBorder(int i, int j, int M, int N, int **board_aux, int **painted_board){
    if(i == 0){
        if((board_aux[M][j] <= 0) && (painted_board[M][j] == 0)) //caso i canto superior esquerdo vizinho cima
            return(1);
    }
    else{
        if((board_aux[i-1][j] <= 0) && (painted_board[i-1][j] == 0)) 
            return(1);
    }
    
    if(i == M){
        if((board_aux[0][j] <= 0) && (painted_board[0][j] == 0)) //caso i canto inferior esquerdo vizinho baixo
            return(1);
    }
    else{
        if((board_aux[i+1][j] <= 0) && (painted_board[i+1][j] == 0)) 
            return(1);
    }

    if(j == 0){
        if((board_aux[i][N] <= 0) && (painted_board[i][N] == 0)) //caso j canto esquerdo vizinho direito
            return(1);
    }
    else{
        if((board_aux[i][j+1] <= 0) && (painted_board[i][j+1] == 0))
            return(1);
    }
    
    if(j == N){
        if((board_aux[i][0] <= 0) && (painted_board[i][0] == 0)) //caso j canto direito vizinho esquerda
            return(1);
    }
    else{
        if((board_aux[i][j-1] <= 0) && (painted_board[i][j-1] == 0)) 
            return(1);
    }
    
    return(0);
}

int colorize(int **tabuleiro, int M, int N, int nextI, int nextJ, int **board_aux, int color, int **painted_board){
    int quantity;

    for (int i = 0; i < M; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if(board_aux[i][j] <= 0){
                tabuleiro[i][j] = color;
                painted_board[i][j] = -1;
                quantity++;
            }
        }
    }

    return(quantity);
}