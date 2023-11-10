#include <stdio.h>


int validaQuantidade(int quantidade) {
    if (quantidade > 0) {
        return 1; // 
    } else {
        return 0; 
    }
}

float calculaSalario(int quantidade) {
    float salario_base = 600.0;
    float adicional = 0.0;

    if (quantidade > 50 && quantidade <= 80) {
        adicional = 0.50 * (quantidade - 50);
    } else if (quantidade > 80) {
        adicional = 0.50 * 30 + 0.75 * (quantidade - 80);
    }

    return salario_base + adicional;
}


void mostraFinal(int funcionario, int quantidade, float salario) {
    printf("Funcionario %d\n", funcionario);
    printf("Quantidade de pecas fabricadas: %d\n", quantidade);
    printf("Salario total: R$ %.2f\n", salario);
    printf("\n");
}

int main() {
    int funcionario = 1;
    int quantidade;

    while (1) {
        printf("Digite a quantidade de peças fabricadas pelo Funcionario %d (ou -1 para encerrar): ", funcionario);
        scanf("%d", &quantidade);

        if (quantidade == -1) {
            break; // Encerra o loop
        }

        if (validaQuantidade(quantidade)) {
            float salario = calculaSalario(quantidade);
            mostraFinal(funcionario, quantidade, salario);
        } else {
            printf("Quantidade invalida. Tente novamente.\n");
        }

        funcionario++;
    }

    return 0;
}