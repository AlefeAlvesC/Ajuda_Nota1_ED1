#include <stdio.h>
#include <string.h>

#include "lista.h"

int main(){
    //Ponteiro para até 100 listas ou seja o texto pode conter só 100 palavras diferentes.
    Lista *l[100];
    for(int i = 0; i < 100; i++){//Inicializa todos os ponteiros com NULL
        l[i] = NULL;
    }
    char texto[101];//Cada palavra pode ter no maximo 100 caracteres tirando \0.

    FILE *fp;
    //Abrindo o arquivo em modo de leitura de texto e recebendo o endereço para o primeiro letra do arquivo.
    fp = fopen("arquivo.txt", "rt");
    
    int i = 0;//Variavel da contagem de indice das linhas
    while(fscanf(fp, " %100[^ \n]", texto) != EOF){//Fazendo a leitura de cada palavra.
        
        //Verificamos se já existe uma lista para a palavra lida.
        int igual = 0, k;
        for(k = 0; l[k] != NULL; k++){
            
            if(!strcmp(texto, lst_palavra(l[k]))){//Função strcpm retorna zero em caso de igualdade.
                lst_insere(l[k], i);
                igual = 1;
                break;
            }
        }

        //Se não foi encontrada palavra igual, então cria uma nova lista
        if(!igual){
            l[k] = lst_cria(texto);
            lst_insere(l[k], i);
        }
            
        int a = fgetc(fp);//Auxilar para saber se é nova linha ou não.
        if(a == '\n' || a == EOF)
            i++;
    }

    //Fechando o arquivo.
    fclose (fp);

    //Imprime a lista com o index invertido
    for(int i = 0; l[i] != NULL; i++){
        lst_imprime(l[i]);
        lst_libera(l[i]);
    }

    return 0;
}
