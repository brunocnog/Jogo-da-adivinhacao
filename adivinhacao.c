#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinha��o *\n");
    printf("************************************\n");

    int numsecreto=42, chute, tentativas=1;
    
    while (1){
        printf("Qual � o seu %d� chute? ", tentativas);
        scanf("%d", &chute);
        
        //verificando se o jogador digitou um n�mero negativo
        int negativo = chute < 0;

        if(negativo){
            printf("Voc� n�o pode chutar n�meros negativos!\n\n");
            continue;
        }

        printf("Seu %d� chute foi %d!\n", tentativas, chute);    

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
        tentativas++;  
        }
    printf("Voc� chutou %d vezes at� acertar.\n", tentativas);
    printf("Fim de Jogo!\n");
    return 0;
}

