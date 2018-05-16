#include "arvore.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	
	Arvore a;
	a.inicializar();
	a.inserir(30);
	a.inserir(45);
	a.inserir(20);
	a.inserir(10);
	a.inserir(27);	
	a.inserir(5);
	a.inserir(12);
	a.inserir(26);
	a.inserir(28);
	a.inserir(11);
	a.inserir(1);
	a.inserir(6);
					
	
	a.exibir();
	
	a.remover(10);
	
	cout << endl << endl;
	
	a.exibir();

}
