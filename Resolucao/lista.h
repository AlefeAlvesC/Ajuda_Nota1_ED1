//TAD de Lista Encadeada

//Tipo exportado: Nodo ou Nó
typedef struct nodo Nodo;

//Tipo exportado: Lista encadeada
typedef struct lista Lista;

//Função cria
//Cria e retorna uma estrutura lista criada dinamicamente.
Lista *lst_cria(char *str);

//Função insere
//Insere um novo nodo na lista.
void lst_insere(Lista *l, int index);

//Função remove
//Remove um nodo da lista.
void lst_remove();

//Função imprime
//Imprime os elementos presentes na lista.
void lst_imprime(Lista *l);

//Função palavra
//Retorna um ponteiro para a palavra da lista.
char *lst_palavra(Lista *l);

//Função vazia
//Verifica se a lista está vazia.
void lst_vazia(Lista *l);

//Função libera
//Libera a memória alocada para uma lista que foi criada anteriormente.
void lst_libera(Lista *l);
