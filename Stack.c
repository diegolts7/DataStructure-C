#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
  char nome[50], cargo[20], sexo;
  int idade, matricula;
  struct Node *prox;
} node;

node *criarNo() {
  node *novoNo = (node*) malloc(sizeof(node));
  return novoNo;
}

node *inserirInicio(node *Lista, char nome[], char cargo[], char sexo, int idade, int matricula){

  node *noNovo = criarNo();
  strcpy(noNovo->nome, nome);
  strcpy(noNovo->cargo, cargo);
  noNovo->sexo = sexo;
  noNovo->idade = idade;
  noNovo->matricula = matricula;

  if(Lista == NULL) {
    
    Lista = noNovo;
    noNovo->prox = NULL;
    
  }else{

    noNovo->prox = Lista;
    Lista = noNovo;
    
  }
  return Lista;
}

void imprimirLista(node *Lista){
  node *aux = Lista;
  
  while(aux != NULL){
    printf("No\nNome: %s\nCargo: %s\nSexo: %c\nIdade: %d\nMatricula: %d\n",aux->nome,aux->cargo,aux->sexo,aux->idade,aux->matricula);
    
    aux = aux->prox;
    printf("\n");
  }
}

node *removeNo(node *lista) {
  
  node *aux = lista;

  if(aux == NULL){
    printf("Nao foj possivel remover, a lista esta vazia.");
  }else if(aux->prox == NULL){
    
    free(aux);
    lista = NULL;
    
  }else{

    lista = aux->prox;
    free(aux);
    
  }

  return lista;
}

int main(void) {

  node *Lista = NULL;

  //atribuindo um novo valor a lista
  Lista = inserirInicio(Lista, "dego","servente",'m',23,2345);
  Lista = inserirInicio(Lista, "digo","servente",'m',23,2345);
  Lista = inserirInicio(Lista, "dogo","servente",'m',23,2345);
  Lista = inserirInicio(Lista, "dhisgo","servente",'m',23,2345);
  //removendo no 
  Lista = removeNo(Lista);
  //imprimindo lista
  imprimirLista(Lista);
  return 0;
}