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
	
	a.exibir();
	
	a.remover(45);
	
	cout << endl << endl;
	
	a.exibir();

}
