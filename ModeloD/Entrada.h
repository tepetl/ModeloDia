/* 
 * File:   Entrada.h
 * Author: alfonso
 *
 * Created on 10 de julio de 2013, 04:02 PM
 */

#ifndef ENTRADA_H
#define	ENTRADA_H

#include <string>
#include <vector>


using namespace std;

class Entrada {
    
public:
    double lecturadp;
    long tiempo;
    long tiempo_real;
    
    vector<string> vs;
    
    double clase_sigma;
    
    Entrada(double lectura,long tiempo,long tiempo_real);

};

#endif	/* ENTRADA_H */

