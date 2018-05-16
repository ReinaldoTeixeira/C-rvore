#include <iostream>
#include "arvore.h"
#include <cstdlib>
#include <queue>

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

void exibirPorNivel (No*raiz){ //nessa situação criamos uma lista para trabalhar com FIFO, sendo que vamos colocar nossos elementos nessa lista para apresentar eles por 
								//niveis. 
	
	queue<No*> fila;
	fila.push(raiz);
	while(!fila.empty()){
		
		No *aux =  fila.front();
		cout << aux->elemento << endl; 
		if(aux->ESQ != NULL) fila.push(aux->ESQ);
		if(aux->DIR != NULL) fila.push(aux->DIR);
		fila.pop();		
	}	
}

void Arvore::exibir(){
	
		exibirPorNivel(this->raiz);
	
}

No* removeNO (No *no){
	
	if(no->ESQ == NULL && no->DIR == NULL){
		
		free(no);
		return NULL;
		
	}	
	
	if(no->DIR != NULL && no->ESQ == NULL){
		
		No *aux = no->DIR;
		free(no);
		return aux;
	}
	
	if(no->ESQ != NULL && no->DIR == NULL){
		
		No *aux = no->ESQ;
		free(no);
		return aux;
		
	}
	
	No *novo = no->ESQ;
	No *pai = no;
	
	while(novo->DIR != NULL){
		
		pai = novo;
		novo = novo->DIR;
		
	}
	
	if(pai != no){
	
		pai->DIR = novo->ESQ;
		novo->ESQ = no->ESQ;
		novo->DIR = no->DIR;
		free(no);
		return novo;
		
	}
	
	else{
		
		novo->DIR = no->DIR;
		free(no);
		return novo;
		
	}
	
	}
	

void Arvore::remover(int elemento){
	
	No *pai = NULL;
	No *no = raiz;
	
	while(no != NULL){
		if(no->elemento == elemento){
			if(no == raiz){
				raiz = removeNO(no);
			}
			else{
				
				if(pai->ESQ == no)
					pai->ESQ =  removeNO(no);
				else
					pai->DIR = removeNO(no);
		}
		return;
				
			}
		else{
			if(elemento < no->elemento){
				pai = no;
				no = no->ESQ;
			}
			else{
				pai = no;
				no = no->DIR;
				
			}
			
		}
			
			
		}
		
		
	}
	


