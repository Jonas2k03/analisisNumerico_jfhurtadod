
/**
 * @file
 * @brief Metodo de Newton Raphson Generalizado
 * @author Jonathan Felipe Hurtado Díaz
 * @copyright MIT License
*/

#ifndef NEWTON_RAPHSON_G_H
#define NEWTON_RAPHSON_G_H

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
	 * @brief Metodo Newton Raphson Generalizado
	*/
	
	class newton_raphson_g {
		

	/**
	* @brief Crea una instancia de newton_raphson_g
	* @param str_func Texto de la funcion
	* @param str_dev Texto de la derivada de la funcion
	* @param str_2dev Texto de la segunda derivada de la funcion
	*/
	public:
		newton_raphson_g(string str_func, string str_dev, string str_2dev):f(str_func), df(str_dev), d2f(str_2dev) {
			
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
				
				double p = p0 - (
								 (f(p0) * df(p0))
								 /
								 (
								  pow(df(p0),2)-
								  (f(p0)* d2f(p0))
								  )
								 );
				
				//Crear la instancia de aproximacion 
				aproximacion ap(p0, p);
				
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
				expression d2f; /*!< Evaluador de la segunda derivada de la funcion */
	};
	
	
};


#endif
