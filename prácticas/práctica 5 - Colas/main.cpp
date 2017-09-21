#include <iostream>
using namespace std;
class Nodo{
	private: int dato;
	private: Nodo *siguiente;
	
	public: void setDato(int dato){
		this->dato = dato;	
	}
	
	public: int getDato(){
		return this->dato;
	}
	
	public: void setSiguiente(Nodo *siguiente){
		this->siguiente = siguiente;
	}	
	
	public: Nodo* getSiguiente(){
		return siguiente;
	}		
};

class Cola{
	private: Nodo *cabeza;
	private: Nodo *ultimo;
	
	public: int getDato(){
		int resultado = -1;
		if (cabeza)
		{
			resultado = cabeza->getDato();
		}else{
			//throw new Exception("Cola vacia");
		}
		return resultado;
	}
	
	public: bool insertar(int dato){
		int resultado = false;
		Nodo *nodo = new Nodo();
		nodo->setDato(dato);
		if (ultimo){
			ultimo->setSiguiente(nodo);
			ultimo = nodo;
		}else{
			cabeza = nodo;
			ultimo = cabeza;
		}
		return resultado;
	}
	
	public: void mostrar(){
		if (cabeza){
			Nodo *posicion = cabeza;
			while (posicion){
				cout << posicion->getDato() << ", ";
				posicion = posicion->getSiguiente();
			}
			cout << endl;
		}else
		{
			cout << "Sin elementos en la cola" << endl;
		}
	}
	public: int atender(){
		int resultado = -1;
		if (cabeza){
			resultado = cabeza->getDato();
			Nodo *enAtencion = cabeza;
			cabeza = cabeza->getSiguiente();
			delete enAtencion; 
		}else{
			cout << "La cola está vacia" << endl;
		}
		return resultado;
	}
	
	public: int contar(){
		int elementos = 0;
		if (cabeza){
			Nodo *posicion = cabeza;
			while (posicion){
				posicion = posicion->getSiguiente();
				elementos++;
			}
		}
		return elementos;
	}
	
	public: estaVacia(){
		bool resultado = true;
		if (cabeza){
			resultado = false;
		}
		return resultado;
	}
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Cola *cola = new Cola();
	cout << "Insertando 10 a la cola" << endl;
	cola->insertar(10);
	cout << "Insertando 11 a la cola" << endl;	
	cola->insertar(11);
	cout << "Insertando 4 a la cola" << endl;
	cola->insertar(4);
	cout << "Insertando 54 a la cola" << endl;
	cola->insertar(54);
	cout << "Insertando 40 a la cola" << endl;
	cola->insertar(40);
	cout << "Insertando 8 a la cola" << endl;
	cola->insertar(8);
	
	cout << "Elementos en la cola: " << cola->contar() << endl;
	
	cout << "Está vacía la cola: " << cola->estaVacia() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Dato siguiente a ser atendido: " << cola->getDato() << endl;
	cout << "Elementos en la cola: " << cola->contar() << endl;
	
	cola->mostrar();
	
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	cout << "Atendiendo: " << cola->atender() << endl;
	
	cola->mostrar();
	return 0;
}
