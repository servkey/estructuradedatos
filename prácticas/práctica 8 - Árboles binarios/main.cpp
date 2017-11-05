#include <iostream>
using namespace std;
class Nodo{
	private: int dato;
	private: Nodo *padre = NULL;
	private: Nodo *derecha = NULL;
	private: Nodo *izquierda = NULL;
	
	public: void setDato(int dato){
		this->dato = dato;	
	}
	
	public: int getDato(){
		return this->dato;
	}
	
	public: void setPadre(Nodo *padre){
		this->padre = padre;
	}	
	
	public: Nodo* getPadre(){
		return padre;
	}		
	
	public: void setIzquierda(Nodo *izquierda){
		this->izquierda = izquierda;
	}	
	
	public: Nodo* getIzquierda(){
		return izquierda;
	}		
	
	public: void setDerecha(Nodo *derecha){
		this->derecha = derecha;
	}	
	
	public: Nodo* getDerecha(){
		return derecha;
	}		
};

class Arbol{
	private: Nodo *raiz;
	
	public: int getDato(){
		int resultado = -1;
		if (raiz)
		{
			resultado = raiz->getDato();
		}else{
			//throw new Exception("Cola vacia");
		}
		return resultado;
	}
	
	public: bool insertar(int dato){
		return insertar(raiz, dato);	
	}
	
	private: bool insertar(Nodo *raiz, int dato){
		int resultado = false;
		if (raiz == NULL){
			Nodo *nodo = new Nodo();
			nodo->setDato(dato);
			this->raiz = nodo;
		}else if(dato < raiz->getDato()){
			if (raiz->getIzquierda() == NULL){
				Nodo *nodo = new Nodo();
				nodo->setDato(dato);
				nodo->setPadre(raiz);
				raiz->setIzquierda(nodo);	
				resultado = true;
			}else{
				resultado = insertar(raiz->getIzquierda(), dato);					
			}
			
		}else if (dato > raiz->getDato()){
			if (raiz->getDerecha() == NULL){
				Nodo *nodo = new Nodo();
				nodo->setDato(dato);
				nodo->setPadre(raiz);
				raiz->setDerecha(nodo);	
				resultado = true;				
			}else{
				resultado = insertar(raiz->getDerecha(), dato);
			}
		}
		return resultado;
	}
	
	public: Nodo* buscar(int dato){
		return buscar(raiz, dato);
	}
	private: Nodo* buscar(Nodo *raiz, int dato){
		Nodo *resultado  = NULL;
		if (raiz){
			if(dato < raiz->getDato()){
				resultado = buscar(raiz->getIzquierda(), dato);					
			}else if (dato > raiz->getDato()){
				resultado = buscar(raiz->getDerecha(), dato);
			}else{
				resultado = raiz;
			}
		}
		return resultado;
	}

	public: bool esHoja(Nodo *nodo){
		bool resultado = false;
		if (nodo && nodo->getIzquierda() == NULL && nodo->getDerecha() == NULL){
			resultado = true;
		} 
		return resultado;
	}	
	
	public:int contar(){
		return contar(raiz);
	}
	
	private: int contar(Nodo *raiz){
		if (raiz == NULL){
			return 0;
		}else{
			return 1  + contar(raiz->getIzquierda()) + contar(raiz->getDerecha());
		}		
	}
	

	public: int altura(){
		return altura(raiz);
	}
	private: int altura(Nodo *raiz){
		if (raiz == NULL){
			return 0;
		}
		int alturaIzq = altura(raiz->getIzquierda());
		int alturaDer = altura(raiz->getDerecha());
		if (alturaIzq > alturaDer){
			return alturaIzq + 1;
		}else{
			return alturaDer + 1;
		}
	}

	public: bool insertarB(int dato){
		return insertarB(raiz, dato);	
	}
	
	private: bool insertarB(Nodo *raiz, int dato){
		int resultado = false;
		Nodo *aux;
		if (raiz){
			if(dato < raiz->getDato()){
				resultado = insertarB(raiz->getIzquierda(), dato);					
				raiz->setIzquierda(raiz);
			}else if (dato > raiz->getDato()){
				resultado = insertarB(raiz->getDerecha(), dato);
				raiz->setDerecha(raiz);
			}
			this->raiz = raiz;
		}else
		{
			aux = new Nodo();
			aux->setDato(dato);
			raiz = aux;
		}
		return resultado;
	}
	
	public: void mostrarPreorden(){
		mostrarPreorden(raiz);	
	}
	
	private: void mostrarPreorden(Nodo *raiz){
		if (raiz != NULL){
			cout << raiz->getDato() << ", ";
			mostrarPreorden(raiz->getIzquierda());
			mostrarPreorden(raiz->getDerecha());
		}
	}

	public: void mostrarInorden(){
		mostrarInorden(raiz);
	}
	
	private: void mostrarInorden(Nodo *raiz){
		if (raiz != NULL){
			mostrarInorden(raiz->getIzquierda());
			cout << raiz->getDato() << ", ";
			mostrarInorden(raiz->getDerecha());
		}
	}

	public: void mostrarPostorden(){
		mostrarPostorden(raiz);
	}

	private: void mostrarPostorden(Nodo *raiz){
		if (raiz != NULL){
			mostrarPostorden(raiz->getIzquierda());
			mostrarPostorden(raiz->getDerecha());
			cout << raiz->getDato() << ", ";
		}
	}

	//Eliminar nodo sin hijos
	private: Nodo *getNodoMasAIzquierda(Nodo *nodo){
		if(nodo && nodo->getIzquierda())
		{
			return getNodoMasAIzquierda(nodo->getIzquierda());
		}
		return nodo;
	}	

	private: bool eliminarCaso1(Nodo *nodo){
		if (nodo){
			if (nodo->getPadre()->getDerecha() == nodo){
				nodo->getPadre()->setDerecha(NULL);
			}else if (nodo->getPadre()->getIzquierda() == nodo){
				nodo->getPadre()->setIzquierda(NULL);
			}
			delete nodo;
		}
	}	

	//Eliminar nodo con un subárbol (puede ser izquierdo o derecho)
	private: bool eliminarCaso2(Nodo *nodo){
		if (nodo){
			//Hijos del padre del nodo
			//Nodo* hijoPadreIzquierdo = nodo->getPadre()->getIzquierda();
			//Nodo* hijoPadreDerecho = nodo->getPadre()->getDerecho();
			if (nodo->getDerecha() != NULL || nodo->getIzquierda() != NULL){
				if (nodo->getIzquierda()){
					//nodo->getPadre getIzquierda()->setPadre(nodo->getPadre());
					nodo->getPadre()->setIzquierda(nodo->getIzquierda());
					nodo->getIzquierda()->setPadre(nodo->getPadre());
					nodo->setIzquierda(NULL);
				}else if (nodo->getDerecha()){
					nodo->getPadre()->setDerecha(nodo->getDerecha());
					nodo->getDerecha()->setPadre(nodo->getPadre());
					nodo->setDerecha(NULL);	
					//nodo->getPadre()->setDerecha(nodo->getDerecha());
				}
				delete nodo;
			}
		}
	}	

	private: bool eliminarCaso3(Nodo *nodo){
		bool resultado = false;
		if (nodo){
			Nodo *nodoIzquierda = getNodoMasAIzquierda(nodo->getDerecha());
			nodo->setDato(nodoIzquierda->getDato());
			//Eliminar el nodo Izquierda puede ser con caso 1 o caso 2
			if (esCaso1(nodoIzquierda))
				eliminarCaso1(nodoIzquierda);
			else if (esCaso2(nodoIzquierda))
				eliminarCaso2(nodoIzquierda);
		}
		return resultado;
	}
	
	public:bool esCaso1(Nodo *nodo){
		bool resultado = false;
		if (nodo){
			if (nodo->getIzquierda() == NULL && nodo->getDerecha() == NULL){
				resultado = true;
			}
		}
		return resultado;
	}
	
	public:bool esCaso2(Nodo *nodo){
		bool resultado = false;
		if (nodo){
			if(nodo->getIzquierda() != NULL && nodo->getDerecha() == NULL){
				resultado = true;
			}else if(nodo->getIzquierda() == NULL && nodo->getDerecha() != NULL){
				resultado = true;
			}
		}
		return resultado;
	}
	
	public:bool esCaso3(Nodo *nodo){
		bool resultado = false;
		if (nodo){
			if (nodo->getIzquierda() != NULL && nodo->getDerecha() != NULL){
				resultado = true;
			}
		}
		return resultado;
	}
	
	public: bool eliminar(int dato){
		bool resultado = false;
		Nodo *eliminar = buscar(dato);
		if (eliminar){
			cout << eliminar->getDato() << endl;
			if (esCaso1(eliminar)){
				cout<<"Es caso 1" << endl;
				resultado = eliminarCaso1(eliminar);
			}else if (esCaso2(eliminar)){
				cout<<"Es caso 2" << endl;
				resultado = eliminarCaso2(eliminar);
			}else if (esCaso3(eliminar)){
				cout<<"Es caso 3" << endl;
				resultado = eliminarCaso3(eliminar);
			}
		}
		return resultado;
	}
		 
	public: estaVacio(){
		bool resultado = true;
		if (raiz){
			resultado = false;
		}
		return resultado;
	}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a(int x){
	if (x == 0){
		return 1;
	}else
	{
		return a(x-1) + x;
	}
}

int main(int argc, char** argv) {
	Arbol *arbol = new Arbol();
	arbol->insertar(700);
	arbol->insertar(600);
	arbol->insertar(1000);
	arbol->insertar(200);
	arbol->insertar(650);
	arbol->insertar(1000);
	arbol->insertar(800);	
	arbol->insertar(1500);
	arbol->insertar(2000);
	
	int dato = 700;
	cout<<"Eliminado " << dato << "...." <<endl;
	//Eliminando raíz
	arbol->eliminar(dato);

	cout<<"Dato en la raíz: " << arbol->getDato() << endl;
	cout<<"Altura del árbol: " << arbol->altura() << endl;
	cout<<"# Nodos: " << arbol->contar() << endl;
	cout<<"El árbol está vacío: " << arbol->estaVacio() << endl;
	cout<<"Preorden: " << endl;
	arbol->mostrarPreorden();
	cout << endl;
	cout<<"Inorden: " << endl;
	arbol->mostrarInorden();
	cout << endl;
	cout<<"Postorden: " << endl;
	arbol->mostrarPostorden();
	cout << endl;
	
	int val = 1500;
	cout<<"Buscando (" << val << ")";
	Nodo *nodo = arbol->buscar(val);
	cout << endl;
	cout<<"El nodo: " << val << " es hoja: " << arbol->esHoja(nodo) << endl;
	
	if (nodo)
	{
		cout<< "Nodo encontrado: " << nodo->getDato() << endl;	
	}else{
		cout<< "Nodo NO encontrado" << endl;	
	}
	return 0;
}
