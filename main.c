#include <stdio.h>
#include <stdlib.h>

struct elemento
{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;



Elemento* lst_cria (void)
{
    return NULL;
}



Elemento* busca (Elemento* lst, int v)
{
    int contador=0;
    Elemento* p;
    Elemento* aux;
    for (p = lst; p!=NULL; p = p->prox)
    {
        if (p->info == v)
        {
            contador++;
            aux = p; //guarda o ultimo valor duplicado
        }
    }
    if(contador == 2) //apenas duplas
    {
        return aux; // retorna o valor duplicado
    }
    return NULL; //não achou o elemento
}



void lst_imprime (Elemento* lst)
{
    Elemento* p;
    for (p = lst; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}



Elemento* lst_retira (Elemento* lst,
                      int val)
{
    Elemento* ant = NULL;
    Elemento* p = lst;
    Elemento* rlst = lst;

    while (p != NULL && p->info != val)
    {
        ant = p;
        p = p->prox;
    }
    if (p == NULL)
    {
        return rlst;
    }

    if (ant == NULL)
    {
        rlst = p->prox;
    }
    else
    {
        ant->prox = p->prox;
    }
    free(p);
    return rlst;
}



Elemento* lst_insere (Elemento* lst, int val)
{
    Elemento* novo =(Elemento*)malloc(sizeof(Elemento));
    novo->info = val;
    novo->prox = lst;
    return novo;
}


int main()
{
    int n, num;
    int i, cont;
    Elemento* lst;
    lst = lst_cria();
    Elemento* Elem;

    printf("DIGITE QUANTOS VALORES DESEJA ADICIONAR NA LISTA --->");
    scanf("%d",&n);
    int hack[n];// vetor que armazena todos os valores da lista

    for(i=0; i<n; i++)
    {
        printf("\nDIGITE O VALOR QUE DESEJA ADICIONAR NO NOH(%d) --->",i+1);
        scanf("%d",&num);
        hack[i] = num;
        lst = lst_insere(lst, num);
    }

    printf("\nLISTA COM VALORES DUPLICADOS :\n");
    lst_imprime(lst);

    for (cont = 0; cont < n; cont++)//percorre todos os elementos da lista
    {
        Elem = busca(lst,hack[cont]);
        if(Elem != NULL)
        {
            lst = lst_retira (lst, Elem->info);  //retira a "informacao" duplicada
            lst = lst_retira (lst, hack[cont]); //retira a "informacao"
        }
    }
    printf("\nLISTA SEM OS VALORES DUPLICADOS : \n");
    lst_imprime(lst);


    return 0;
}
