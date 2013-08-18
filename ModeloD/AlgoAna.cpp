/* 
 * File:   AlgoAna.cpp
 * Author: alfonso
 * 
 * Created on 17 de agosto de 2013, 08:16 PM
 */

#include "AlgoAna.h"

AlgoAna::AlgoAna() {
}

AlgoAna::~AlgoAna() {
}

/**
 * 
 * @param vEnt
 * @param vCent
 * @return 
 */
void AlgoAna::calculaMedia(vector<Entrada>& vEnt, vector<CEntrada>& vCent) {

    for (vector<Entrada>::iterator itren = vEnt.begin(); itren != vEnt.end(); itren++) {
        this->sumaEntrada(*itren, vCent);
    }

    for (vector<CEntrada>::iterator it = vCent.begin(); it != vCent.end(); it++) {
        it->avg = it->slectura /= it->n;
    }

}

/**
 * 
 * @param vEnt
 * @param vCent
 * @see http://en.wikipedia.org/wiki/Variance
 */
void AlgoAna::calculaVarSDC(vector<Entrada>& vEnt, vector<CEntrada>& vCent) {
    for (vector<CEntrada>::iterator it = vCent.begin(); it != vCent.end(); it++) {
        double aux = 0.0;
        for (vector<Entrada>::iterator itren = vEnt.begin(); itren != vEnt.end(); itren++) {

            if (it->tiempo == itren->tiempo) {
                aux = +pow(itren->lectura - it->avg, 2);
            }

        }

        it->variance = aux / it->n;
        it->csigma = sqrt(aux / (it->n - 1));
    }
}

/**
 * 
 * @param vEnt
 * @param vCent
 */
void AlgoAna::clasificaEntradas(vector<Entrada>& vEnt, vector<CEntrada>& vCent) {
    for (vector<CEntrada>::iterator it = vCent.begin(); it != vCent.end(); it++) {
        for (vector<Entrada>::iterator itren = vEnt.begin(); itren != vEnt.end(); itren++) {

            if (itren->tiempo == it->tiempo) {
                itren->clase_sigma = ceil(fabs(itren->lectura - it->avg) / it->csigma);
            }

        }
    }
}

/**
 * 
 * @param tiempo
 * @param lectura
 * @return 
 */
CEntrada AlgoAna::creaCEntrada(long tiempo, double lectura) {

    CEntrada cen;

    cen.tiempo = tiempo;
    cen.slectura = lectura;

    return cen;
}

/**
 * 
 * @param ent
 * @param vCent
 */
void AlgoAna::sumaEntrada(Entrada& ent, vector<CEntrada>& vCent) {

    if (vCent.size() == 0) {

        vCent.push_back(this->creaCEntrada(ent.tiempo, ent.lectura));
        return;

    }

    for (vector<CEntrada>::iterator it = vCent.begin(); it != vCent.end(); it++) {

        if (it->tiempo == ent.tiempo) {
            it->slectura += ent.lectura;
            it->n += 1.0;
            return;
        }

    }

    vCent.push_back(this->creaCEntrada(ent.tiempo, ent.lectura));

}