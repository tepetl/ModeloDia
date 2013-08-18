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

#include "Entrada.h"
#include "LectorData.h"

using namespace std;

/**
 * 
 */
int main(int argc, char** argv) {

     if (argc == 1) {

        cout << "Falta ..." << endl;

    }
     
     vector<Entrada> vEnt;
     LectorData lecd();
     
     lecd.leeArchivo(string(argv[1]),vEnt);
     
    return 0;
}

