/* Testando Processo
#include "Processo.h"
int main(void)
{
	srand(time(NULL));
	Processo p;
	InicializarProcesso(&p);
	ImprimeProcesso(p);
	return 0;
}
*/
/*
#ifndef LISTAENCDUPLA_H_INCLUDED
#define LISTAENCDUPLA_H_INCLUDED
#include "Processo.h"
typedef struct _LEDItem{
	struct _LEDItem *prox, *ant;
	Processo info;
} LEDItem;
typedef struct{
	LEDItem *primeiro, *ultimo;
	int sz;
} TListaEnc;
void LEDInicializar(TListaEnc *le);
void LEDDestruir(TListaEnc *le);
int LEDSize(TListaEnc *le);
int LEDInsere(TListaEnc *le);
int LEDRetirarPrimeiro(TListaEnc *le);
int LEDRetirarUltimo(TListaEnc *le);
void LEDImprimir(TListaEnc *le);

#endif

 */
/* Testando Lista Duplamente Encadeada */
/*
#include "ListaEncDupla.h"
int main(void)
{
	srand(time(NULL));
	TListaEnc lista;
	LEDInicializar(&lista);
	LEDImprimir(lista);
	printf("\nSIZE = %d\n",LEDSize(lista));
	for (int i = 0; i < 10; i++) {
		LEDInsere(&lista);
	}
	LEDImprimir(lista);
	printf("\nSIZE = %d\n",LEDSize(lista));
	LEDRetirarPrimeiro(&lista);
	LEDImprimir(lista);
	printf("\nSIZE = %d\n",LEDSize(lista));
	LEDRetirarUltimo(&lista);
	LEDImprimir(lista);
	printf("\nSIZE = %d\n",LEDSize(lista));
	LEDDestruir(&lista);
	LEDImprimir(lista);
	printf("\nSIZE = %d\n",LEDSize(lista));
	return 0;
}
*/
/*
#ifndef LISTACURS_H_INCLUDED
#define LISTACURS_H_INCLUDED
#include "Processo.h"
typedef struct{
	int prox, ant;
	Processo info;
} TLCItem;
typedef struct{
	int primeiro, ultimo;
	TLCItem *items;
	int sz;
} TListaCurs;
void TLCInicializar(TListaCurs *lc,unsigned int n);
int TLCSize(TListaCurs *lc);
int TLCInsere(TListaCurs *lc);
int TLCRetirarPrimeiro(TListaCurs *lc);
int TLCRetirarUltimo(TListaCurs *lc);
void TLCImprimir(TListaCurs *lc);
#endif
*/
/*
#include "ListaCurs.h"
int main(void)
{
	int i;
	srand(time(NULL));
	TListaCurs lista;
	TLCInicializar(&lista,10);
	TLCImprimir(&lista);
	printf("\nSIZE = %d\n",TLCSize(&lista));
	for (i = 0; i < 10; i++) {
		TLCInsere(&lista);
	}
	TLCImprimir(&lista);
	printf("\nSIZE = %d\n",TLCSize(&lista));
	TLCRetirarUltimo(&lista);
	TLCImprimir(&lista);
	printf("\nSIZE = %d\n",TLCSize(&lista));
	TLCRetirarPrimeiro(&lista);
	TLCImprimir(&lista);
	printf("\nSIZE = %d\n",TLCSize(&lista));
	TLCDestruir(&lista);
	TLCImprimir(&lista);
	printf("\nSIZE = %d\n",TLCSize(&lista));
	return 0;
}
*/

#include "ListaCurs.h"
#include "ListaEncDupla.h"
#define inFile "input.dat"
#define outFile "output.dat"
int lerInput(int *tam, int *tipo, int *num, int **Op, int **Qt){
	int i;
	FILE* input;
	if((input = fopen(inFile,"r")) != NULL){
		fscanf(input,"%d\n%d\n%d\n",tam,tipo,num);
		*Op = (int*)malloc(sizeof(int)*(*num));
		*Qt = (int*)malloc(sizeof(int)*(*num));
		for(i = 0; i < *num;i++){
			fscanf(input,"%d %d\n",&(*Op)[i],&(*Qt)[i]);
		}
		fclose(input);
		return 1;
	}
	else{
		return 0;
	}


}
double mainListaCurs(TListaCurs *tlc,int tam, int num,int *Op,int *Qt){
	clock_t inicio, fim;
	int i, j;
	TLCInicializar(tlc,tam);
	for(i = 0;i<num;i++){
		switch(Op[i]){
			case 0:
				inicio = clock();
				for(j = 0; j < Qt[i]; j++){
					TLCInsere(tlc);
				}
				fim = clock();

				break;
			case 1:
				for(j = 0; j < Qt[i]; j++){
					TLCInsere(tlc);
				}
				inicio = clock();
				for(j = 0; j < Qt[i] - 1; j++){

					TLCRetirarPrimeiro(tlc);
				}
				fim = clock();
				break;
		}
	}
	return ((double)fim-inicio)/(CLOCKS_PER_SEC);
}
double mainListaEnc(TListaEnc tle,int  num,int *Op,int *Qt){
	clock_t inicio,fim;
	int i, j;
	 
	LEDInicializar(&tle);
	for(i = 0;i<num;i++){
		switch(Op[i]){
			case 0:
				inicio = clock();
				for(j = 0; j < Qt[i]; j++){
					LEDInsere(&tle);
				}
				fim = clock();
				break;
			case 1:
				for(j = 0; j < Qt[i]; j++){
					LEDInsere(&tle);
				}
				inicio = clock();
				for(j = 0; j < Qt[i]; j++){
					LEDRetirarPrimeiro(&tle);
				}
				fim = clock();
				break;
		}
	}
	return ((double)fim-inicio)/(CLOCKS_PER_SEC);
}
int QuantosTestesJaFeitos(){
	char ch;
	int lines = 0;
	FILE *output;
	if((output = fopen(outFile,"r"))!=NULL){
		while(!feof(output)){
			ch = fgetc(output);
			if(ch == '\n'){
				lines++;
			}
		}
		fclose(output);
	}
	else{
	}
	return lines;
}
int EscreverOutput(double TempoCurs, double TempoEnc){
	int lines = QuantosTestesJaFeitos();
	FILE *output;
	if((output = fopen(outFile,"a")) != NULL){
		if(TempoEnc == 0.0){
			fprintf(output,"%d LED %lf\n",lines+1,TempoEnc);
		}
		else if(TempoCurs == 0.0){
			fprintf(output,"%d LC %lf\n",lines+1,TempoCurs);
		}
		else{
			fprintf(output,"%d %lf %lf\n",lines+1,TempoCurs,TempoEnc);
		}
		return 1;
	}
	else{
		return 0;
	}
	

}
int main(void)
{
	double TempoCurs = 0.0, TempoEnc = 0.0;
	int tamDaLista, tipoDaLista, numOperacoes, *Op, *Qt;
	TListaCurs tlc; 
	TListaEnc tle;

	srand(time(NULL));
	if(!lerInput(&tamDaLista,&tipoDaLista,&numOperacoes,&Op,&Qt)){
		printf("Erro! Nao existe input.dat\n");
	}
	if(tipoDaLista == 0){
		TempoCurs = mainListaCurs(&tlc,tamDaLista,numOperacoes,Op,Qt);
	}
	else if(tipoDaLista == 1){
		TempoEnc = mainListaEnc(tle,numOperacoes,Op,Qt);
		
	}
	else{
		TempoCurs = mainListaCurs(&tlc,tamDaLista,numOperacoes,Op,Qt);
		TempoEnc = mainListaEnc(tle,numOperacoes,Op,Qt);
	}
	LEDDestruir(&tle);
	TLCDestruir(&tlc); //A SER ESTUDADO

	if(!EscreverOutput(TempoCurs,TempoEnc)){
		printf("Erro! Nao tem como escrever em output.dat\n");
	}
	return 0;
}

