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

    int numsecreto, chute, acertou = 0, maior, menor, nivel, totTentativas;
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

    printf("Escolha o n�vel de dificuldade?\n");
    printf("(1) F�cil   (2) M�dio   (3) Dif�cil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);
    printf("\n");

    switch (nivel){
        case 1:
            totTentativas = 20;
            break;
        case 2:
            totTentativas = 15;
            break;
        default: //qualquer n�mero diferente de 4 cair� nesta condi��o
            totTentativas = 6;
            break;
        }
            
    for (int i = 1; i <= totTentativas; i++){
        printf("Tentativa %d de %d\n", i, totTentativas);
        printf("Qual � o seu %d� chute?\n", i);
        printf("Chute: ");
        scanf("%d", &chute);
        
        //verificando se o jogador acertou, se o chute e maior o menor que o n�mero secreto        
        acertou = chute == numsecreto;
        maior = chute > numsecreto;
        menor = chute < numsecreto;

        //verificando se o jogador digitou um n�mero negativo
        int negativo = chute < 0;

        if(negativo){
            printf("\n");
            printf("Voc� n�o pode chutar n�meros negativos!\n\n");
            i--;
            continue;
        }        
                
        if(acertou){ 
            printf("\n");
            printf("Parab�ns! voc� acertou!\n");
            printf("Voc� chutou %d vezes at� acertar.\n", i);
            break;
        }
        if(maior){     
            printf("\n");  
            printf("Seu chute foi maior que o n�mero secreto!\n");
            printf("Tente Novamente!!\n\n");
        }
        if(menor){                
            printf("\n");
            printf("Seu chute foi menor que o n�mero secreto!\n");
            printf("Tente Novamente!!\n\n");
            }
        
        //calculando a pontua��o do jogador a cada rodada
        double pontosperditos = abs(chute - numsecreto) / 2.0; // poderia ser usado (double)2
        pontos = pontos - pontosperditos;          
    }

    if(!acertou){
        printf("Voc� perdeu! Tente Novamente!\n");
    }
    printf("\n");
    printf("Voc� fez %.2f pontos.\n", pontos);
    printf("Obrigado por jogar!\n\n");

return 0;
}

