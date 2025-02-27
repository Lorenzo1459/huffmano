#ifndef COMPACTADOR_H_
#define COMPACTADOR_H_
#include "bitmap.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct arv Arv;
typedef struct celula TCelula;
typedef struct lista TipoLista;

//FUNCOES DE LISTA
TipoLista* InicializaLista();
void Insere_lista (Arv* arvore, TipoLista* lista);
Arv* Retira_lista (TipoLista* lista, Arv* arv);
void ImprimeLista (TipoLista* lista);
TipoLista* LiberaLista (TipoLista* lista);
Arv* RetornaArvoreOtima(TipoLista* lista);
TCelula* retorna_inicio_lista(TipoLista* lista);

void bubbleSort(TCelula* comeco);
void troca(TCelula *a, TCelula *b);
//FIM DAS FUNCOES DE LISTA

//FUNCOES DE ARVORE
Arv* arv_criavazia (void);
Arv* arv_cria (char c, int peso, Arv* e, Arv* d);
Arv* arv_libera (Arv* a);
int arv_vazia (Arv* a);
int arv_pertence (Arv* a, char c);
int eh_folha(Arv* a);
void arv_mapeia(Arv* a, int i, char* posicao, char** asc);
void arv_cabecalho(Arv* a, bitmap* bm);
void arv_imprime (Arv* a);
char info (Arv* a);
int altura (Arv* a);
//FIM DAS FUNCOES DE ARVORE

//FUNCOES ESPECIFICAS
TipoLista* Alg_HuffmanComp(TipoLista* lista);
TipoLista* Alg_Huffman1rep(TipoLista* lista);
//FIM DAS FUNCOES ESPECIFICAS



#endif // COMPACTADOR_H_
