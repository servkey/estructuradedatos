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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	//Declaración de objetos, Persona, Socio, Trabajador... p1, p2, s1, s2, ...
	
	Trabajador *t1 = new Trabajador("Juan", "Perez", "Lopez", "10/01/17", "Av. Murillo Vidal #4565", 30942, "Administrativo", 4678);
	Trabajador *t2 = new Trabajador("Pedro", "Picapiedra", "", "13/05/63", "Av. Xalapa #344", 30942, "Academico", 392);
	Persona *p1 = new Persona("Enrique", "Peña", "Salinas", "09/11/47", "Av. Rebsamen #5");
	Socio *s1 = new Socio("Homero", "Simpson", "Lopez", "30/09/49", "Av. Siempreviva #5", "FEI", "S1540293");
	Socio *s2 = new Socio("Bart", "Simpson", "Nieto", "10/09/99", "Av. Siempreviva #5", "FEI", "S1040143");
	

	//Declaración de un arreglo tipo Persona
	Persona *personas[5] = {NULL};

	//Asignar a cada posición del arreglo los objetos declaros previamente	
	personas[0] = t1;
	personas[1] = p1;
	personas[2] = t2;
	personas[3] = s2;
	personas[4] = s1;
	
	//Iterar el arreglo con los objetos, e invocar el mostrar...
	cout<<endl<<"Mostrando información de los objetos creados" <<endl;
	
	for (int i = 0; i < 5; i++){
		personas[i]->mostrar();
	}
	
	return 0;
}
