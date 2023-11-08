#include <stdio.h>

float validaQuantidade(float qtdPecas){
     if(qtdPecas > 50 && qtdPecas <= 80){
        
    }else if(qtdPecas > 80){
        
    }else{}
}

float calculaSalario(float qtdPecas){
    float nSalario = 0;
    if(qtdPecas > 50 && qtdPecas <= 80){
        nSalario = (qtdPecas - 50) * 0.5 + 600;
    }else if(qtdPecas > 80){
        nSalario = (qtdPecas - 80) * 0.75 + 600 + 15;
    }else{}
    return nSalario;
}

float mostraFinal(float qtdPecas, float nSalario){
    printf("%f", nSalario);
    return nSalario;
}

int main(){
    float qtdPecas;
   

    do{
    printf("\nDigite a quantidade de pecas produzidas ou -1 para encerrar: ");
    scanf("%f", &qtdPecas);

    float nSalario = calculaSalario(qtdPecas);
    mostraFinal(qtdPecas, nSalario);
   
    } while (qtdPecas != -1);
    return 0;
}
