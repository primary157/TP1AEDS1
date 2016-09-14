#include "Processo.h"

//**************************\/\/\/\/  INICIALIZAR  \/\/\/\/******************************************

//Inicializa cada variavel de um processo
int InicializarProcesso(Processo *p){
	const time_t tempo = time(NULL); 		//segundos desde Jan 1, 1970 00:00
	unsigned int PID = rand();			//gerando PID aleatoriamente. [0,RAND_MAX]
	unsigned char prioridade = rand()%5 + 1;	//gerando prioridade aleatoriamente. [1,5]
	Horario *hora_local = localtime(&tempo);	//captura do localtime do pc
	SetCriadoEm(p,*hora_local);                 //chama a Funçao para definir um novo horario de criacao de um processo
	SetPID(p,PID);                              //chama a funcao para definir o ID
	if(!SetPrioridade(p,prioridade)){           //Cheka a prioridade para ver se esta aceitavel acima de 0 e menor que 6
		return 0;
	}
	return 1;
}

//*******************************\/\/\/\/  IMPRIMIR  \/\/\/\/*******************************************

//Funçao que imprime as informacoes do processo
void ImprimeProcesso(Processo p){
	char buffer[8];
	Horario h = GetCriadoEm(p);  //cria uma variavel do tipo tm e armazena o tempo que o processo foi criado
	strftime(buffer,8,"%R",&h);	// Formatando tempo para HH:MM dentro da string buffer
	printf("PID:%u\nPrioridade: %u\nHorario de criação: %s\n",GetPID(p),GetPrioridade(p),buffer);
}


//**************************\/\/\/\/  SETTERS/MODIFICAR  \/\/\/\/**********************************

//Funçao para definir um novo valor de PID(process identifier) de um processo passado
void SetPID(Processo *p,unsigned int PID){
	p->PID = PID;
}

//Funçao para definir um novo horario de criacao de um processo
void SetCriadoEm(Processo *p,Horario horas){
	p->criadoEm = horas;                        //p->criadoEm recebe as horas do computador quando o processo foi criado
}

//Funçao para definir uma nova prioridade de um processo
int SetPrioridade(Processo *p,unsigned char prioridade){
	if(prioridade > 5 || prioridade == 0){	//checa se a nova prioridade esta entre: [1,5]
		return 0;
	}
	p->prioridade = prioridade;             //se estiver entre [1,5] armazena a nova prioridade
	return 1;
}


//**************************\/\/\/\/  GETTERS/OBTER  \/\/\/\/********************************************

//Funcao para obter PID de um dado processo
unsigned int GetPID(Processo p){
	return p.PID;                   //retorna o ID do processo
}
//Funcao para obter o horario de criacao de um dado processo
Horario GetCriadoEm(Processo p){
	return p.criadoEm;                   //retorna a hora de criacao do processo
}
//Funcao para obter a prioridade de um dado processo
unsigned char GetPrioridade(Processo p){
	return p.prioridade;                 //retorna a prioridade do processo
}
