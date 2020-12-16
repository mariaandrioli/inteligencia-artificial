#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(){
	int linhas, colunas, cores, initialI, initialJ;
	int **tabuleiro, *sequence, plays = 0;
	scanf("%d %d %d", &linhas, &colunas, &cores);

	initialI = 0;
	initialJ = 0;
	tabuleiro = alocateMatrix(linhas, colunas);

	for (int i = 0; i < linhas; i++)
		for (int j = 0; j < colunas; j++)
			scanf("%d", &tabuleiro[i][j]);


	printf("%d %d %d\n", linhas, colunas, cores);
	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
			printf("%d ", tabuleiro[i][j]);
		puts("");
	}

	findStart(tabuleiro,linhas,colunas,&initialI,&initialJ, cores);
	sequence = makeSequence(300);
	plays = playGame(tabuleiro, initialI, initialJ, cores, linhas, colunas, sequence);
	printResult(initialI, initialJ, plays, sequence);

	free(sequence);
	free(tabuleiro);
	return(0);
}
