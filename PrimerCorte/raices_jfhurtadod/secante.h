
/**
 * @file 
 * @brief Declaraciones del método de la secante 
 * @author Jonathan Felipe Hurtado Díaz <jfhurtadod@unicauca.edu.co>
*/

#ifndef SECANTE_H
#define SECANTE_H

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
	* @brief Metodo de la secante
	*/
	class secante {
		
		/**
		* @brief Crea una instancia del metodo de la secante
		* @param str_func Texto de la funcion
		*/
		
	public:
		secante(string str_func):f(str_func) {
			
		}
		
		/**
		* @brief Encuentra una raiz con los parametros dados
		* @param x0 Valor del primer punto
		* @param x1 Valor del segundo punto
		* @param tol Tolerancia (Error relativo porcentual)
		* @param n Numero maximo de iteraciones
		* @return Solucion del metodo
		*/
		
		solucion encontrar_raiz(double x0, double x1, double tol, int n){
			
			solucion sol;
			
			if(es_raiz(f, x0)) {
				sol.raiz = x0;
				return sol;
			}
			if(es_raiz(f, x1)) {
				sol.raiz = x1;
				return sol;
			}
			int i = 1;
			
			do{
				
				//Calcular la nueva aproximacion 
				double x2 = x1 - (( f(x1) * (x0-x1) )/( f(x0) - f(x1) ));
				//Crear la instancia de aproximacion
				aproximacion aprox(x1,x2);
				//Adicionar la aproximacion a la solucion
				sol.agregar(aprox);
				//Verificar si se encontró la raíz
				
				if(aprox.erp < tol) {
					sol.raiz=x2;
					return sol;
				}
				//Siguiente iteracion
				i++;
				//Actualizar los valores x0 y x1
				x0 = x1;
				x1=x2;
				
			} while(i<=n);
			
			
			//Retornar la solucion
			return sol;
		}
			
	private:
				expression f; /*!< Evaluador de la funcion */
	};
	
	
};


#endif
