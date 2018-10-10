/*Trabalho 1 - Estrutura de Dados 1
 *Dupla: Dener Silva Guimaraes e Tassio Santuchi
 	**************************************
 	***** IMPLEMENTACAO TAD CONEXAO ******
 	**************************************
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*----- Estrutura das Conexoes -----*/

typedef struct tipoconexao TipoConexao;

struct tipoconexao{
    int num;
    int numramos;
};

typedef struct celconexao CelConexao;

struct celconexao{
    void* dispositivo;
    struct celconexao* prox;
};

typedef struct listConexao ListConexao;

struct listconexao{
  CelConexao* prim;
  Celconexao* ult;
};

TipoConexao* inicializaTipoConexao(int no){
	TipoConexao* novo = (TipoConexao*)malloc(sizeof(TipoConexao));
	novo->num = no;
	return(novo);
}

/*----- Insere novo terminal na lista -----*/

TipoTerminal* inicializaTipoTerminal(char* nome, char* localidade){
	TipoTerminal* novoter = (TipoTerminal*)malloc(sizeof(TipoTerminal));
	novoter->nomeTer = malloc( (strlen(nome)+1)*sizeof(char) );
	strcpy(novoter->nomeTer, nome);
	novoter->localidade = malloc( (strlen(localidade)+1)*sizeof(char) );
	strcpy(novoter->localidade, localidade);
	return(novoter);
}

ListTerminais* cadastraTerminal(ListTerminais* lstTer, char* terminal, char* localidade){
	TipoTerminal* tipoTer = inicializaTipoTerminal(terminal, localidade);
	//Aloca espaco para uma nova celula
	CelTerminal* nova_celterminal = (CelTerminal*)malloc(sizeof(CelTerminal));
	nova_celterminal->info = tipoTer;
	nova_celterminal->prox = NULL;
	//Se a lista estiver vazia:
	if(lstTer->prim == NULL){
		lstTer->prim = nova_celterminal;
		lstTer->ult = nova_celterminal;
	}
	else{//Insere no final da lista:
		lstTer->ult->prox = nova_celterminal;
		lstTer->ult = nova_celterminal;
	}
	return(lstTer);
}

/*----- Imprime a lista de terminais -----*/

void imprimeTerminais(ListTerminais* l){
	CelTerminal* p = l->prim;
	while(p != NULL){
		printf("TERMINAL: %s, CIDADE: %s\n", p->info->nomeTer, p->info->localidade);
		p = p->prox;
	}
}

/*----- Remove terminal do NetMap -----*/

void removeTerminal(ListTerminais* lstTer, char* terminal){
	CelTerminal* p = lstTer->prim;
	CelTerminal* ant = NULL;
	while(p != NULL && (strcmp(p->info->nomeTer, terminal) != 0	) ){//Percorre a lista ate achar o elemento ou ate ela ser NULL.
		ant = p;
		p = p->prox;
	}
	if(p == NULL){//Se o elemento nao estiver na lista.
		printf("Erro: %s inexistente no NetMap\n", terminal);
		return;
	}
	if(p == lstTer->prim && p == lstTer->ult){
		lstTer->prim = NULL;
		lstTer->ult = NULL;
		free(p);
		return;
	}
	if(p == lstTer->prim){//Se elemento a ser retirado estiver no inicio.
		lstTer->prim = p->prox;
		free(p);
		return;
	}
	if(p == lstTer->ult){//Se elemento a ser retirado estiver no final.
		lstTer->ult = ant;
		ant->prox = NULL;
		free(p);
		return;
	}
	else{//Se elemento a ser retirado estiver no meio.
		ant->prox = p->prox;
		p = ant->prox;
		free(p);
		return;
	}
}
	int FrequenciaTerminal(CelTerminal* cel, char* localidade){
    if(cel != NULL){
        int cont = 0;
        CelTerminal *cc = cel->prim;
        CelTerminal *ee = NULL;
        while (p != NULL) {
            if(strcmp(cc->prim->localidade, localidade) == 0){
                cont++;
            }else{
                ee = cc;
                cc = cc->prox;
            }

        }
        return cont;
    }else return -1;
}

char* nomeTerminal(Terminal* t){
  return t->nome;
}

void liberaTerminal (CelTerminal* cel){
    if(cel != NULL){
        CelTerminal* cc = cel->prim;
        CelTerminal* temp;
        while (cc != NULL) {
            temp = cc->prox;
            free(cc->info->nomeTer);
            free(cc->info->localidade);
            free(cc->info);
            cc = temp;
        }
        free(cel);
    }
