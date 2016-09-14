//*********************************************\/\/\/\/ TESTES \/\/\/\/*********************************************

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
/* Testando Lista Duplamente Encadeada

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
/* Testando Lista de Cursores
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

//*********************************************\/\/\/\/ FUNÇÕES PRINCIPAIS \/\/\/\/*********************************************

#include "ListaCurs.h"		/* TLCInicializar(), TLCDestruir(), TLCSize(), TLCInsere(), TLCRetirarPrimeiro() */
#include "ListaEncDupla.h"	/* LEDInicializar(), LEDDestruir(), LEDSize(), LEDInsere(), LEDRetirarPrimeiro() */
#define inFile "input.dat"	//Arquivo de entrada
#define outFile "output.dat"	//Arquivo de saida

//Lê Arquivo de entrada
int lerInput(int *tam, int *tipo, int *num, int **Op, int **Qt){
	int i;
	FILE* input;
	if((input = fopen(inFile,"r")) != NULL){	//Confere existencia
		fscanf(input,"%d\n%d\n%d\n",tam,tipo,num);	//Obtem dados do arquivo atribuindo-os as variaveis tam, tipo e num
		*Op = (int*)malloc(sizeof(int)*(*num));			///Aloca espaço suficiente para o numero(num) de instruçoes no arquivo
		*Qt = (int*)malloc(sizeof(int)*(*num));			//
		for(i = 0; i < *num;i++){				//
			fscanf(input,"%d %d\n",&(*Op)[i],&(*Qt)[i]);	//Atribui valor obtido para cada instruçao no arquivo
		}
		fclose(input);	//Fecha apropriadamente o arquivo
		return 1;
	}
	else{
		return 0;
	}


}
//Função que ira executar as instruçoes especificadas no arquivo de entrada e calcular o tempo de execução
double mainListaCurs(TListaCurs *tlc,int tam, int num,int *Op,int *Qt){
	clock_t inicio = 0, fim = 0;		//Variaveis usadas para calcular tempo de execução
	int i, j;
	TLCInicializar(tlc,tam);	//Inicializa a lista de cursores de acordo com tamanho especificado no arquivo de entrada
	for(i = 0;i<num;i++){
		switch(Op[i]){
			case 0:		//Se instrução é de inserção
				if(!inicio){ //Captura do tempo inicial
                                    inicio = clock();
                                }
				for(j = 0; j < Qt[i]; j++){
					TLCInsere(tlc);	//Insere item na lista
				}
				fim = clock();	//Captura do tempo final

				break;
			case 1:		//Se instrução é de remoção
				for(j = 0; j < Qt[i]; j++){
					TLCInsere(tlc);	//Insere item na lista
				}
				if(!inicio){ //Captura do tempo inicial
                                    inicio = clock();
                                }
				for(j = 0; j < Qt[i] - 1; j++){

					TLCRetirarPrimeiro(tlc);	//Remove item da lista
				}
				fim = clock();	//Captura do tempo final

				break;
		}
	}
	return ((double)fim-inicio)/(CLOCKS_PER_SEC);	//Converte o tempo, que é calculado em clocks, para segundos
}
//Função que ira executar as instruçoes especificadas no arquivo de entrada e calcular o tempo de execução
double mainListaEnc(TListaEnc tle,int  num,int *Op,int *Qt){
	clock_t inicio,fim;		//Variaveis usadas para calcular tempo de execução
	int i, j;

	LEDInicializar(&tle);	//Inicializa a lista Duplamente Encadeada de acordo com tamanho especificado no arquivo de entrada
	for(i = 0;i<num;i++){
		switch(Op[i]){
			case 0:		//Se instrução é de inserção
				inicio = clock();	//Captura do tempo inicial
				for(j = 0; j < Qt[i]; j++){
					LEDInsere(&tle);	//Insere item na lista
				}
				fim = clock();	//Captura do tempo final
				break;
			case 1:		//Se instrução é de remoção

				for(j = 0; j < Qt[i]; j++){
					LEDInsere(&tle);	//Insere item na lista
				}
				inicio = clock();	//Captura do tempo inicial
				for(j = 0; j < Qt[i]; j++){
					LEDRetirarPrimeiro(&tle);	//Remove item da lista
				}
				fim = clock();	//Captura do tempo final

				break;
		}
	}
	return ((double)fim-inicio)/(CLOCKS_PER_SEC);	//Converte o tempo, que é calculado em clocks, para segundos
}
//Confere quantos testes estao especificados no arquivo de saida
int QuantosTestesJaFeitos(){
	char ch;	//iteradora
	int lines = 0;	//Num de testes
	FILE *output;	//Ponteiro para arquivo de saida
	if((output = fopen(outFile,"r"))!=NULL){	//Se arquivo nao existir retorna valor inicial de testes
		while(!feof(output)){			//Percorre ate o final do arquivo
			ch = fgetc(output);		
			if(ch == '\n'){			//Captura quebras de linha
				lines++;		//Incrementa numero de testes
			}
		}
		fclose(output);				//Fecha arquivo apropriadamente
	}
	return lines;		//retorna numero de testes
}
//Escreve no arquivo de saida
int EscreverOutput(double TempoCurs, double TempoEnc){
	int lines = QuantosTestesJaFeitos();	//Armazena numero de testes em variavel
	FILE *output;	//Ponteiro para arquivo de saida
	if((output = fopen(outFile,"a")) != NULL){	//Testa permissao para alteração
		if(TempoEnc == 0.0 && TempoCurs != 0.0){	//Confere se houve alguma operação feita por lista duplamente encadeada apenas
			fprintf(output,"Teste numero %d\t- Tempo Lista Cursores: %lf\n",lines+1,TempoCurs);	//Escreve no arquivo de saida
		}
		else if(TempoCurs == 0.0 && TempoEnc != 0.0){ //Confere se houve alguma operação feita por lista de cursores apenas
			fprintf(output,"Teste numero %d\t- Tempo Lista Duplamente Encadeada: %lf\n",lines+1,TempoEnc);	//Escreve no arquivo de saida
		}
		else{
			fprintf(output,"Teste numero %d\t- Tempo Lista Cursores: %lf - Tempo Lista Duplamente Encadeada: %lf\n",lines+1,TempoCurs,TempoEnc);	//Escreve no arquivo de saida
		}
		fclose(output);	//Fecha arquivo apropriadamente
		return 1;
	}
	else{
		return 0;
	}


}
//Função Principal
int main(void)
{
	double TempoCurs = 0.0, TempoEnc = 0.0;		//Declara variaveis que armazenam o tempo decorrido nas operações requisitadas no arquivo de entrada
	int tamDaLista, tipoDaLista, numOperacoes, *Op, *Qt;	//Declara variaveis que armazenem info do arquivo de entrada
	TListaCurs tlc;	//Declara lista de cursores
	TListaEnc tle;	//Declara lista duplamente encadeada

	srand(time(NULL));	//Determina semente para gerar numero aleatorio
	if(!lerInput(&tamDaLista,&tipoDaLista,&numOperacoes,&Op,&Qt)){	//Confere se a função lerInput foi bem sucedida
		printf("Erro! Nao existe input.dat\n");
	}
	if(tipoDaLista == 0){	//Se a lista requisitada for lista de cursores
		TempoCurs = mainListaCurs(&tlc,tamDaLista,numOperacoes,Op,Qt);
		TLCDestruir(&tlc); //Destroi lista de forma segura
	}
	else if(tipoDaLista == 1){	//Se a lista requisitada for lista duplamente encadeada
		TempoEnc = mainListaEnc(tle,numOperacoes,Op,Qt);
		LEDDestruir(&tle); //Destroi lista de forma segura
	}
	else{	//Se nao for requisitado nenhuma lista especifica
		TempoCurs = mainListaCurs(&tlc,tamDaLista,numOperacoes,Op,Qt);
		TempoEnc = mainListaEnc(tle,numOperacoes,Op,Qt);
		TLCDestruir(&tlc); //Destroi lista de forma segura
		LEDDestruir(&tle); //Destroi lista de forma segura
	}


	
	if(!EscreverOutput(TempoCurs,TempoEnc)){	//Confere se a função EscreverOutput foi bem sucedida
		printf("Erro! Nao tem como escrever em output.dat\n");
	}
	return 0;
}

