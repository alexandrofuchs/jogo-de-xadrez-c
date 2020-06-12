#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int CHECKMATE(char Tabuleiro[10][10]){

for(int i=1;i<=8;i++){
    for(int j=1;j<=8;j++){
        if(Tabuleiro[i][j] == 'K'){
            return 0;
        }
        if(Tabuleiro[i][j] == 'k'){
            return 0;
        }
    }
}
}

void exibe(char Tabuleiro[10][10], int jogador){

printf("|----JOGO DE XADREZ----|\n\n");

if(jogador == 1){
    printf("Turno do JOGADOR 1 - Pecas Maiusculas\n");
}
if(jogador == 2){
    printf("Turno do JOGADOR 2 - Pecas Minusculas\n");
}
printf("\n|-----Tabuleiro-----|\n");
for(int i=0;i<10;i++){
        printf("\n|");
    for(int j=0;j<10;j++){
        printf("%c|", Tabuleiro[i][j]);

   }}
}

int validaPosicao(char Tabuleiro[10][10], int i2, int j2, int jogador){


        if(jogador == 1){
         if( Tabuleiro[i2][j2] == 'T'){return 0;}
         if( Tabuleiro[i2][j2] == 'B'){return 0;}
         if( Tabuleiro[i2][j2] == 'C'){return 0;}
         if( Tabuleiro[i2][j2] == 'R'){return 0;}
         if( Tabuleiro[i2][j2] == 'K'){return 0;}
         if( Tabuleiro[i2][j2] == 'P'){return 0;}else{return 1;}
        }
        if(jogador == 2){
         if( Tabuleiro[i2][j2] == 't'){return 0;}
         if( Tabuleiro[i2][j2] == 'b'){return 0;}
         if( Tabuleiro[i2][j2] == 'c'){return 0;}
         if( Tabuleiro[i2][j2] == 'r'){return 0;}
         if( Tabuleiro[i2][j2] == 'k'){return 0;}
         if( Tabuleiro[i2][j2] == 'p'){return 0;}else{return 1;}
        }
}



int validaPeao(char Tabuleiro[10][10], int i1, int j1, int i2, int j2, int jogador){

    int k1= i1, k2= i2;
    if(i1>i2)
    {
        k1= i2;
        k2= i1;
    }

    if(i2==i1){return 0;}
    if(k2-k1 > 1){return 0;}
    if(k2<k1){return 0;}
    if(j2 != j1){
        int v = validaPosicao(Tabuleiro, i2, j2, jogador);
        if(Tabuleiro[i2][j2] == '\0'){
            return 0;
        }
        if(v==0){
            return 0;}else{return 1;}
            }
    if(j2==j1){
        if(Tabuleiro[i2][j2] != '\0'){
            return 0;}
        else{return 1;}}

            }



int validaCavalo(char Tabuleiro[10][10], int i1,int j1,int i2,int j2, int jogador){


if(i1 == i2 && j1 == j2){
    return 0;
}
int k1 = i1, k2 = i2;
int l1 = j1, l2 = j2;
if(i1>i2){
    k1=i2;
    k2=i1;
}
if(j1>j2){
    l1=j2;
    l2=j1;
}
if(k2-k1 == 2){
    if(l2-l1 != 1){
        return 0;}}
if(l2-l1 == 2){
    if(k2-k1 != 1){
        return 0;}}
if(k2-k1 != 2 && l2-l1 != 2){
    return 0;}
int v = validaPosicao(Tabuleiro, i2, j2, jogador);
if(v == 0){
    return 0;}else{return 1;}


}

int validaKing(char Tabuleiro[10][10], int i1, int j1, int i2, int j2, int jogador){

int k1=i1, k2=i2;
int l1=j1, l2=j2;
if(i1>i2){
    k1=i2;
    k2=i1;
}
if(j1>j2){
    l1=j2;
    l2=j1;
}
    //MOVIMENTO INVALIDO
    if(i1==i2 && j1==j2){return 0;}
    //CIMA-BAIXO
    if(l1==l2){
       if(k2-k1 != 1){return 0;}}
    //ESQUERDA-DIREITA
    if(k1==k2){
       if(l2-l1 != 1){return 0;}}
    //DIAGONAIS
    if(k2-k1 != 1 && l2-l1 != 1){return 0;}
    //VALIDA POSICAO DESTINO
    int v= validaPosicao(Tabuleiro, i2, j2, jogador);
    if(v==0){
        return 0;
    }else{return 1;}
}


int validaBispo(char Tabuleiro[10][10], int i1, int j1, int i2, int j2, int jogador){

if( i1 == i2 || j1 == j2 ){
    return 0;
}
int k1=i1, k2=i2;
int l1=j1, l2=j2;
if(i1>i2){
    k1=i2;
    k2=i1;
}
if(j1>j2){
    l1=j2;
    l2=j1;
}
if(k2-k1 != l2-l1 ){return 0;}



k1 = k1+1;
l1 = l1+1;
for(;k1<k2;k1++,l1++){
        if(Tabuleiro[k1][l1] != '\0'){
        return 0;}}
int v= validaPosicao(Tabuleiro, i2, j2, jogador);
if(v==0){return 0;}else{return 1;}


}


int validaTorre(char Tabuleiro[10][10], int i1, int j1, int i2, int j2, int jogador){

//MOVIMENTO INVALIDO
   if (i1 != i2 && j1 != j2){
       return 0;}

int k1, k2;
 //MOVIMENTO HORIZONTAL
   if(i1 == i2){
     int k1 = j1, k2 = j2;
        if( j1>j2){
            k1 = j2;
            k2 = j1;}
            k1 = k1+1;
            for(;k1<k2;k1++){
                if(Tabuleiro[k1][i1]!='\0'){
                    return 0;}}
           int v= validaPosicao(Tabuleiro, i2, j2, jogador);
           if(v==0){
     return 0;}else{return 1;}}
 //MOVIMENTO VERTICAL
   if (j1 == j2){
     k1= i1, k2=i2;
      if (i1>i2){
        k1 = i2;
        k2 = i1;}
        k1 = k1+1;
        for (;k1<k2;k1++){
         if (Tabuleiro[k1][j1]!='\0'){
            return 0;}}
        int v= validaPosicao(Tabuleiro, i2, j2, jogador);
        if(v==0){return 0;}else{return 1;}}
}


int verificaXeque(char Tabuleiro[10][10],int i2, int j2, int jogador){

int r, i, j, b, t;

for(i=1;i<=8;i++){
   for(j=1;j<=8;j++){

if(jogador== 2){
// TORRE
        if( Tabuleiro[i][j] == 't' ){

            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                    printf("\nJogador 1 - Seu Rei esta em Xeque pela Torre do inimigo\n");
                    return 0;}
            }
// BISPO
        if( Tabuleiro[i][j] == 'b' ){
            r= validaBispo(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 1 -Seu Rei esta em Xeque pelo Bispo do inimigo\n");
                return 0;
                }
            }

// CAVALO
        if( Tabuleiro[i][j] == 'c' ){

            r= validaCavalo(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 1 -Seu Rei esta em Xeque pelo Cavalo do inimigo\n");
                return 0;
                }
            }

// RAINHA
       if( Tabuleiro[i][j] == 'r' ){
            b= validaBispo(Tabuleiro, i, j, i2, j2, jogador);
            t= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(b != 0 || t != 0){
                printf("\nJogador 1 -Seu Rei esta em Xeque pela Rainha do inimigo\n");
                return 0;
            }}

// REI
        if( Tabuleiro[i][j] == 'k' ){

            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 1 -Seu Rei esta em Xeque pelo Rei do inimigo\n");
                return 0;
                }
            }

//PEAO
        if( Tabuleiro[i][j] == 'p' ){
            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 1 -Seu Rei esta em Xeque pelo Peao do inimigo\n");
                return 0;
                }
}}
if(jogador == 1){

// TORRE
        if( Tabuleiro[i][j] == 'T' ){
            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 2 -Seu Rei esta em Xeque pela Torre do inimigo\n");
                return 0;
                }
            }

// BISPO
        if( Tabuleiro[i][j] == 'B' ){
            r= validaBispo(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 2 -Seu Rei esta em Xeque pelo Bispo do inimigo\n");
                return 0;
                }
            }

// CAVALO
        if( Tabuleiro[i][j] == 'C' ){

            r= validaCavalo(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 2 -Seu Rei esta em Xeque pelo Cavalo do inimigo\n");
                return 0;
                }
            }

// RAINHA
       if( Tabuleiro[i][j] == 'R' ){
            b= validaBispo(Tabuleiro, i, j, i2, j2, jogador);
            t= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(b != 0 || t != 0){
                printf("\nJogador 2 -Seu Rei esta em Xeque pela Rainha do inimigo\n");
                return 0;
                }
            }

// REI
        if( Tabuleiro[i][j] == 'K' ){

            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 2 -Seu Rei esta em Xeque pelo Rei do inimigo\n");
                return 0;
                }
            }

//PEAO
        if( Tabuleiro[i][j] == 'P' ){

            r= validaTorre(Tabuleiro, i, j, i2, j2, jogador);
            if(r !=0 ){
                printf("\nJogador 2 -Seu Rei esta em Xeque pelo Peao do inimigo\n");
                return 0;
                }

        } }}}}



int validaXeque(char Tabuleiro[10][10]){

int r;

    for(int i=1;i<9;i++){
        for(int j=1;j<9;j++){
            if(Tabuleiro[i][j] == 'K'){
                int jogador = 2;
                r= verificaXeque(Tabuleiro, i, j, jogador);
                if(r==0){return 0;}

            }
            if(Tabuleiro[i][j] == 'k'){
                int jogador = 1;
                r= verificaXeque(Tabuleiro, i, j, jogador);
                if(r==0){return 0;}else{return 1;}
            }
        }
    }


}

void main(){
int jogador =1;
int i1, j1, i2, j2;
int verdade;
int checkmate=0;
int x;

char Tabuleiro[10][10] ={'-','1', '2', '3', '4', '5', '6', '7', '8', '-',
                       '1', 'T', 'C', 'B', 'R', 'K', 'B', 'C', 'T', '1',
                       '2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', '2',
                       '3', '\0','\0','\0','\0','\0','\0','\0','\0','3',
                       '4', '\0','\0','\0','\0','\0','\0','\0','\0','4',
                       '5', '\0','\0','\0','\0','\0','\0','\0','\0','5',
                       '6', '\0','\0','\0','\0','\0','\0','\0','\0','6',
                       '7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p', '7',
                       '8', 't', 'c', 'b', 'r', 'k', 'b', 'c', 't', '8',
                       '-','1', '2', '3', '4', '5', '6', '7', '8', '-'
                      };
//IMPRESSAO DO TABULEIRO

exibe(Tabuleiro, jogador);
//EXECUÇAO MOVIMENTO

while(checkmate ==0){
validaXeque(Tabuleiro);
if(jogador == 1){
    verdade=1;
    while( verdade==1 ){
        printf("\nESCOLHA UMA PECA SUA PARA MOVER:\n");
        printf("Linha:");
        scanf("%d", &i1);
        printf("Coluna:");
        scanf("%d", &j1);
        printf("\n      Peca Escolhida: '%c' \n", Tabuleiro[i1][j1]);

    if (Tabuleiro[i1][j1] != '\0' && Tabuleiro[i1][j1] != 't' && Tabuleiro[i1][j1] != 'b' && Tabuleiro[i1][j1] != 'c' && Tabuleiro[i1][j1] != 'r' && Tabuleiro[i1][j1] != 'k' && Tabuleiro[i1][j1] != 'p' ){
        verdade = 0;
        printf("\nPOSICAO DESTINO:\n");
        printf("Linha: ");
        scanf("%d", &i2);
        printf("Coluna: ");
        scanf("%d", &j2);

        int r, x;
// TORRE
        if( Tabuleiro[i1][j1] == 'T' ){
            r= validaTorre(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 2;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// BISPO
        if( Tabuleiro[i1][j1] == 'B' ){
            r= validaBispo(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                //system("cls");
                jogador = 2;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// CAVALO
        if( Tabuleiro[i1][j1] == 'C' ){
            r= validaCavalo(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 2;
                exibe(Tabuleiro, jogador);}}
           else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n       ''''Movimento invalido''''");}}

// RAINHA
        if( Tabuleiro[i1][j1] == 'R'){
            int b, t;
            b = validaBispo(Tabuleiro, i1,j1,i2,j2, jogador);
            t = validaTorre(Tabuleiro, i1,j1,i2,j2, jogador);
            if(b != 0 || t != 0){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
               jogador = 2;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// REI
        if( Tabuleiro[i1][j1] == 'K' ){
            r= validaKing(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 2;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

//PEAO
        if( Tabuleiro[i1][j1] == 'P' ){
            r= validaPeao(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 2;
                exibe(Tabuleiro, jogador);}}
           else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}



        }

    else{printf("Peca Informada Invalida\n");}
 }
 }

 validaXeque(Tabuleiro);

if(jogador == 2){
    verdade=1;
    while( verdade==1 ){
        printf("\nESCOLHA UMA PECA SUA PARA MOVER:\n");
        printf("Linha:");
        scanf("%d", &i1);
        printf("Coluna :");
        scanf("%d", &j1);
        printf("\n      Peca Escolhida: '%c' \n", Tabuleiro[i1][j1]);

    if (Tabuleiro[i1][j1] != '\0' && Tabuleiro[i1][j1] != 'T' && Tabuleiro[i1][j1] != 'B' && Tabuleiro[i1][j1] != 'C' && Tabuleiro[i1][j1] != 'R' && Tabuleiro[i1][j1] != 'K' && Tabuleiro[i1][j1] != 'P' ){
        verdade = 0;
        printf("\nPOSICAO DESTINO:\n");
        printf("Linha: ");
        scanf("%d", &i2);
        printf("Coluna: ");
        scanf("%d", &j2);

        int r, x;
// TORRE
        if( Tabuleiro[i1][j1] == 't' ){
            r= validaTorre(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
               x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// BISPO
        if( Tabuleiro[i1][j1] == 'b' ){
            r= validaBispo(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
               int x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// CAVALO
        if( Tabuleiro[i1][j1] == 'c' ){
            r= validaCavalo(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
               x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Rei esta em Xeque");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// RAINHA
        if( Tabuleiro[i1][j1] == 'r'){
            int b, t;
            b = validaBispo(Tabuleiro, i1,j1,i2,j2, jogador);
            t = validaTorre(Tabuleiro, i1,j1,i2,j2, jogador);
            if(b != 0 || t != 0){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Seu Rei esta em Xeque, salve-o");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
               jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

// REI
        if( Tabuleiro[i1][j1] == 'k' ){
            r= validaKing(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Seu Rei esta em Xeque, salve-o");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
               jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}

//PEAO
        if( Tabuleiro[i1][j1] == 'p' ){
            r= validaPeao(Tabuleiro, i1, j1, i2, j2, jogador);
            if(r !=0 ){
                x = validaXeque(Tabuleiro);
                if(x == 0){printf("Movimento invalido, Seu Rei esta em Xeque, salve-o");}
                else{
                Tabuleiro[i2][j2] = Tabuleiro[i1][j1];
                Tabuleiro[i1][j1] = '\0';
                system("cls");
                jogador = 1;
                exibe(Tabuleiro, jogador);}}
            else{
                    system("cls");
                    exibe(Tabuleiro, jogador);
                    printf("\n\n\n        ''''Movimento invalido''''");}}



        }

    else{printf("Peca Informada Invalida\n");}
 }
 }


checkmate = CHECKMATE(Tabuleiro);
 }
 if(jogador == 1){
    printf("jogador 2 GANHOU!");
 }
 if(jogador == 2){
    printf("jogador 1 GANHOU!");
 }


 }








