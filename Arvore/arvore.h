#ifndef _ARVORE_H_
#define _ARVORE_H_


struct No{
	
	int elemento;
	No *ESQ;
	No *DIR;
	
};

struct Arvore{
	
	No *raiz;
	void inicializar();
	void exibir();
	void inserir(int elemento);
	void remover(int elemento);
	
	
};

#endif
