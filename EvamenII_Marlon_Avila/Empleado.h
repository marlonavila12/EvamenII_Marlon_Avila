#pragma once
#include <string>
#include<iostream>
using namespace std;
class Empleado
{
private:
	int cod_emp;
	string nom_emp;
	float salario;
	bool activo;
	Empleado* siguiente;
	Empleado* anterior;

public:
	Empleado();
	~Empleado();

	//setters
	void setCodigo(int c);
	void setNombre(string n);
	void setSalario(float s);
	void setActivo(bool a);
	void setSiguiente(Empleado* s);
	void setAnterior(Empleado* a);

	//funciones
	void imprimir();

	//
	int getCodigo();
	string getNombre();
	float getSalario();
	bool getActivo();
	Empleado* getSiguiente();
	Empleado* getAnterior();

};

