#ifndef PROCESSO_H_INCLUDED
#define PROCESSO_H_INCLUDED
#include <stdio.h>	/* printf */
#include <stdlib.h>	/* srand(), rand() */
#include <time.h>	/* struct tm, localtime(), time(), difftime(), asctime() */
typedef struct tm Horario;	//Definindo Horario a partir da struct tm
typedef struct {
	unsigned int PID;	//ProcessID
	Horario criadoEm;	//Quando o processo foi criado
	unsigned char prioridade; //[1,5] Prioridade do processo
} Processo;
int InicializarProcesso(Processo *p); //Inicializa cada variavel em um processo
void ImprimeProcesso(Processo p); //Printar processo
//Setters
void SetPID(Processo *p,unsigned int PID);
void SetCriadoEm(Processo *p,Horario horas);
int SetPrioridade(Processo *p,unsigned char prioridade);
//Getters
unsigned int GetPID(Processo p);
Horario GetCriadoEm(Processo p);
unsigned char GetPrioridade(Processo p);
#endif
