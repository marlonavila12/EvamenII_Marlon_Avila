#include <iostream>
#include"ListaEmpleados.h"

using namespace std;

int main(){
	ListaEmpleados* l = new ListaEmpleados();
	l->agregar(2, "hollaadsjsadsa", 200, true);
	l->agregar(3, "hollaadsjsadsa", 200, true);
	l->agregar(4, "hollaadsjsadsa", 200, true);
	l->imprimirEmpleado();
	l->dasctivarEmpleado(3);
	l->imprimirEmpleado();
	return 0;
}