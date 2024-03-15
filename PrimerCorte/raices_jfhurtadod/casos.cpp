
#include "casos.h"
#include<iostream>
#include "biseccion.h"
#include "expression.h"
#include <string>
#include "raices.h"
#include "regla_falsa.h"
#include "newton_raphson.h"
#include "casos.h"
#include "secante.h"
#include "newton_raphson_g.h"
#include "muller.h"

using raices::biseccion;
using raices::regla_falsa;
using raices::aproximacion;
using raices::solucion;
using raices::imprimir_solucion;
using raices::newton_raphson;
using std::cout;
using std::endl;
using std::string;
using raices::secante;
using raices::newton_raphson_g;
using raices::muller;

#define TOL 1e-5f





void caso_1() {
	string str_func = "e^~(x)-ln(x)";
	double xInf = 1.0f; //Extremo inferior
	double xSup = 1.5f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = TOL; //Error relativo procentual
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
	
	//Tomar la primera 
	double p0 = xInf; //Extremo inferior
	
	
	string str_devf = "~e^~(x)-(1/x)"; //Derivada de la funcion
	
	cout << "\nSolucion por el metodo de newton_raphson" << endl;
	newton_raphson nr(str_func,str_devf);
	
	solucion solNr = nr.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNr);
	
	cout << "\nSolucion por el metodo de la secante" << endl;
	
	double x0 = xInf;
	double x1 = xSup;
	secante sec(str_func);
	
	solucion solSec =sec.encontrar_raiz(x0,x1, tol, n);
	
	imprimir_solucion(solSec);
	
	cout << "\nSolucion por el metodo de Muller" << endl;
	
	
	 x0 = 0.5f;
	 x1 = 2.0f;
	 double x2 = 4.0f;
	 
	 cout << "Puntos de la parabola: " << x0 << "..." << x1 << "..."<< x2  <<endl;
	
	muller mull(str_func);
	
	solucion solMull =mull.encontrar_raiz(x0,x1,x2, tol, n);
	
	imprimir_solucion(solMull);
	
}

void caso_2() {
	string str_func = "x^3+4*x^2-10";
	double xInf = -0.5f; //Extremo inferior
	double xSup = 0.5f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = TOL; //Error relativo procentual
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
	
	//Tomar la primera 
	double p0 = xInf; //Extremo inferior
	
	
	string str_devf = "3*x^2 + 8*x"; //Derivada de la funcion
	
	cout << "\nSolucion por el metodo de newton_raphson" << endl;
	newton_raphson nr(str_func,str_devf);
	
	solucion solNr = nr.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNr);
	
	cout << "\nSolucion por el metodo de la secante" << endl;
	secante sec(str_func);
	double x0= xInf;
	double x1=xSup;
	solucion solSec =sec.encontrar_raiz(x0,x1, tol, n);
	
	imprimir_solucion(solSec);
}
void caso_3(){
	string str_func = "(e^(~x)) + x^2 - 2";
	double xInf = -1.0f; //Extremo inferior
	double xSup = 0.0f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = TOL; //Error relativo procentual
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
	
	//Tomar la primera 
	double p0 = xInf; //Extremo inferior
	
	
	string str_devf = "(~e^(~x)) + 2*x"; //Derivada de la funcion
	
	cout << "\nSolucion por el metodo de newton_raphson" << endl;
	newton_raphson nr(str_func,str_devf);
	
	solucion solNr = nr.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNr);

	cout << "\nSolucion por el metodo de la secante" << endl;
	
	double x0 = xInf;
	double x1 = xSup;
	secante sec(str_func);
	
	solucion solSec =sec.encontrar_raiz(x0,x1, tol, n);
	
	imprimir_solucion(solSec);
}


	
void caso_4() {
	string str_func = "(e^~(x^2)) - x";
	double x0 = -0.5f; //Extremo inferior
	double x1 = 0.5f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = 1.0f; //Error relativo procentual
	int n = 100; //Iteracion maxima
	
	
	
	cout << "Funcion: " << str_func << endl;
	cout << "Intervalo: " << x0 << "..." << x1  <<endl;
	

	
	cout << "\nSolucion por el metodo de la secante" << endl;
	secante sec(str_func);
	
	solucion solSec =sec.encontrar_raiz(x0,x1, tol, n);
	
	imprimir_solucion(solSec);
	
	
}


void caso_5() {
	string str_func = "2*(e^(~x)) - sen(x)";
	double x0 = 1.2f; //Extremo inferior
	double x1 = 2.0f; //Exremo superior
	
	/*
	expression f(str_func);
	cout << "xInf=" << xInf << "f(" << xInf << ")  " << f(xInf) << endl;
	cout << "xSup=" << xSup << "f(" << xSup << ")  " << f(xSup) << endl;
	*/
	
	double tol = 1.0f; //Error relativo procentual
	int n = 100; //Iteracion maxima
	
	
	
	cout << "Funcion: " << str_func << endl;
	cout << "Intervalo: " << x0 << "..." << x1  <<endl;
	
	
	
	cout << "\nSolucion por el metodo de la secante" << endl;
	secante sec(str_func);
	
	solucion solSec =sec.encontrar_raiz(x0,x1, tol, n);
	
	imprimir_solucion(solSec);
	
	
}
void caso_6() {
	
	double p0 = 2.33f; //Extremo inferior
	string str_func = "x^3 - (5*(x^2)) + (7*x) -3";
	string str_devf = "3*x^2 - 10*x + 7"; //Derivada de la funcion
	string str_dev2f = "6*x - 10"; //Derivada de la funcion
	
	double tol = 0.01f; //Error relativo procentual
	int n = 100; //Iteracion maxima
	
	
	cout << "\nSolucion por el metodo de Newton Raphson Generalizado" << endl;
	newton_raphson_g nrg(str_func,str_devf, str_dev2f);
	
	solucion solNrg = nrg.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNrg);
	
	
}

void caso_parcial() {
	
	//string str_func = "x^2 * (0.6e-6f) - ((2 * sqrt(2)) / 225) * x - 2";
	string str_func= "x^2*(0.6*e-6f) - (((2 * sqrt(2)) / 225)*x - 2";
	double xInf = 0.0f;
	double xSup = 50.0f;
	
	int n = 100;
	cout << "\nSolucion por el metodo de regla falsa" << endl;
	
	//Crea una instancia del metodo
	regla_falsa rf(str_func);
	
	//Entrontrar la raiz en el intervalo dado.
	solucion solRf =rf.encontrar_raiz(xInf, xSup, TOL, n);
	
	//Imprimir la solucion
	imprimir_solucion(solRf);
	
	cout << "\nSolucion por el metodo de la secante" << endl;
	
	double x0 = xInf;
	double x1 = xSup;
	secante sec(str_func);
	
	solucion solSec =sec.encontrar_raiz(x0,x1, TOL, n);
	
	imprimir_solucion(solSec);
	
	cout << "\nSolucion por el metodo de newton_raphson" << endl;
	double p0 = xInf;
	string str_devf = "2*x*(0.6e-6f) - ((2 * sqrt(2)) / 225)";
		
	newton_raphson nr(str_func,str_devf);
	
	solucion solNr = nr.encontrar_raiz(p0, TOL, n);
	
	imprimir_solucion(solNr);
}
void caso_parcial2() {
	double tol = TOL;
	int n = 100;
	
	double xInf = 0.0f;
	double xSup = 20.0f;
	string str_func = "-36.05*x^7 + 546x^6 + 22449*x^4 + 67284*x^3 + 118124x^2 - 109584x";
	string str_devf = "7*-36.05*x^6 + 6*546x^5 + 4*22449*x^3 + 3*67284*x^2 + 2*118124x - 109584";
	string str_dev2f = "6*7*-36.05*x^5 + 6*5*546x^4 + 4*3*22449*x^2 + 3*2*67284*x + 2*118124";

	cout << "\nSolucion por el metodo de newton_raphson" << endl;
	newton_raphson nr(str_func,str_devf);
	
	double p0=xInf;
	solucion solNr = nr.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNr);
	
	cout << "\nSolucion por el metodo de Newton Raphson Generalizado" << endl;
	newton_raphson_g nrg(str_func,str_devf, str_dev2f);
	
	solucion solNrg = nrg.encontrar_raiz(p0, tol, n);
	
	imprimir_solucion(solNrg);
}
