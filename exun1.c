#include <stdio.h>

float validaQuantidade(float qtdPecas){
    float adicional = 0;
     if(qtdPecas > 50 && qtdPecas <= 80){
        adicional += 0.5;
    }else if(qtdPecas > 80){
        adicional += 0.75;
    }else{}
    return adicional;
}

float calculaSalario(float qtdPecas){
    float nSalario = 0;
    float adicional = validaQuantidade(qtdPecas); 

    if(qtdPecas > 50 && qtdPecas <= 80){
        nSalario = (qtdPecas - 50) * adicional + 600;
    }else if(qtdPecas > 80){
        nSalario = (qtdPecas - 80) * adicional + 600 + 15;
    }else{
        nSalario = 600;
    }
    return nSalario;
}

float mostraFinal(float qtdPecas, float nSalario){
    if(qtdPecas != -1){
    printf("Salario com o bonus: [%.2f]", nSalario);
    }
    return nSalario;
}

int main(){
    float qtdPecas;
   

    do{
    printf("\n\nDigite a quantidade de pecas produzidas ou -1 para encerrar: ");
    scanf("%f", &qtdPecas);

    float nSalario = calculaSalario(qtdPecas);
    mostraFinal(qtdPecas, nSalario);

    } while(qtdPecas != -1);
    return 0;
}
