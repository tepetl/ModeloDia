/* 
 * File:   LectorData.cpp
 * Author: alfonso
 * 
 * Created on 17 de agosto de 2013, 06:54 PM
 */

#include "LectorData.h"

LectorData::LectorData() {


}

/**
 * 
 * @param snomarch
 * @param vEnt
 */
void LectorData::leeArchivo(string snomarch, vector<Entrada>& vEnt) {
    string line;
    ifstream myfile(snomarch.c_str());
    if (myfile.is_open()) {
        while (myfile.good()) {
            getline(myfile, line);
            vEnt.push_back(parser(line));
        }
        myfile.close();
    } else {
        cout << "(LectorData::leeArchivo) Problemas para abrir el archivo " << snomarch << endl;
    }


}

/**
 * 
 * @param theStringVector
 * @param theString
 * @param theDelimiter
 */
void LectorData::split(vector<string>& theStringVector, const string& theString, const string& theDelimiter) {
    size_t start = 0, end = 0;

    while (end != string::npos) {
        end = theString.find(theDelimiter, start);

        // If at end, use length=maxLength.  Else use length=end-start.
        theStringVector.push_back(theString.substr(start,
                (end == string::npos) ? string::npos : end - start));

        // If at end, use start=maxSize.  Else use start=end+delimiter.
        start = ((end > (string::npos - theDelimiter.size()))
                ? string::npos : end + theDelimiter.size());
    }
}

/**
 * 
 * @param scad
 * @return 
 */
Entrada LectorData::parser(string scad) {

    vector<string> vc;
    split(vc, scad, DELIMITER);

    Entrada aux(atol(vc[4].c_str()), atof(vc[5].c_str()), atol(vc[8].c_str()));
    aux.vs=vc;
    return aux;
}