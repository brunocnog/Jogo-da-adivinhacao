#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUMERO_DE_TENTATIVAS 3

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");

    int numsecreto=42, chute;
    
    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){ //jogador tem 3 chances de acertar
        printf("Qual é o seu %d° chute? ", i);
        scanf("%d", &chute);
        printf("Seu %d° chute foi %d!\n", i, chute);

        int acertou = chute == numsecreto;
        if(acertou){ //verificando se o jogador acertou, se o chute e maior o menor que o número secreto
            printf("Parabéns! Você acertou!\n\n");
            break;
        } else{        
            int maior = chute >numsecreto;
            if (maior){
                printf("Seu chute foi maior que o número secreto!\n");
                printf("Tente Novamente!!\n\n");
            } else {
                printf("Seu chute foi menor que o número secreto!\n");
                printf("Tente Novamente!!\n\n");
            }        
        }
    }
    printf("Fim de Jogo!\n");
    return 0;
}


