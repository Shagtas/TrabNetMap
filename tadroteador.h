#ifndef TADROTEADOR_H
#define TADROTEADOR_H

typedef struct tiporoteador TipoRoteador;

typedef struct celrot CelRot;

typedef struct listrot ListRot;

ListRot* inicializaListaRot();

TipoRoteador* inicializaTipoRoteador(char* nome, char* op);

ListRot* cadastraRoteador(ListRot* lstRot, char* roteador, char* operadora);

void imprimeRoteadores(ListRot* l);

void removeRoteador(ListRot* lstRot, char* roteador);

CelRot* buscaRot(ListRot* lstRot, char* roteador);

CelRot* insereConexao(CelRot* original, CelRot* anexado);

void imprimeSubListaRot(CelRot* aux);

void conectaRoteador(ListRot* lstRot, char* rot1, char* rot2);

void liberaRoteador (listRot* lsRot);

#endif // TADROTEADOR_H
