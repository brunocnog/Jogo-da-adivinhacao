#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define NUMERO_DE_TENTATIVAS 3

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinha��o *\n");
    printf("************************************\n");

    int numsecreto=42, chute;
    
    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++){
        printf("Qual � o seu %d� chute? ", i);
        scanf("%d", &chute);
        printf("Seu %d� chute foi %d!\n", i, chute);

        //verificando se o jogador acertou, se o chute e maior o menor que o n�mero secreto
        int acertou = chute == numsecreto;
        int maior = chute > numsecreto;
        int menor = chute < numsecreto;
                
        if(acertou){ 
            printf("Parab�ns! Voc� acertou!\n\n");
            break;
        }
        if(maior){        
            printf("Seu chute foi maior que o n�mero secreto!\n");
            printf("Tente Novamente!!\n\n");
        }
        if(menor){                
            printf("Seu chute foi menor que o n�mero secreto!\n");
            printf("Tente Novamente!!\n\n");
            }        
        }
    printf("Fim de Jogo!\n");
    return 0;
}

