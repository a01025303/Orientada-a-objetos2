#include <iostream>
#include <string>

using namespace std; 
#pragma once

class Time
{
public: 
    //Atributos 
    int hh;
    int min; 

    //Métodos
    int getHour(); 
    int getMinutes(); 
    int toMins(); 
    Time(); 
    Time(int, int); 
};

