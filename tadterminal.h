#ifndef TADTERMINAL_H
#define TADTERMINAL_H

#include "tadroteador.h"
#include "tadconexao.h"

typedef struct tipoterminal TipoTerminal;

typedef struct celterminal CelTerminal;

typedef struct listterminais ListTerminais;

ListTerminais* inicializaListaTerminais();

TipoTerminal* inicializaTipoTerminal(char* nome, char* localidade);

ListTerminais* cadastraTerminal(ListTerminais* lstTer, char* terminal, char* localidade);

void imprimeTerminais(ListTerminais* l);

void removeTerminal(ListTerminais* lstTer, char* terminal);

Terminal* buscaTerminal(tlista* t,char* nome);

int FrequenciaTerminal(CelTerminal* cel, char* local);

char* nomeTerminal(CelTerminal* cel);

char* localidadeTer(TipoTerminal* t);

void liberaterminal (CelTerminal* cel);

#endif // TADTERMINAL_H
