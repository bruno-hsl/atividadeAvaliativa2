#include <stdio.h>

float validaSalario(float salario){
    if(salario > 1 ){
        return salario;
    }else{
        printf("Salario invalido");
        return -1;
    }
}

char validaSexo(char sexo){
     if(sexo == 'm' || sexo == 'M'){
        return 'm';
        }
        else if(sexo == 'f' || sexo == 'F'){
        return 'f';
        }
}

char classificaSalario(float salario, int *qtdAbaixoMinimo, int *qtdAcimaMinimo){
    if(salario < 1400){
            (*qtdAbaixoMinimo)++;
            return 'm';
        }
        else if(salario == 1400){
           return 'i';
        }
        else if(salario > 1400){
            (*qtdAcimaMinimo)++;
            return 's';
        }
        else{
            return ' ';
        }
}

void mostraClassifica(float salario, char classificacao, char sexo){
     switch(classificacao){
        case 'm':
            printf("\nSalario: R$ %.2f, Salario abaixo do minimo", salario);
            break;
        case 'i':
            printf("\nSalario: R$ %.2f, Salario iqual ao minimo", salario);
            break;
        case 's':
            printf("\nSalario: R$ %.2f, Salario acima do minimo", salario);
            break;
        }
        
        switch(sexo){
        case 'm':
            printf("\nSexo: Masculino");
            break;
        case 'f':
            printf("\nSexo: Feminino");
            break;
        }
}

int main(){
    char sexo;
    float salario;
    int qtdAbaixoMinimo = 0, qtdAcimaMinimo = 0;
    do{

        printf("\n\nDigite o salario ou -1 para mostrar o resultado final: ");
        scanf("%f", &salario);
        fflush(stdin);

        salario = validaSalario(salario);

        if(salario != -1){
        printf("Digite o sexo (m/f): ");
        scanf("%c", &sexo);
        fflush(stdin);

        char classificacao = classificaSalario(salario, &qtdAbaixoMinimo, &qtdAcimaMinimo);
        mostraClassifica(salario, classificacao, sexo);
        }
    }while(salario != -1);

    printf("\nquantidade de assalariados com salario abaixo do salario minimo: %d", qtdAbaixoMinimo);

    printf("\nquantidade de assalariados com salario acima do salario minimo: %d", qtdAcimaMinimo);

    return 0;
}
