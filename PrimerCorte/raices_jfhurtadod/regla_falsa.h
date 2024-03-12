#ifndef REGLA_FALSA_H
#define REGLA_FALSA_H
#include "biseccion.h"

#include <cmath>
#include <iostream>
#include <string.h>
#include "expression.h"
#include "raices.h"

using raices::es_raiz;
using std::cout;
using std::endl;
using std::string;
using raices::aproximacion;
using raices::solucion;



namespace raices{
	/**
	 * @brief Metodo de biseccion
	*/
	class regla_falsa{
	public:
		/**
		* @brief Crea una instancia de biseccion
		* @param str_func Texto de la funcion
		*/
		regla_falsa(string str_func):f(str_func){
		}
		/**
		* @brief Encuentra una raiz con los parametros dados
		* @param xi Valor inferior del intervalo
		* @param xs Valor superior del intervalo
		* @param tol Tolerancia (Error relativo porcentual)
		*/
		solucion encontrar_raiz(double xi, double xs, double tol, int n){
			//solucion a retornar
			solucion sol;
			if(es_raiz(f, xi)) {
				sol.raiz = xi;
				return sol;
			}
			
			if(es_raiz(f, xs)) {
				sol.raiz = xs;
				return sol;
			}
			
			if(f(xi)* f(xs) > 0) {
				return sol;
			}
			
			//Paso 1
			int i=1;
			//Paso 2 Calcular la primera aproximacion y evaluar en cual sub-intervalo continuar
			double xrAnt = xs - ((f(xs)* (xi-xs))/(f(xi) - f(xs)));
			if(f(xi)*f(xrAnt)>0.0f){
				xi = xrAnt;
			}
			else{
				xs = xrAnt;
			}
			//Paso 3
			while(i<=n){
				//Paso 4 calculo de la nueva raiz y el error relativo
				double xrNueva = xs - ((f(xs)* (xi-xs))/(f(xi) - f(xs)));
				
				//Crear una instancia de aproximacion
				aproximacion ap(xrAnt, xrNueva);
				
				//Adicionar la nueva aproximacion al vector solucion
				sol.agregar(ap);
				
				//Paso 5
				if(fabs(f(xrNueva))<DBL_EPSILON || ap.erp < tol){
					sol.raiz = xrNueva;
					return sol;
				}
				//Paso 6
				i++;
				//Paso 7
				if(f(xi)*f(xrNueva)>0.0f){
					xi = xrNueva;
				}
				else{
					xs = xrNueva;
				}
				xrAnt = xrNueva;
			};
			
			return sol;
		}
	private:
				expression f; //Evaluador de la funcion
	};
};

#endif
