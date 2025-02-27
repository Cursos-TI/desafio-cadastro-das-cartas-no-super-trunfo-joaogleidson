#include <stdio.h>
#include <string.h>

#define ESTADOS 8
#define CIDADES 4

typedef struct {
    char codigo[4];
    unsigned long int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float super_poder;
} Cidade;

void calcularPropriedades(Cidade *cidade) {
    cidade->densidade = cidade->populacao / cidade->area;
    cidade->super_poder = cidade->populacao + cidade->area + cidade->pib + cidade->pontos_turisticos + (1.0 / cidade->densidade);
}

void cadastrarCartas(Cidade cidades[ESTADOS][CIDADES]) {
    char estados[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES; j++) {
            sprintf(cidades[i][j].codigo, "%c%02d", estados[i], j + 1);
            printf("Cadastro da cidade %s:\n", cidades[i][j].codigo);
            printf("Populacao: ");
            scanf("%lu", &cidades[i][j].populacao);
            printf("Area (km^2): ");
            scanf("%f", &cidades[i][j].area);
            printf("PIB (em bilhões): ");
            scanf("%f", &cidades[i][j].pib);
            printf("Número de pontos turísticos: ");
            scanf("%d", &cidades[i][j].pontos_turisticos);
            calcularPropriedades(&cidades[i][j]);
            printf("\n");
        }
    }
}

void exibirCartas(Cidade cidades[ESTADOS][CIDADES]) {
    printf("\n=== Cartas Cadastradas ===\n");
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES; j++) {
            printf("Código: %s\n", cidades[i][j].codigo);
            printf("População: %lu\n", cidades[i][j].populacao);
            printf("Área: %.2f km^2\n", cidades[i][j].area);
            printf("PIB: %.2f bilhões\n", cidades[i][j].pib);
            printf("Pontos turísticos: %d\n", cidades[i][j].pontos_turisticos);
            printf("Densidade populacional: %.2f hab/km^2\n", cidades[i][j].densidade);
            printf("Super Poder: %.2f\n", cidades[i][j].super_poder);
            printf("----------------------\n");
        }
    }
}

void compararCartas(Cidade c1, Cidade c2) {
    printf("\nComparação entre %s e %s:\n", c1.codigo, c2.codigo);
    printf("Densidade populacional: %d\n", (c1.densidade < c2.densidade) ? 1 : 0);
    printf("Área: %d\n", (c1.area > c2.area) ? 1 : 0);
    printf("PIB: %d\n", (c1.pib > c2.pib) ? 1 : 0);
    printf("Pontos turísticos: %d\n", (c1.pontos_turisticos > c2.pontos_turisticos) ? 1 : 0);
    printf("Super Poder: %d\n", (c1.super_poder > c2.super_poder) ? 1 : 0);
}

int main() {
    Cidade cidades[ESTADOS][CIDADES];
    cadastrarCartas(cidades);
    exibirCartas(cidades);
    
    char codigo1[4], codigo2[4];
    printf("\nDigite o código da primeira carta para comparação: ");
    scanf("%s", codigo1);
    printf("Digite o código da segunda carta para comparação: ");
    scanf("%s", codigo2);
    
    Cidade *c1 = NULL, *c2 = NULL;
    for (int i = 0; i < ESTADOS; i++) {
        for (int j = 0; j < CIDADES; j++) {
            if (strcmp(cidades[i][j].codigo, codigo1) == 0) c1 = &cidades[i][j];
            if (strcmp(cidades[i][j].codigo, codigo2) == 0) c2 = &cidades[i][j];
        }
    }
    
    if (c1 && c2) {
        compararCartas(*c1, *c2);
    } else {
        printf("Uma ou ambas as cartas não foram encontradas.\n");
    }
    
    return 0;
}
