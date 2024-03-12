#ifndef MULLER_H
#define MULLER_H

#include <cmath>
#include <iostream>
#include <string.h>
#include "expression.h"
#include "raices.h"


using std::cout;
using std::endl;
using std::string;
using raices::aproximacion;
using raices::solucion;


namespace raices {
	/**
	 *	@brief Metodo de muller
	*/
	class muller {
		
		/**
		 * @brief Crea una instancia de muller
		 * @param str_func Texto de la funcion 
		*/
	public: 
		muller(string str_func):f(str_func) {
			
		}
		
		/**
		* @brief Encuentra una raiz usando el metodo de Muller con los parametros dados
		*
		* @param x0 Punto inicial
		* @param x1 Punto inicial
		* @param x2 Punto inicial
		* @param tol Tolerancia (Error relativo porcentual)
		* @param n Numero maximo de iteraciones
		*
		* @return Aproximacion de la funcion
		*/
		
		solucion encontrar_raiz(double x0,double x1,double x2, double tol, int n){
			
			solucion sol;
			
			if(es_raiz(f, x1)) {
				sol.raiz = x1;
				return sol;
			}
			
			if(es_raiz(f, x2)) {
				sol.raiz = x2;
				return sol;
			}
			
			//Paso1 
			double h1 = x1-x0;
			double h2 = x2-x1;
			
			double d1 = ((f(x1)-f(x0))/h1);
			double d2 = ((f(x2)-f(x1))/h2);
			
			double a = ((d2-d1)/(h2+h1));
			
			int i = 2;
			
			//Paso 2
			
			while (i<=n) {
				
				//Paso 3
				double b = d2 + (h2*a);
				double c = f(x2);
				double D = sqrt(pow(b,2))-(4.0f*a*c);
				
				//Paso 4
				double E = b-D;
				if(fabs(b-D) < fabs(b+D)) {
					E = b + D;
				}
				
				//Paso 5
				
				double h = (-2.0f * c)/E;
				double p = x2 + h;
				
				//Paso 6
				
				
				//Establecer la raiz y retornar si cumple el parametro de la tolerancia
				aproximacion ap(x2,p);
				
				sol.agregar(ap);
				if(ap.erp < tol) {
					sol.raiz = p; //METODO ESTABLECER 
					return sol;
				}
				
				//Paso 7 
				
				x0 = x1;
				x1=x2;
				x2=p;
				
				h1 = x1-x0;
				h2 = x2-x1;
				
				d1 = ((f(x1)-f(x0))/h1);
				d2 = ((f(x2)-f(x1))/h2);
				
				a = ((d2-d1)/(h2+h1));
				
				i++;
				
			}
			
			return sol;
		}
		
		
		
	private:
			expression f; /*!< Evaluador de la funcion */
		
	};
	
	
};

#endif
