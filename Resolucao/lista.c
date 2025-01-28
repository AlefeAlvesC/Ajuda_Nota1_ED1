#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct nodo{
    int index;//Representa a linha
    int vezes;//A qtde de vezes que apareceu na linha.
    struct nodo *prox;
};

struct lista{
    int tam;
    char info[100];
    Nodo *head;
};

Lista *lst_cria(char *str){
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->tam = 0;
    strcpy(l->info, str);//Copia a palavra chave da lista
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

//Função imprime 
//Primeiro percorre a lista até o fim e depois vai imprimindo de trás para frente.
void imprime_no(Nodo *no){
    if(no->prox != NULL){
        imprime_no(no->prox);
    }

    if(no->prox == NULL){
        printf("(%d|%d)", no->index, no->vezes);
    }else{
        printf(", (%d|%d)", no->index, no->vezes);
    }
}

void lst_imprime(Lista *l){
    
    //Printa a palavra.
    printf("%8s: ", l->info);//Justificado em 8
    imprime_no(l->head);
    printf("\n");

}

char *lst_palavra(Lista *l){
    return l->info;
}

//Libera os nós de tras para frente evitando a perda do encadeamento.
void libera_no(Nodo *no){
    if(no->prox != NULL){
        libera_no(no->prox);
    }
    free(no);
}


void lst_libera(Lista *l){
    l->tam = 0;
    libera_no(l->head);
    free(l);
}

