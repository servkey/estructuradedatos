#include <iostream>
#include <cstdlib>
using namespace std;
template <typename T>
class Nodo{
	private: T dato;
	private: Nodo<T> *anterior;
	
	public: void setDato(T dato){
		this->dato = dato;	
	}
	
	public: T getDato(){
		return this->dato;
	}
	
	public: void setAnterior(Nodo<T> *anterior){
		this->anterior = anterior;
	}	
	
	public: Nodo<T>* getAnterior(){
		return anterior;
	}		
};

template <typename T>
class Pila{
	private: Nodo<T> *tope;
	
	public: T getDato(){
		T resultado;
		if (tope)
		{
			resultado = tope->getDato();
		}else{
			//throw new Exception("Cola vacia");
		}
		return resultado;
	}
	
	public: void mostrarLF(){
		mostrarLF(tope);
	}
	
	private: void mostrarLF(Nodo<T> *posicion){
		if (posicion){
			cout<<posicion->getDato()<< ", ";
			mostrarLF(posicion->getAnterior());
		}
	}
	
	public: void mostrarFL(){
		mostrarFL(tope);
	}
	
	private: void mostrarFL(Nodo<T> *posicion){
		if (posicion){
			mostrarFL(posicion->getAnterior());
			cout<<posicion->getDato()<< ", ";
		}
	}

	public:  T get(int indiceBuscar){
		return get(tope, indiceBuscar, contar()-1);
	}
	
	private: T get(Nodo<T> *posicion, int indiceBuscar, int indice){
		T resultado;
		if (posicion){
			if (indice != indiceBuscar){
				resultado = get(posicion->getAnterior(), indiceBuscar, indice - 1);
			}else{
				resultado = posicion->getDato();
			}
		}
		return resultado;
	}

	
	public: bool meter(T dato){
		bool resultado = false;
		Nodo<T> *nodo = new Nodo<T>();
		nodo->setDato(dato);
		if (tope){
			nodo->setAnterior(tope);
			tope = nodo;
		}else{
			tope = nodo;
		}
		resultado = true;
		return resultado;
	}
	
	public: void mostrar(){
		if (tope){
			Nodo<T> *posicion = tope;
			while (posicion){
				cout << posicion->getDato() << ", ";
				posicion = posicion->getAnterior();
			}
			cout << endl;
		}else
		{
			cout << "Sin elementos en la pila" << endl;
		}
	}

	public: T sacar(){
		T resultado = -1;
		if (tope){
			resultado = tope->getDato();
			Nodo<T> *enAtencion = tope;
			tope = tope->getAnterior();
			delete enAtencion; 
		}else{
			cout << "La pila está vacia" << endl;
		}
		return resultado;
	}
	
	public: int contar(){
		int elementos = 0;
		if(tope){
			Nodo<T> *posicion = tope;
			while (posicion){
				posicion = posicion->getAnterior();
				elementos++;
			}
		}
		return elementos;
	}
	
	public: estaVacia(){
		bool resultado = true;
		if (tope){
			resultado = false;
		}
		return resultado;
	}
};


class EvaluacionExpresion{
	private: string expr;
	private: string expp;
	private: Pila<char> *pilaAux1;
	
	public: EvaluacionExpresion(string expr){
		pilaAux1 = new Pila<char>();
		this->expr = expr;
		convertirPostfija();
	}
	public:void iterarCadena(){
		string::iterator it;	
		for (int n = 0; n < expr.length() ;n++){
			cout << "Elemento: " << expr[n] << " , ";
			cout << "Prioridad: " << prioridad(expr[n]) << ", ";
		
			char tmp = expr[n];
			//Convertir char a string
			cout << "Es digito: " << esDigito(tmp) << ", " ;
			string stmp (1, tmp);
			
			//Convertir string a entero
			int numTmp1 = std::atoi(stmp.c_str());
			cout<< "Numérico: " << numTmp1; 
			cout<<endl;	
		}
	}
		
	public: int prioridad(char c){
	  switch(c){
	    case '(': return 0;
	    case '+': return 1;
	    case '-': return 1;
	    case '*': return 2;
	    case '/': return 2;
	    default: return -1;
	  }
	}


	public: bool esDigito(char caracter){
		bool resultado = false;
		switch(caracter){
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				resultado = true;
		}
		return resultado;
	}
	
	public: bool validarParentesis(){
		//Se requiere uso de una pila
		bool resultado = false;
		return resultado;
	}
	
	//Convierte una expresión a posfija, el valor de la expresión postfija se asigna a expp
	public: string convertirPostfija(){
		//Se requiere uso de una pila
		this->expp = "";
		return this->expp;
	}
	
	//Realizar la evaluación de la expresión postfija
	public: int evalua(){
		float num = 0;
		//Se requiere una pila
		//Hacer algo con expp
		
		return num;
	}
		
};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Pila<int> *pila = new Pila<int>();
	cout << "Insertando 10 a la pila" << endl;
	pila->meter(10);
	cout << "Insertando 11 a la pila" << endl;	
	pila->meter(11);
	cout << "Insertando 4 a la pila" << endl;
	pila->meter(4);
	cout << "Insertando 54 a la pila" << endl;
	pila->meter(54);
	cout << "Insertando 40 a la pila" << endl;
	pila->meter(40);
	cout << "Insertando 8 a la pila" << endl;
	pila->meter(8);
	cout << "Elementos de la pila:" << pila->contar() << endl;
	
	cout << "get(1) de la pila:" << pila->get(1) << endl;
	
	
	cout << "Elementos en la pila: " << pila->contar() << endl;
	
	cout << "Está vacía la pila: " << pila->estaVacia() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Dato siguiente a ser atendido: " << pila->getDato() << endl;
	cout << "Elementos en la pila: " << pila->contar() << endl;
	
	pila->mostrar();
	cout<<endl<< "Mostrando pila de forma recursiva" << endl;	
	pila->mostrarFL();
	cout <<endl;

	pila->mostrarLF();
	cout <<endl;

	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	cout << "Atendiendo: " << pila->sacar() << endl;
	pila->mostrar();
	
	string expr = "(10+49)+19*2";
	cout<<"Evaluando : " << expr << endl;
	EvaluacionExpresion *ev1 = new EvaluacionExpresion(expr);
	ev1->iterarCadena();
	
	return 0;
}
