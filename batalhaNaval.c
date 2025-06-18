#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    // Declaração do tabuleiro: matriz 10x10 inicializada com zeros (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Posicionamentos dos navios:
    // Dois na horizontal ou vertical
    int linhaNavio1 = 1;   // linha inicial do primeiro navio (horizontal ou vertical)
    int colunaNavio1 = 2;  // coluna inicial do primeiro navio

    int linhaNavio2 = 4;   // linha inicial do segundo navio
    int colunaNavio2 = 7;  // coluna inicial do segundo navio

    // Dois na diagonal
    int linhaDiagonal1 = 0;   // início da diagonal principal (de cima para baixo)
    int colunaDiagonal1 = 0;

    int linhaDiagonal2 = 9;   // início da diagonal secundária (de cima para baixo)
    int colunaDiagonal2 = 9;

    // Validação das posições para garantir que os navios cabem no tabuleiro
    if (linhaNavio1 < 0 || linhaNavio1 >= TAMANHO_TABULEIRO ||
        colunaNavio1 < 0 || colunaNavio1 + TAMANHO_NAVIO -1 >= TAMANHO_TABULEIRO) {
        printf("Posição inválida para o navio horizontal/vertical.\n");
        return 1;
    }

    if (linhaNavio2 < 0 || linhaNavio2 + TAMANHO_NAVIO -1 >= TAMANHO_TABULEIRO ||
        colunaNavio2 < 0 || colunaNavio2 >= TAMANHO_TABULEIRO) {
        printf("Posição inválida para o segundo navio.\n");
        return 1;
    }

    if (linhaDiagonal1 < 0 || linhaDiagonal1 + TAMANHO_NAVIO -1 >= TAMANHO_TABULEIRO ||
        colunaDiagonal1 < 0 || colunaDiagonal1 + TAMANHO_NAVIO -1 >= TAMANHO_TABULEIRO) {
        printf("Posição inválida para a diagonal principal.\n");
        return 1;
    }

    if (linhaDiagonal2 - (TAMANHO_NAVIO -1) <0 || linhaDiagonal2 >= TAMANHO_TABULEIRO ||
        colunaDiagonal2 - (TAMANHO_NAVIO -1) <0 || colunaDiagonal2 >= TAMANHO_TABULEIRO) {
        printf("Posição inválida para a diagonal secundária.\n");
        return 1;
    }

    // Verifica sobreposição dos navios horizontais/verticais
    bool sobrepoem = false;

    for(int i=0; i<TAMANHO_NAVIO; i++) {
        if (tabuleiro[linhaNavio1][colunaNavio1 + i] ==3) {
            sobrepoem=true;
            break;
        }
        if (tabuleiro[linhaNavio2 + i][colunaNavio2]==3){
            sobrepoem=true;
            break;
        }

        // Diagonais também podem se sobrepor com outros navios
        if(tabuleiro[linhaDiagonal1 + i][colunaDiagonal1 + i]==3){
            sobrepoem=true;
            break;
        }

        if(tabuleiro[linhaDiagonal2 - i][colunaDiagonal2 - i]==3){
            sobrepoem=true;
            break;
        }

        // Checar cruzamentos diagonais com horizontais/verticais
        if(tabuleiro[linhaNavio1][colunaNavio1 + i]==3 && 
           (linhaDiagonal1 + i)==(linhaDiagonal1+i) && 
           (colunaDiagonal1 + i)==(colunaDiagonal1+i)){
               sobrepoem=true;
               break;
           }

       if(tabuleiro[linhaNavio2 + i][colunaNavio2]==3 &&
          (linhaDiagonal2 - i)==(linhaDiagonal2-i) &&
          (colunaDiagonal2 -i)==(colunaDiagonal2-i)){
              sobrepoem=true;
              break;
          }

       // Para simplificar, podemos apenas verificar se há alguma posição já ocupada antes de colocar.
       // Como ainda não colocamos nada, essa validação será feita após posicionar.

    }

    if(sobrepoem){
        printf("Os navios se sobrepõem. Reposicione-os.\n");
        return 1;
    }

    // Posiciona os dois navios horizontais/verticais
    for(int i=0; i<TAMANHO_NAVIO; i++){
        tabuleiro[linhaNavio1][colunaNavio1+i]=3;     // horizontal
        tabuleiro[linhaNavio2+i][colunaNavio2]=3;     // vertical
    }

    // Posiciona os dois navios diagonais
    for(int i=0; i<TAMANHO_NAVIO; i++){
        tabuleiro[linhaDiagonal1+i][colunaDiagonal1+i]=3;             // diagonal principal
        tabuleiro[linhaDiagonal2-i][colunaDiagonal2-i]=3;             // diagonal secundária
    }

    // Exibe o tabuleiro completo com espaços entre os números para melhor visualização
    printf("Tabuleiro de Batalha Naval:\n");

    for(int linha=0; linha<TAMANHO_TABULEIRO; linha++){
        for(int col=0; col<TAMANHO_TABULEIRO; col++){
            printf("%d ", tabuleiro[linha][col]);
        }
        printf("\n");
    }

    return 0;
}