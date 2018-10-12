/*Trabalho 1 - Estrutura de Dados 1
 *Dupla: Dener Silva Guimaraes e Tassio Santuchi
 	**************************************
 	***** IMPLEMENTACAO TAD CONEXAO ******
 	**************************************
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tadconexao.h"
#include "tadroteador.h"
#include "tadterminal.h"

/*----- Estrutura das Conexoes -----*/

typedef struct tipoconexao TipoConexao;

struct tipoconexao{
    TipoRoteador* num;
    LisRot* numramos;
    ListTerminais* listter;
};

typedef struct celconexao CelConexao;

struct celconexao{
    TipoConexao* dispositivo;
    struct celconexao* prox;
};

typedef struct listConexao ListConexao;

struct listconexao{
  CelConexao* prim;
  Celconexao* ult;
};

ListConexao* inicializalstConexao () {
  ListConexao* nn = (ListConexao*) malloc (sizeof (ListConexao));
  m->prim = NULL;
  m->ult = NULL;
  return nn;
}

CelConexao* inicializaCelConexao(ListConexao* no){
  CelConexao* cc = (CelConexao*)malloc(sizeof(CelConexao));
  TipoConexao* tc = (TipoConexao*)malloc(sizeof(TipoConexao));
  cc->dispositivo = tc;
  cc->prox = no->prim;
  no->prim = cc;
  if(no->ult == NULL)
    no->ult = cc;
  return cc;
}

void inicializaConRot(TipoRoteador* a, TipoRoteador* b, ListConexao* c){
  CelConexao* d = c->prim;
  if(a == NULL)
    d->dispositivo->num = a;
  conectaRoteador (b, d->dispositivo->num);
}

int terexiste(ListTerminais* aa, char* bb){
    CelConexao* cc = aa->prim;
    CelConexao* dd = NULL;
    while (cc != NULL && buscaRot(c->dispositivo->numramos, bb) != cc->dispositivo->num) {
        dd = cc;
        cc = cc->prox;
    }
    if(cc == NULL)
        return 0;
    else
        return 1;
}


void inicializaConTerl(ListConexao* a, TipoRoteador* b, ListTerminais* c, TipoTerminal* d){
    CelConexao* cc = a->prim;
    CelConexao* dd = NULL;
    while ((cc != NULL) && (cc->dispositivo->num != b) {
        dd = cc;
        cc = cc->prox;
    }
    if(cc->dispositivo->num == a)
        conectaTerminal(c, d);
}


void removeConRot(ListaConexao* a, LisRot* b, char* c){
    CelConexao* d = a->prim;
    CelConexao* e = NULL;
    TipoConexao* f;
    TipoRoteador* g;
    char vet[10];
    while (a != NULL) {
        f = a->prim->dispositivo;
        f->b = buscaRot(b, c);
        g = f->b;
        strcpy(vet, nomeRot(g));
        if(strcmp(vet, c) == 0){
          removeRoteador(b, c);
          break;
        }
        e = d;
        d = d->prox;
    }
}

char* nomeEnl(ListaConexao* a){
  CelConexao* b = a->prim;
  TipoConexao* c = b->dispositivo;
  TipoRoteador* d = c->num;
  return nomeRot(d);
}

ListaTerminais* capturaListTe(ListaConexao* a, char* b){
    CelConexao* c = a->prim;
    TipoConexa* d = c->dispositivo;
    ListaTerminais* e = d->listter;
    return buscaTerminal(e, b);
}

ListRot* capturaListRot(ListaConexao* a, ListRot* b){
  CelConexao* c = a->prim;
  TipoConexao* d = c->dispositivo;
  TipoRoteador* e = d->num;
  return buscaRot(b, nomeRot(e));
}

ListRot* capturaListRotRemove(ListaConexao* a){
    CelConexao* b = a->prim;
    TipoConexao* c = b->dispositivo;
    ListRot* d = c->numramos;
    return d;
}


void liberaListCon(ListaTerminais* a){
    if(a != NULL){
        CelConexao* b = a->prim;
        CelConexao* c;
        while (b != NULL) {
            c = b->prox;
            LiberaRoteador(b->dispositivo->num);
            liberListRot(b->dispositivo->numramos);
            liberaListTer(b->dispositivo->listter);
            free(b->dispositivo);
            free(b);
             b = c;
        }
        free(a);
    }
}
