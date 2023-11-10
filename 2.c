#include <stdio.h>


int validaSexo(char sexo) {
    return (sexo == 'm' || sexo == 'f');
}


int validaSalario(float salario) {
    return (salario > 1.0);
}


void classificaSalario(float salario, char *classificacao) {
    float salario_minimo = 1400.0;

    if (salario > salario_minimo) {
        strcpy(classificacao, "Acima do salario minimo");
    } else if (salario == salario_minimo) {
        strcpy(classificacao, "Igual ao salario minimo");
    } else {
        strcpy(classificacao, "Abaixo do salario minimo");
    }
}


void mostraClassificacao(char sexo, float salario) {
    char classificacao[30];
    
    classificaSalario(salario, classificacao);

    printf("Sexo: %s\n", (sexo == 'm' ? "Masculino" : "Feminino"));
    printf("Salario: R$ %.2f\n", salario);
    printf("Classificacao em relacao ao salario minimo: %s\n\n", classificacao);
}

int main() {
    int num_assalariados, i;
    int abaixo_salario_minimo = 0, acima_salario_minimo = 0;

    printf("Quantos assalariados serao pesquisados? ");
    scanf("%d", &num_assalariados);

    for (i = 0; i < num_assalariados; i++) {
        char sexo;
        float salario;

        while (1) {
            printf("Informe o sexo (m/f): ");
            scanf(" %c", &sexo);
            if (validaSexo(sexo)) {
                break;
            }
            printf("Sexo invalido. Tente novamente.\n");
        }

        while (1) {
            printf("Informe o salario em reais: ");
            scanf("%f", &salario);
            if (validaSalario(salario)) {
                break;
            }
            printf("Salario invalido. Deve ser maior que R$1,00. Tente novamente.\n");
        }

        mostraClassificacao(sexo, salario);

        if (salario < 1400.0) {
            abaixo_salario_minimo++;
        } else {
            acima_salario_minimo++;
        }
    }

    printf("Quantidade de assalariados abaixo do salario minimo: %d\n", abaixo_salario_minimo);
    printf("Quantidade de assalariados acima do salario minimo: %d\n", acima_salario_minimo);

    return 0;
}