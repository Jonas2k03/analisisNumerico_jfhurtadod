/**
*@file
*@brief Definiciones de los metodos para hallar raices. 

*@copyright MIT license
*/

#ifndef RAICES_H
#define RAICES_H

#include <iomanip>
#include <cmath>
#include <vector>
#include <iostream>


using std::cout;
using std::endl;
using std::vector;
using std::setw;
using std::setprecision;

namespace raices {
	
	/**
	*@brief Aproximacion de una raiz
	*/
	struct aproximacion {
		double anterior; /*!< Valor anterior*/
		double nuevo; /*!< Valor Nuevo*/
		double erp; /*!< Error Relativo Porcentual*/
		
		/**
		*@brief Crea una nueva instancia de aproximacion
		*@param vAnterior Valor anerior
		*@param vNuevo Valor nuevo
		*/
		aproximacion(double vAnterior, double vNuevo) : anterior(vAnterior), nuevo(vNuevo) {
			
			erp = fabs((nuevo-anterior)/nuevo) * 100.0f;
			
		};
	};
	
	/**
	* @brief Solucion de un metodo para hallar la raiz
	*/
	struct solucion {
		double raiz = NAN; /*!< Valor de la raiz */
		vector<aproximacion> aproximaciones; /*!< Aproximaciones realizadas */
		
		/**
		* @brief Adiciona una nueva aproximacion
		* @param a Nueva aproximacion
		*/
		void agregar(aproximacion a) {
			aproximaciones.push_back(a);
		}
	};
	/**
	 * @brief Determina si el x dado se evalua en cero (es raíz)
	 * @param f Evaluador de la funcion
	 * @param x Valor a evaluar
	 * @return true si f(x) = 0, false en caso contrario
	*/
	bool es_raiz(expression & f, double x){
		
		
		return fabs(f(x)) <= DBL_EPSILON;
	}
	
	/**
	* @brief Imprime una solucion encontrada
	* @param sol solucion
	*/
	void imprimir_solucion(solucion & sol) {
		if(std::isnan(sol.raiz)) {
			cout << "No se pudo encontrar la raiz" << endl;
		}
		else {
			cout << "Raiz: " << setprecision(9) << sol.raiz <<endl;
		}
		
		size_t cantAproximaciones = sol.aproximaciones.size();
		//Terminar la funcion si no se realizaron aproximaciones
		if (cantAproximaciones == 0 ) {
			return;
		}
		
		cout<<"Aproximaciones: " << cantAproximaciones << endl;
		
		cout 
			<< setw(15) << "Anterior"
			<< setw(3) << "   "
			<<setw(15) << "Nuevo" 
			<<setw(3) << "   "
			<<setw(2) << "Error rel. porcent."
			<< endl;
		
		for(size_t i = 0; i<cantAproximaciones; i++) {
			const aproximacion ap = sol.aproximaciones[i];
			cout
				<< setw(15) <<setprecision(9)<<ap.anterior
				<< setw(3) <<"   "
				<< setw(15) <<setprecision(9) <<ap.nuevo
				<< setw(3) <<"   "
				<< setw(20) <<setprecision(3) << ap.erp 
				<< endl;
		}
		
	}
	
	/**
	* @brief Establece la raiz encontrada
	* @param val Valor de la raiz
	*/
	
	
	
};

#endif
