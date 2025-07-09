#include <stdio.h>

void vitoria1(int tabuleiro[3][3], int *fim);
void vitoria2(int tabuleiro[3][3], int *fim);

int main(){
    int tabuleiro[3][3];
    int fim = 0;
    int jogador = 0;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = 0;
        }
    }

    while(fim == 0){
        printf("  a   b   c\n");
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(j == 0){
                    if(i == 0){
                        printf("1 ");
                    }else if(i == 1){
                        printf("2 ");
                    }else{
                        printf("3 ");
                    }
                }
                if(tabuleiro[i][j] == 1){
                    printf("X");
                }else if(tabuleiro[i][j] == 2){
                    printf("O");
                }else{
                    printf(" ");
                }
                if(j < 2){
                    printf(" | ");
                }
            }
            printf(" ");
            if(i < 2){
                printf("\n  ---------\n");

            }
            if(jogador == 1){
                jogador = 2;
            }
            if(jogador == 3){
                jogador = 0;
            }
        }
        vitoria1(tabuleiro, &fim);
        vitoria2(tabuleiro, &fim);

        if(fim == 0){
        while(jogador == 0){
            int x;
            char y;
            int y2;
            int temp = 0;
            printf("\nDigite sua jogada (linha, coluna. Ex: 1a)\n");
            scanf("%d %c", &x, &y);
            if(x == 1 || x == 2 || x == 3){
                temp = 0;
            }else{
                printf("Digite um valor válido!");
                temp++;
            }
            if(y == 'a' || y == 'A'){
                y2 = 0;
            }else if(y == 'b' || y == 'B'){
                y2 = 1;
            }else if(y == 'c' || y == 'C'){
                y2 = 2;
            }else{
                if(temp != 0){
                    printf("Digite um valor válido!");
                    temp++;
                }
            }
            if(temp == 0){
                if(tabuleiro[x - 1][y2] == 0){
                    tabuleiro[x - 1][y2] = 1;
                    jogador = 1;
                }else{
                    printf("Esta casa está ocupada!");
               }
            }
        }

        while(jogador == 2){
            int x;
            char y;
            int y2;
            int temp = 0;
            printf("\nDigite sua jogada (linha, coluna. Ex: 1a)\n");
            scanf("%d %c", &x, &y);
            if(x == 1 || x == 2 || x == 3){
                temp = 0;
            }else{
                printf("Digite um valor válido!");
                temp++;
            }
            if(y == 'a' || y == 'A'){
                y2 = 0;
            }else if(y == 'b' || y == 'B'){
                y2 = 1;
            }else if(y == 'c' || y == 'C'){
                y2 = 2;
            }else{
                if(temp != 0){
                    printf("Digite um valor válido!");
                    temp++;
                }
            }
            if(tabuleiro[x - 1][y2] == 0){
                tabuleiro[x - 1][y2] = 2;
                jogador = 3;
            }else{
                printf("Esta casa está ocupada!");
            }

        }
    }
    }

    return 0;
}

// | aqui pra baixo são as checagens de vitória dos jogadores |
// v                                                          v

void vitoria1(int tabuleiro[3][3], int *fim){
    //jogador número 1
    //primeira linha
    if(tabuleiro[0][0] == 1 && tabuleiro[0][1] == 1 && tabuleiro[0][2] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //segunda linha
    if(tabuleiro[1][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[1][2] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //terceira linha
    if(tabuleiro[2][0] == 1 && tabuleiro[2][1] == 1 && tabuleiro[2][2] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //primeira coluna
    if(tabuleiro[0][0] == 1 && tabuleiro[1][0] == 1 && tabuleiro[2][0] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //segunda coluna
    if(tabuleiro[0][1] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][1] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //terceira coluna
    if(tabuleiro[0][2] == 1 && tabuleiro[1][2] == 1 && tabuleiro[2][2] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //diagonal principal
    if(tabuleiro[0][0] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][2] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    //diagonal secundária
    if(tabuleiro[0][2] == 1 && tabuleiro[1][1] == 1 && tabuleiro[2][0] == 1){
        printf("\nJogador 1 ganhou!");
        *fim = *fim + 1;
    }
    
}

void vitoria2(int tabuleiro[3][3], int *fim){
    //jogador número 2
    //primeira linha
    if(tabuleiro[0][0] == 2 && tabuleiro[0][1] == 2 && tabuleiro[0][2] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //segunda linha
    if(tabuleiro[1][0] == 2 && tabuleiro[1][1] == 2 && tabuleiro[1][2] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //terceira linha
    if(tabuleiro[2][0] == 2 && tabuleiro[2][1] == 2 && tabuleiro[2][2] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //primeira coluna
    if(tabuleiro[0][0] == 2 && tabuleiro[1][0] == 2 && tabuleiro[2][0] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //segunda coluna
    if(tabuleiro[0][1] == 2 && tabuleiro[1][1] == 2 && tabuleiro[2][1] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //terceira coluna
    if(tabuleiro[0][2] == 2 && tabuleiro[1][2] == 2 && tabuleiro[2][2] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //diagonal principal
    if(tabuleiro[0][0] == 2 && tabuleiro[1][1] == 2 && tabuleiro[2][2] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }
    //diagonal secundária
    if(tabuleiro[0][2] == 2 && tabuleiro[1][1] == 2 && tabuleiro[2][0] == 2){
        printf("\nJogador 2 ganhou!");
        *fim = *fim + 1;
    }

}