#include <iostream>
#include <string>
#include "elementLine.h"
using namespace std; 
#pragma once

class LineStatistics
{
public:
    //Atributo
    Elemento elemento; 

    //Métodos

    //Constructores
    LineStatistics(); 
    LineStatistics(Elemento);

    //Métodos
    int getTiempoMin(); 
    int getTiempoMax(); 
    float getTiempoProm(); 
    int TiempoMinAtencion(); 
    int TiempoMaxAtencion(); 
    float TiempoPromAtencion(); 
    string personaDespues(string); 
    string personaAntes(string); 
}; 