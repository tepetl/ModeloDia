/* 
 * File:   Entrada.h
 * Author: alfonso
 *
 * Created on 10 de julio de 2013, 04:02 PM
 */

#ifndef ENTRADA_H
#define	ENTRADA_H

using namespace std;

class Entrada {
    
public:
    double lectura;
    long tiempo;
    long tiempo_real;
    
    
    int sigma;
    
    Entrada(double lectura,long tiempo,long tiempo_real);

};

#endif	/* ENTRADA_H */

