//#include <iostream>
//#include <string>
#include "Date.h"
using namespace std; 
#pragma once

class Person
{
    protected: 
        //Atributos de la clase
        string name; 
        Fecha birthday; 
        string address; 
        string phone_number; 
    public: 
        //Métodos
        Person(); 
        Person(string theName, Fecha, string, string); 
        Person(string elNombre);
        string getName();
        int personAge();
        Fecha getFecha(); 
        string getAddress(); 
        string getPhone(); 
};