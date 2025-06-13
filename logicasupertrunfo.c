#include <stdio.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char nomePais[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

// Função para calcular a densidade demográfica
void calcularDensidade(Carta *carta) {
    carta->densidadeDemografica = carta->populacao / carta->area;
}

// Função para mostrar opções de atributos
void mostrarOpcoes(int escolhido) {
    printf("Escolha o atributo:\n");
    if (escolhido != 1) printf("1 - População\n");
    if (escolhido != 2) printf("2 - Área\n");
    if (escolhido != 3) printf("3 - PIB\n");
    if (escolhido != 4) printf("4 - Número de Pontos Turísticos\n");
    if (escolhido != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    // Duas cartas fixas
    Carta carta1 = {"Brasil", 213000000, 8515767.0, 1839000000000.0, 25, 0.0};
    Carta carta2 = {"Canadá", 38000000, 9984670.0, 1900000000000.0, 15, 0.0};

    // Calcular densidade demográfica
    calcularDensidade(&carta1);
    calcularDensidade(&carta2);

    int atributo1 = 0, atributo2 = 0;

    // Menu para o primeiro atributo
    printf("===== SUPER TRUNFO - NÍVEL MESTRE =====\n");
    mostrarOpcoes(0);
    printf("Escolha o primeiro atributo: ");
    scanf("%d", &atributo1);

    // Verificar se a opção é válida
    if (atributo1 < 1 || atributo1 > 5) {
        printf("Opção inválida! Programa encerrado.\n");
        return 1;
    }

    // Menu para o segundo atributo (dinâmico)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    mostrarOpcoes(atributo1);
    printf("Escolha o segundo atributo: ");
    scanf("%d", &atributo2);

    // Verificar se a opção é válida e diferente da primeira
    if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1) {
        printf("Opção inválida ou repetida! Programa encerrado.\n");
        return 1;
    }

    printf("\nComparando: %s vs %s\n", carta1.nomePais, carta2.nomePais);

    float valor1_attr1 = 0, valor2_attr1 = 0;
    float valor1_attr2 = 0, valor2_attr2 = 0;

    // ---- COMPARAÇÃO PRIMEIRO ATRIBUTO ----
    printf("\nPrimeiro Atributo:\n");
    switch (atributo1) {
        case 1:
            printf("População\n");
            valor1_attr1 = carta1.populacao;
            valor2_attr1 = carta2.populacao;
            break;
        case 2:
            printf("Área\n");
            valor1_attr1 = carta1.area;
            valor2_attr1 = carta2.area;
            break;
        case 3:
            printf("PIB\n");
            valor1_attr1 = carta1.pib;
            valor2_attr1 = carta2.pib;
            break;
        case 4:
            printf("Número de Pontos Turísticos\n");
            valor1_attr1 = carta1.pontosTuristicos;
            valor2_attr1 = carta2.pontosTuristicos;
            break;
        case 5:
            printf("Densidade Demográfica\n");
            valor1_attr1 = carta1.densidadeDemografica;
            valor2_attr1 = carta2.densidadeDemografica;
            break;
        default:
            printf("Erro inesperado!\n");
            return 1;
    }
    printf("%s: %.2f\n", carta1.nomePais, valor1_attr1);
    printf("%s: %.2f\n", carta2.nomePais, valor2_attr1);

    int vencedor_attr1 = (atributo1 == 5)
        ? (valor1_attr1 < valor2_attr1 ? 1 : (valor1_attr1 > valor2_attr1 ? 2 : 0))
        : (valor1_attr1 > valor2_attr1 ? 1 : (valor1_attr1 < valor2_attr1 ? 2 : 0));

    // ---- COMPARAÇÃO SEGUNDO ATRIBUTO ----
    printf("\nSegundo Atributo:\n");
    switch (atributo2) {
        case 1:
            printf("População\n");
            valor1_attr2 = carta1.populacao;
            valor2_attr2 = carta2.populacao;
            break;
        case 2:
            printf("Área\n");
            valor1_attr2 = carta1.area;
            valor2_attr2 = carta2.area;
            break;
        case 3:
            printf("PIB\n");
            valor1_attr2 = carta1.pib;
            valor2_attr2 = carta2.pib;
            break;
        case 4:
            printf("Número de Pontos Turísticos\n");
            valor1_attr2 = carta1.pontosTuristicos;
            valor2_attr2 = carta2.pontosTuristicos;
            break;
        case 5:
            printf("Densidade Demográfica\n");
            valor1_attr2 = carta1.densidadeDemografica;
            valor2_attr2 = carta2.densidadeDemografica;
            break;
        default:
            printf("Erro inesperado!\n");
            return 1;
    }
    printf("%s: %.2f\n", carta1.nomePais, valor1_attr2);
    printf("%s: %.2f\n", carta2.nomePais, valor2_attr2);

    int vencedor_attr2 = (atributo2 == 5)
        ? (valor1_attr2 < valor2_attr2 ? 1 : (valor1_attr2 > valor2_attr2 ? 2 : 0))
        : (valor1_attr2 > valor2_attr2 ? 1 : (valor1_attr2 < valor2_attr2 ? 2 : 0));

    // ---- Soma dos valores ----
    float soma_carta1 = valor1_attr1 + valor1_attr2;
    float soma_carta2 = valor2_attr1 + valor2_attr2;

    printf("\n===== RESULTADO FINAL =====\n");
    printf("%s - Soma dos atributos: %.2f\n", carta1.nomePais, soma_carta1);
    printf("%s - Soma dos atributos: %.2f\n", carta2.nomePais, soma_carta2);

    if (soma_carta1 > soma_carta2) {
        printf("Vencedor: %s\n", carta1.nomePais);
    } else if (soma_carta1 < soma_carta2) {
        printf("Vencedor: %s\n", carta2.nomePais);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
