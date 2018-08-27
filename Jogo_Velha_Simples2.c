#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

//int semente = 1;
int celulasOcupadas = 0;
char tabuleiro[3][3];


void inicializa(void) {
	for(int i=0;i<3;i++)		
		for(int j=0;j<3;j++) 
			tabuleiro[i][j]=' ';
	
}

void mostra_tabuleiro(void) {
	printf("\n");
	for(int i=0;i<3;i++) {
		printf(" %c | %c | %c ",tabuleiro[i][0],tabuleiro[i][1],tabuleiro[i][2]);
		if(i!=2)
			printf("\n---|---|---\n");		
	}
	printf("\n");
}

void pede_movimento_jogador(void) {
	
	int x,y; 
	printf("\nDitite a linha e a coluna de sua jogada: ");
	scanf("%d %d",&x,&y);
	x--;
	y--;
	if(x>2 || y>2 || x<0 || y<0) {
		printf("\nPosicao invalida! Tente novamente.\n");
		pede_movimento_jogador();
	}
	else if(tabuleiro[x][y]!=' ') {
		printf("\nPosicao ja ocupada! Tente novamente.\n");
		pede_movimento_jogador();
	}
	else {
		tabuleiro[x][y]='X';
		celulasOcupadas++;
	}
}

void movimento_computador(void) {
	int x,y;
	srand(time(NULL));
	while(1) {
		x=rand()%3;
		y=rand()%3;
		if(tabuleiro[x][y]==' '){
			tabuleiro[x][y]='O';
			celulasOcupadas++;
			return;
		}
	}
}

char checaFimDeJogo() {
	if(tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
		return tabuleiro[0][0];
	if(tabuleiro[2][0] == tabuleiro[1][1] && tabuleiro[2][0] == tabuleiro[0][2])
		return tabuleiro[2][0];
	for(int i=0;i<3;i++)
		if(tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
			return tabuleiro[i][0];
	for(int i=0;i<3;i++)
		if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
			return tabuleiro[0][i];
	if(celulasOcupadas==9)
		return 'E';
	else
		return ' ';
}

int main(void) {
	
	char FimDeJogo=' ';
	printf("\n-------Jogo da Velha--------\n");
	printf("\nVoce jogara com o computador\n");
	inicializa();
	while(1){
		mostra_tabuleiro();
		pede_movimento_jogador();
		FimDeJogo = checaFimDeJogo();
		if(FimDeJogo!=' ')
			break;
		movimento_computador();
		FimDeJogo = checaFimDeJogo();
		if(FimDeJogo!=' ')
			break;
	}
	mostra_tabuleiro();
	switch(FimDeJogo) {
	case 'E':
		printf("\nHouve empate!\n");
		break;
	case 'X':
		printf("\nVoce ganhou!\n");
		break;
	default:
		printf("\nVoce perdeu!\n");
		break;
	}
	printf("\nAperte qualquer tecla para sair.\n");
	getch();
	return 0;
}
