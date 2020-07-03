#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados()
{
	primero = nullptr;
	ultimo = nullptr;
}

ListaEmpleados::~ListaEmpleados()
{
}

bool ListaEmpleados::isEmpty()
{
	return primero == nullptr;
}

bool ListaEmpleados::search(int r)
{
	if (primero == nullptr)
		return false;
	Empleado* aux = primero;
	while ((aux->getSiguiente() != primero) && (!(aux->getCodigo() == r)))
		aux = aux->getSiguiente();
	return aux->getCodigo() == r;
	
}

void ListaEmpleados::agregar(int c, string n, float s, bool a)
{
	if (search(c))
		return;
	//agregar
	Empleado* nuevo = new Empleado();
	nuevo->setCodigo(c);
	nuevo->setNombre(n);
	nuevo->setSalario(s);
	nuevo->setActivo(a);

	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;

		primero->setSiguiente(ultimo);
		ultimo->setAnterior(primero);
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);
	}
}

void ListaEmpleados::imprimirEmpleado()
{
	if (isEmpty())
	{
		cout << "Sin elementos" << endl;
	}
	else {
		Empleado* aux = primero;
		do
		{
			if(aux->getActivo())
				aux->imprimir();
			aux = aux->getSiguiente();
		} while (aux != primero);
	}
}

void ListaEmpleados::actualizarSalario(float s)
{
	if (!(isEmpty())) {
		Empleado* aux = primero;
		while (aux != primero) {
			if (s > 0 && s <= 1) {
				float t = aux->getSalario() + s * aux->getSalario();
				aux->setSalario(t);
			}
			else {
				cout << "Incremento no valido" << endl;
			}
			aux = aux->getSiguiente();
		}
	}
}

void ListaEmpleados::dasctivarEmpleado(int r)
{
	if (!(isEmpty())) {
		Empleado* aux = primero;
		do {
			if (aux->getCodigo() == r)
				aux->setActivo(false);
			aux = aux->getSiguiente();
		} while (aux != primero);
	}
}

void ListaEmpleados::eliminarEmpleado(int r)
{
	if (!(isEmpty())) {
		Empleado* aux = primero;
		do {
			if (!(isEmpty())) {
				if (aux->getCodigo() == r) {
					if (aux == primero) {
						primero = aux->getSiguiente();
						primero->setAnterior(ultimo);
						ultimo->setSiguiente(primero);

						delete aux;
					}
					else if (aux = ultimo) {
						ultimo = aux->getAnterior();
						ultimo->setSiguiente(primero);
						primero->setAnterior(ultimo);

						delete aux;
					}
					else {
						aux->getAnterior()->setSiguiente(aux->getSiguiente());
						aux->getSiguiente()->setAnterior(aux->getAnterior());
					}
				}
				aux = aux->getSiguiente();
			}
		} while (aux != primero);
	}
}

void ListaEmpleados::guardarEmpleados()
{
	Empleado* aux = primero;

	do {
		if (aux->getActivo() == true) {

			ofstream of("RRHH.dat", ios::out | ios::binary);

			if (!of) {

				cout << "Error al intentar abrir archivo\n";
				return;
			}


			of.write(reinterpret_cast<const char*>(&aux), sizeof(of));
			aux = aux->getSiguiente();
		}
		else {
			aux = aux->getSiguiente();
		}
	} while (aux != primero);

}
