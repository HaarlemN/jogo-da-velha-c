/*
	Copyright (c) 2019 Haarlem Notoroberto Neto
	Date: 10/20/2019
	Released under the MIT license
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void tutorial(){
	printf("O jogo funciona da seguinte forma:\nA # e dividida em linhas e colunas. Temos entao, um total de 3 linhas e 3 colunas.\n"
		"Para escolher onde quer jogar deve-se passar o valor da linha e da coluna. Exemplo:\nLinha 1, Coluna 2. O jogo marcara da seguinte forma:\n\n"
		"\t  |  |  \n\t  | X| \n\t%c%c|%c%c|%c%c\n\t  |  |  \n\t%c%c|%c%c|%c%c\n\t  | X|  \n"
		"\nNao ha a necessidade de escrever a palavra 'Linha' ou 'Coluna', apenas passe os valores correspondentes. Ex: 1 2.\n\n"
		"O jogo acaba quando o jogador ou a maquina conseguir completar uma sequencia de tres caracteres na diagonal, vertical ou horizontal.\n"
		"Exemplo:\n\n\t  |  |  \n\t  | X| \n\t%c%c|%c%c|%c%c\n\t  | X|  \n\t%c%c|%c%c|%c%c\n\t  | X|  \n\n"
		"Digite 0 para voltar ao menu principal: ",238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238,238);
}

void jogadaInvalida(){
	printf("Voce nao pode jogar aqui. Escolha outra localizacao.\n");
	Sleep(750);
}

int validaJogada(char hashtag[3][3], char forma[2], int c, int v, int aux){
	if(hashtag[c][v] == '\0'){
		hashtag[c][v] = forma[aux];
		return 1;
	}else{
		fflush(stdin);
		return 0;
	}
}

void placar(char forma[2], char hashtag[3][3]){
	printf("<--Placar do jogo-->\n");
	printf("Voce = %c.\nPC = %c.\n",forma[0],forma[1]);
	printf("\t  |  |  \n\t %c| %c| %c\n\t%c%c|%c%c|%c%c\n\t %c| %c| %c\n\t%c%c|%c%c|%c%c\n\t %c| %c| %c\n\n",hashtag[0][0],hashtag[0][1],hashtag[0][2],238,238,238,238,238,238,hashtag[1][0],hashtag[1][1],hashtag[1][2],238,238,238,238,238,238,hashtag[2][0],hashtag[2][1],hashtag[2][2]);
}

int apresentaPlacar(char hashtag[3][3], int fim, char forma[2]){
	system("cls");
	placar(forma,hashtag);
	return 0;
}

main(){
	char op;
	srand(time(NULL));
	menu:
		system("cls");
		fflush(stdin);
		printf("<--Jogo da velha-->\n");
		printf("1 - INICIAR |  2 - TUTORIAL  | 3 - SAIR\n");
		scanf("%c",&op);
		system("cls");
	
	if(op != '1' && op != '2' && op != '3'){
		printf("Opcao invalida.\n");
		fflush(stdin);
		system("cls");
		goto menu;
	}
	else if(op == '1'){
		fflush(stdin);
		int linha, coluna, pcLinha, pcColuna;
		int c = 0, v = 0, resultado, aux = 0, fim = 1;
		char forma[2], x = 'X', o = 'O', fn, vencedor = '\0';
		char hashtag[3][3] = {{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
		
		
		forma:
			printf("<--Jogo da velha-->\n");
			printf("\t  |  |  \n\t  |  | \n\t%c%c|%c%c|%c%c\n\t  |  |  \n\t%c%c|%c%c|%c%c\n\t  |  |  \n\n",238,238,238,238,238,238,238,238,238,238,238,238);
			printf("Escolha qual forma deseja utilizar: X ou O?\n");
			scanf("%c",&forma);
		
		if(forma[0] != x && forma[0] != o){
			printf("Forma invalida, por favor escolha entre X ou O.");
			Sleep(550);
			system("cls");
			goto forma;
		}else{
			start:
				aux = 0;
				
				if(forma[0] == x){
					forma[1] = o;
				}else{
					forma[1] = x;
				}
				
				fflush(stdin);
				system("cls");
				placar(forma,hashtag);
				
				if(hashtag[0][0] == '\0' || hashtag[0][1] == '\0' || hashtag[0][2] == '\0' || hashtag[1][0] == '\0' || hashtag[1][1] == '\0' || hashtag[1][2] == '\0' || hashtag[2][0] == '\0' || hashtag[2][1] == '\0' || hashtag[2][2] == '\0'){
					printf("Escolha a linha e a coluna onde quer realizar a jogada:\n");
					scanf("%d%d",&linha,&coluna);
					
					if(linha == 1){
						linha = 0;
					}else if(linha == 2){
						linha = 1;
					}else{
						linha = 2;
					}
					
					if(coluna == 1){
						coluna = 0;
					}else if(coluna == 2){
						coluna = 1;
					}else{
						coluna = 2;
					}
					
					if(linha == c && coluna == v){
						resultado = validaJogada(hashtag,forma,c,v,aux);
					}else if(linha == c && coluna == v+1){
						resultado = validaJogada(hashtag,forma,c,v+1,aux);
					}else if(linha == c && coluna == v+2){
						resultado = validaJogada(hashtag,forma,c,v+2,aux);
					}else if(linha == c+1 && coluna == v){
						resultado = validaJogada(hashtag,forma,c+1,v,aux);
					}else if(linha == c+1 && coluna == v+1){
						resultado = validaJogada(hashtag,forma,c+1,v+1,aux);
					}else if(linha == c+1 && coluna == v+2){
						resultado = validaJogada(hashtag,forma,c+1,v+2,aux);
					}else if(linha == c+2 && coluna == v){
						resultado = validaJogada(hashtag,forma,c+2,v,aux);
					}else if(linha == c+2 && coluna == v+1){
						resultado = validaJogada(hashtag,forma,c+2,v+1,aux);
					}else if(linha == c+2 && coluna == v+2){
						resultado = validaJogada(hashtag,forma,c+2,v+2,aux);
					}else{
						printf("Linha ou coluna invalida, tente novamente.\n");
						Sleep(500);
						goto start;
					}
					
					if(resultado == 0){
						jogadaInvalida();
						goto start;
					}else{
						goto pcRand;
					}
				}else{
					fim = 0;
					goto fim;
				}
							
			
			pcRand:
				fflush(stdin);
				
				if(hashtag[0][0] == '\0' || hashtag[0][1] == '\0' || hashtag[0][2] == '\0' || hashtag[1][0] == '\0' || hashtag[1][1] == '\0' || hashtag[1][2] == '\0' || hashtag[2][0] == '\0' || hashtag[2][1] == '\0' || hashtag[2][2] == '\0'){
					
					aux = 1;
					
					pcLinha = rand()%3;
					pcColuna = rand()%3;
					
					if(pcLinha == c && pcColuna == v){
						resultado = validaJogada(hashtag,forma,c,v,aux);
					}else if(pcLinha == c && pcColuna == v+1){
						resultado = validaJogada(hashtag,forma,c,v+1,aux);
					}else if(pcLinha == c && pcColuna == v+2){
						resultado = validaJogada(hashtag,forma,c,v+2,aux);
					}else if(pcLinha == c+1 && pcColuna == v){
						resultado = validaJogada(hashtag,forma,c+1,v,aux);
					}else if(pcLinha == c+1 && pcColuna == v+1){
						resultado = validaJogada(hashtag,forma,c+1,v+1,aux);
					}else if(pcLinha == c+1 && pcColuna == v+2){
						resultado = validaJogada(hashtag,forma,c+1,v+2,aux);
					}else if(pcLinha == c+2 && pcColuna == v){
						resultado = validaJogada(hashtag,forma,c+2,v,aux);
					}else if(pcLinha == c+2 && pcColuna == v+1){
						resultado = validaJogada(hashtag,forma,c+2,v+1,aux);
					}else if(pcLinha == c+2 && pcColuna == v+2){
						resultado = validaJogada(hashtag,forma,c+2,v+2,aux);
					}else{
						goto pcRand;
					}
					
					if(resultado == 0){
						goto pcRand;
					}else{
						goto placar;
					}
				
				}else{
					goto placar;
				}
			
			placar:
				fflush(stdin);
				for(int i = 0;i < 3;i++){
					if((hashtag[i][v] == x && hashtag[i][v+1] == x && hashtag[i][v+2] == x) || 
						(hashtag[i][v] == x && hashtag[i+1][v+1] == x && hashtag[i+2][v+2] == x) || 
						(hashtag[i][v+2] == x && hashtag[i+1][v+1] == x && hashtag[i+2][v] == x) || 
						(hashtag[i][v] == x && hashtag[i+1][v] == x && hashtag[i+2][v] == x) ||
						(hashtag[i][v+1] == x && hashtag[i+1][v+1] == x && hashtag[i+2][v+1] == x) ||
						(hashtag[i][v+2] == x && hashtag[i+1][v+2] == x && hashtag[i+2][v+2] == x)){
							fim = apresentaPlacar(hashtag,fim,forma);
							vencedor = 'X';
							break;
					}else if((hashtag[i][v] == o && hashtag[i][v+1] == o && hashtag[i][v+2] == o) || 
						(hashtag[i][v] == o && hashtag[i+1][v+1] == o && hashtag[i+2][v+2] == o) || 
						(hashtag[i][v+2] == o && hashtag[i+1][v+1] == o && hashtag[i+2][v] == o) || 
						(hashtag[i][v] == o && hashtag[i+1][v] == o && hashtag[i+2][v] == o) ||
						(hashtag[i][v+1] == o && hashtag[i+1][v+1] == o && hashtag[i+2][v+1] == o) ||
						(hashtag[i][v+2] == o && hashtag[i+1][v+2] == o && hashtag[i+2][v+2] == o)){
							fim = apresentaPlacar(hashtag,fim,forma);
							vencedor = 'O';
							break;
					}else if(i == 2){
						goto start;
						break;
					}
				
				}
				
			fim:	
				if(fim == 0){
					if((vencedor == 'X' && forma[0] == 'X') || (vencedor == 'O' && forma[0] == 'O')){
						printf("Voce ganhou!");
					}else if((vencedor == 'X' && forma[1] == 'X') || (vencedor == 'O' && forma[1] == 'O')){
						printf("PC ganhou!");
					}else{
						printf("Deu empate!");
					}
					goto end;
				}
		}
		
		end:
			fflush(stdin);
			printf("\nDigite 1(UM) para voltar ao menu principal.\n");
			scanf("%c",&fn);
			
			if(fn != '1' && fn != '0'){
				printf("Opcao invalida, tente novamente.");
				Sleep(750);
				system("cls");
				goto end;
			}else{
				goto menu;
			}
	
	}else if(op == '2'){		
		char voltar = '\0';
		fflush(stdin);
		tutorial();
		scanf("%c",&voltar);
		
		if(voltar!='0'){
			
			do{
				fflush(stdin);
				printf("\nOpcao invalida. Por favor, tente novamente.\n");
				printf("Digite 0 para voltar ao menu principal: ");
				scanf("%c",&voltar);
			}while(voltar!='0');
			system("cls");
			goto menu;
		
		}else{
			system("cls");
			goto menu;
		}
	
	}else{
		exit(0);
	}
}
