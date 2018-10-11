/*Trabalho 1 - Estrutura de Dados 1
 *Dupla: Dener Silva Guimaraes e Tassio Santuchi
 	**************************************
 	***** IMPLEMENTACAO TAD CONEXAO ******
 	**************************************
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "conexao.h"
#include "roteador.h"
#include "terminal.h"

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


void iniciaConexaoTerminal(Lista3* l, Router *r, tlista* t, Terminal* s){
    Malha* m = l->primeiro;
    Malha* u = NULL;
    while (m != NULL && m->equipamento->rot != r) {
        u = m;
        m = m->prox;
    }

    if(m->equipamento->rot == r){
        conectaTerminal(t,s);
    }
}


void removeConexaoRoteadores(Lista3* m,List* rot, char* nome){
    Malha* prim = m->primeiro;
    Malha* ult = NULL;
    Conexao* c;
    Router* r;
    char nome2[10];
    while (m != NULL) {
        c = m->primeiro->equipamento;
        c->rot= buscaRoteador(rot,nome);
        r = c->rot;
        strcpy(nome2,nomeRoteador(r));
        if(nome2 == nome){
          RemoveRoteador(rot,nome);
          break;
        }
        ult = prim;
        prim = prim->prox;
    }

}

char* nomeEnlace(Lista3* c){
  Malha* con;
  Conexao* eq;
  con = c->primeiro;
  eq = con->equipamento;
  Router* r = eq->rot;
  return nomeRoteador(r);
}

tlista* capturaListaTerminal(Lista3* t, char* nome){
    Malha *m = t->primeiro;
    Conexao *c = m->equipamento;
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
