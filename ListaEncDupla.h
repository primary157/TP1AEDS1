#ifndef LISTAENCDUPLA_H_INCLUDED
#define LISTAENCDUPLA_H_INCLUDED
#include "Processo.h"
#include <math.h> /* abs() */
//Tipo de cada celula em uma Lista Duplamente Encadeada
typedef struct _LEDItem{
	struct _LEDItem *prox, *ant;	//Ponteiros para proximo na lista e anterior na lista
	Processo info;			//Variavel que armazena informações de um item
} LEDItem;
//Tipo Lista Duplamente Encadeada
typedef struct{
	LEDItem *primeiro, *ultimo;	//Ponteiros para primeiro e ultimo itens da lista
	int sz;				//Variável que armazena atual tamanho da lista
} TListaEnc;
void LEDInicializar(TListaEnc *le);	//Inicializa uma lista
void LEDDestruir(TListaEnc *le);	//Destroi uma lista
int LEDSize(TListaEnc le);		//Retorna tamanho atual da lista
int LEDInsere(TListaEnc *le);		//Insere item na lista em ordem crescente
int LEDRetirarPrimeiro(TListaEnc *le);	//Retira primeiro item da lista
int LEDRetirarUltimo(TListaEnc *le);	//Retira ultimo item da lista
void LEDImprimir(TListaEnc le);		//Imprime a lista

#endif
