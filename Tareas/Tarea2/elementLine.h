#include <iostream>
#include <string>
#include "time.h"

using namespace std; 
#pragma once

class Elemento
{
public:
    //Atributos
    string nombre; 
    Time llegada; 
    Time salida; 
    Elemento* personaEnfrente; 
    
    //Constructores
    Elemento(); 
    Elemento(string, Time, Time, Elemento*); 
    //Métodos
    string getName(); 
    Time getLlegada(); 
    Time getSalida(); 
    Elemento* getPersonaEnfrente(); 
    int countLine(); 
};