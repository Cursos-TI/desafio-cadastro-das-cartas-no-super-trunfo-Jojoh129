#include <stdio.h>

// 'typedef struct' estrutura para armazenar as informações de uma secção 'carta'
typedef struct {
    char estado;
    char codigo[4];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
} Carta;

// 'void capturarDados' função para armazenar os dados da carta na secção que criamos anteriormenteCarta.
void capturarDados(Carta *carta) {
    //Como criamos um secção 'Carta', 'carta->estado' Acessa o campo estado usando '->' (pois carta é um ponteiro). 
    printf("Estado (A-H): "); scanf(" %c", &carta->estado);
    // '%3s' vai permitir que apenas 3 caracteres sejão colocados, para ser como esperamos.
    printf("Código (ex: A01): "); scanf(" %3s", &carta->codigo);
    printf("Nome da Cidade: "); scanf(" %s[^]", &carta->nome_cidade);
    printf("População: "); scanf(" %d", &carta->populacao);
    printf("Área (km²): "); scanf(" %f", &carta->area);
    printf("PIB: "); scanf(" %f", &carta->pib);
    printf("Pontos Turísticos: "); scanf(" %d", &carta->pontos_turisticos);
}
/* 'void exibirDados' vai mostrar os dados colocados anteriormente.
 'const Carta *carta, int numero' vai fazer com que o os dados sejam exibidos sem poder ser alterados na secção de cada carta
 assim podemos adicionar um numero para criar varias nossas cartas*/
void exibirDados(const Carta *carta, int numero) {
    printf("\n--- Carta %d ---\nEstado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f\nPontos Turísticos: %d\n",
           numero, carta->estado, carta->codigo, carta->nome_cidade, carta->populacao, carta->area, carta->pib, carta->pontos_turisticos);
}
//agora com todos os dados protos para serem registrados, usamos a secção 'Carta' parar criarmos a carta 1 e 2 para exibilas com 'printf' e a carta1 ou carta2
int main() {
    Carta carta1, carta2;
    printf("\n--- Carta 1 ---\n"); capturarDados(&carta1);
    printf("\n--- Carta 2 ---\n"); capturarDados(&carta2);
    exibirDados(&carta1, 1);
    exibirDados(&carta2, 2);
    return 0;
}
