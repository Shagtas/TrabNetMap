#ifndef TADCONEXAO_H
#define TADCONEXAO_H

#include "tadroteador.h"
#include "tadterminal.h"

typedef struct tipoconexao TipoConexao;

typedef struct celconexao CelConexao;

typedef struct listConexao ListConexao;

ListConexao* inicializaCelConexao ();

CelConexao* inicializaCelConexao(ListConexao* no);

void inicializaConRot(TipoRoteador* a, TipoRoteador* b, ListConexao* c);

int terexiste(ListTerminais* aa, char* bb);
  
void inicializaConTerl(ListConexao* a, TipoRoteador* b, ListTerminais* c, TipoTerminal* d);

void removeConRot(ListaConexao* a, LisRot* b, char* c);

char* nomeEnl(ListaConexao* a);

ListaTerminais* capturaListTe(ListaConexao* a, char* b);

ListRot* capturaListRot(ListaConexao* a, ListRot* b);

ListRot* capturaListRotRemove(ListaConexao* a);

void liberaListCon(ListaTerminais* a);

#endif // TADCONEXAO_H
