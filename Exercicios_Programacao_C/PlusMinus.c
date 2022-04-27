#include <math.h>
#include <stdlib.h>
#include <stdio.h>

/*
* ### HackerRank Plus Minus (Problem Solving) ###
* ~Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero.
*  Print the decimal value of each fraction on a new line with 6 places after the decimal.
* ~Entrada:
* ~Tamanho do array(n)
* ~Elementos do array
* ~Saida:
* ~Frequencia dos elementos positivos, negativos, e zeros
*/

void PlusMinus(int n, int* pvet){
    double pos, neg, zer;
    pos = 0; neg = 0; zer = 0;
    for(int i = 0; i < n; i++){
        if(pvet[i] > 0)
            pos++;
        else if(pvet[i] < 0)
            neg++;
        else
            zer++;
    }
    pos = pos / n;
    neg = neg / n;
    zer = zer / n;
    printf("\n %lf\n %lf\n %lf", pos, neg, zer);
}

//MAIN
int main(){
    int* pvet; //Ponteiro do array
    int n =0; //Tamanho do array
    int aux = 0;
   //
    scanf("%d", &n);
   //
    pvet = (int*)malloc(n* sizeof(int));

    if(pvet == NULL){
        printf("Erro na alocacao de memoria.\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        pvet[i] = aux;
    }

    PlusMinus(n, pvet);
    //
    free(pvet);
    return 0;
}//END_MAIN

/**
* Rafael Toffalini;
* 27/04/2022;
**/
