#include "ListaEncDupla.h"
void LEDInicializar(TListaEnc *le){				//Função que inicializa Lista Duplamente Encadeada
	le->primeiro = le->ultimo = (LEDItem*)malloc(sizeof(LEDItem));	//Inicializa ponteiros primeiro e ultimo da lista para uma mesma posição na memoria de tamanho LEDItem vazia
	le->primeiro->prox = le->primeiro->ant = le->ultimo->ant = le->ultimo->prox = NULL;	
	//InicializarProcesso(&le->primeiro->info);
	le->sz = 0;
}
int LEDSize(TListaEnc le){					//Função que retorna sz(Tamanho atual da lista)
	return le.sz;
}
int LEDInsere(TListaEnc *le){					//Função que insere item em sua devida posição na ordem crescente
	if(le->primeiro == NULL && le->ultimo == NULL){		//Falha se a lista for destruido ou nao inicializada
		return 0;
	}
	LEDItem *novoItem = (LEDItem*)malloc(sizeof(LEDItem));	//Ponteiro para o novo ultimo
	InicializarProcesso(&le->ultimo->info);			//Inicializa antigo ultimo que estava vazio
	//if(abs(le->ultimo->info.PID - le->ultimo->ant->info.PID) < abs(le->ultimo->info.PID - le->primeiro->info.PID)){
	
	//}
	novoItem->ant = le->ultimo;				///Substitui antigo ultimo pelo novoItem vazio criado
	novoItem->prox = le->ultimo->prox;			//
	le->ultimo->prox = novoItem;				//
	le->ultimo = novoItem;					//
	le->sz++;						//Incrementa tamanho da lista
	return 1;
}
int LEDRetirarPrimeiro(TListaEnc *le){				//Funçao que retira menor item da lista
	if(le->primeiro == le->ultimo){	//sinonimo de LEDSize(le) == 0
		return 0;
	}
	le->primeiro = le->primeiro->prox;	//Move ponteiro primeiro para o prox na lista
	free(le->primeiro->ant);		//Libera espaço do antigo primeiro
	le->primeiro->ant = NULL;		//Aponta ponteiro ant do novo primeiro item para NULL
	le->sz--;				//Decrementa o tamanho da lista
	return 1;
}
int LEDRetirarUltimo(TListaEnc *le){				//Função que retira maior item da lista
	if(le->primeiro == le->ultimo){	//sinonimo de LEDSize(le) == 0
		return 0;
	}
	le->ultimo = le->ultimo->ant;		//Move ponteiro ultimo para o ant na lista
	free(le->ultimo->prox);			//Libera espaço do antigo ultimo
	le->ultimo->prox = NULL;		//Aponta ponteiro prox do novo ultimo item para NULL
	le->sz--;				//Decrementa o tamanho da lista
	return 1;

}
void LEDImprimir(TListaEnc le){					//Função que imprime a lista
	LEDItem *i = NULL;					//Ponteiro que ira percorrer a lista
	for (i = le.primeiro; i != le.ultimo; i = i->prox) {	//Percorre toda a lista ignorando o ultimo item( que aponta para um espaço não inicializado)
		ImprimeProcesso(i->info);			//Imprime cada processo isoladamente
	}
}
void LEDDestruir(TListaEnc *le){				//Função que Destroi cada item da lista, zera o sz e "reseta" os ponteiros primeiro e ultimo
	LEDItem *i = NULL, *j = NULL;				//Ponteiros que irao percorrer a lista destruindo-a
	for (i = le->primeiro; j != NULL; i = j) {
		j = i->prox;					//Necessario para nao perder a referencia para o espaço de memoria
		free(i);					//Libera espaço de memoria
	}
	le->primeiro = le->ultimo = NULL;
	le->sz = 0;
}
