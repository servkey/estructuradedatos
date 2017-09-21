#include <iostream>
#include <string.h>

using namespace std;

//Clase Persona
class Persona{
	private: string nombre;
	private: string apellidoPaterno;
	private: string apellidoMaterno;
	private: string fechaNacimiento;
	private: string direccion;
	
	public: Persona(){
	}
	
	public: Persona(string nombre, string apellidoPaterno, string apellidoMaterno, string fechaNacimiento, string direccion){
		this->nombre = nombre;
		this->apellidoPaterno = apellidoPaterno;
		this->apellidoMaterno = apellidoMaterno;
		this->fechaNacimiento = fechaNacimiento;
		this->direccion = direccion;
	}
		
	public: string getNombre(){
		return nombre;
	}
	
	public: void setNombre(string nombre){
		this->nombre = nombre;
	}
	
	public: virtual void mostrar(){
		cout << endl << "Nombre: " << nombre << ", apellido paterno: " << apellidoPaterno << ", apellido materno: " << apellidoMaterno << ", fecha de nacimiento: " << fechaNacimiento  << ", dirección: " << direccion;
	}
};


class Trabajador : public Persona{
	private: int numeroEmpleado;
	private: string puesto;
	private: double salario;
	
	public: Trabajador(){
	}
	
	public: Trabajador(string nombre, string apellidoPaterno, string apellidoMaterno, string fechaNacimiento, string direccion, int numeroEmpleado, string puesto, double salario): Persona(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, direccion) {
		this->numeroEmpleado = numeroEmpleado;
		this->puesto = puesto;
		this->salario = salario;
	}

	public: int getNumeroEmpleado(){
		return numeroEmpleado;
	}
	
	public: void setNumeroEmpleado(int numeroEmpleado){
		this->numeroEmpleado = numeroEmpleado;
	}
	
	public: void mostrar(){
		Persona::mostrar();
		cout<<" Número empleado: " << numeroEmpleado << ", puesto: " << puesto << ", salario: " << salario << endl;
	}
};

class Socio: public Persona{
	private: string escuela;
	private: string numeroMatricula;
	
	public: Socio(){
	}
	
	public: Socio(string nombre, string apellidoPaterno, string apellidoMaterno, string fechaNacimiento, string direccion, string escuela, string numeroMatricula) : Persona(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento, direccion) {
		this->escuela = escuela;
		this->numeroMatricula = numeroMatricula;
	}

	public: void mostrar(){
		Persona::mostrar();
		cout<<" Escuela procedencia: " << escuela << ", Matrícula: " << numeroMatricula << endl;
	}
	
};

int main(int argc, char** argv) {
	//Declaración de objetos, Persona, Socio, Trabajador... p1, p2, s1, s2, ...
	Trabajador *t1 = new Trabajador("Juan", "Perez", "Lopez", "10/01/17", "Av. Murillo Vidal #4565", 30942, "Administrativo", 4678);
	Trabajador *t2 = new Trabajador("Pedro", "Picapiedra", "", "13/05/63", "Av. Xalapa #344", 30942, "Academico", 392);
	Persona *p1 = new Persona("Enrique", "Peña", "Salinas", "09/11/47", "Av. Rebsamen #5");
	Socio *s1 = new Socio("Homero", "Simpson", "Lopez", "30/09/49", "Av. Siempreviva #5", "FEI", "S1540293");
	Socio *s2 = new Socio("Bart", "Simpson", "Nieto", "10/09/99", "Av. Siempreviva #5", "FEI", "S1040143");
	


	Trabajador tt1 = Trabajador("Juan", "Perez", "Lopez", "10/01/17", "Av. Murillo Vidal #4565", 30942, "Administrativo", 4678);
	Trabajador tt2 = Trabajador("Pedro", "Picapiedra", "", "13/05/63", "Av. Xalapa #344", 30942, "Academico", 392);
	Persona pp1 = Persona("Enrique", "Peña", "Salinas", "09/11/47", "Av. Rebsamen #5");
	Socio ss1 = Socio("Homero", "Simpson", "Lopez", "30/09/49", "Av. Siempreviva #5", "FEI", "S1540293");
	Socio ss2 = Socio("Bart", "Simpson", "Nieto", "10/09/99", "Av. Siempreviva #5", "FEI", "S1040143");
	
	
	//Declaración de un arreglo tipo Persona
	Persona *personas[5] = {NULL};
	Persona ppersonas[5];

	//Asignar a cada posición del arreglo los objetos declaros previamente	
	personas[0] = t1;
	personas[1] = p1;
	personas[2] = t2;
	personas[3] = s2;
	personas[4] = s1;
	
	ppersonas[0] = tt1;
	ppersonas[1] = pp1;
	ppersonas[2] = tt2;
	ppersonas[3] = ss2;
	ppersonas[4] = ss1;


	int arreglo[] = {10, 33, 45, 11, 2, -1, 40, 30, 45, 4};
	
	int arreglo2[10] = {10, 33, 45, 11, 2, -1, 40, 30, 45, 4};
	
	int arreglo3[9];
	
	arreglo3[0] = 10;
	arreglo3[1] = 33;
	arreglo3[2] = 45;
	arreglo3[3] = 11;
	arreglo3[4] = 2;
	arreglo3[5] = -1;
	arreglo3[6] = 40;
	arreglo3[7] = 30;
	arreglo3[8] = 45;	
	arreglo3[9] = 4;	

	unsigned int t = 10;
	t = -1;
	cout <<"T: " << t << endl;
	/*
	char cad[10];
	cout << "Hola, ¿cual es tu nombre?: ";
	cin >> cad;
	cout << "Bienvenido ;) " << cad << endl;


	char *apuntador;
	apuntador = cad;
	cout << "Mostrando información del arreglo con apuntador: " << endl;
	int indice = 0;
	
	while (*apuntador != '\0'){
		cout << *apuntador << endl;
		if (indice == 1){
			*apuntador = '5';
		}
		apuntador++;
		indice++;
	}

	int y = 150;
	
	int *ay; //?¡?¡?
	ay = &y;
	
	*ay = 10;
	
	
	int x = 5;
	int *ax;
	ax = &x;

	*ax = 10;
	
	
	delete ay;
	delete ax;
	
	
	cout << "Dirección de memoria de a102: " << &x << endl;
	cout << "Dirección de memoria de ax: " << &ax << endl;
	
	cout << "Contenido de la variable apuntador ax: " << *ax << endl;
	cout << "Contenido de la variable apuntador ax: " << x << endl;
	
	cout<< "sizeof de arreglo (bytes): " << sizeof(arreglo) << endl;
	cout<< "sizeof de un elemento del arreglo (bytes): " << sizeof(arreglo[0]) << endl;
	int tamanioarreglo = sizeof(arreglo) / sizeof(arreglo[0]);	
	int elemento = arreglo[0];
	
	for (int i = 0; i < tamanioarreglo; i++){
		cout << "Elemento( " << i << "): " << arreglo[i] << endl;
		if (elemento < arreglo[i]){
			elemento = arreglo[i]; 
		}
	}
	
	cout << "El número mayor del arreglo es: " << elemento << endl;
	
*/	
	/*
	double a = 10;
	cout << "Tamaño del double (bytes): " << sizeof(a) << endl;

	int x = 10;
	cout << "Tamaño del int (bytes): " << sizeof(x) << endl;
	
	short y = 10;
	cout << "Tamaño del short (bytes): " << sizeof(y) << endl;
	
	bool z = true;
	cout << "Tamaño del bool (bytes): " << sizeof(z) << endl;

*/
	
	
	
	
	//Iterar el arreglo con los objetos, e invocar el mostrar... 
	/*cout<<endl<<"Mostrando información de los objetos creados con apuntadores" <<endl;
	for (int i = 0; i < 5; i++){
		personas[i]->mostrar();
	}
	
	//Iterar el arreglo con los objetos, e invocar el mostrar... 
	cout<<endl<<"Mostrando información de los objetos creados" <<endl;
	for (int i = 0; i < 5; i++){
		ppersonas[i].mostrar();
	}*/
	/*
	double f = 10.0f;
	cout << "Tamaño del float (bytes): " << sizeof(f) << endl;

	unsigned int t = 10;
	t = -1;
	cout <<"T: " << t << endl;
	
	char cad[10];
	cout << "Hola, ¿cual es tu nombre?: ";
	cin >> cad;
	cout << "Bienvenido ;) " << cad << endl;


	char *apuntador;
	apuntador = cad;
	cout << "Mostrando información del arreglo con apuntador: " << endl;
	int indice = 0;
	
	while (*apuntador != '\0'){
		cout << *apuntador << endl;
		if (indice == 1){
			*apuntador = '5';
		}
		apuntador++;
		indice++;
	}
	
	cout << "Cadena: " << cad << endl;
	*/
	
	/*int numeroTmp = 10;
	int *apuntadorEntero;
	int *apuntadorEnteroSecundario;
	
	apuntadorEntero = &numeroTmp;
	//delete apuntadorEntero;
	apuntadorEnteroSecundario = apuntadorEntero;
	cout << "Dirección de memoria (numeroTmp): " << &numeroTmp << ", " << apuntadorEntero << endl; 
	
	cout << "Valor de memoria (numeroTmp): " << &numeroTmp << endl; 
	
	*apuntadorEntero = 15; 
	*apuntadorEnteroSecundario = 49;
		
	cout << "Valor de numeroTmp = " << numeroTmp << endl;
	*/
	
	return 0;
}





/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*int determinarMayor(int numeros[]){
	cout << "size in: " << sizeof(numeros) << endl;
	int inumero = numeros[0];
	int i = 1;
	while (numeros[i] != NULL){
		cout << "Número: " << numeros[i] << endl;
		
		if (numeros[i] > inumero){
			inumero = numeros[i];
			cout << "Número mayor: " << numeros[i] << endl;
		}
		i++;
	}
	
	/*
	int numeros[] = {1,3,22,1};
	cout << " size: " << sizeof(numeros) <<endl;
	
	int mayor = determinarMayor(numeros);
	
	cout << "Mayor: " << mayor << " size: " << sizeof(numeros) <<endl;
	*/
//	return inumero;
//}
