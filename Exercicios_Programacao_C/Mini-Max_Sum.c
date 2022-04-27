#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
* ### HackerRank Mini_max sum (Problem Solving) ###
* ~Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the
*  five integers. Then print the respective minimum and maximum values.
* ~Entrada:
* ~5 elementos inteiros positivos
* ~Saida:
* ~Menor soma
* ~Maior soma
*/
int particiona(int* pvet, int beg, int end);
void quickSortMinMax(int* pvet, int beg, int end){
    int pivo;
    if(end>beg){
        pivo = particiona(pvet, beg, end);
        quickSortMinMax(pvet, beg, pivo-1);
        quickSortMinMax(pvet, pivo+1, end);
    }
}
int particiona(int* pvet, int beg, int end){
    int esq, dir, aux;
    esq = beg;
    dir = end;
    int pivo = pvet[beg];
    while(esq<dir){
        while(pvet[esq] <= pivo && esq <= end)
            esq++;
        while(pvet[dir] > pivo && dir >= 0)
            dir--;
        if(esq < dir){
            aux = pvet[esq];
            pvet[esq] = pvet[dir];
            pvet[dir] = aux;
        }
    }
    pvet[beg] = pvet[dir];
    pvet[dir] = pivo;
    return dir;
}

void miniMaxSum(int* pvet){
    int tam = 5; //tamanho do arry definido no exercicio
    int maxSum = 0, minSum = 0;
    quickSortMinMax(pvet, 0, tam-1);
    for(int i = 0; i < 4; i++){
        minSum += pvet[i];
        maxSum += pvet[i+1];
    }
    printf("\n Soma MENOR: %d\n Soma MAIOR: %d", minSum, maxSum);
}

int main(){
   //
    int aux = 0;
    int* pvet = (int*)malloc(5*sizeof(int));
   //
    for(int i = 0; i < 5; i++){
        scanf("%d", &aux);
        pvet[i] = aux;
    }
   //
    miniMaxSum(pvet);
    return 0;
}//END_MAIN

/**
* ~Rafael Toffalini
* ~27/04/2022
*//
