#include "ListaEncDupla.h"

//*********************************************\/\/\/\/ INICIALIZA/IMPRIMIR \/\/\/\/*********************************************
void LEDInicializar(TListaEnc *le){				//Função que inicializa Lista Duplamente Encadeada
	le->primeiro = le->ultimo = (LEDItem*)malloc(sizeof(LEDItem));	//Inicializa ponteiros primeiro e ultimo da lista para uma mesma posição na memoria de tamanho LEDItem vazia
	le->primeiro->prox = le->primeiro->ant = le->ultimo->ant = le->ultimo->prox = NULL; //define os anteriores e os proximos da primeira e ultima posição para NULL evitando lixo de memória
	//InicializarProcesso(&le->primeiro->info);
	le->sz = 0; //define tamanho da lista como 0
}
void LEDImprimir(TListaEnc le){					//Função que imprime a lista
	LEDItem *i = NULL;					//Ponteiro que ira percorrer a lista
	for (i = le.primeiro; i != le.ultimo; i = i->prox) {	//Percorre toda a lista ignorando o ultimo item( que aponta para um espaço não inicializado)
		ImprimeProcesso(i->info);			//Imprime cada processo isoladamente
	}
}
int LEDSize(TListaEnc le){					//Função que retorna sz(Tamanho atual da lista)
	return le.sz;
}
//*********************************************\/\/\/\/ GETTERS/SETTERS \/\/\/\/*********************************************
int LEDInsere(TListaEnc *le){					//Função que insere item em sua devida posição na ordem crescente
	LEDItem *i = NULL;
	if(le->primeiro == NULL && le->ultimo == NULL){		//Falha se a lista for destruido ou nao inicializada
		return 0;
	}
	LEDItem *novoItem = (LEDItem*)malloc(sizeof(LEDItem));	//Ponteiro para o novo ultimo
	InicializarProcesso(&novoItem->info);			//Inicializa antigo ultimo que estava vazio
	if(le->ultimo->ant != NULL){				//Sinonimo de LEDSize(le) == 0
		if((abs(novoItem->info.PID - le->ultimo->ant->info.PID) >= abs(novoItem->info.PID - le->primeiro->info.PID))){
			//Percorrer do primeiro ate a pos esperada
			for(i = le->primeiro; (i->info.PID < novoItem->info.PID) && (i != le->ultimo); i = i->prox){}
			if(i->info.PID == novoItem->info.PID){	//Se PID nao é unico gerar novos valores para Processo de novoItem
				free(novoItem);                     //Libera o espaco do novoItem
				return  LEDInsere(le);              //chama a função LEDInsere()

			}
			novoItem->prox = i;
			novoItem->ant = i->ant;
			if(i->ant != NULL){ //confirma que i não é o primeiro
				i->ant->prox = novoItem;
			}
			else{
				le->primeiro = novoItem;
			}
			i->ant = novoItem;
		}
		else{
			//Percorrer do ultimo ate a pos esperada
			for(i = le->ultimo->ant;(i->info.PID > novoItem->info.PID) && (i->ant != NULL); i = i->ant){} //percorrendo a lista de tras para frente, procurando a posição onde o novo item será maior que i
			if(i->info.PID == novoItem->info.PID){	//Se PID nao é unico gerar novos valores para Processo de novoItem
				free(novoItem);                 //Libera o espaco do novoItem
				return  LEDInsere(le);          //chama a função LEDInsere()
			}
			if(i->ant == NULL && i->info.PID > novoItem->info.PID){  //se a primeira posição é maior que o novo item
				novoItem->ant = i->ant;             //Colocando novo item na primeira posicao primeira posição
				novoItem->prox = i;                 //Colocando novo item na primeira posicao primeira posição
				i->ant = novoItem;                  //Colocando novo item na primeira posicao primeira posição
				le->primeiro = novoItem;            //Colocando novo item na primeira posicao primeira posição
			}
			else{
				novoItem->prox = i->prox;           //Colocando novo item qualquer outra posição
				if(i->prox != NULL){                //verificando que i não é o ultimo
					i->prox->ant = novoItem;    //Colocando novo item qualquer outra posição   
				}
				novoItem->ant = i;                  //Colocando novo Item na ultima posição
				i->prox = novoItem;                 //Colocando novo Item na ultima posição
			}
		}
	}
	else{  //Se caso não existir nenhum item na lista
		novoItem->prox = le->ultimo;      //Colocando novoItem como primeiro e unico item da lista
		novoItem->ant = NULL;             //Colocando novoItem como primeiro e unico item da lista
		le->primeiro = novoItem;          //Colocando novoItem como primeiro e unico item da lista
		le->ultimo->ant = novoItem;       //Colocando novoItem como primeiro e unico item da lista
	}
	
	le->sz++;						//Incrementa tamanho da lista

	return 1;
}
int LEDRetirarPrimeiro(TListaEnc *le){				//Funçao que retira menor item da lista
	if(le->primeiro == le->ultimo){	//sinonimo de LEDSize(le) == 0 (Lista vazia)
		return 0;
	}
	le->primeiro = le->primeiro->prox;	//Move ponteiro primeiro para o prox na lista
	free(le->primeiro->ant);		//Libera espaço do antigo primeiro
	le->primeiro->ant = NULL;		//Aponta ponteiro ant do novo primeiro item para NULL
	le->sz--;				//Decrementa o tamanho da lista
	return 1;
}
int LEDRetirarUltimo(TListaEnc *le){				//Função que retira maior item da lista
	if(le->primeiro == le->ultimo){	           //sinonimo de LEDSize(le) == 0
		return 0;
	}
	le->ultimo = le->ultimo->ant;		//Move ponteiro ultimo para o ant na lista
	free(le->ultimo->prox);			//Libera espaço do antigo ultimo
	le->ultimo->prox = NULL;		//Aponta ponteiro prox do novo ultimo item para NULL
	le->sz--;				//Decrementa o tamanho da lista
	return 1;

}
//*********************************************\/\/\/\/ DESTRUIR \/\/\/\/*********************************************
void LEDDestruir(TListaEnc *le){				//Função que Destroi cada item da lista, zera o sz e "reseta" os ponteiros primeiro e ultimo
	LEDItem *i = NULL, *j = NULL;				//Ponteiros que irao percorrer a lista destruindo-a
	for (i = le->primeiro; j != NULL; i = j) {
		j = i->prox;					//Necessario para nao perder a referencia para o espaço de memoria
		free(i);					//Libera espaço de memoria
	}
	le->primeiro = le->ultimo = NULL;                       //destroi o ultimo item
	le->sz = 0;                                             //tamanho da lista recebe 0
}
