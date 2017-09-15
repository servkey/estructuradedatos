#include <iostream>
using namespace std;
class Nodo{
	private: Nodo *siguiente;
	private: int valor;
	
	public: void setSiguiente(Nodo *nodo){
		this->siguiente = nodo;
	}
	
	public: Nodo *getSiguiente(){
		return siguiente;
	}
	
	public: int getValor(){
		return valor;
	}

	public: void setValor(int valor){
		this->valor = valor;
	}
};

class Lista{
	private: Nodo *cabeza; 

	public: Nodo* getCabeza(){
		return cabeza;
	}
	
	public: bool esVacia(){
		bool resultado = false;
		if (cabeza == NULL){
			resultado = true;		
		}
		return resultado;		
	}
	
	public: bool insertarAlInicio(int x){
		Nodo *nodo = new Nodo();
		nodo->setValor(x);
		nodo->setSiguiente(cabeza);
		cabeza = nodo;
	}
	
	public: bool insertar(int x){
		bool resultado = false;
		Nodo *nodo = new Nodo();
		nodo->setValor(x);
		
		if (cabeza){
			Nodo *anterior = cabeza;
			Nodo *posicion = cabeza;
			while(posicion){
				anterior = posicion;
				posicion = posicion->getSiguiente();	
			} 
			anterior->setSiguiente(nodo);	
		}else{
			cabeza = nodo;
		}	
	}
	
	public: int contar(){
		int indice = 0;
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion){
				posicion = posicion->getSiguiente();	
				indice++;
			}
		}
		return indice;
	}

	public: int contarR(Nodo *posicion){
		int resultado = 0;
		if (posicion){
			resultado = 1 + contarR(posicion->getSiguiente());
		}
		return resultado;
	}

	public: int obtenerValorPorIndice(int indiceBuscar){
		int resultado = -1;
		int indice = 0;
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion && resultado == -1){
				if (indice == indiceBuscar){
					resultado = posicion->getValor();
				}
				posicion = posicion->getSiguiente();	
				indice++;
			}
		}
		return resultado;
	}

	public: bool cambiarValorEnIndice(int indiceBuscar, int valor){
		bool resultado = false;
		int indice = 0;
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion && !resultado){
				if (indice == indiceBuscar){
					posicion->setValor(valor);
					resultado = true;
				}
				posicion = posicion->getSiguiente();	
				indice++;
			}
		}
		return resultado;
	}
	
	public: void ordenar(){
		if (cabeza){
			Nodo *actual = cabeza;
			Nodo *siguiente;
		
			while(actual->getSiguiente()){
				siguiente = actual->getSiguiente();				 
				while(siguiente){
					if (actual->getValor() > siguiente->getValor()){
						int aux = siguiente->getValor();
						siguiente->setValor(actual->getValor());
						actual->setValor(aux);
					}
					siguiente = siguiente->getSiguiente();
				}
				actual = actual->getSiguiente();
				siguiente = actual->getSiguiente();
			}
		}
	}

	public: void ordenarFor(){
		if (cabeza){
			for (int i = 1; i < this->contar(); i++){
				for (int j = 0; j < this->contar()-1; j++){
					if (this->obtenerValorPorIndice(j) > this->obtenerValorPorIndice(j+1)){
						int aux = this->obtenerValorPorIndice(j);
						this->cambiarValorEnIndice(j, this->obtenerValorPorIndice(j+1));
						this->cambiarValorEnIndice(j+1, aux);
					}
				}
			}
		}
	}

	public: int buscarIndice(int valor){
		int resultado = -1;
		int indice = 0;
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion && resultado == -1){
				if (posicion->getValor() == valor){
					resultado = indice;
				}
				posicion = posicion->getSiguiente();	
				indice++;
			}
		}
		return resultado;
	}

	public: int buscarIndiceR(int valor, Nodo *posicion, int indice){
		int indiceEncontrado = -1;
		if (posicion){
			if (posicion->getValor() == valor)
			{
				indiceEncontrado = indice;
			}
			else{
				indiceEncontrado = buscarIndiceR(valor, posicion->getSiguiente(), indice + 1);	
			}
		}
		return indiceEncontrado;
	}


	public: bool buscar(int valor){
		bool resultado = false;
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion && !resultado){
				if (posicion->getValor() == valor){
					resultado = true;
				}
				posicion = posicion->getSiguiente();	
			}
		}
		return resultado;
	}

	public: bool buscarR(int valor, Nodo *posicion){
		bool resultado = false;
		if (posicion){
				if (posicion->getValor() == valor){
					resultado = true;
				}else{
					resultado = buscarR(valor, posicion->getSiguiente());	
				}
		}
		return resultado;
	}
	
	public: bool eliminar(int valor){
		bool resultado = false;
		if (cabeza){
			Nodo *anterior;
			Nodo *posicion = cabeza;

			while(posicion->getSiguiente() && posicion->getValor() != valor){	
				anterior = posicion;
				posicion = posicion->getSiguiente();
			}
			if (posicion->getValor() == valor){
				resultado = true;
				if (cabeza == posicion){
					cabeza = cabeza->getSiguiente();
				}else{
					anterior->setSiguiente(posicion->getSiguiente());
				}
				delete posicion;
			}
		}
		return resultado;
	}

	public: bool eliminarR(int valor, Nodo *anterior, Nodo *posicion){
		bool resultado = false;
		if (posicion){
			if(posicion->getSiguiente() && posicion->getValor() != valor){	
				anterior = posicion;
				resultado = eliminarR(valor, anterior, posicion->getSiguiente());
			}
			if (posicion->getValor() == valor){
				resultado = true;
				if (cabeza == posicion){
					cabeza = cabeza->getSiguiente();
				}else{
					anterior->setSiguiente(posicion->getSiguiente());
				}
				delete posicion;
			}
		}
		return resultado;
	}
	
	public: void mostrar(){
		if (cabeza){
			Nodo *posicion = cabeza;
			while(posicion){
				cout<< posicion->getValor() << ", ";
				posicion = posicion->getSiguiente();				
			}
			cout << endl;
		}
	}
};

int main(int argc, char** argv) {
	Lista *lista = new Lista();
	cout << "La lista está vacia:" << lista->esVacia() << endl;

	lista->insertar(10);
	lista->insertar(20);
	lista->insertar(103);
	lista->insertar(15);
	lista->insertar(25);
	lista->insertar(55);
	lista->insertar(140);
	lista->insertar(131);
	lista->insertar(249);
	lista->insertar(143);
	lista->insertar(19);
	lista->insertar(2);
	lista->mostrar();

	cout << "La lista está vacia:" << lista->esVacia() << endl;

	cout << "Eliminando el 10 (R):" << lista->eliminarR(10, lista->getCabeza(), lista->getCabeza()) << endl;
	lista->mostrar();

	cout << "Eliminando el 25 (R):" << lista->eliminarR(25, lista->getCabeza(), lista->getCabeza()) << endl;
	//cout << "Eliminando el 25:" << lista->eliminar(25) << endl;
	lista->mostrar();
	
	//cout << "Eliminando el 25:" << lista->eliminar(25) << endl;
	cout << "Eliminando el 25 (R):" << lista->eliminarR(25, lista->getCabeza(), lista->getCabeza()) << endl;

	cout << "Eliminando el 221 (R):" << lista->eliminarR(221, lista->getCabeza(), lista->getCabeza()) << endl;
	//cout << "Eliminando el 221:" << lista->eliminar(221) << endl;
	
	cout << "Eliminando el 2 (R):" << lista->eliminarR(2, lista->getCabeza(), lista->getCabeza()) << endl;
	//cout << "Eliminando el 2:" << lista->eliminar(2) << endl;
	
	lista->mostrar();

	cout<<"Indice de 143: " << lista->buscarIndice(143) << endl;
	int indice = lista->buscarIndice(143);
	cout<<"Buscar valor dado índice (" << indice << "): " << lista->obtenerValorPorIndice(indice) << endl;
	
	cout<<"Indice 55 *R: " << lista->buscarIndiceR(55, lista->getCabeza(), 0) << endl;
	cout<<"Indice 150 *R: " << lista->buscarIndiceR(150, lista->getCabeza(), 0) << endl;

	cout<<"Buscando 55: " << lista->buscar(55) << endl;
	cout<<"Bucando 150: " << lista->buscar(150) << endl;
	
	cout<<"Buscando 55: " << lista->buscarR(55, lista->getCabeza()) << endl;
	cout<<"Bucando 150: " << lista->buscarR(150, lista->getCabeza()) << endl;
	
	cout<<"Elementos en la lista: " << lista->contar() << endl;
	cout<<"Elementos en la lista (R): " << lista->contarR(lista->getCabeza()) << endl;
	
	//lista->ordenar();
	lista->ordenarFor();

	lista->mostrar();
	
	return 0;
}
