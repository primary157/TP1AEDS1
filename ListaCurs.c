#include "ListaCurs.h"
void TLCInicializar(TListaCurs *lc,unsigned int n){
	unsigned int i;
	lc->primeiro = lc->ultimo = 0;
	lc->items = (TLCItem *)malloc(sizeof(TLCItem)*n);
	for (i = 1; i < n - 1; i++) {
		lc->items[i].prox = i + 1;
		lc->items[i].ant = i - 1;
	}
	lc->items[0].ant = -1;
	lc->items[n-1].ant = n-2;
	lc->items[0].prox = 1;
	lc->items[n-1].prox = -1;

	lc->sz = 0;
}
void TLCDestruir(TListaCurs *lc){
	lc->primeiro = lc->ultimo = lc->sz = 0;
	free(lc->items);
	lc->sz = 0;
}
int TLCSize(TListaCurs *lc){
	return lc->sz;
}
int TLCInsere(TListaCurs *lc){
	if(lc->items[lc->ultimo].prox == -1){
		InicializarProcesso(&lc->items[lc->ultimo].info);
		lc->sz++;
		return 0;
	}
	InicializarProcesso(&lc->items[lc->ultimo].info);
	lc->ultimo = lc->items[lc->ultimo].prox;
	lc->sz++;
	return 1;
}
int TLCRetirarPrimeiro(TListaCurs *lc){
	if(lc->primeiro == lc->ultimo){
		return 0;
	}
	lc->primeiro = lc->items[lc->primeiro].prox;
	lc->items[lc->items[lc->primeiro].ant].prox = lc->ultimo;
	lc->items[lc->items[lc->primeiro].ant].ant = lc->items[lc->ultimo].ant;
	lc->ultimo = lc->items[lc->primeiro].ant;
	lc->items[lc->primeiro].ant = -1;
	lc->sz--;
	return 1;
}
int TLCRetirarUltimo(TListaCurs *lc){
	if(lc->primeiro == lc->ultimo){
		return 0;
	}
	lc->ultimo = lc->items[lc->ultimo].ant;
	lc->sz--;
	return 1;
}
/*
void TLCImprimir(TListaCurs *lc){
	int i;
	for (i = lc->primeiro; i != lc->ultimo; i = lc->items[i].prox) {
		ImprimeProcesso(lc->items[i].info);
	}

}
*/
void TLCImprimir(TListaCurs *lc){
	int i, j = lc->primeiro;
	for (i = 0; i != TLCSize(lc); i++) {
		ImprimeProcesso(lc->items[j].info);
		j = lc->items[j].prox;
	}

}
