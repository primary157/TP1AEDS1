#ifndef LISTACURS_H_INCLUDED
#define LISTACURS_H_INCLUDED
#include "Processo.h"
#include <math.h> /* abs() */
//Tipo de cada celula em uma Lista de Cursores
typedef struct{
	int prox, ant;	//Cursores para o index dos itens prox e ant
	Processo info;	//Variavel que armazena informações do item
} TLCItem;
//Tipo Lista de Cursores
typedef struct{
	int primeiro, ultimo;	//Cursores para o index do primeiro e do ultimo item da lista
	TLCItem *items;		//Ponteiro para o vetor de items
	int sz;			//tamanho atual da lista
} TListaCurs;
void TLCInicializar(TListaCurs *lc,unsigned int n);	//Inicializa uma lista
void TLCDestruir(TListaCurs *lc);			//Destroi uma lista
int TLCSize(TListaCurs *lc);				//Retorna tamanho atual da lista
int TLCInsere(TListaCurs *lc);				//Insere item na lista em ordem crescente
int TLCRetirarPrimeiro(TListaCurs *lc);			//Retira primeiro item da lista
int TLCRetirarUltimo(TListaCurs *lc);			//Retira ultimo item da lista
void TLCImprimir(TListaCurs *lc);			//Imprime a lista
#endif
