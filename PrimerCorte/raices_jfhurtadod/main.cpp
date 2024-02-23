#include<iostream>
#include "biseccion.h"
#include "expression.h"
#include <string>
#include "raices.h"
#include "regla_falsa.h"

using std::cout;
using std::endl;
using std::string;

using raices::biseccion;
using raices::regla_falsa;
using raices::aproximacion;
using raices::solucion;
using raices::imprimir_solucion;

int main (int argc, char *argv[]) {
	
	string str_func = "e^~(x)-ln(x)";
	double xInf = 1.0f; //Extremo inferior
	double xSup = 1.5f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = 1.0f; //Error relativo procentual
	int n = 100; //Iteracion maxima
	
	
	
	cout << "Funcion: " << str_func << endl;
	cout << "Intervalo: " << xInf << "..." << xSup  <<endl;


	cout << "\nSolucion por el metodo de biseccion" << endl;
	
	//Crea una instancia del metodo
	biseccion b(str_func);
	
	//Entrontrar la raiz en el intervalo dado.
	solucion sol = b.encontrar_raiz(xInf, xSup, tol, n);
	
	//Imprimir la solucion
	imprimir_solucion(sol);
	
	cout << "\nSolucion por el metodo de regla falsa" << endl;
	
	//Crea una instancia del metodo
	regla_falsa rf(str_func);
	
	//Entrontrar la raiz en el intervalo dado.
	solucion solRf =rf.encontrar_raiz(xInf, xSup, tol, n);
	
	//Imprimir la solucion
	imprimir_solucion(solRf);
	
	
	
	
	return 0;
}

