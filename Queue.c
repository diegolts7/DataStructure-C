#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa {
  char nome[30], sexo;
  int idade;
  struct Pessoa *prox;
} pessoa;

pessoa *inicio = NULL;

pessoa *criarPessoa() {
  pessoa *novaPessoa = (pessoa *)malloc(sizeof(pessoa));
  return novaPessoa;
}

pessoa *inserirPessoaFinal(pessoa *lista, char nome[], char sexo, int idade) {

  pessoa *pessoaNova = criarPessoa();
  strcpy(pessoaNova->nome, nome);
  pessoaNova->sexo = sexo;
  pessoaNova->idade = idade;

  if (lista == NULL) {

    lista = pessoaNova;
    pessoaNova->prox = NULL;
    inicio = pessoaNova;

  } else {

    pessoa *aux = inicio;
    aux->prox = pessoaNova;
    pessoaNova->prox = NULL;
    inicio = pessoaNova;
    
  }

  return lista;
}

void imprimirPessoas(pessoa *lista) {

  pessoa *aux = lista;

  while (aux != NULL) {
    printf("Nome: %s\nSexo: %c\nIdade: %d\n\n", aux->nome, aux->sexo,
           aux->idade);
    aux = aux->prox;
  }
}

pessoa *deletaPessoa(pessoa *lista) {

  pessoa *aux = lista;

  if(aux == NULL){
    printf("A lista esta vazia");
    
  }else if (aux->prox == NULL) {
    free(aux);
    lista = NULL;
    inicio = NULL;
  } else {

    lista = aux->prox;
    free(aux);
  }

  return lista;
}

void buscarPessoa(pessoa *lista, char nomePessoa[]) {
  pessoa *aux = lista;
  int achou = 0;

  while (aux != NULL) {

    if (strcmp(aux->nome, nomePessoa) == 0) {
      achou = 1;
      break;
    }

    aux = aux->prox;
  }

  if (achou == 0) {
    printf("Pessoa nao encontrada!");
  } else {
    printf("Nome: %s\nSexo: %c\nIdade: %d\n\n", aux->nome, aux->sexo,aux->idade);
  }
}


int main(void) {

  pessoa *listaPessoas = NULL;
  listaPessoas = inserirPessoaFinal(listaPessoas, "diego", 'm', 21);
  listaPessoas = inserirPessoaFinal(listaPessoas, "mary", 'f', 23);
  listaPessoas = inserirPessoaFinal(listaPessoas, "chico", 'm', 25);
  //listaPessoas = deletaPessoa(listaPessoas);
  imprimirPessoas(listaPessoas);
  

  return 0;
}
