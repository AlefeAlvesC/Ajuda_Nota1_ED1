#include <stdio.h> 
#include <stdlib.h>
#include "lista.h"

struct nodo{
    int index;//Representa a linha
    int vezes;//A qtde de vezes que apareceu na linha.
    struct nodo *prox;
};

struct lista{
    int tam;
    char info;//Recebe o ponteiro para a primeira letra da palavra.
    Nodo *head;
};

Lista *lst_cria(char str){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->tam = 0;
    l->info = str;
    l->head = NULL;
    return l;
}

void lst_insere(Lista *l, int index){
    Nodo *atual = l->head;
    //Verifica se o index informado ja existe.
    while(atual != NULL && atual->index != index){
        atual = atual->prox;
    }

    //Caso não tenha o index informado, cria um novo nodo.
    if(atual == NULL){
        Nodo *novo = (Nodo*) malloc(sizeof(Nodo));
        novo->index = index;
        novo->vezes = 1;
        novo->prox = l->head;
        l->head = novo;
        l->tam++;
    }else{//Caso tenha, apenas incrementa a qtde de vezes.
        atual->vezes++;
    }
}

//Não precisaremos da função remover.
void lst_remove(Lista *l, int index);


void lst_imprime(Lista *l){
    int prime = 1;//Varialvel para verificar se é o primeiro nodo da lista.
    
    //Printa a palavra.
    printf("%c: ", l->info);
    

    Nodo *atual = l->head;
    for(atual; atual != NULL; atual = atual->prox){
        if(prime){
            printf("(%d|%d)", atual->index, atual->vezes);
            prime = 0;
        }else
            printf(", (%d|%d)", atual->index, atual->vezes);
    }
    printf("\n");

}

char lst_palavra(Lista *l){
    return l->info;
}

