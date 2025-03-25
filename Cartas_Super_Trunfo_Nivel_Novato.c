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
    printf("Estado (A-H): ");
    scanf(" %c", &carta->estado);
    printf("Código (ex: A01): ");
    // '%3s' vai permitir que apenas 3 caracteres sejão colocados, para ser como esperamos.
    scanf(" %3s", carta->codigo);
    printf("Nome da Cidade: ");
    scanf(" %49s", carta->nome_cidade);
    printf("População: ");
    scanf("%d", &carta->populacao);
    printf("Área (km²): ");
    scanf("%f", &carta->area);
    printf("PIB: ");
    scanf("%f", &carta->pib);
    printf("Pontos Turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

/* 'void exibirDados' vai mostrar os dados colocados anteriormente.
 'const Carta *carta, int numero' vai fazer com que o os dados sejam exibidos sem poder ser alterados na secção de cada carta
 assim podemos adicionar um numero para criar nossas cartas*/
void exibirDados(const Carta *carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\nCódigo: %s\nCidade: %s\nPopulação: %d\nÁrea: %.2f km²\nPIB: %.2f\nPontos Turísticos: %d\n",
           carta->estado, carta->codigo, carta->nome_cidade, carta->populacao, carta->area, carta->pib, carta->pontos_turisticos);
}

void compararCartas(Carta carta1, Carta carta2) {
    int opcao;
    
    do {
        // Exibe o menu de opções para o jogador escolher um atributo
        printf("\nEscolha um atributo para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Demográfica\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        float valor1, valor2; // Variáveis para armazenar os valores do atributo escolhido
        char atributo[30]; // String para armazenar o nome do atributo escolhido
    
        // Utiliza switch para determinar qual atributo será comparado
        switch (opcao) {
            case 1:
                valor1 = carta1.populacao;
                valor2 = carta2.populacao;
                sprintf(atributo, "População");
                break;
            case 2:
                valor1 = carta1.area;
                valor2 = carta2.area;
                sprintf(atributo, "Área");
                break;
            case 3:
                valor1 = carta1.pib;
                valor2 = carta2.pib;
                sprintf(atributo, "PIB");
                break;
            case 4:
                valor1 = carta1.pontos_turisticos;
                valor2 = carta2.pontos_turisticos;
                sprintf(atributo, "Pontos Turísticos");
                break;
            case 5:
                // Densidade demográfica é calculada como população / área
                valor1 = carta1.populacao / carta1.area;
                valor2 = carta2.populacao / carta2.area;
                sprintf(atributo, "Densidade Demográfica");
                break;
            case 0:
                printf("Saindo...\n");
                return; // Encerra a função
            default:
                printf("Opção inválida! Tente novamente.\n");
                continue; // Volta ao início do loop caso a opção seja inválida
        }
    
        // Exibe os valores do atributo escolhido para as duas cartas
        printf("\nComparando pelo atributo: %s\n", atributo);
        printf("%s: %.2f vs %s: %.2f\n", carta1.nome_cidade, valor1, carta2.nome_cidade, valor2);
    
        // Regra especial para Densidade Demográfica (vence quem tem o menor valor)
        if (opcao == 5) {
            if (valor1 < valor2)
                printf("Vitória da carta: %s\n", carta1.nome_cidade);
            else if (valor1 > valor2)
                printf("Vitória da carta: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
        } else {
            // Regra padrão (vence quem tem o maior valor)
            if (valor1 > valor2)
                printf("Vitória da carta: %s\n", carta1.nome_cidade);
            else if (valor1 < valor2)
                printf("Vitória da carta: %s\n", carta2.nome_cidade);
            else
                printf("Empate!\n");
        }
    
    } while (opcao != 0); // Repete enquanto o jogador não escolher sair
}

//agora com todos os dados protos para serem registrados, usamos a secção 'Carta' parar criarmos a carta 1 e 2 para exibilas com 'printf' e a carta1 ou carta2
int main() {
    Carta carta1, carta2;

    printf("\n--- Cadastro da Carta 1 ---\n");
    capturarDados(&carta1);
    printf("\n--- Cadastro da Carta 2 ---\n");
    capturarDados(&carta2);

    exibirDados(&carta1, 1);
    exibirDados(&carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}
