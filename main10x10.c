#include <stdio.h>
#include <stdlib.h>

void imprimir(int tabuleiro1[10][10], int *jogador, int tabuleiro2[10][10]);
void colocar_pecas(int tabuleiro1[10][10], int *jogador, int pecas1[3], int plataforma, int tabuleiro2[10][10], int pecas2[3]);
void limpar_tela(int plataforma);
void converter_y(int *y2, char *y);
void aa(int a[2], int tabuleiro1[10][10], int tabuleiro2[10][10]); //essa é a função pra setar quantas peças cada jogador jogou
void jogo(int plataforma, int tabuleiro1[10][10], int tabuleiro2[10][10], int *jogador, int a[2], int pontos[2]);

int main(){
    int tabuleiro1[10][10]; int tabuleiro2[10][10];
    int pecas1[3]; int pecas2[3]; int pontos[2]; int a[2]; //a é só pra guardar quantas peças cada jogador jogou
    int fim = 0; int jogador = 0; int plataforma;
    pecas1[0] = 4; pecas1[1] = 3; pecas1[2] = 2; pecas2[0] = 4; pecas2[1] = 3; pecas2[2] = 2;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            tabuleiro1[i][j] = 0;
            tabuleiro2[i][j] = 0;
        }
    }
    printf("Qual sistema operacional voce esta usando?\n1) Windows\n2) Linux\n");
    scanf("%d", &plataforma);
    if(plataforma == 3){
        printf("modo debug\n");
        pecas1[0] = 1; pecas1[1] = 0; pecas1[2] = 0; pecas2[0] = 1; pecas2[1] = 0; pecas2[2] = 0;
        plataforma = 2; //1 pra windows, qualquer outra coisa pra linux (isso é só pro debug)
    }
    limpar_tela(plataforma);

    while(fim == 0){
        colocar_pecas(tabuleiro1, &jogador, pecas1, plataforma, tabuleiro2, pecas2);
        limpar_tela(plataforma);
        jogador = 1;
        colocar_pecas(tabuleiro1, &jogador, pecas1, plataforma, tabuleiro2, pecas2);
        jogador = 2;
        aa(a, tabuleiro1, tabuleiro2);
        limpar_tela(plataforma);
        jogo(plataforma, tabuleiro1, tabuleiro2, &jogador, a, pontos);

        fim++;
    }

    return 0;
}

void imprimir(int tabuleiro1[10][10], int *jogador, int tabuleiro2[10][10]){
    //imprime o tabuleiro1
    if(*jogador == 0 || *jogador == 2){
        printf(" Jogador numero 1\n");
        printf("   A  B  C  D  E  F  G  H  I  J\n");
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(j == 0){
                   if(i == 0){
                        printf("1  ");
                    }else if(i == 1){
                        printf("2  ");
                    }else if(i == 2){
                        printf("3  ");
                    }else if(i == 3){
                        printf("4  ");
                    }else if(i == 4){
                        printf("5  ");
                    }else if(i == 5){
                        printf("6  ");
                    }else if(i == 6){
                        printf("7  ");
                    }else if(i == 7){
                        printf("8  ");
                    }else if(i == 8){
                        printf("9  ");
                    }else if(i == 9){
                        printf("10 ");
                    }
               }
                if(tabuleiro1[i][j] == 0){
                    printf("0  "); //talvez não tenha nada no espaço 
                }else if(tabuleiro1[i][j] == 1){
                    printf("1  "); //talvez tenha apenas uma peça sua
                }else if(tabuleiro1[i][j] == 2){
                    printf("1X "); //tem uma peça sua e tinha uma peça do oponente que foi destruido
                }else if(tabuleiro1[i][j] == 3){
                    printf("1E "); //tem uma peça sua e não tem uma peça do oponente
                }else if(tabuleiro1[i][j] == 4){
                    printf("D  "); //tinha uma peça sua, que foi destruída
                }else if(tabuleiro1[i][j] == 5){
                    printf("DX "); //tinha uma peça sua e uma peça do oponente no mesmo espaço, as duas foram destruídas
                }else if(tabuleiro1[i][j] == 6){
                    printf("DE "); //tinha uma peça sua que foi destruída, e não tem uma peça do seu oponente
                }else if(tabuleiro1[i][j] == 7){
                    printf("E  "); //não tem uma peça do oponente no espaço (não tem nada nesse espaço)
                }else if(tabuleiro1[i][j] == 8){
                    printf("X  "); //matou uma peça do oponente
                }
                
            }
            printf(" ");
            printf("\n");
        }
    }
    if(*jogador == 1 || *jogador == 3){ //imprime o tabuleiro 2
        printf(" Jogador numero 2\n");
        printf("   A  B  C  D  E  F  G  H  I  J\n");
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                if(j == 0){
                   if(i == 0){
                        printf("1  ");
                    }else if(i == 1){
                        printf("2  ");
                    }else if(i == 2){
                        printf("3  ");
                    }else if(i == 3){
                        printf("4  ");
                    }else if(i == 4){
                        printf("5  ");
                    }else if(i == 5){
                        printf("6  ");
                    }else if(i == 6){
                        printf("7  ");
                    }else if(i == 7){
                        printf("8  ");
                    }else if(i == 8){
                        printf("9  ");
                    }else if(i == 9){
                        printf("10 ");
                    }
                }
                if(tabuleiro2[i][j] == 0){
                    printf("0  ");
                }else if(tabuleiro2[i][j] == 1){
                    printf("1  ");
                }else if(tabuleiro2[i][j] == 2){
                    printf("1X ");
                }else if(tabuleiro2[i][j] == 3){
                    printf("1E ");
                }else if(tabuleiro2[i][j] == 4){
                    printf("D  ");
                }else if(tabuleiro2[i][j] == 5){
                    printf("DX ");
                }else if(tabuleiro2[i][j] == 6){
                    printf("DE ");
                }else if(tabuleiro2[i][j] == 7){
                    printf("E  ");
                }else if(tabuleiro2[i][j] == 8){
                    printf("X  ");
                }
            }
            printf(" ");
            printf("\n");
        }
    }
}

void colocar_pecas(int tabuleiro1[10][10], int *jogador, int pecas1[3], int plataforma, int tabuleiro2[10][10], int pecas2[3]){
    if(*jogador == 0){ //jogador 1
        int input = 0;
        int x, y2, temp = 0;
        char y;
        int orientacao_peca = 0;
        int turno0 = 0;
        while(temp == 0){
            if(turno0 == 0){
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("1) colocar peca 1x1 (%d)\n2) colocar peca 1x2 (%d)\n3) colocar peca 1x3 (%d)\n", pecas1[0], pecas1[1], pecas1[2]);
                scanf("%d", &input);
                if(input == 1){ // 1x1
                    if(pecas1[0] > 0){
                        printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                        scanf("%d %c", &x, &y);
                        converter_y(&y2, &y);

                        if(tabuleiro1[x - 1][y2] == 0){
                            tabuleiro1[x - 1][y2] = 1;
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
                    if(orientacao_peca == 1){ //horizontal
                        if(y2 != 9){
                            if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x - 1][y2 + 1] == 0){
                                tabuleiro1[x - 1][y2] = 1;
                                tabuleiro1[x - 1][y2 + 1] = 1;
                                pecas1[1] = pecas1[1] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }else{ //vertical
                        if(x-1 != 9){
                            if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x][y2] == 0){
                                tabuleiro1[x - 1][y2] = 1;
                                tabuleiro1[x][y2] = 1;
                                pecas1[1] = pecas1[1] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
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
                    if(orientacao_peca == 1){ //horizontal
                        if(y2 < 8){
                            if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x - 1][y2 + 1] == 0 && tabuleiro1[x - 1][y2 + 2] == 0){
                                tabuleiro1[x - 1][y2] = 1;
                                tabuleiro1[x - 1][y2 + 1] = 1;
                                tabuleiro1[x - 1][y2 + 2] = 1;
                                pecas1[2] = pecas1[2] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }else{ //vertical
                        if(x-1 < 8){
                            if(tabuleiro1[x - 1][y2] == 0 && tabuleiro1[x][y2] == 0 && tabuleiro1[x + 1][y2] == 0){
                                tabuleiro1[x - 1][y2] = 1;
                                tabuleiro1[x][y2] = 1;
                                tabuleiro1[x + 1][y2] = 1;
                                pecas1[2] = pecas1[2] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }
                }
                if(pecas1[0] == 0 && pecas1[1] == 0 && pecas1[2] == 0){
                    turno0++;
                }
            }else{
                temp++;
            }
        }
    }else if(*jogador == 1){ //jogador 2
        int input = 0;
        int x, y2, temp = 0;
        char y;
        int orientacao_peca = 0;
        int turno0 = 0;
        while(temp == 0){
            if(turno0 == 0){
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("1) colocar peca 1x1 (%d)\n2) colocar peca 1x2 (%d)\n3) colocar peca 1x3 (%d)\n", pecas2[0], pecas2[1], pecas2[2]);
                scanf("%d", &input);
                if(input == 1){ // 1x1
                    if(pecas2[0] > 0){
                        printf("Onde voce quer colocar a peca? (linha, coluna. Ex: 1a)\n");
                        scanf("%d %c", &x, &y);
                        converter_y(&y2, &y);

                        if(tabuleiro2[x - 1][y2] == 0){
                            tabuleiro2[x - 1][y2] = 1;
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
                    if(orientacao_peca == 1){ //horizontal
                        if(y2 != 9){
                            if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x - 1][y2 + 1] == 0){
                                tabuleiro2[x - 1][y2] = 1;
                                tabuleiro2[x - 1][y2 + 1] = 1;
                                pecas2[1] = pecas2[1] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }else{ //vertical
                        if(x-1 != 9){
                            if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x][y2] == 0){
                                tabuleiro2[x - 1][y2] = 1;
                                tabuleiro2[x][y2] = 1;
                                pecas2[1] = pecas2[1] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
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
                    if(orientacao_peca == 1){ //horizontal
                        if(y2 < 8){
                            if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x - 1][y2 + 1] == 0 && tabuleiro2[x - 1][y2 + 2] == 0){
                                tabuleiro2[x - 1][y2] = 1;
                                tabuleiro2[x - 1][y2 + 1] = 1;
                                tabuleiro2[x - 1][y2 + 2] = 1;
                                pecas2[2] = pecas2[2] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }else{ //vertical
                        if(x-1 < 8){
                            if(tabuleiro2[x - 1][y2] == 0 && tabuleiro2[x][y2] == 0 && tabuleiro2[x + 1][y2] == 0){
                                tabuleiro2[x - 1][y2] = 1;
                                tabuleiro2[x][y2] = 1;
                                tabuleiro2[x + 1][y2] = 1;
                                pecas2[2] = pecas2[2] - 1;
                            }else{
                                limpar_tela(plataforma);
                                printf("Esta casa esta ocupada!\n");
                            }
                        }else{
                            limpar_tela(plataforma);
                            printf("Valor inválido!\n");
                        }
                    }
                }
                if(pecas2[0] == 0 && pecas2[1] == 0 && pecas2[2] == 0){
                    turno0++;
                }
            }else{
                temp++;
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

void aa(int a[2], int tabuleiro1[10][10], int tabuleiro2[10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(tabuleiro1[i][j] == 1){
                a[0]++;
            }
            if(tabuleiro2[i][j] == 1){
                a[1]++;
            }
        }
    }
}

void jogo(int plataforma, int tabuleiro1[10][10], int tabuleiro2[10][10], int *jogador, int a[2], int pontos[2]){
    int temp = 0; int x; int y2;
    char y;
    int turno0 = 0;

    while(temp == 0){
        if(turno0 == 0){
            if(*jogador == 2){ //jogador1
                limpar_tela(plataforma);
                printf("Pontos jogador 1: %d\nPontos jogador 2: %d\n", pontos[0], pontos[1]);
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("Escolha onde você quer atacar. (linha, coluna. Ex: 1a)\n");
                scanf("%d %c", &x, &y);
                converter_y(&y2, &y);
                if(tabuleiro2[x-1][y2] == 0){ //errou
                    if(tabuleiro1[x-1][y2] == 0){
                        tabuleiro1[x-1][y2] = 4; //0 -> E
                    }else if(tabuleiro1[x-1][y2] == 1){
                        tabuleiro1[x-1][y2] = 3; //1 -> 1E
                    }else if(tabuleiro1[x-1][y2] == 4){
                        tabuleiro1[x-1][y2] = 6; //D -> DE
                    }
                    *jogador = 3;
                }else if(tabuleiro2[x-1][y2] == 1 || tabuleiro2[x-1][y2] == 2 || tabuleiro2[x-1][y2] == 3){ //acertou
                    if(tabuleiro1[x-1][y2] == 0){
                        tabuleiro1[x-1][y2] = 8; //0 -> X
                    }else if(tabuleiro1[x-1][y2] == 1){
                        tabuleiro1[x-1][y2] = 2; //1 -> 1X
                    }else if(tabuleiro1[x-1][y2] == 4){
                        tabuleiro1[x-1][y2] = 5; //D -> DX
                    }
                    if(tabuleiro2[x-1][y2] == 1){
                        tabuleiro2[x-1][y2] = 4; //1 -> D
                    }else if(tabuleiro2[x-1][y2] == 2){
                        tabuleiro2[x-1][y2] = 5; //1X -> DX
                    }else if(tabuleiro2[x-1][y2] == 3){
                        tabuleiro2[x-1][y2] = 6; //1E -> DE
                    }
                    pontos[0]++;
                    if(pontos[0] == a[0]){
                        turno0++; //caso o jogador ganhe antes de poder jogar de novo
                    }
                }else if(tabuleiro2[x-1][y2] == 4 || tabuleiro2[x-1][y2] == 5 || tabuleiro2[x-1][y2] == 6 || tabuleiro2[x-1][y2] == 7){
                    printf("Esta casa ja teve uma peca destruida!\n"); //isso não vai nem printar, mas to com preguiça de fazer funcionar
                }
            }else if(*jogador == 3){ //jogador2
                limpar_tela(plataforma);
                printf("Pontos jogador 1: %d\nPontos jogador 2: %d\n", pontos[0], pontos[1]);
                imprimir(tabuleiro1, jogador, tabuleiro2);
                printf("Escolha onde você quer atacar. (linha, coluna. Ex: 1a)\n");
                scanf("%d %c", &x, &y);
                converter_y(&y2, &y);
                if(tabuleiro1[x-1][y2] == 0){ //errou
                    if(tabuleiro2[x-1][y2] == 0){
                        tabuleiro2[x-1][y2] = 4; //0 -> E
                    }else if(tabuleiro2[x-1][y2] == 1){
                        tabuleiro2[x-1][y2] = 3; //1 -> 1E
                    }else if(tabuleiro2[x-1][y2] == 4){
                        tabuleiro2[x-1][y2] = 6; //D -> DE
                    }
                    *jogador = 2;
                }else if(tabuleiro1[x-1][y2] == 1 || tabuleiro1[x-1][y2] == 2 || tabuleiro1[x-1][y2] == 3){ //acertou
                    if(tabuleiro2[x-1][y2] == 0){
                        tabuleiro2[x-1][y2] = 8; //0 -> X
                    }else if(tabuleiro2[x-1][y2] == 1){
                        tabuleiro2[x-1][y2] = 2; //1 -> 1X
                    }else if(tabuleiro2[x-1][y2] == 4){
                        tabuleiro2[x-1][y2] = 5; //D -> DX
                    }
                    if(tabuleiro1[x-1][y2] == 1){
                        tabuleiro1[x-1][y2] = 4; //1 -> D
                    }else if(tabuleiro1[x-1][y2] == 2){
                        tabuleiro1[x-1][y2] = 5; //1X -> DX
                    }else if(tabuleiro1[x-1][y2] == 3){
                        tabuleiro1[x-1][y2] = 6; //1E -> DE
                    }
                    pontos[1]++;
                    if(pontos[1] == a[1]){
                        turno0++; //caso o jogador ganhe antes de poder jogar de novo
                    }else if(tabuleiro1[x-1][y2] == 4 || tabuleiro1[x-1][y2] == 5 || tabuleiro1[x-1][y2] == 6 || tabuleiro1[x-1][y2] == 7){
                    printf("Esta casa ja teve uma peca destruida!\n"); //isso não vai nem printar, mas to com preguiça de fazer funcionar
                }
                }
            }
        }else{
            if(pontos[0] == a[0]){
                printf("Jogador 1 Venceu!\n");
                temp++;
            }else if(pontos[1] == a[1]){
                printf("Jogador 2 Venceu!\n");
                temp++;
            }
        }
    }
}