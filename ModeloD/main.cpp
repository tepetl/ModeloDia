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
/**
 * 
 */
int main(int argc, char** argv) {

     if (argc == 1) {

        cout << "Falta ..." << endl;

    }
     
     vector<Entrada> vEnt;
     LectorData lecd;
     
     lecd.leeArchivo(string(argv[1]),vEnt);
     
     
     vector<CEntrada> vCent;
     
     AlgoAna ana;
     
     ana.calculaMedia(vEnt,vCent);
     ana.calculaVarSDC(vEnt,vCent);
     ana.clasificaEntradas(vEnt,vCent);
     
     imprimeEntradas(vEnt);
     
    return 0;
}


void imprimeEntradas(vector<Entrada> &vEnt){
    
}


void imprimeCEntradas(vector<CEntrada> &vCent){
    
}
