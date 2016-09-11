#include "ListaCurs.h"
//Função Inicializadora de Lista Encadeada por Cursores
void TLCInicializar(TListaCurs *lc,unsigned int n){
	unsigned int i;
	lc->primeiro = lc->ultimo = 0;
	lc->items = (TLCItem *)malloc(sizeof(TLCItem)*n);	//Utiliza-se alocação dinamica pois n pode ser um numero muito grande, levando a lista a n caber fora do heap
	for (i = 1; i < n - 1; i++) {				//Em uma lista encadeada por cursores os cursores dos items de valores "apontam" para o item seguinte na ordem crescente de PID
		lc->items[i].prox = i + 1;			//O cursor prox do maior item de valor "aponta" para o menor item vazio
		lc->items[i].ant = i - 1;			//O cursor ant do menor item vazio "aponta" para o maior item de valor
	}							//O cursor ant do menor item de valor tem valor -1
	lc->items[0].ant = -1;					//O cursor prox do maior item vazio tem valor -1
	lc->items[n-1].ant = n-2;
	lc->items[0].prox = 1;
	lc->items[n-1].prox = -1;

	lc->sz = 0;	//o inteiro sz armazena o tamanho atual da lista (numero de itens com valor)
}
//Função Destruidora de Lista Encadeada por Cursores
void TLCDestruir(TListaCurs *lc){
	lc->primeiro = lc->ultimo = lc->sz = 0;
	free(lc->items);
	lc->sz = 0;
}
//Retorna Tamanho atual da lista encadeada por cursores
int TLCSize(TListaCurs *lc){
	return lc->sz;
}
//Função que insere item na lista encadeada por cursores, mantendo-a em ordem crescente
int TLCInsere(TListaCurs *lc){
	int i = 0, velho_ultimo_de_valor = lc->items[lc->ultimo].ant,
	    novo_ultimo = lc->items[lc->ultimo].prox;	//no ultimo item do vetor vai receber -1
	InicializarProcesso(&lc->items[lc->ultimo].info);
	if(abs((lc->items[lc->ultimo].info.PID) - (lc->items[velho_ultimo_de_valor].info.PID)) >= abs((lc->items[lc->ultimo].info.PID) - (lc->items[lc->primeiro].info.PID))){
		i = lc->primeiro;
		while(i != lc->ultimo){		//Se tiver alguem que é maior que o novo valor e (lc->primeiro != lc->ultimo)
			if(lc->items[lc->ultimo].info.PID < lc->items[i].info.PID){
				if(i == lc->primeiro){		//Se o primeiro item que é maior do que o novo. Entao o novo se tornara o primeiro item da lista
					lc->primeiro = lc->ultimo;	
				}
				lc->items[lc->ultimo].prox = i;
				lc->items[lc->ultimo].ant = lc->items[i].ant;
				if(lc->items[i].ant != -1){		//o anterior do primeiro é -1 e item[-1] esta fora do escopo
					lc->items[lc->items[i].ant].prox = lc->ultimo;	
				}
				lc->items[i].ant = lc->ultimo;
				lc->items[velho_ultimo_de_valor].prox = novo_ultimo;
				if(novo_ultimo == -1){
					lc->ultimo = velho_ultimo_de_valor;
					printf("linha 50 ultimo recebe: %d\n",lc->ultimo);
					lc->sz++;
					return 0;
				}
				lc->ultimo = novo_ultimo;
				printf("linha 55 ultimo recebe: %d\n",lc->ultimo);
				lc->items[novo_ultimo].ant = velho_ultimo_de_valor;
				lc->sz++;
				return 1;
			}
			else if(lc->items[lc->ultimo].info.PID == lc->items[i].info.PID){
				return TLCInsere(lc);
			}
			i = lc->items[i].prox;
		}
		//Se é a primeiro inserção na lista
		//E/Ou se o novo valor é maior do que todos os items da lista / i == lc->ultimo, que é o novo item de valor
		if(novo_ultimo == -1){
			lc->sz++;
			return 0;
		}
		lc->ultimo = novo_ultimo;
	}
	else{
		i = velho_ultimo_de_valor;
		//Se for uma lista vazia ou se lc->ultimo for maior q o maior item da lista
		if((i == -1) || (lc->items[lc->ultimo].info.PID > lc->items[i].info.PID)){
			if(novo_ultimo == -1){
				lc->sz++;
				return 0;
			}
			lc->ultimo = novo_ultimo;
			lc->sz++;
			return 1;
		}
		while(i != -1){	//percorrer do lc->items[lc->ultimo].ant ate o lc->primeiro
			//printf("Entrou no loop!\n");
			if(lc->items[lc->ultimo].info.PID == lc->items[i].info.PID){
				return TLCInsere(lc);
			}
			else if(lc->items[lc->ultimo].info.PID > lc->items[i].info.PID){
				//colocar depois do lc->item[i]
				lc->items[lc->ultimo].ant = i;
				lc->items[lc->ultimo].prox = lc->items[i].prox;
				lc->items[lc->items[i].prox].ant = lc->ultimo;
				lc->items[i].prox = lc->ultimo;
				lc->items[velho_ultimo_de_valor].prox = novo_ultimo;
				if(novo_ultimo == -1){
					lc->ultimo = velho_ultimo_de_valor;
					lc->sz++;
					return 0;
				}
				lc->ultimo = novo_ultimo;
				lc->items[novo_ultimo].ant = velho_ultimo_de_valor;
				lc->sz++;
				return 1;
				
			}
			i = lc->items[i].ant;
		}
		//i == -1
		if(lc->items[lc->ultimo].info.PID < lc->items[lc->primeiro].info.PID){
			//colocar antes do primeiro
			i = lc->primeiro;
			lc->primeiro = lc->ultimo;
			lc->items[lc->ultimo].prox = i;
			lc->items[lc->ultimo].ant = -1;
			lc->items[i].ant = lc->primeiro;
			lc->items[velho_ultimo_de_valor].prox = novo_ultimo;
			if(novo_ultimo == -1){
				lc->ultimo = velho_ultimo_de_valor;
				lc->sz++;
				return 0;
			}
			lc->ultimo = novo_ultimo;
			lc->items[novo_ultimo].ant = velho_ultimo_de_valor;
		}
	}
	lc->sz++;
	return 1;
}
//Função que remove item de menor PID da lista encadeada por cursores
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
//Função que remove item de maior PID da lista encadeada por cursores
int TLCRetirarUltimo(TListaCurs *lc){
	if(lc->primeiro == lc->ultimo){ 	//Sinonimo para TLCSize(lc) == 0
		return 0;
	}
	printf("%d\n",lc->ultimo);
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
//Função que imprime cada item contido na lista encadeada por cursores
void TLCImprimir(TListaCurs *lc){
	int i, j = lc->primeiro;
	for (i = 0; i != TLCSize(lc); i++) {
		ImprimeProcesso(lc->items[j].info);
		j = lc->items[j].prox;
	}

}
