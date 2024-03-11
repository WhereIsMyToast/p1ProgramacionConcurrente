#include <stdio.h>
#include <stdlib.h>
#include <lista.h>
#include <string.h>
// Crea una lista con un nodo.
void crear(TLista *pLista, char* valor)
{
  pLista->pPrimero = malloc(sizeof(TNodo));
  pLista->pPrimero->valor = malloc(strlen(valor)+1);
  strcpy(pLista->pPrimero->valor, valor);
  pLista->pPrimero->pSiguiente = NULL;
}

void destruir(TLista *pLista)
{
  TNodo *pAux1;
  TNodo *pAux2;
  for (pAux1 = pLista->pPrimero; pAux1 != NULL;)
  {
    pAux2 = pAux1->pSiguiente;
    free(pAux1->valor);
    free(pAux1);
    pAux1 = pAux2;
  }
  free(pLista);
}

// Inserta al ppio de la lista.
void insertar(TLista *pLista, char* valor)
{
  TNodo *pAux1 = malloc(sizeof(TNodo));
  pAux1->valor = malloc(strlen(valor)+1);
  strcpy(pAux1->valor, valor);
  pAux1->pSiguiente = pLista->pPrimero;
  pLista->pPrimero = pAux1;
}

void insertarFinal(TLista *pLista, char* valor)
{
  TNodo *pAux1 = malloc(sizeof(TNodo));
  TNodo *pAux2;
  pAux1->valor = malloc(strlen(valor)+1);
  strcpy(pAux1->valor,valor);
  pAux1->pSiguiente = NULL;
  for(pAux2=pLista->pPrimero;pAux2->pSiguiente!=NULL;pAux2=pAux2->pSiguiente);
  pAux2->pSiguiente = pAux1;
}

// Suponemos n = 1, 2, ...
void insertarN(TLista *pLista, int index, char* valor)
{
  TNodo *pAux1 = malloc(sizeof(TNodo));
  TNodo *pAux2 = pLista->pPrimero;
  pAux1->valor = malloc(strlen(valor)+1);
  strcpy(pAux1->valor, valor);
  for(int i = 1; i<index-1 && pAux2!=NULL;i++, pAux2 = pAux2->pSiguiente);
  pAux1->pSiguiente = pAux2->pSiguiente;
  pAux2->pSiguiente = pAux1;
}

// Elimina el primer elemento de la lista.
void eliminar(TLista *pLista)
{
  TNodo *pAux1 = pLista->pPrimero;
  pLista->pPrimero = pLista->pPrimero->pSiguiente;
  free(pAux1->valor);
  free(pAux1);
} 

void eliminarN(TLista *pLista, int index)
{
  struct Nodo *pAux1= pLista->pPrimero;
  for(int i = 1; i<index-1 && pAux1!=NULL;i++, pAux1 = pAux1->pSiguiente);
  struct Nodo *pAux2 = pAux1->pSiguiente;
  pAux1->pSiguiente = pAux2->pSiguiente;
  free(pAux2->valor);
  free(pAux2);
}

char* getElementoN(TLista *pLista, int index)
{
  TNodo *pAux1= pLista->pPrimero;
  for(int i = 1; i<index && pAux1!=NULL;i++, pAux1 = pAux1->pSiguiente);
  return (pAux1 != NULL) ? pAux1->valor : NULL;
}

void imprimir(TLista *pLista)
{
  TNodo *pAux1 = pLista->pPrimero;
  while (pAux1 != NULL)
  {
    printf("%s, ", pAux1->valor);
    pAux1 = pAux1->pSiguiente;
  }
  printf("\n");
}

int longitud(TLista *pLista)
{
  int i; 
  TNodo *pAux1 = pLista->pPrimero;
  for(i = 0; pAux1!= NULL;i++,pAux1 = pAux1->pSiguiente);
  return i;
}