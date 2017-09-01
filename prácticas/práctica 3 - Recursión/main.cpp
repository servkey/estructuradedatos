iostream>
#include <string.h>
using namespace std;

bool isPrimoR(int n, int j){
	bool resultado = true;
	if (j > 1){
		if (n % j == 0){
			resultado = false;
		}else{
			resultado = isPrimoR(n, j-1);
		}
	}
	return resultado;
}


//Ejemplo mayor de un arreglo recursivo
int verificarMayorArregloR(int *numeros, int tn, int mayor, int i){
	//void verificarArreglo(int numeros[], int tn){
	if (i < tn)
	{
		if (mayor < numeros[i]){
			mayor = numeros[i];
		}
		mayor = verificarMayorArregloR(numeros, tn, mayor, i+1);
	}	
	return mayor;
}

//Mayor de un arreglo sin recursión
int verificarMayorArreglo(int *numeros, int tn){
	int mayor = numeros[0];
	for (int i = 0; i < tn; i++){
		if (mayor < numeros[i]){
			mayor = numeros[i];
		}
	}	
	return mayor;
}

bool r =  isPrimoRecursivoIncrementando(5, 2);


bool isPrimoRecursivoIncrementando(int n, int indice){
	bool resultado = false;
	cout << "Índice: " << indice << endl;
 	if (indice == n){
		resultado = true;
	}else if (n % indice == 0){
		resultado = false;
	}else{
		resultado = isPrimoRecursivoIncrementando(n, indice + 1);
	}
	return resultado;	
}

bool isPrimoRecursivoIncrementandoTransparente(int n){
	return isPrimoRecursivoIncrementando(n, 2);
}


bool isPrimoRecursivo(int n, int indice){
	bool resultado = false;
	if ((indice-1) == 1){
		resultado = true;
	}else if (n % (indice-1) == 0){
		resultado = false;
	}else{
		resultado = isPrimoRecursivo(n, indice-1);
	}
	return resultado;	
}


bool isPrimoRecursivoTransparente(int n){
	return isPrimoRecursivo(n, n);
}


bool isPrimo(int n){
	bool esPrimo = true;
	for (int j = n - 1; j > 1; j--)
	{			
		if (n % j == 0){
			esPrimo = false;
			break;
		}
	}
	return esPrimo;	
}


void verificarArreglo(int *numeros, int tn){
	//void verificarArreglo(int numeros[], int tn){
	for (int i = 0; i < tn; i++)
	{
		int n = numeros[i];
		
		if (isPrimo(n))		
			cout << "El número " << n << " es primo " << endl; 		
	}	
}

int factorial(int numero){
	int resultado = 1;
	for (int i = numero; i > 0; i--){
		resultado = resultado * i;
	}
	return resultado;
}


int factorialRecursivo(int numero){
	int resultado = 1;
	if (numero == 0){
		return resultado;
	}else
	{
		resultado = numero * factorialRecursivo(numero - 1);
	}
	return resultado;
}

//Sumar arreglo versión iterativa
int sumarArreglo(int numeros[], int ta){
	int sumatoria;
	for (int i = 0; i < ta; i++){
		sumatoria = sumatoria + numeros[i];
	}
	return sumatoria;
}

//Sumar arreglo versión recursiva
int sumarArregloRecursiva(int numeros[], int ta, int i){
	int sumatoria = 0;
	if  (i < ta){
		sumatoria = numeros[i] + sumarArregloRecursiva(numeros, ta, i + 1);
	}
	return sumatoria;
}

int main(int argc, char** argv) {
	int numerosA[] = {1, 4, 42, 2};
	int ta = sizeof(numerosA)/sizeof(numerosA[0]);
	int resultadoFuncion = sumarArreglo(numerosA, ta);
	int resultadoFuncionR = sumarArregloRecursiva(numerosA, ta, 0);

	cout << "Primo (5): " << isPrimo(999983) << endl;
	
	//cout << "Primo (4): " << isPrimo(4801) << endl;
	
	//Versión 1 - decrementando indice
	
	cout << "Primo (2341): " << isPrimoRecursivoTransparente(2341) << endl;
 	
/* 	system("PAUSE()"); 
	cout << "Primo (5): " << isPrimoRecursivo(999983, 999983) << endl;
 	system("PAUSE()"); 
*/	
	//cout << "Primo (4): " << isPrimoRecursivo(4801, 4801) << endl;

	
	
	cout << "Primo (5): " << isPrimoRecursivoIncrementandoTransparente(5) << endl;
	//cout << "Primo (4): " << isPrimoRecursivoIncrementandoTransparente(4) << endl;
	//cout << "Primo (179): " << isPrimoRecursivoIncrementandoTransparente(179) << endl;


	cout << "Factorial (5): " << factorial(5) << endl;
	cout << "Factorial Recursivo (5): " << factorialRecursivo(5) << endl;
	
	cout << "La sumatoria de los elementos del arreglo es: " << resultadoFuncion << endl;

	cout << "La sumatoria de los elementos del arreglo es (recursiva): " << resultadoFuncionR << endl;
/*
	int numeros[] = {15670, 21, 1, 3, 4, 50, 7, 300};
	int tn = sizeof(numeros) / sizeof(numeros[0]);
	verificarArreglo(numeros, tn);	
	
	cout << "El número mayor del arreglo es " << verificarMayorArregloR(numeros, tn, numeros[0], 0) << endl;
	cout << "El número mayor del arreglo es " << verificarMayorArreglo(numeros, tn) << endl;

	cout << "Factorial (5): " << factorial(5) << endl;
*/
/*	int i1 = 1, i2 = 3, i3 = 5, i4 = 8;
	cout << i1 << " es primo: " << isPrimoR(i1, i1-1) << endl;
	cout << i2 << " es primo: " << isPrimoR(i2, i2-1) << endl;
	cout << i3 << " es primo: " << isPrimoR(i3, i3-1) << endl;
	cout << i4 << " es primo: " << isPrimoR(i4, i4-1) << endl;
	
	int numerossuma[] = {1, 2, 3, 4};
	cout<< "La suma es :" << sumar(numerossuma, 4, 0) << endl;
	cout<< "La suma es :" << sumar2(numerossuma, 4) << endl;
	cout<< "La suma es :" << sumariter(numerossuma, 4) << endl;
	
	mostrar(3);
*/
	return 0;
}

