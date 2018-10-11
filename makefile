### Makefile ###
all: netMap

netMap: conexao.o terminal.o roteador.o
	gcc conexao.o terminal.o roteador.o -o netMap

conexao.o: conexao.c
	gcc -c conexao.c

terminal.o: terminal.c
	gcc -c terminal.c

roteador.o: roteador.c
	gcc -c roteador.c

graph: 
	neato -Tpdf saida.dot -o saida.pdf

clean:
	rm -rf *.o

run: netMap
	./netMap entradaNetMap.txt
