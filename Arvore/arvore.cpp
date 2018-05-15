#include <iostream>
#include "arvore.h"
#include <cstdlib>

using namespace std;

void Arvore::inicializar(){
	
	this->raiz = NULL;
}


No * inserirElemento(No*raiz, int elemento){
	
	if(raiz == NULL){
		raiz = (No*) malloc (sizeof(No));
		raiz->elemento =  elemento;
		raiz->ESQ = NULL;
		raiz->DIR = NULL; 
	}
		
	else{
		if(elemento > raiz->elemento)
			raiz->DIR = inserirElemento(raiz->DIR, elemento);
		else if(elemento < raiz->elemento)
			raiz->ESQ = inserirElemento(raiz->ESQ, elemento);
		else
			cout << "Elemento Ja Existente" << endl;
	}	
	
	return raiz;
	
	
}

void Arvore::inserir(int elemento){

	this->raiz = inserirElemento(this->raiz, elemento);

	
}

void exibirPreOrdem(No*raiz){
	
	if(raiz != NULL){
		cout << raiz->elemento << endl;
		exibirPreOrdem(raiz->ESQ);
		exibirPreOrdem(raiz->DIR);
	}	
	
}

void exibirEmOrdem(No*raiz){
	
	if(raiz != NULL){
		exibirPreOrdem(raiz->ESQ);
		cout << raiz->elemento << endl;
		exibirPreOrdem(raiz->DIR);
	}	
	
}

void exibirPosOrdem(No*raiz){
	
	if(raiz != NULL){
		exibirPreOrdem(raiz->ESQ);
		exibirPreOrdem(raiz->DIR);
		cout << raiz->elemento << endl;
	}	
	
}

void Arvore::exibir(){
	
		exibirPreOrdem(this->raiz);
	
}
