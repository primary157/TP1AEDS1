---
abstract: |
    Este trabalho se baseia na simulação de uma cadeia de processos de um
    sistema operacional, desenvolvido através de dois tipos abstratos de
    dados( e ). Como instruído pela Doutora Thais Regina de Moura Braga
    Silva. Com o objetivo de descobrir qual o melhor TAD para utilizar na
    manipulação dos processos, foram feitas algumas sequências de testes
    entre os dois Tipos.Para concluir o objetivo do trabalho,foram criadas e
    usadas algumas bibliotecas com a intenção de obter o melhor
    desenvolvimento. O método de comparação se dá por meio do cálculo do
    tempo gasto de uma determinada ação para um TAD específico. Todos
    arquivos estão disponibilizados em um [repositório do
    GitHub](https://github.com/primary157/TP1AEDS1.git) com cada etapa do
    processo de criação.
author:
- 'Victor (02658) e Fillipe (02671)'
title: |
    Documentação 1º Trabalho Pratico de Algoritmos e Estrutura de Dados\
    Universidade Federal de Viçosa\
    Campus Florestal\
    Ciência da Computação
---

Tutorial
========

O trabalho totaliza em sua criação três arquivos de cabeçalho (.h),
quatro arquivos de código-fonte(.c) e dois arquivos de texto (.dat) com
o objetivo de descobrir qual o TAD mais veloz para tomar ações
especificas.

Com o intuito de testar suas velocidades, foi proposto pela professora,
uma simulação da cadeia de processos de um sistema operacional. Situação
na qual é necessário remoção de itens com gasto de tempo constante no
final e inicio da lista.

Simulando um processo:
----------------------

O projeto se desenrolou com a criação do Tipo , o qual continha em sua
estrutura: um número de , o em que foi criado e uma .

E funções que permitiam alterar os valores dos campos de sua estrutura
depois de inicializada.

A simulação de um processo foi então possibilitada com a criação dessa
biblioteca.

Criação do TAD Lista Duplamente Encadeada:
------------------------------------------

Após a criação da biblioteca Processo foi necessária a criação do Tipo
Abstrato de Dados Lista Duplamente Encadeada no qual armazenaríamos
itens que por meio de um ponteiro acessariam as informações de seu
respectivo processo e registraríamos sua eficiência.

A possui 2 ponteiros para Item que servem para referenciar a posição de
memória onde o item estão armazenados. Estes por sua vez possuem dois
ponteiros que apontam para o .

Graças a essa estrutura de dados é possível percorrer a a partir do fim
ou do início dependendo de qual sentido for o mais eficaz. Para fazer
uma aproximação de qual é o melhor sentido a se seguir, comparamos a
diferença do valor do processo a ser inserido com os processos
armazenados na ultima e primeira posição da lista. A menor diferença
indica um caminho possivelmente mais curto.

Criação do TAD Lista de Cursores
--------------------------------

Por outro lado criamos um outro TAD de nome que diferente da tem como
estrutura de dados um vetor, que na inicialização da lista é alocado no
heap devido ao seu extenso tamanho e com um tamanho definido.

Esse TAD por utilizar um vetor possui ao invés de ponteiros, variáveis
do tipo inteiro conhecidas como cursores as quais armazenariam o numero
do índice do vetor em que são encontrados o . Em nossa implementação o é
caracterizado por ser o item de menor e o é o próximo item vazio a ser
inicializado na lista. Uma vez que cada item tem em seus cursores a
posição no vetor do próximo item seja ele maior ou um item vazio, caso
esse item seja o ultimo item de valor ou um outro item vazio que não
seja o ultimo da lista. O mesmo ocorre com o que armazenará a posição na
lista do item anterior seja ele um item de menor ou um item vazio, caso
esse seja um item vazio que não seja o item cuja posição é armazenada na
variável ultimo.

Inserção
--------

A inserção nos TADs utilizados se da a partir de funções específicas
para cada TAD (, ), sendo que ambas utilizam lógicas similares com
exceção da origem do item, uma vez que na os itens já estão previamente
alocados na inicialização da lista, o que não ocorre na que utiliza
alocação dinâmica e referenciação por ponteiros para novas posições na
memória dedicadas para cada item inserido.

Nos dois casos a inserção é feita de forma a manter os itens ordenados
em ordem crescente de .

Remoção no inicio e no final
----------------------------

O processo de remoção na é por meio da liberação do espaço de memória
alocado para o item removido e na atribuição de novos valores para os
ponteiros que anteriormente referenciavam tal item.

O processo de remoção na é baseado apenas na alteração da ordem dos
item, de forma atribuir ao item a ser removido uma posição de item
vazio.

Note que não é necessário tirar os valores das variáveis do item ou
liberar um espaço de memória como é feito na outra lista.

Destruindo de forma segura
--------------------------

A destruição das Listas é baseada na liberação da memória alocada
dinamicamente por meio da função *free()* e na atribuição de valores
nulos (0 ou *NULL*) para as variáveis da lista.

input.dat e output.dat
======================

input.dat
---------

O arquivo *input.dat* tem a função de armazenar dados os quais o
programa terá acesso.\
A primeira linha contém o tamanho do vetor para cursores\
A segunda linha define o tipo de TAD a ser usado:

0 - Para TAD com Cursores

1 - Para TAD Duplamente Encadeado tradicional

Outro valor - Para usar os dois TADs\
A terceira linha recebe a quantidades de linhas de operações a ser
feitas\
E a quarta linha em diate é composta pelas ações a ser calculado o tempo
de execução:

0 - Para inserção

1 - Para remoção do inicio

Mais a quantidade de vezes a ser executado\

<span>20em</span>

Obs$^{1}$.:A cada teste de inserção, uma nova lista é criada, calculando
apenas o tempo desta, logo em seguida a lista é destruída de forma
segura.\
Obs$^{2}$.:No caso do teste de retirada, é criada uma nova lista onde é
inserido a quantidade de itens descritos e após inserir ocorre a remoção
a qual terá seu tempo calculado.\

**Exemplo:**

1000

2

2

0 1000

1 500

output.dat
----------

*output.dat* é um arquivo no qual o programa gravará o resultado dos
testes escritos no *input.dat*.\
A linha é composta pelo número do teste juntamente com o tempo que o TAD
ou os TADs demoraram para realizar o teste

Obs.: O tempo mostrado é em segundos\
\
\
**Exemplo:**

Teste numero 15 - Tempo Lista Cursores: 0.003252 - Tempo Lista
Duplamente Encadeada: 0.002810

Makefile
========

Variaveis
---------

-   **LIBS** *Bibliotecas que serão “linkadas” em tempo de compilação*

-   **FILES** *Nome de cada arquivo fonte (.c) a ser compilado*

-   **OBJECTS** *Nome de cada arquivo objeto (.o) gerado a partir de
    cada arquivo fonte (.c)*

-   **EXEC** *Nome do arquivo executável resultante da compilação*

-   **bindir** *Caminho para a pasta onde o executável sera guardado
    apos a instalação*

make
----

Comando que irá desencadear a compilação de todos os arquivos em objetos
e destes em um executável.

make mrproper
-------------

Comando que deleta todos os arquivos resultantes de compilações
anteriores.

make clean
----------

Comando que deleta todos os arquivos temporários criados durante a
compilação.

make install
------------

Comando que irá mover o executável para o diretório armazenado na
variável *bindir*

make uninstall
--------------

Comando que irá deletar o executável anteriormente movido para o
diretório armazenado na variável *bindir* pelo comando “make install”

Processo.h
==========

Typedefs
--------

Typedef struct tm Horario\
Typedef struct Processo

Funções
-------

        int InicializarProcesso(Processo *p)
        

*Inicializa um processo*

        void    ImprimeProcesso(Processo p)
        

*Imprime dados do processo*

        void    SetPID(Processo *p,unsigned int PID)
        

*Modifica ID do processo*

        void    SetCriadoEm(Processo *p,Horario horas)
        

*Modifica a hora em que o processo foi criado*

        int SetPrioridade(Processo *p,unsigned char prioridade)
        

*Modifica Prioridade do processo*

        unsigned int    GetPID(Processo p)
        

*Retorna ID do processo*

        Horario GetCriadoEm(Processo p)
        

*Retorna horario do Processo*

        unsigned char   GetPrioridade(Processo p)
        

*Retorna prioridade do processo*

Documentação dos Typedefs
-------------------------

-   Typedef struct tm Horario

    Vide documentação
    [aqui](http://www.tutorialspoint.com/c_standard_library/time_h.htm)\

-   Typedef struct Processo\
    **<span>Variáveis:</span>**\

    1.  **PID** *Variável do tipo inteiro que não pode ser
        negativa.Indica o ID do processo.*

    2.  **criadoEm** *Variável do tipo (tm) que indica o horário em que
        o processo foi criado*

    3.  **prioridade** *Variavél do tipo (unsigned char) que indica a
        prioridade do processo*

Documentação das Funções
------------------------

        void InicializarProcesso(Processo *p)
        

*Função que cria um processo com os campos tempo, ID e prioridade
gerados aleatoriamente*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
inicializado*

        void ImprimeProcesso(Processo p)
        

*Função que imprime todos as informações da lista*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
percorrido imprimindo seus dados*

        void SetPID(Processo *p,unsigned int PID)
        

*Função para definir um novo valor de PID(process identifier) de um
processo*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
percorrido imprimindo seus dados*

*PID Variável do tipo inteiro não podendo ser negativo que será o novo
ID do processo*

        void SetCriadoEm(Processo *p,Horario horas)
        

*Função que armazena o horário atual do computador no campo CriadoEm
dentro do processo*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
alterado o horário*

*horas Variável do tipo Horario(tm) que está armazenado o horário atual
do computador*

        int SetPrioridade(Processo *p,unsigned char prioridade)
        

*Função para definir uma nova prioridade de um processo entre 1 e 5*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
alterado a prioridade*

*prioridade Variável que armazena a nova prioridade não podendo ser
negativo*

        unsigned int GetPID(Processo p)
        

*Função que imprime o PID do processo passado*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
mostrado o PID*

        Horario GetCriadoEm(Processo p)
        

*Função que imprime o horário de criaçâo do processo*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
mostrado o horário em que foi criado*

        unsigned char GetPrioridade(Processo p)
        

*Função para obter a prioridade de um dado processo*\
**Parâmetros:**\
*p Variável tipo ponteiro para Processo que aponta para o processo a ser
mostrado a prioridade*

ListaCurs.h
===========

Typedefs
--------

Typedef struct TLCItem\
Typedef struct TListaCurs

Funções
-------

        void TLCInicializar(TListaCurs *lc,unsigned int n)  
        

*Inicializa uma lista*

        void TLCDestruir(TListaCurs *lc)
        

*Destrói uma lista*

        int TLCSize(TListaCurs *lc)
        

*Retorna tamanho atual da lista*

        int _ulttopri(TListaCurs *lc,int velho_ultimo_de_valor, int novo_ultimo)
        

*Percorre os processo de uma lista de cursores do ultimo item ao
primeiro*

        int _pritoult(TListaCurs *lc,int velho_ultimo_de_valor, int novo_ultimo)
        

*Percorre os processo de uma lista de cursores do primeiro item ao
ultimo*

        int TLCInsere(TListaCurs *lc)
        

*Insere item na lista em ordem crescente*

        int TLCRetirarPrimeiro(TListaCurs *lc)
        

*Retira primeiro item da lista*

        int TLCRetirarUltimo(TListaCurs *lc)
        

*Retira ultimo item da lista*

        void TLCImprimir(TListaCurs *lc)
        

*Imprime a Lista de Cursores*

Documentação dos Typedefs
-------------------------

-   Typedef struct TLCItem\
    **Variáveis:**\

    1.  **prox** *Variável do tipo inteiro que irá armazenar o endereço
        de memoria do próximo item a esse na lista*

    2.  **ant** *Variável do tipo inteiro que irá armazenar o endereço
        de memoria do item anteriora esse na lista*

    3.  **info** *Estrutura de um processo*\

-   Typedef struct TListaCurs\
    **Variáveis:**\

    1.  **primeiro** *Variável do tipo inteiro/ponteiro que irá
        armazenar o endereço de memoria do primeiro item da lista*

    2.  **ultimo** *Variável do tipo inteiro/ponteiro que irá armazenar
        o endereço de memoria do ultimo item da lista*

    3.  **items** *Ponteiro para a estrutura TLCItem*

    4.  **sz** *Variável que armazena o tamanho da lista*

Documentação das Funções
------------------------

        void TLCInicializar(TListaCurs *lc,unsigned int n)
        

*Função que inicializa a Lista por cursores alocando N elementos*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
inicializada*

*n Variável inteira não negativa que serve de parâmetro para o tamanho
da lista*

        void TLCImprimir(TListaCurs *lc)
        

*Função que imprime todos as informações da lista*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
percorrida imprimindo seus dados*

        int TLCSize(TListaCurs *lc)
        

*Função que retorna Tamanho atual da lista encadeada por cursores*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
imprimido seu tamanho*

        int TLCInsere(TListaCurs *lc)
        

*Função que insere item na lista em ordem crescente(chamando as funções
\_ulttopri \_pritoult)*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
inserido um item*

        int _pritoult(TListaCurs *lc,int velho_ultimo_de_valor, int novo_ultimo)
        

*Função que percorre os itens de uma lista de cursores do primeiro item
ao ultimo inserindo o novo item na posição correta mantendo a lista
ordenada*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
percorrido do primeiro item ao ultimo*

*velho\_ultimo\_de\_valor Variável que armazena o ultimo item*

*novo\_ultimo Variável que armazena o novo ultimo item*

        int _ulttopri(TListaCurs *lc,int velho_ultimo_de_valor, int novo_ultimo)
        

*Função que percorre os itens de uma lista de cursores do ultimo item ao
primeiro inserindo o novo item na posição correta mantendo a lista
ordenada*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
percorrido do primeiro item ao ultimo*

*velho\_ultimo\_de\_valor Variável que armazena o ultimo item*

*novo\_ultimo Variável que armazena o novo ultimo item*

        int TLCRetirarPrimeiro(TListaCurs *lc)
        

*Função que remove primeiro item da lista*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
removido o primeiro item*

        int TLCRetirarUltimo(TListaCurs *lc)
        

*Função remove ultimo item da lista*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
removido o ultimo item*

        void TLCDestruir(TListaCurs *lc)
        

*Função para destruir a lista*\
**Parâmetros:**\
*lc Variável tipo ponteiro para TListaCurs que aponta para a lista a ser
destruída*

ListaEncDupla.h
===============

Typedefs
--------

Typedef struct LEDItem\
Typedef struct TListaEnc

Funções
-------

        void LEDInicializar(TListaEnc *le)
        

*Inicializa uma lista*

        void LEDDestruir(TListaEnc *le)
        

*Destrói uma lista*

        int LEDSize(TListaEnc *le)
        

*Retorna tamanho atual da lista*

        int LEDInsere(TListaEnc *le)
        

*Insere item na lista*

        int LEDRetirarPrimeiro(TListaEnc *le)
        

*Retira Primeiro item da lista*

        int LEDRetirarUltimo(TListaEnc *le)
        

*Retira último item da lista*

        void Imprimir(TListaEnc *le)
        

*Imprime a lista*

Documentação dos Typedefs
-------------------------

-   Typedef struct \_LEDItem\
    **Variáveis:**\

    1.  **prox** *Ponteiro para o endereço de memória da próxima
        estrutura \_LEDItem*

    2.  **ant** *Ponteiro para o endereço de memória da estrutura
        \_LEDItem anterior a ela*

    3.  **info** *Estrutura de um processo*\

-   Typedef struct TListaEnc\
    **Variáveis:**\

    1.  **primeiro** *Variável do tipo inteiro/ponteiro que irá
        armazenar o endereço de memoria do primeiro item da lista*

    2.  **ultimo** *Variável do tipo inteiro/ponteiro que irá armazenar
        o endereço de memoria do ultimo item da lista*

    3.  **sz** *Variável que armazena o tamanho da lista*

Documentação das Funções
------------------------

        void LEDInicializar(TListaEnc *le)
        

*Função que inicializa uma lista Duplamente Encadeada*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
inicializada com segurança*

        void LEDDestruir(TListaEnc *le)
        

*Função para destruir uma lista*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
destruída com segurança*

        int LEDSize(TListaEnc *le)
        

*Função que retorna o tamanho atual da lista*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
obtido o tamanho*

        int LEDInsere(TListaEnc *le)
        

*Função que insere um item na lista Duplamente Encadeada*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a qual
será inserido um item*

        int LEDRetirarPrimeiro(TListaEnc *le)
        

*Função que retira Primeiro item da lista*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
retirado seu primeiro item, mas, mantendo a lista ordenada*

        int LEDRetirarUltimo(TListaEnc *le)
        

*Função que retira o último item da lista*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
retirado seu último item, mas, mantendo a lista ordenada*

        void Imprimir(TListaEnc *le)
        

*Função que imprime todos os dados da lista*\
**Parâmetros:**\
*le Variável tipo ponteiro para TListaEnc que aponta para a lista a ser
percorrida e imprimindo seus dados*
