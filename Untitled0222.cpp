#include <stdio.h>

#define MAX 100

void cadastrarPecas(int codigos[], int quantidades[], float custos[], int *total) {
    int continuar = 1;

    while (continuar == 1 && *total < MAX) {
        printf("\n--- CADASTRO DE PEÇA ---\n");
        printf("Código da peça: ");
        scanf("%d", &codigos[*total]);

        printf("Quantidade produzida: ");
        scanf("%d", &quantidades[*total]);

        printf("Custo unitário (R$): ");
        scanf("%f", &custos[*total]);

        (*total)++;

        printf("\nDeseja cadastrar outra peça? (1 - Sim / 0 - Não): ");
        scanf("%d", &continuar);
    }

    if (*total >= MAX) {
        printf("\nLimite máximo de peças atingido!\n");
    }
}

void listarPecas(int codigos[], int quantidades[], float custos[], int total) {
    if (total == 0) {
        printf("\nNenhuma peça cadastrada.\n");
        return;
    }

    printf("\n--- LISTAGEM DE PEÇAS ---\n");
    for (int i = 0; i < total; i++) {
        printf("Código: %d | Quantidade: %d | Custo Unitário: R$ %.2f | Custo Total: R$ %.2f\n",
               codigos[i], quantidades[i], custos[i], quantidades[i] * custos[i]);
    }
}

float calcularCustoTotal(int quantidades[], float custos[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += quantidades[i] * custos[i];
    }
    return soma;
}

float calcularMediaCusto(float custos[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += custos[i];
    }
    if (total == 0)
        return 0;
    else
        return soma / (float)total;
}

void mostrarPecaMaisCara(int codigos[], float custos[], int total) {
    if (total == 0) {
        printf("\nNenhuma peça cadastrada.\n");
        return;
    }

    int indiceMaior = 0;
    for (int i = 1; i < total; i++) {
        if (custos[i] > custos[indiceMaior]) {
            indiceMaior = i;
        }
    }

    printf("\nPeça mais cara:\n");
    printf("Código: %d | Custo Unitário: R$ %.2f\n", codigos[indiceMaior], custos[indiceMaior]);
}

int main() {
    int codigos[MAX];
    int quantidades[MAX];
    float custos[MAX];
    int total = 0;
    int opcao;

    do {
        printf("\n========== FÁBRICA DE COSTURA ==========\n");
        printf("1 - Cadastrar peças\n");
        printf("2 - Listar peças\n");
        printf("3 - Mostrar custo total da produção\n");
        printf("4 - Mostrar média dos custos unitários\n");
        printf("5 - Mostrar peça mais cara\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPecas(codigos, quantidades, custos, &total);
                break;
            case 2:
                listarPecas(codigos, quantidades, custos, total);
                break;
            case 3:
                printf("\nCusto total da produção: R$ %.2f\n", calcularCustoTotal(quantidades, custos, total));
                break;
            case 4:
                printf("\nMédia de custo unitário: R$ %.2f\n", calcularMediaCusto(custos, total));
                break;
            case 5:
                mostrarPecaMaisCara(codigos, custos, total);
                break;
            case 0:
                printf("\nEncerrando o sistema...\n");
                break;
            default:
                printf("\n? Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}
