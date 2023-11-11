#include <stdio.h>

char validaSexo() {
    char sexo;
    do {
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);
    } while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');
    return sexo;
}

float validaSalario() {
    float salario;
    do {
        printf("Informe o salario: R$ ");
        scanf("%f", &salario);
    } while (salario <= 1.0);
    return salario;
}

char classificaSalario(float salario) {
    if (salario > 1400.0) {
        return 'A';
    } else if (salario == 1400.0) {
        return 'I';
    } else {
        return 'B';
    }
}

void mostraClassificacao(char sexo, float salario, char classificacao) {
    printf("\nSexo: %s, Salario: R$ %.2f, Classificação: ", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino", salario);
    switch (classificacao) {
        case 'A':
            printf("Acima do salario minimo\n");
            break;
        case 'I':
            printf("Igual ao salario minimo\n");
            break;
        case 'B':
            printf("Abaixo do salario minimo\n");
            break;
    }
}

int main() {
    int numAssalariados, abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    printf("Informe o numero de assalariados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        printf("\nAssalariado %d:", i + 1);

        char sexo = validaSexo();
        float salario = validaSalario();
        char classificacao = classificaSalario(salario);

        mostraClassificacao(sexo, salario, classificacao);

        if (classificacao == 'A') {
            acimaSalarioMinimo++;
        } else if (classificacao == 'B') {
            abaixoSalarioMinimo++;
        }
    }

    printf("\nResumo:\n");
    printf("Assalariados abaixo do salario minimo: %d\n", abaixoSalarioMinimo);
    printf("Assalariados acima do salario minimo: %d\n", acimaSalarioMinimo);

    return 0;
}
