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
  }else{
    node *aux = Lista;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = noNovo;
    noNovo->prox = NULL;
  }
  return Lista;
}

void imprimirLista(node *Lista){
  node *aux = Lista;
  int cont = 1;
  while(aux != NULL){
    printf("%d No\nNome: %s\nCargo: %s\nSexo: %c\nIdade: %d\nMatricula: %d\n",cont,aux->nome,aux->cargo,aux->sexo,aux->idade,aux->matricula);
    cont++;
    aux = aux->prox;
    printf("\n");
  }
}

int main(void) {
  
  node *Lista = NULL;
  
  //atribuindo um novo valor a lista
  Lista = inserirFinal(Lista, "dego","servente",'m',23,2345);
  Lista = inserirFinal(Lista, "digo","servente",'m',23,2345);
  Lista = inserirFinal(Lista, "diego","servente",'m',23,2345);
  Lista = inserirFinal(Lista, "diego","servente",'m',23,2345);
  //imprimindo lista
  imprimirLista(Lista);
  return 0;
}