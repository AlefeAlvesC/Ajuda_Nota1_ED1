#include <stdio.h>

#include "lista.h"

int main(){
    //Ponteiro para 100 listas ou 100 letras.
    Lista *l[100];
    for(int i = 0; i < 100; i++){
        l[i] = NULL;
    }
    char texto[4][100];

    FILE *fp;
    //Abrindo o arquivo e recebendo o endereço para o primeiro letra do arquivo.
    fp = fopen("arquivo.txt", "rt");
    for(int i = 0; i < 4; i++){
        fscanf(fp, " %100[^\n]", texto[i]);
    }

    //Fechando o arquivo.
    fclose (fp);
    
    
    for(int i = 0; i < 4; i++){//Percorre as linhas
         
        for(int j = 0; texto[i][j] != '\0'; j++){//Percorre cada letra.
            int igual = 0, k;
            for(k = 0; l[k] != NULL; k++){
                if(texto[i][j] == lst_palavra(l[k])){
                    lst_insere(l[k], i);
                    igual = 1;
                    break;
                }
            }

            if(!igual){
                l[k] = lst_cria(texto[i][j]);
                lst_insere(l[k], i);
            }
                

        }
    }

    for(int i = 0; l[i] != NULL; i++){
        lst_imprime(l[i]);
    }


    return 0;
}
