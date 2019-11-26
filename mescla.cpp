#include<stdio.h>
#include<stdlib.h>


/*esta é uma versão QUEBRADA de um jogo da velha para exemplo.
	1 - O usuário consegue quebrar o código dando input em uma Letra ao invés de um int.
	2 - O código contém várias formas de implementação que não deveriam ter sido utilizadas ~~verifica linhas , colunas e diagonais
*/

main()
{
   char matriz[4][4], valor;
   int linha=0, coluna=0, i=0, j=0, empate=0, venceu=0,cont=1, jogada=0, verifica[4][4];
      jogada=1;
      empate=0;
      venceu=0;
      fflush(stdin);  
      printf("\n");
      printf("                                                  JOGO DA VELHA LP\n");
      printf("                                                ====================\n\n\n\n");
      printf("========================================================================================================================");
      printf("JOGADOR 1 = \"X\"\n");
      printf("JOGADOR 2 = \"O\"\n");
      printf("========================================================================================================================\n");
      printf("PRESSIONE \"ENTER\" PARA CONTINUAR..."); getchar();
      system("cls");
      for(i = 0; i <= 3; i++)
      {
         for(j = 0; j <= 3; j++)
         {
            matriz[i][j]  =' '; //esvazia os vetores / limpa o tabuleiro.
            verifica[i][j]=' '; //esvazia os vetores / limpa o tabuleiro.
         }
      }
      
      do
      {
      	 // cls funciona como um "apagador" para tudo que já foi escrito , para utilizá-lo é preciso usar o stdlib
         if(jogada <= 10) system("cls"); 
         printf("\n");
         for(i = 1; i <= 3; i++)
         {
            for(j = 1; j <= 3; j++)
            {
               //controla o preenchimento dos valores.
               if(matriz[i][j] == 'X' || matriz[i][j] == 'O')
               printf(" %2c  ",matriz[i][j]); //mostra os valores colocados.
               else
               printf("     "); //deixa em branco espaços ainda não informados.
               if(j <= 2)
               printf("%c", 179); //desenha as colunas. 179 é referente a um caracter na tabela ASCII.
            }
            printf("\n");
            if(i <= 2) //controla a exibição da última linha do desenho.
            for(cont = 1; cont <= 15; cont++)
            {
               printf("%c", 196); //desenha as linhas. 196 é referente a um caracter na tabela ASCII.
               if(cont == 5 || cont == 10) 
               printf("%c", 197); //coloca o caractere '+' na junção das linhas e colunas. 197 é referente a um caracter na tabela ASCII.
            }
            printf("\n");
         }
         
         if(venceu == 1)
         {
            printf("===============================================================\n\n");
            if (jogada%2 == 0)printf("RESULTADO: >>> \"X\" VENCEU <<<\n");
            else printf("RESULTADO: >>> \"O\" VENCEU <<<\n");
            break; //termina o jogo
         }
         if(empate == 1)
         {
            printf("===============================================================\n\n");
            printf("RESULTADO: >>> O JOGO EMPATOU <<<\n");
            break; //termina o jogo
         }
         
         if(jogada % 2 != 0) //Impar = jogador 1, Par = jogador 2.
         {
            printf("VEZ DO JOGADOR 1: \"X\"\n");
            valor= 'X';
         }
         else
         {
            printf("VEZ DO JOGADOR 2:  \"O\"\n");
            valor= 'O';
         }
         printf("===============================================================\n\n");
         do 
		 {
         	do 
        	{
            	printf("INFORME O NUMERO DA LINHA: "); scanf("%d",&linha);
            	if(linha > 3) printf("O numero da linha nao pode ser maior que 3.\n");
            	if(linha < 1) printf("O numero da linha nao pode ser menor que 1.\n");
            	
         	}while(linha > 3 || linha < 1 ); //restrição do tamanho da linha
         	
         	do
         	{
            	printf("INFORME O NUMERO DA COLUNA: "); scanf("%d",&coluna);
            	if(coluna > 3) printf("O numero da coluna nao pode ser maior que 3.\n");
            	if(coluna < 1) printf("O numero da coluna nao pode ser menor que 1.\n");
        
            	
         	}while(coluna > 3 || coluna < 1); //restrição do tamanho da coluna
         
         	if(verifica[linha][coluna]==1) //verifica se a jogada já foi feita
         	{
          	  printf(">>> Esta jogada ja foi feita!! <<<\n");
         	}
		 }while(verifica[linha][coluna]==1); //esperando movimento válido			 
         matriz[linha][coluna]=valor; // coloca o valor no jogo "X" ou "O".
         verifica[linha][coluna]=1;   // coloca valor 1 em jogadas já feitas
        
         
         //VERIFICA LINHAS.
         if(matriz[1][1]=='X' && matriz[1][2]=='X' && matriz[1][3]=='X') venceu=1;
         if(matriz[2][1]=='X' && matriz[2][2]=='X' && matriz[2][3]=='X') venceu=1;
         if(matriz[3][1]=='X' && matriz[3][2]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[1][2]=='O' && matriz[1][3]=='O') venceu=1;
         if(matriz[2][1]=='O' && matriz[2][2]=='O' && matriz[2][3]=='O') venceu=1;
         if(matriz[3][1]=='O' && matriz[3][2]=='O' && matriz[3][3]=='O') venceu=1;			
         //VERIFICA COLUNAS.
         if(matriz[1][1]=='X' && matriz[2][1]=='X' && matriz[3][1]=='X') venceu=1;
         if(matriz[1][2]=='X' && matriz[2][2]=='X' && matriz[3][2]=='X') venceu=1;
         if(matriz[1][3]=='X' && matriz[2][3]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[2][1]=='O' && matriz[3][1]=='O') venceu=1;
         if(matriz[1][2]=='O' && matriz[2][2]=='O' && matriz[3][2]=='O') venceu=1;
         if(matriz[1][3]=='O' && matriz[2][3]=='O' && matriz[3][3]=='O') venceu=1;
         //VERIFICA DIAGONAIS.
         if(matriz[1][1]=='X' && matriz[2][2]=='X' && matriz[3][3]=='X') venceu=1;
         if(matriz[1][3]=='X' && matriz[2][2]=='X' && matriz[3][1]=='X') venceu=1;
         if(matriz[1][1]=='O' && matriz[2][2]=='O' && matriz[3][3]=='O') venceu=1;
         if(matriz[1][3]=='O' && matriz[2][2]=='O' && matriz[3][1]=='O') venceu=1;
         
         jogada++; //incrementa as jogadas
         if(jogada > 9) empate=1; //mais jogadas que espaços disponíveis,jogo empatou
      }while(jogada > 1 );
}
