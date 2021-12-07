//#include <iostream>
//#include <string>
#include "fecha_tarea.h"
using namespace std; 
#pragma once

class Person
{
    public: 
        //Atributos de la clase
        string name; 
        Fecha birthday; 
        Person* father;
        Person* mother;
    public: 
        //Métodos
        Person(); 
        Person(string, Fecha, Person*, Person*); 
        string getName();
        int personAge();
        Person* getMother(); 
        Person* getFather();
        int getAntecesores(); 
        Fecha getFecha(); 
        int nombresAntecesores(); 
        int antecesorViejo(); 
        int antecesorJoven(); 
};