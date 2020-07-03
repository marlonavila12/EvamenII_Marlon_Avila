#pragma once
#include"Empleado.h"
#include <fstream>
class ListaEmpleados
{
private:
	Empleado* primero;
	Empleado* ultimo;

public:
	ListaEmpleados();
	~ListaEmpleados();

	//funciones
	bool isEmpty();
	bool search(int r);
	void agregar(int c, string n, float s, bool a); 
	void imprimirEmpleado();
	void actualizarSalario(float s);
	void dasctivarEmpleado(int r);
	void eliminarEmpleado(int r);
	void guardarEmpleados();
};

