#ifndef NEWTON_RAPHSON_H
#define NEWTON_RAPHSON_H

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
	* @brief Crea una instancia de newton_raphson
	* @param str_func Texto de la funcion
	* @param str_dev Texto de la derivada de la funcion
	*/
	class newton_raphson {
		
	public:
		newton_raphson(string str_func, string str_dev):f(str_func), df(str_dev) {
				
		}
			
		/**
		* @brief Encuentra una raiz con los parametros dados
		* @param p0 Punto inicial
		* @param tol Tolerancia (Error relativo porcentual)
		* @param n Numero maximo de iteraciones
		*/
			
		solucion encontrar_raiz(double p0, double tol, int n){
				
			solucion sol;
			if(es_raiz(f, p0)) {
				sol.raiz = p0;
				return sol;
			}
			//Paso 1
			int i= 1;
			
			//Paso 2 
			while (i<=n) {
				
				//Paso 3 
				
				double p = p0 - (f(p0)/df(p0));
				
				//Crear la instancia de aproximacion 
				aproximacion ap(p0, p);
				
				//Adicionar la aproximacion a la solucion
				sol.agregar(ap);
				
				//Paso 4 
				
				if (ap.erp < tol) {
					
					sol.raiz = p;
					return sol;
				}
				//Paso 5
				i++;
				
				p0 = p;
				
			}
			
			return sol;
		}
			
	private:
			expression f; /*!< Evaluador de la funcion */
			expression df; /*!< Evaluador de la derivada de la funcion */
	};
		
		
};



#endif
