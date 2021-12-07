#include "time.h"

//Constructor default con lista de inicialización 
Time::Time(): hh(12), min(0){}
//Constructor por parámetros con lista de inicialización
Time::Time(int theHour, int theMinutes) : hh(theHour), min(theMinutes){}

//Método para obtener hora
int Time::getHour()
{
    return hh; 
}

//Método para obtener minutos 
int Time::getMinutes()
{
    return min; 
}

//Método para convertir tiempo (hh:min) a minutos
int Time::toMins()
{
    int horas = getHour(); 
    int mins = getMinutes();  
    return horas*60 + mins;
}