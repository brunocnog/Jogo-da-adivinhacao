#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");

    int numsecreto=42, chute, tentativas=1;
    
    while (1){
        printf("Qual é o seu %d° chute? ", tentativas);
        scanf("%d", &chute);
        
        //verificando se o jogador digitou um número negativo
        int negativo = chute < 0;

        if(negativo){
            printf("Você não pode chutar números negativos!\n\n");
            continue;
        }

        printf("Seu %d° chute foi %d!\n", tentativas, chute);    

        //verificando se o jogador acertou, se o chute e maior o menor que o número secreto        
        int acertou = chute == numsecreto;
        int maior = chute > numsecreto;
        int menor = chute < numsecreto;
                
        if(acertou){ 
            printf("Parabéns! Você acertou!\n\n");
            break;
        }
        if(maior){        
            printf("Seu chute foi maior que o número secreto!\n");
            printf("Tente Novamente!!\n\n");
        }
        if(menor){                
            printf("Seu chute foi menor que o número secreto!\n");
            printf("Tente Novamente!!\n\n");
            }
        tentativas++;  
        }
    printf("Você chutou %d vezes até acertar.\n", tentativas);
    printf("Fim de Jogo!\n");
    return 0;
}

