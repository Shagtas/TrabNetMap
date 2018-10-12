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

ListConexao* criaConexao () {
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

int seexiste(ListTerminais* aa, char* bb){
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

tlista* capturaListaTerminal(ListaConexao* a, char* b){
    CelConexao* c = a->prim;
    TipoConexa* d = c->dispositivo;
    tlista *t1 = c->terminal;
    buscaTerminal(t1,nome);
}

List* capturaListaRoteador(Lista3* l, List* l1){
  Malha* m = l->primeiro;
  Conexao* c = m->equipamento;
  Router* r = c->rot;
  buscaRoteador(l1,nomeRoteador(r));
}

List* capturaListaRoteadorRemocao(Lista3* m){
    Malha* n = m->primeiro;
    Conexao* c = n->equipamento;
    List* l = c->roteador;
    return l;
}


void EncerraListaConexoes(Lista3* l){
    if(l != NULL){
        Malha* novo = l->primeiro;
        Malha* t;
        while (novo != NULL) {
            t = novo->prox;
            LiberaRoteador(novo->equipamento->rot);
            EncerraLista(novo->equipamento->roteador);
            EncerraListaTerminais(novo->equipamento->terminal);
            free(novo->equipamento);
            free(novo);
            novo = t;
        }
        free(l);
    }
}
