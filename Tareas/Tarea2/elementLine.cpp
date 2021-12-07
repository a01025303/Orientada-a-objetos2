#include "elementLine.h"

//Constructor default con lista de inicialización
Elemento::Elemento() : nombre("Paula"), llegada(Time(11, 45)), salida(Time(12,0)), personaEnfrente(0){}
//Constructor con parámetros con lista de inicialización
Elemento::Elemento(string elNombre, Time horaLlegada, Time horaSalida, Elemento* personaE): nombre(elNombre), 
llegada(horaLlegada), salida(horaSalida), personaEnfrente(personaE){}

//Método para obtener nombre
string Elemento::getName()
{
    return nombre; 
}

//Método para obtener tiempo de llegada
Time Elemento::getLlegada()
{
    return llegada; 
}

//Método para obtener tiempo de salida
Time Elemento::getSalida()
{
    return salida; 
}

//Método para obtener persona de enfrente
Elemento* Elemento::getPersonaEnfrente()
{
    return personaEnfrente; 
}

//Método para contar personas en la línea
int Elemento::countLine()
{
    int counter = 1; 
    Elemento* persona_aux = getPersonaEnfrente(); 
    while(persona_aux != 0)
    {
        counter++; 
        persona_aux = persona_aux-> getPersonaEnfrente(); 
    }
    return counter; 
}