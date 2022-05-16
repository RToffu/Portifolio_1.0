#include <stdlib.h>
#include <stdio.h>


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
int tamStr(char *str);

//COMBINE
void shiftCombine(char ***str, int pos, int tam){
    int x = 32;
    for(int i = pos; i < tam-1; i++){
        *(**str+i*sizeof(char)) = *(**str + (i+1)*sizeof(char)) | x;
    }
    *(**str + pos*sizeof(char)) = *(**str + pos*sizeof(char)) & ~x;
    **str = realloc(**str, (tam-1)*sizeof(char));
    *(**str +(tam-1)*sizeof(char)) = '\0';
    return;
}
void combineStr(char **str){
    int tam = tamStr(*str);
    int i = 3, x = 33, pos = 0;
    char aux = ' ';
 //
   do{
        i++;
            if(*(*str + i*sizeof(char)) == aux){
                pos = i;
                shiftCombine(&str, pos, tam);
                i--;
                tam = tamStr(*str);
            }
   }while(i<(tam-1));
    return;
}

//SPLIT
void shiftSplit(char ***str, int pos, int tam){
    char aux = ' ';
    tam++;
    //printf("%d", tam);
    **str = realloc(**str, (tam+1)*sizeof(char));
    *(**str + tam*sizeof(char)) = '\0';
    for(int i = tam-1; i > pos; i-- ){
         *(**str+i*sizeof(char)) = *(**str + (i-1)*sizeof(char));
    }
    *(**str+pos*sizeof(char)) = aux;
    return;
}
void splitStr(char **str){
   //var
    int x = 32, pos = 0;
    int i = 3;
    int tam = tamStr(*str);
   //
    while(*(*str + i*sizeof(char)) != '\0'){
        i++;
            if((*(*str + i*sizeof(char))) == (*(*str + i*sizeof(char)) & ~x) && (*(*str + i*sizeof(char)) != '\0')){
                pos = i;
                shiftSplit(&str, pos, tam);
                i++;
                tam = tamStr(*str);
            }
    }
   //output
    return;
}

//AUX
int tamStr(char *str){
    int tam = 0;
    while(str[tam] != '\0'){
        tam++;
    }
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
    //tam = tamStr(str);
  //-------------------
    if(str[0] == 'S')
        splitStr(&str);
    if(str[0] == 'C')
        combineStr(&str);
  //-------------------
    //M => method
    //V => variable
    //C => class
  //###OUTPUT###
    tam = tamStr(str);
    printf("%d", tam);
    printf("\n%s", str);

    free(str);
    return 0;
}//END_MAIN
