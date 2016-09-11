#include "Processo.h"
//Inicializa cada variavel de um processo
int InicializarProcesso(Processo *p){
	const time_t tempo = time(NULL); 		//segundos desde Jan 1, 1970 00:00
	unsigned int PID = rand();			//gerando PID aleatoriamente. [0,RAND_MAX]
	unsigned char prioridade = rand()%5 + 1;	//gerando prioridade aleatoriamente. [1,5]
	Horario *hora_local = localtime(&tempo);	//captura do localtime do pc
	SetCriadoEm(p,*hora_local);
	SetPID(p,PID);
	if(!SetPrioridade(p,prioridade)){
		return 0;
	}
	return 1;
}
//Funçao que imprime info do processo passado como parametro
void ImprimeProcesso(Processo p){
	char buffer[8];
	Horario h = GetCriadoEm(p);
	strftime(buffer,8,"%R",&h);	// Formatando tempo para HH:MM dentro da string buffer
	printf("PID:%u\nPrioridade: %u\nHorario de criação: %s\n",GetPID(p),GetPrioridade(p),buffer);
}
//Funçao para definir um novo valor de PID(process identifier) de um processo passado
void SetPID(Processo *p,unsigned int PID){
	p->PID = PID;
}
//Funçao para definir um novo horario de criacao de um processo passado
void SetCriadoEm(Processo *p,Horario horas){
	p->criadoEm = horas;
}
//Funçao para definir uma nova prioridade de um processo passado
int SetPrioridade(Processo *p,unsigned char prioridade){
	if(prioridade > 5 || prioridade == 0){	//prioridade: [1,5]
		return 0;
	}
	p->prioridade = prioridade;
	return 1;
}
//Funcao para obter PID de um dado processo
unsigned int GetPID(Processo p){
	return p.PID;
}
//Funcao para obter o horario de criacao de um dado processo
Horario GetCriadoEm(Processo p){
	return p.criadoEm;
}
//Funcao para obter a prioridade de um dado processo
unsigned char GetPrioridade(Processo p){
	return p.prioridade;
}
