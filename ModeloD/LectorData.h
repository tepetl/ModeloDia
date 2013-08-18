/* 
 * File:   LectorData.h
 * Author: alfonso
 *
 * Created on 17 de agosto de 2013, 06:54 PM
 */

#ifndef LECTORDATA_H
#define	LECTORDATA_H


#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Entrada.h"

#define DELIMITER       ","

using namespace std;



class LectorData {
public:
    
    LectorData();
   void leeArchivo(string snomarch,vector<Entrada>& vEnt);
private:

    vector<Entrada> & vEnt;
protected:
    void split(vector<string>& theStringVector, const string& theString, const string& theDelimiter);
    Entrada parser(string scad);
};

#endif	/* LECTORDATA_H */

