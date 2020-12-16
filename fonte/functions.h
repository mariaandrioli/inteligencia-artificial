void printResult(int initialI, int initialJ, int size,  int *sequence);
int *makeSequence(int size);	
int **alocateMatrix(int lines, int columns);
void findStart(int **tabuleiro, int linhas, int colunas, int *resultI, int *resultJ, int cores);
int biggerGroup(int **tabuleiro, int M, int N, int **board_aux, int color, int quantity, int i, int j);
int playGame(int **tabuleiro, int initialI, int initialJ, int colors, int M, int N, int *sequence);
int isOnBorder(int i, int j, int M, int N, int **board_aux, int **painted_board);
int colorize(int **tabuleiro, int M, int N, int nextI, int nextJ, int **board_aux, int color, int **painted_board);