#ifndef TADCONEXAO_H
#define TADCONEXAO_H

#include "tadroteador.h"
#include "tadterminal.h"

typedef struct tipoconexao TipoConexao;

typedef struct celconexao CelConexao;

typedef struct listConexao ListConexao;

ListConexao* criaConexao ();

CelConexao* inicializaCelConexao(ListConexao* no);

void inicializaConRot(TipoRoteador* a, TipoRoteador* b, ListConexao* c);

int seexiste(ListTerminais* aa, char* bb)
  
void inicializaConTerl(ListConexao* a, TipoRoteador* b, ListTerminais* c, TipoTerminal* d);

void removeConRot(ListaConexao* a, LisRot* b, char* c);



#endif // TADCONEXAO_H
