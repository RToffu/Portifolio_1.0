#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
* ~
* ~
* ~
* ~
* ~
* ~
* ~
* ~
* ~
* ~
*/
void shiftSplit(char ***str, int pos, int tam){
    char aux = ' ';
    tam++;
    //printf("%s", **str);
    **str = realloc(**str, tam*sizeof(char));
    *(**str + tam*sizeof(char)) = '\0';
    for(int i = tam-1; i > pos; i-- ){
         *(**str+i*sizeof(char)) = *(**str + (i-1)*sizeof(char));
    }
    *(**str+pos*sizeof(char)) = aux;
    printf("%s", **str);
    return;
}
void splitStr(char **str, int tam){
    int x = 32, pos = 0;
    for(int i = 4; i < tam; i++){
        if((*(*str + i*sizeof(char))) == (*(*str + i*sizeof(char)) & ~x)){
        pos = i;
        shiftSplit(&str, pos, tam);
        }
    }
    return;
}
int tamStr(char *str){
    int tam = -1;
    do{
        tam++;
    }while(str[tam] != '\0');
    return tam;
}
void readInput(char **str, int maxLen){
    int tam = 0;
    char* tempStr = malloc(maxLen * sizeof(char));
    fgets(tempStr, maxLen*sizeof(char), stdin);
    do{
        tam++;
    }while(tempStr[tam] != '\n');

    *str = malloc(tam*sizeof(char));
    for(int i = 0; i<tam; i++){
        *(*str + i*sizeof(char)) = tempStr[i];
    }
    *(*str + tam*sizeof(char)) = '\0';
    free(tempStr);
    return;
}


//DRIVER(main)
int main(){
   //var
    int maxLen = 100;
    int tam = 0;
    char *str = NULL;
   //input
    readInput(&str, maxLen);
    tam = tamStr(str);
   //---------
    if(str[0] == 'S')
        splitStr(&str, tam);




    //printf("%d", tam);
    //printf("\n%s", str);

    free(str);
    return 0;
}//END_MAIN
