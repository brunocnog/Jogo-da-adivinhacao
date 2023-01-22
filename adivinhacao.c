#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");

    int numsecreto, chute;

    numsecreto = 42;
    printf("Qual é o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d!\n", chute);

    if(chute == numsecreto){
        printf("Parabéns! Você acertou!");
    } else{        
        if (chute > numsecreto){
            printf("Seu chute foi maior que o número secreto!\n");
        }
        if (chute < numsecreto){
            printf("Seu chute foi menor que o número secreto!\n");
        }        
    }
    return 0;
}


