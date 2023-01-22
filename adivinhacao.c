#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinha��o *\n");
    printf("************************************\n");

    int numsecreto, chute;

    numsecreto = 42;
    printf("Qual � o seu chute? ");
    scanf("%d", &chute);
    printf("Seu chute foi %d!\n", chute);

    int acertou = chute == numsecreto;

    if(acertou){
        printf("Parab�ns! Voc� acertou!");
    } else{        
        int maior = chute >numsecreto;
        if (maior){
            printf("Seu chute foi maior que o n�mero secreto!\n");
        } else {
            printf("Seu chute foi menor que o n�mero secreto!\n");
        }        
    }
    return 0;
}


