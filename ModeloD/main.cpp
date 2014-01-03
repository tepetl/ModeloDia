/** 
 * @file   main.cpp
 * @author AAFR <alffore@yahoo.com.mx>
 *
 * Creado el 10 de julio de 2013, 02:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>

#include "Entrada.h"
#include "CEntrada.h"
#include "LectorData.h"
#include "AlgoAna.h"

using namespace std;


void imprimeEntradas(vector<Entrada> &vEnt);
void imprimeCEntradas(vector<CEntrada> &vCent);

string snomarch;

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {

    if (argc == 1) {
        cout << "Falta ..." << endl;
    }

    vector<Entrada> vEnt;
    LectorData lecd;

    snomarch = string(argv[1]);
    cout << "Se lee el archivo: " << snomarch << endl;
    lecd.leeArchivo(snomarch, vEnt);


    vector<CEntrada> vCent;

    AlgoAna ana;
    cout << "Calculan las medias, variancia y se clasifica " << endl;
    ana.calculaMedia(vEnt, vCent);
    ana.calculaVarSDC(vEnt, vCent);
    ana.clasificaEntradas(vEnt, vCent);

    cout << "Imprime las entradas clasificadas " << endl;
    imprimeEntradas(vEnt);

    cout << "Imprime el clasificador" << endl;

    imprimeCEntradas(vCent);

    return 0;
}

/**
 * @brief función que imprime un vector con las entradas 
 * @param vEnt
 */
void imprimeEntradas(vector<Entrada> &vEnt) {
    string sna = snomarch + ".ent";
    ofstream miar(sna.c_str());


    if (miar.is_open()) {

        for (vector<Entrada>::iterator it = vEnt.begin(); it != vEnt.end(); it++) {
            vector<string> vs = (*it).vs;

            for (vector<string>::iterator itc = vs.begin(); itc != vs.end(); ++itc) {
                miar << *itc << "|";
            }
            miar << it->clase_sigma;
            //miar <<"|"<< it->;

            miar << endl;
        }


        miar.close();
    }
}

/**
 * 
 * @param vCEnt
 */
void imprimeCEntradas(vector<CEntrada> &vCEnt) {
    string sna = snomarch + ".cent";
    ofstream miar(sna.c_str());


    if (miar.is_open()) {

        for (vector<CEntrada>::iterator it = vCEnt.begin(); it != vCEnt.end(); it++) {
            miar << it->avg << "|" << it->csigma << "|" << it->n << "|" << it->slectura << "|" << it->tiempo << "|" << it->variance << endl;
        }


        miar.close();
    }
}
