/* 
 * File:   CEntrada.h
 * Author: alfonso
 *
 * Created on 17 de agosto de 2013, 07:37 PM
 */

#ifndef CENTRADA_H
#define	CENTRADA_H

class CEntrada {
public:
    
    double avg;
    long tiempo;
    double variance;
    double csigma;
    
    /**
     * Lectura acumulada
     */
    double slectura;
    
    /**
     * Total de lecturas 
     */
    double n;
    
    CEntrada();
   
    
private:

};

#endif	/* CENTRADA_H */

