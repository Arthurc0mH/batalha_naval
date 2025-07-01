#include <stdio.h>
#include <stdlib.h>

//eu vou ficar maluco

void imprimir(int tabuleiro1[6][6], int *jogador, int tabuleiro2[6][6]);
void colocar_pecas(int tabuleiro1[6][6], int *jogador, int pecas1[3], int plataforma, int tabuleiro2[6][6], int pecas2[3]);
void limpar_tela(int plataforma);
void converter_y(int *y2, char *y);

int main(){
    int tabuleiro1[6][6]; int tabuleiro2[6][6];
    int pecas1[3]; int pecas2[3];
    int fim = 0; int jogador = 1; int plataforma;
    for(int i = 0; i < 6; i++){
        if(i < 3){
            pecas1[i] = 3;
        }
        for(int j = 0; j < 6; j++){
            tabuleiro1[i][j] = 0;
        }
    }
    printf("Qual sistema operacional voce esta usando?\n1) Windows\n2) Linux\n");
    scanf("%d", &plataforma);
    limpar_tela(plataforma);
    while(fim == 0){
        colocar_pecas(tabuleiro1, &jogador, pecas1, plataforma, tabuleiro2, pecas2);

        fim++;
    }

    return 0;
}

void imprimir(int tabuleiro1[6][6], int *jogador, int tabuleiro2[6][6]){
    //imprime o tabuleiro1
    if(*jogador == 0){
        printf(" Jogador numero 1\n");
        printf("  A  B  C  D  E  F\n");
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(j == 0){
                   if(i == 0){
                        printf("1 ");
                    }else if(i == 1){
                        printf("2 ");
                    }else if(i == 2){
                        printf("3 ");
                    }else if(i == 3){
                        printf("4 ");
                    }else if(i == 4){
                        printf("5 ");
                    }else if(i == 5){
                        printf("6 ");
                    }
                }
                if(tabuleiro1[i][j] == 0){
                    printf("0  ");
                }else if(tabuleiro1[i][j] == 1){
                    printf("1  ");
                }
            }
            printf(" ");
            printf("\n");
        }
    }
    if(*jogador == 1){ //imprime o tabuleiro 2
        printf(" Jogador numero 2\n");
        printf("  A  B  C  D  E  F\n");
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(j == 0){
                   if(i == 0){
                        printf("1 ");
                    }else if(i == 1){
                        printf("2 ");
                    }else if(i == 2){
                        printf("3 ");
                    }else if(i == 3){
                        printf("4 ");
                    }else if(i == 4){
                        printf("5 ");
                    }else if(i == 5){
                        printf("6 ");
                    }
                }
                if(tabuleiro2[i][j] == 0){
                    printf("0  ");
                }else if(tabuleiro2[i][j] == 1){
                    printf("2  ");
                }
            }
            printf(" ");
            printf("\n");
        }
    }
}

void colocar_pecas(int tabuleiro1[6][6], int *jogador, int pecas1[3], int plataforma, int tabuleiro2[6][6], int pecas2[3]){
    if(*jogador == 0){ //jogador 1
        int input = 0;
        int x, y2, temp = 0;
        char y;
        int orientacao_peca = 0;
        while(temp == 0){
            if(pecas1[0] > 0 && pecas1[1] > 0 && pecas1[2] > 0){
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("1) colocar peca 1x1 (%d)\n2) colocar peca 1x2 (%d)\n3) colocar peca 1x3 (%d)\n", pecas1[0], pecas1[1], pecas1[2]);
                scanf("%d", &input);
                if(input == 1){ // 1x1
                    if(pecas1[0] > 0){
                        printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                        scanf("%d %c", &x, &y);
                        converter_y(&y2, &y);

                        if(tabuleiro1[x - 1][y2] == 0){
                            tabuleiro1[x - 1][y2] = 11;
                            pecas1[0] = pecas1[0] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        limpar_tela(plataforma);
                        printf("\nVoce nao tem mais pecas deste tipo!\n");
                    }
                }else if(input == 2){ // 1x2
                    int temp2 = 0;
                    while (temp2 == 0){
                        printf("Qual orientacao?\n1)Horizontal\n2)Vertical\n");
                        scanf("%d", &orientacao_peca);
                        if(orientacao_peca == 1 || orientacao_peca == 2){
                            temp2++;
                        }else{
                            printf("Valor inválido!\n");
                        }
                    }
                    printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                    scanf("%d %c", &x, &y);
                    converter_y(&y2, &y);
                    if(orientacao_peca == 1){
                        if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x - 1][y2 + 1] == 0){
                            tabuleiro1[x - 1][y2] = 1;
                            tabuleiro1[x - 1][y2 + 1] = 1;
                            pecas1[1] = pecas1[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x][y2] == 0){
                            tabuleiro1[x - 1][y2] = 1;
                            tabuleiro1[x][y2] = 1;
                            pecas1[1] = pecas1[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }
                }else{ // 1x3
                    int temp2 = 0;
                    while (temp2 == 0){
                        printf("Qual orientacao?\n1)Horizontal\n2)Vertical\n");
                        scanf("%d", &orientacao_peca);
                        if(orientacao_peca == 1 || orientacao_peca == 2){
                            temp2++;
                        }else{
                            printf("Valor inválido!\n");
                        }
                    }
                    printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                    scanf("%d %c", &x, &y);
                    converter_y(&y2, &y);
                    if(orientacao_peca == 1){
                        if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x - 1][y2 + 1] == 0 && tabuleiro1[x - 1][y2 + 2] == 0){
                            tabuleiro1[x - 1][y2] = 1;
                            tabuleiro1[x - 1][y2 + 1] = 1;
                            tabuleiro1[x - 1][y2 + 2] = 1;
                            pecas1[1] = pecas1[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x][y2] == 0 && tabuleiro1[x + 1][y2] == 0){
                            tabuleiro1[x - 1][y2] = 1;
                            tabuleiro1[x][y2] = 1;
                            tabuleiro1[x + 1][y2] = 1;
                            pecas1[1] = pecas1[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }
                }

            }else{
                temp++;
                *jogador++;
            }
        }
    }else if(*jogador == 1){ //jogador 2
        int input = 0;
        int x, y2, temp = 0;
        char y;
        int orientacao_peca = 0;
        while(temp == 0){
            if(pecas2[0] > 0 && pecas2[1] > 0 && pecas2[2] > 0){
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("1) colocar peca 1x1 (%d)\n2) colocar peca 1x2 (%d)\n3) colocar peca 1x3 (%d)\n", pecas2[0], pecas2[1], pecas2[2]);
                scanf("%d", &input);
                if(input == 1){ // 1x1
                    if(pecas2[0] > 0){
                        printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                        scanf("%d %c", &x, &y);
                        converter_y(&y2, &y);

                        if(tabuleiro2[x - 1][y2] == 0){
                            tabuleiro2[x - 1][y2] = 11;
                            pecas2[0] = pecas2[0] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        limpar_tela(plataforma);
                        printf("\nVoce nao tem mais pecas deste tipo!\n");
                    }
                }else if(input == 2){ // 1x2
                    int temp2 = 0;
                    while (temp2 == 0){
                        printf("Qual orientacao?\n1)Horizontal\n2)Vertical\n");
                        scanf("%d", &orientacao_peca);
                        if(orientacao_peca == 1 || orientacao_peca == 2){
                            temp2++;
                        }else{
                            printf("Valor inválido!\n");
                        }
                    }
                    printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                    scanf("%d %c", &x, &y);
                    converter_y(&y2, &y);
                    if(orientacao_peca == 1){
                        if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x - 1][y2 + 1] == 0){
                            tabuleiro2[x - 1][y2] = 1;
                            tabuleiro2[x - 1][y2 + 1] = 1;
                            pecas2[1] = pecas2[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x][y2] == 0){
                            tabuleiro2[x - 1][y2] = 1;
                            tabuleiro2[x][y2] = 1;
                            pecas2[1] = pecas2[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }
                }else{ // 1x3
                    int temp2 = 0;
                    while (temp2 == 0){
                        printf("Qual orientacao?\n1)Horizontal\n2)Vertical\n");
                        scanf("%d", &orientacao_peca);
                        if(orientacao_peca == 1 || orientacao_peca == 2){
                            temp2++;
                        }else{
                            printf("Valor inválido!\n");
                        }
                    }
                    printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                    scanf("%d %c", &x, &y);
                    converter_y(&y2, &y);
                    if(orientacao_peca == 1){
                        if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x - 1][y2 + 1] == 0 && tabuleiro2[x - 1][y2 + 2] == 0){
                            tabuleiro2[x - 1][y2] = 1;
                            tabuleiro2[x - 1][y2 + 1] = 1;
                            tabuleiro2[x - 1][y2 + 2] = 1;
                            pecas2[1] = pecas2[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }else{
                        if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x][y2] == 0 && tabuleiro2[x + 1][y2] == 0){
                            tabuleiro2[x - 1][y2] = 1;
                            tabuleiro2[x][y2] = 1;
                            tabuleiro2[x + 1][y2] = 1;
                            pecas2[1] = pecas2[1] - 1;
                        }else{
                            limpar_tela(plataforma);
                            printf("Esta casa esta ocupada!\n");
                        }
                    }
                }

            }else{
                temp++;
                *jogador++;
            }
        }
    }
}



void limpar_tela(int plataforma){
    if(plataforma == 1){
        system("cls");
    }else{
        system("clear");
    }
}

void converter_y(int *y2, char *y){
    if(*y == 'a' || *y =='A'){
        *y2 = 0;
    }else if(*y == 'b' || *y == 'B'){
        *y2 = 1;
    }else if(*y == 'c' || *y =='C'){
        *y2 = 2;
    }else if(*y == 'd' || *y == 'D'){
        *y2 = 3;
    }else if(*y == 'e' || *y == 'E'){
        *y2 = 4;
    }else if(*y == 'f' || *y == 'F'){
        *y2 = 5;
    }   
}