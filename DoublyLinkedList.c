#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  char nome[50], cargo[20], sexo;
  int idade, matricula;
  struct Node *anter;
  struct Node *prox;
} node;

node *ultimo = NULL;

node *criarNo() {
  node *novoNo = (node*) malloc(sizeof(node));
  return novoNo;
}

node *inserirFinal(node *Lista, char nome[], char cargo[], char sexo, int idade, int matricula){

  node *noNovo = criarNo();
  strcpy(noNovo->nome, nome);
  strcpy(noNovo->cargo, cargo);
  noNovo->sexo = sexo;
  noNovo->idade = idade;
  noNovo->matricula = matricula;

  if(Lista == NULL) {
    
    Lista = noNovo;
    noNovo->prox = NULL;
    noNovo->anter = NULL;
    ultimo = noNovo;
    
  }else{
    
    node *aux = ultimo;
    aux->prox = noNovo;
    noNovo->anter = aux;
    noNovo->prox = NULL;
    ultimo = noNovo;
  }
  return Lista;
}

void imprimirLista(node *lista){
  node *aux = lista;
  
  if(aux != NULL){
    
    imprimirLista(aux->prox);
    
    printf("Nome: %s\nCargo: %s\nSexo: %c\nIdade: %d\nMatricula: %d\n",aux->nome,aux->cargo,aux->sexo,aux->idade,aux->matricula);
    printf("\n");
    
  }
}

node *deletarInicio(node *lista){

  node *aux = lista;

  if(aux == NULL){
    printf("A lista já esta vazia.");
  }else if(aux->prox == NULL){
    lista = NULL;
    free(aux);
  }else {
    lista = aux->prox;
    lista->anter = NULL;
    free(aux);
  }
  
  return lista;
} 

int main(void) {

  node *Lista = NULL;

  //atribuindo um novo valor a lista
  Lista = inserirFinal(Lista, "diego","servente",'m',27,2366);
  Lista = inserirFinal(Lista, "joao","servente",'m',30,2355);
  Lista = inserirFinal(Lista, "alek","svente",'m',18,2344);
  Lista = inserirFinal(Lista, "emilly","rapariga",'f',20,2323);
  //removendo
  Lista = deletarInicio(Lista);
  //imprimindo lista
  imprimirLista(Lista);
  
  return 0;
}