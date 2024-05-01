#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define YEL "\x1B[33m"
#define BLU "\x1B[34m"
#define MAG "\x1B[35m"
#define CYN "\x1B[36m"
#define WHT "\x1B[37m"
#define RESET "\x1B[0m"

int i=0, j=0, linha=0, coluna=0, a, b, loopjogadax = 1, loopjogadao = 1, loopcolisao = 1;
int jogo[3][3]; 
int jogador=1;
int chk = 0;
int empate=0; 

// FUNÇÃO COLISÃO - KAUE
void foramapa(void){ 
    do{
    scanf("%d %d", &linha, &coluna);    
    if(linha < 0 || linha > 3 || coluna < 0 || coluna > 3){
    printf("indices invalido, você não pode posicionar fora do jogo da velha");
        } else {
          break;
           }

    } while (loopcolisao == 1);
    }


void introd();
void zeramapa();
int mapax();
int mapao();
int wincondition();

int empat(){
    empate++;
    //printf("empate: %d", empate);
    if(empate == 9){
        chk = 1;
        printf("O jogo empatou!");
        return empate;
    }
}

int main () {
setlocale(LC_ALL, "Portuguese");    
int repetidor;

introd();

do {
    zeramapa();

    do {

        if (jogador == 1) {
                mapax();
                wincondition(jogo[3][3]);
                empat();
        } else {
                mapao();
                wincondition(jogo[3][3]);
                empat();
        }

    }while(chk==0);

    printf("\nDesejam jogar novamente? \nDigite 0 para sair ou 1 para jogar novamente: ");
    scanf("%d", &repetidor);
    system("CLS");
    chk = 0;
    jogador = 1;

} while (repetidor == 1);

printf ("Obrigado por jogar!");

    return 0;
}

void introd(){

    printf("\nBem vindo ao jogo da velha!\n\nDesenvolvido por: "MAG"Nicole Hemp"RESET", "YEL"Kaue Albrecht"RESET", "CYN"Otavio Alves"RESET"\n\nEste e um jogo da velha comum, o primeiro jogador a completar 3 '"RED"X"RESET"' ou '"BLU"O'"RESET" em uma linha, seja vertical, horizontal ou diagonal vence!\nDigite linha 0 e coluna 0 para resetar\n");
    for (int i = 0; i < 3; i++) {
        printf("\n");
        for (int j = 0; j < 3; j++) {
            printf("[ ]");
            
        }
    }

    printf (GRN"\n\nVamos comecar!\n"RESET);
}     

void zeramapa() {
    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
           jogo[i][j]= ' ';
        }
    }
}

int mapax() {
int chkx = 0;

    do {
        printf (RED"\nJogador X"RESET", Digite a linha e a coluna:");
        foramapa();
        printf ("\n");

        if (jogo[linha-1][coluna-1] == 'O') {
            printf (RED"\nLugar ja ocupado! Tente novamente\n!"RESET);
            chkx = 1;
        } else {
            chkx = 0;
    }
    } while (chkx==1);

    if (linha==1) {
        if (coluna==1) {
            jogo[0][0] = 'X';  
        } else if (coluna==2) {
            jogo[0][1] = 'X';
        } else {
            jogo[0][2] = 'X';
        }
    }

    if (linha==2) {
        if (coluna==1) {
            jogo[1][0] = 'X';  
        } else if (coluna==2) {
            jogo[1][1] = 'X';
        } else {
            jogo[1][2] = 'X';
        }   
    }

    if (linha==3) {
        if (coluna==1) {
            jogo[2][0] = 'X';  
        } else if (coluna==2) {
            jogo[2][1] = 'X';
        } else {
            jogo[2][2] = 'X';
        }
    }

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (jogo[i][j]!='X' && jogo[i][j]!='O')
            {
            printf ("[ ] ", jogo[i][j]);
            }
            if (jogo[i][j]=='X')
            {
                printf ("["RED"X"RESET"] ", jogo[i][j]);
            }
            if (jogo[i][j]=='O')
            {
                printf ("["BLU"O"RESET"] " , jogo[i][j]);
            }
            
        }
        printf ("\n");
    }

    if (linha==0 && coluna==0) {
        chk = 1;
    }

    jogador = 2;
    return chk;
}

int mapao() {
    int chko=0;

    do {
        printf (BLU"\nJogador O"RESET", Digite a linha e a coluna:");
        foramapa();
        printf ("\n");

        if (jogo[linha-1][coluna-1] == 'X') {
            printf (RED"\nLugar ja ocupado! Tente novamente\n!"RESET);
            chko = 1;
        } else {
            chko = 0;
        }
    } while (chko==1);

    if (linha==1) {
        if (coluna==1) {
            jogo[0][0] = 'O';  
        } else if (coluna==2) {
            jogo[0][1] = 'O';
        } else {
            jogo[0][2] = 'O';
        }
    }

    if (linha==2) {
        if (coluna==1) {
            jogo[1][0] = 'O';  
        } else if (coluna==2) {
            jogo[1][1] = 'O';
        } else {
            jogo[1][2] = 'O';
        }
    }

    if (linha==3) {
        if (coluna==1) {
            jogo[2][0] = 'O';  
        } else if (coluna==2) {
            jogo[2][1] = 'O';
        } else {
            jogo[2][2] = 'O';
        }
    }

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (jogo[i][j]!='X' && jogo[i][j]!='O')
            {
            printf ("[ ] ", jogo[i][j]);
            }
            if (jogo[i][j]=='X')
            {
                printf ("["RED"X"RESET"] ", jogo[i][j]);
            }
            if (jogo[i][j]=='O')
            {
                printf ("["BLU"O"RESET"] " , jogo[i][j]);
            }
            
        }
        printf ("\n");
    }

    if (linha==0 && coluna==0) {
        printf("RESETOU");
        chk = 1;
    }

    jogador = 1;
    return chk;
}

int wincondition() {
    if ((jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X')) {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[2][0] == 'X') {
        printf ("\nGanhador X!\n");
        chk = 1;
    }

    //----------------------------------------------------------------//

    if ((jogo[0][0] == 'O' && jogo[0][1] == 'O' && jogo[0][2] == 'O')) {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[1][0] == 'O' && jogo[1][1] == 'O' && jogo[1][2] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[2][0] == 'O' && jogo[2][1] == 'O' && jogo[2][2] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[0][0] == 'O' && jogo[1][0] == 'O' && jogo[2][0] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[0][1] == 'O' && jogo[1][1] == 'O' && jogo[2][1] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[0][2] == 'O' && jogo[1][2] == 'O' && jogo[2][2] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[0][0] == 'O' && jogo[1][1] == 'O' && jogo[2][2] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }

    if (jogo[0][3] == 'O' && jogo[1][1] == 'O' && jogo[2][0] == 'O') {
        printf ("\nGanhador O!\n");
        chk = 1;
    }
}