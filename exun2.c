#include <stdio.h>

float validaSalario() {
    float salario;
    do {
        printf("\nDigite o salario ou -1 para mostrar o resultado final: R$ ");
        scanf("%f", &salario);
        fflush(stdin);
    } while (salario < -1.0);
    return salario;
}

char validaSexo() {
    char sexo;
    do {
        printf("Digite o sexo (m/f): ");
        scanf(" %c", &sexo);
        fflush(stdin);
    } while (sexo != 'm' && sexo != 'M' && sexo != 'f' && sexo != 'F');
    return sexo;
}

char classificaSalario(float salario) {
    if (salario < 1400) {
        return 'A';
    } else if (salario == 1400) {
        return 'I';
    } else {
        return 'S';
    }
}

void mostraClassifica(char sexo, float salario, char classificacao) {
    printf("\nSalario: R$ %.2f, Sexo: %s, Classificação: ", salario, (sexo == 'm' || sexo == 'M') ? "Masculino" : "Feminino");
    switch (classificacao) {
        case 'A':
            printf("Abaixo do salario minimo\n");
            break;
        case 'I':
            printf("Igual ao salario minimo\n");
            break;
        case 'S':
            printf("Acima do salario minimo\n");
            break;
    }
}

int main() {
    float salario;
    char sexo;
    int qtdAbaixoMinimo = 0, qtdAcimaMinimo = 0;

    do {
        salario = validaSalario();
        if (salario != -1) {
            sexo = validaSexo();
            char classificacao = classificaSalario(salario);
            mostraClassifica(sexo, salario, classificacao);

            if (classificacao == 'A') {
                qtdAbaixoMinimo++;
            } else if (classificacao == 'S') {
                qtdAcimaMinimo++;
            }
        }
    } while (salario != -1);

    printf("\nQuantidade de assalariados com salario abaixo do salario minimo: %d", qtdAbaixoMinimo);
    printf("\nQuantidade de assalariados com salario acima do salario minimo: %d\n", qtdAcimaMinimo);

    return 0;
}
