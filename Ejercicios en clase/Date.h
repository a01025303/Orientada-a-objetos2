#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <ctime>

using namespace std; 
#pragma once

class Fecha
{
public: 
    //Día
    int day;
    //Mes
    string month; 
    //Año
    string year;  

    //Métodos
    //Constructor default
    Fecha();
    //Constructor con parámetros
    Fecha(int, string, string); 
    //Getter de días
    int getDay(); 
    //Getter de meses
    string getMonth(); 
    //Getter de años
    string getYear(); 
    //Obtener fecha proporcionada por el usuario
    int getDate(); 
    //Métodos con condiciones para la representación de meses
    int posicMes(string elMes);
    //Método que devuelve la fecha actual
    int getCurrentDate();
};