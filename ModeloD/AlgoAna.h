/* 
 * File:   AlgoAna.h
 * Author: alfonso
 *
 * Created on 17 de agosto de 2013, 08:16 PM
 */

#ifndef ALGOANA_H
#define	ALGOANA_H

#include <vector>
#include <algorithm>
#include <cmath>

#include "Entrada.h"
#include "CEntrada.h"


using namespace std;


class AlgoAna {
public:
    AlgoAna();

    void calculaMedia(vector<Entrada>& vEnt,vector<CEntrada> &vCent);
    
    void calculaVarSDC(vector<Entrada>& vEnt,vector<CEntrada> &vCent);
     
    void clasificaEntradas(vector<Entrada>& vEnt, vector<CEntrada>& vCent);
    
    virtual ~AlgoAna();
private:

    CEntrada creaCEntrada(long tiempo, double lectura);
    
    void sumaEntrada(Entrada &ent,vector<CEntrada> &vCent);
};

#endif	/* ALGOANA_H */

