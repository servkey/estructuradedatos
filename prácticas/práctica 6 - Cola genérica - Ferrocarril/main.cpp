#include <iostream>
using namespace std;

class Persona{
	private:
		string nombre;
		string apPaterno;
		
	public:
		Persona(){
			
		}
		
		Persona(string nombre, string apPaterno){
			this->nombre = nombre;
			this->apPaterno = apPaterno;
		}
		
		string getNombre(){
			return nombre;
		}
};
template <typename T>
class Nodo{
	private: T dato;
	private: Nodo *siguiente;
	
	public: void setDato(T dato){
		this->dato = dato;	
	}
	
	public: T getDato(){
		return this->dato;
	}
	
	public: void setSiguiente(Nodo *siguiente){
		this->siguiente = siguiente;
	}		
	public: Nodo* getSiguiente(){
		return siguiente;
	}		
};

template <typename T>
class Cola{
	private: Nodo<T> *cabeza;
	private: Nodo<T> *ultimo;
	
	public: T getDato(){
		T resultado = -1;
		if (cabeza)
		{
			resultado = cabeza->getDato();
		}else{
			//throw new Exception("Cola vacia");
		}
		return resultado;
	}
	
	public: bool insertar(T dato){
		bool resultado = false;
		Nodo<T> *nodo = new Nodo<T>();
		nodo->setDato(dato);
		if (ultimo){
			ultimo->setSiguiente(nodo);
			ultimo = nodo;
		}else{
			cabeza = nodo;
			ultimo = cabeza;
		}
		resultado = true;
		return resultado;
	}
	
	public: void mostrar(){
		if (cabeza){
			Nodo<T> *posicion = cabeza;
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

	public: T atender(){
		T resultado;
		if (cabeza){
			resultado = cabeza->getDato();
			Nodo<T> *enAtencion = cabeza;
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
			Nodo<T> *posicion = cabeza;
			while (posicion){
				posicion = posicion->getSiguiente();
				elementos++;
			}
		}
		return elementos;
	}


	public: T get(int index){
		int indexTmp = 0;
		T resultado;
		if (cabeza){
			Nodo<T> *posicion = cabeza;
			while (posicion){
				if (index == indexTmp){
					resultado = posicion->getDato();
					break;
				}
				posicion = posicion->getSiguiente();
				indexTmp++;
			}
		}
		return resultado;
	}

	
	public: estaVacia(){
		bool resultado = true;
		if (cabeza){
			resultado = false;
		}
		return resultado;
	}
};

class Vagon{
	private: int cantidad;
	public: int getCantidad(){
		return cantidad;
	}
	
	public: void setCantidad(int cantidad){
		this->cantidad = cantidad;
	}
};

class Ferrocarril{
	//Propiedades
	private: string nombre;
	private: string maquinista;
	
	//Relación de agregación
	private: Cola<Vagon> *vagones;
	private: int contador;
	
	public: Ferrocarril(){
		vagones = new Cola<Vagon>();
	}
	
	public: string getNombre(){
		return nombre;
	}
	
	public: void setNombre(string nombre){
		this->nombre = nombre;
	}
	
	public: string getMaquinista(){
		return maquinista;
	}
	
	public: void setMaquinista(string maquinista){
		this->maquinista = maquinista;
	}
	
	public: Vagon obtenerVagon(int indice){
		return vagones->get(indice);
	}
	
	public: int obtenerNumeroDeVagones(){
		return contador;
	}
	
	public: bool agregarVagon(Vagon *vagon){
		bool resultado = false;
		//Calcular tamaño del arreglo
		if (vagones->insertar(*vagon)){
			resultado = true;
		}else{
			cout << "Espacio insuficiente para agregar vagón" << endl;
		}
		return resultado;
	}
	
	public: void mostrar(){
		for (int i = 0; i < vagones->contar(); i++){
			cout<<"Vagon (" << i << ")-Cantidad = " << vagones->get(i).getCantidad() << endl;
		}
	}
};

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



int main(int argc, char** argv) {
	Ferrocarril *ferrocarril = new Ferrocarril();
	
	Vagon *v1 = new Vagon();
	v1->setCantidad(10);
	Vagon *v2 = new Vagon();
	v2->setCantidad(15);
	Vagon *v3 = new Vagon();
	v3->setCantidad(14);
	Vagon *v4 = new Vagon();
	v4->setCantidad(12);
	
	ferrocarril->agregarVagon(v1);
	ferrocarril->agregarVagon(v2);
	ferrocarril->agregarVagon(v3);
	ferrocarril->agregarVagon(v4);
	ferrocarril->mostrar();
	
	
	Cola<int> *cola = new Cola<int>();
	
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
	
	cout<<"Cola de personas: "<< endl;
	Cola<Persona> *colaP = new Cola<Persona>();
	Persona *p1 = new Persona("X1","Y1");
	Persona *p2 = new Persona("X2","Y2");
	Persona *p3 = new Persona("X3","Y3");
	Persona *p4 = new Persona("X4","Y4");
	colaP->insertar(*p1);
	colaP->insertar(*p2);
	colaP->insertar(*p3);
	colaP->insertar(*p4);
		
	Persona ptmp = colaP->atender();
	cout<< "Elemento atendido:" << ptmp.getNombre() << endl;	

	for (int i = 0; i < colaP->contar(); i++){
		cout<<"Nombre: " << colaP->get(i).getNombre() << endl;
	}
	
	return 0;
}
