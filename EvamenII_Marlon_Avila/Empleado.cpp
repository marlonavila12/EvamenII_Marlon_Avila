#include "Empleado.h"

Empleado::Empleado()
{
	cod_emp = 0;
	nom_emp = "";
	salario = 0;
	activo = false;
	siguiente = nullptr;
	anterior = nullptr;
}

Empleado::~Empleado()
{
}

void Empleado::setCodigo(int c)
{
	cod_emp = c;
}

void Empleado::setNombre(string n)
{
	nom_emp = n;
}

void Empleado::setSalario(float s)
{
	salario = s;
}

void Empleado::setActivo(bool a)
{
	activo = a;
}

void Empleado::setSiguiente(Empleado* s)
{
	siguiente = s;
}

void Empleado::setAnterior(Empleado* a)
{
	anterior = a;
}

void Empleado::imprimir()
{
	cout << "Codigo de empleado: " << cod_emp << " Nombre de empleado: " << nom_emp << " Salario: " << salario<<endl;
}

int Empleado::getCodigo()
{
	return cod_emp;
}

string Empleado::getNombre()
{
	return nom_emp;
}

float Empleado::getSalario()
{
	return salario;
}

bool Empleado::getActivo()
{
	return activo;
}

Empleado* Empleado::getSiguiente()
{
	return siguiente;
}

Empleado* Empleado::getAnterior()
{
	return anterior;
}
