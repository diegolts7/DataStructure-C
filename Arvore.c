#include <stdlib.h>
#include <stdio.h>

typedef struct no
{
    int dado;
    struct no *left;
    struct no *rigth;
} No;

No *criarNo()
{
    No *novoNo = (No *)malloc(sizeof(No));
    novoNo->left = NULL;
    novoNo->rigth = NULL;
    return novoNo;
}

typedef struct arvore
{
    No *raiz;
} Arvore;

void InserirEsquerda(No *noNovo, int dado)
{
    if (noNovo->left == NULL)
    {
        No *novoNo = criarNo();
        novoNo->dado = dado;
        noNovo->left = novoNo;
    }
    else
    {
        if (dado < noNovo->left->dado)
        {
            InserirEsquerda(noNovo->left, dado);
        }
        else
        {
            InserirDireita(noNovo->left, dado);
        }
    }
}

void InserirDireita(No *noNovo, int dado)
{
    if (noNovo->rigth == NULL)
    {
        No *novoNo = criarNo();
        novoNo->dado = dado;
        noNovo->rigth = novoNo;
    }
    else
    {
        if (dado < noNovo->rigth->dado)
        {
            InserirEsquerda(noNovo->rigth, dado);
        }
        else
        {
            InserirDireita(noNovo->rigth, dado);
        }
    }
}

void Inserir(Arvore *arv, int dado)
{
    if (arv->raiz == NULL)
    {
        No *novoNo = criarNo();
        novoNo->dado = dado;
        arv->raiz = novoNo;
    }
    else
    {
        if (dado < arv->raiz->dado)
        {
            InserirEsquerda(arv->raiz, dado);
        }
        else
        {
            InserirDireita(arv->raiz, dado);
        }
    }
}

void ImprimirArvore(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%d\n", raiz->dado);
        ImprimirArvore(raiz->left);
        ImprimirArvore(raiz->rigth);
    }
}

int main()
{
    Arvore arv;
    arv.raiz = NULL;

    Inserir(&arv, 50);
    Inserir(&arv, 30);
    Inserir(&arv, 333);
    Inserir(&arv, 66);
    Inserir(&arv, 18);

    ImprimirArvore(arv.raiz);

    return 0;
}
