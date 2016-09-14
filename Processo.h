#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED
#include <stdio.h>	/* printf() */
#include <stdlib.h>	/* srand(), rand() */
#include <time.h>	/* struct tm, localtime(), time(), difftime(), asctime() */

typedef struct tm Horario;	//Definindo Horario a partir da struct tm
typedef struct {
	unsigned int PID;	//ID do processo, nao sendo possivel negativo
	Horario criadoEm;	//Quando o processo foi criado
	unsigned char prioridade; //Prioridade do processo podendo variar entre [1,5]
} Processo;

int InicializarProcesso(Processo *p); //Inicializa cada variavel em um processo
void ImprimeProcesso(Processo p); //Funçao que imprime as informacoes do processo

//Setters

void SetPID(Processo *p,unsigned int PID); //Funçao para definir um novo valor de PID(process identifier) de um processo
void SetCriadoEm(Processo *p,Horario horas); //Funçao para definir um novo horario de criacao de um processo
int SetPrioridade(Processo *p,unsigned char prioridade); //Funçao para definir uma nova prioridade de um processo

//Getters

unsigned int GetPID(Processo p); //Funcao para obter PID de um dado processo
Horario GetCriadoEm(Processo p); //Funcao para obter o horario de criacao de um dado processo
unsigned char GetPrioridade(Processo p); //Funcao para obter a prioridade de um dado processo

#endif
