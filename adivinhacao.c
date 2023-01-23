#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"Portuguese");

    printf("************************************\n");
    printf("* Bem-vindo ao Jogo da Adivinhação *\n");
    printf("************************************\n");

    int numsecreto, chute, acertou = 0, maior, menor, nivel, totTentativas;
    double pontos = 1000;

   //Calculando de forma randômica o número secreto
    srand(time(0));
    numsecreto = rand() % 100;

    //mostrando o número secreto para efeitos de teste durante a criação do jogo
    printf("%d\n\n", numsecreto);

    /*
    O código acima poderia ser feito da seguinte forma, para ser mais didático
    
    int segundos = time(0);
    srand(segundos);
    
    int numerogrande = rand();
    numerosecreto = numerogrande % 100;
    */

    printf("Escolha o nível de dificuldade?\n");
    printf("(1) Fácil   (2) Médio   (3) Difícil\n");
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
        default: //qualquer número diferente de 4 cairá nesta condição
            totTentativas = 6;
            break;
        }
            
    for (int i = 1; i <= totTentativas; i++){
        printf("Tentativa %d de %d\n", i, totTentativas);
        printf("Qual é o seu %d° chute?\n", i);
        printf("Chute: ");
        scanf("%d", &chute);
        
        //verificando se o jogador acertou, se o chute e maior o menor que o número secreto        
        acertou = chute == numsecreto;
        maior = chute > numsecreto;
        menor = chute < numsecreto;

        //verificando se o jogador digitou um número negativo
        int negativo = chute < 0;

        if(negativo){
            printf("\n");
            printf("Você não pode chutar números negativos!\n\n");
            i--;
            continue;
        }        
                
        if(acertou){ 
            printf("\n");
            printf("Parabéns! você acertou!\n");
            printf("Você chutou %d vezes até acertar.\n", i);
            break;
        }
        if(maior){     
            printf("\n");  
            printf("Seu chute foi maior que o número secreto!\n");
            printf("Tente Novamente!!\n\n");
        }
        if(menor){                
            printf("\n");
            printf("Seu chute foi menor que o número secreto!\n");
            printf("Tente Novamente!!\n\n");
            }
        
        //calculando a pontuação do jogador a cada rodada
        double pontosperditos = abs(chute - numsecreto) / 2.0; // poderia ser usado (double)2
        pontos = pontos - pontosperditos;          
    }

    if(!acertou){
        printf("Você perdeu! Tente Novamente!\n");
    }
    printf("\n");
    printf("Você fez %.2f pontos.\n", pontos);
    printf("Obrigado por jogar!\n\n");

return 0;
}

