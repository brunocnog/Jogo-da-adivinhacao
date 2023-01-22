#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinha��o *\n");
    printf("************************************\n");

    int numsecreto, chute, tentativas = 1;
    double pontos = 1000;

    //Calculando de forma rand�mica o n�mero secreto
    srand(time(0));
    numsecreto = rand() % 100;

    //mostrando o n�mero secreto para efeitos de teste durante a cria��o do jogo
    printf("%d\n\n", numsecreto);

    /*
    O c�digo acima poderia ser feito da seguinte forma, para ser mais did�tico
    
    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();
    numerosecreto = numerogrande % 100;
    */
        
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
            printf("Parab�ns! voc� acertou!\n\n");
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
        
        //calculando a pontua��o do jogador a cada rodada
        double pontosperditos = abs(chute - numsecreto) / 2.0; // poderia ser usado (double)2
        pontos = pontos - pontosperditos;
        
        tentativas++;  
        }
    printf("Voc� chutou %d vezes at� acertar.\n", tentativas);
    printf("Voc� fez %.2f pontos.\n", pontos);
    printf("Fim de Jogo!\n");

    return 0;
}

