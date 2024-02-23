#ifndef BISECCION_H
#define BISECCION_H

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

namespace raices{
	
	/**
	* @brief Crea una instancia de biseccion
	* @param str_func Texto de la funcion
	*/
	class biseccion{
	public:
		
		/**
		* @brief Encuentra una raiz con los parametros dados
		* @param xa Valor inferior del intervalo
		* @param xs Valor superior del intervalo
		* @param tol Tolerancia (Error relativo porcentual)
		*/
		biseccion(string str_func):f(str_func){
		}
		solucion encontrar_raiz(double xa, double xb, double tol, int n){
			//solucion a retornar
			solucion sol;
			
			
			//Paso 1
			int i=1;
			//Paso 2 Calcular el punto medio y evaluar en cual sub-intervalo continuar
			double xAnt = (xa+xb)/2.0f;
			if(f(xa)+f(xAnt)>0.0f){
				xa = xAnt;
			}
			else{
				xb = xAnt;
			}
			//Paso 3
			while(i<=n){
				//Paso 4 calculo de la nueva raiz y el error relativo
				double xNueva = (xa+xb)/2.0f;
				
				//Crear una instancia de aproximacion
				aproximacion ap(xAnt, xNueva);
				
				//Adicionar la nueva aproximacion al vector solucion
				sol.agregar(ap);
				
				//Paso 5
				if(xNueva<DBL_EPSILON || ap.erp < tol){
					sol.raiz = xNueva;
					return sol;
				}
				//Paso 6
				i++;
				//Paso 7
				if(f(xa)*f(xNueva)>0.0f){
					xa = xNueva;
				}
				else{
					xb = xNueva;
				}
				xAnt = xNueva;
			};
			
			return sol;
		}
	private:
				expression f; //Evaluador de la funcion
	};
};

#endif
