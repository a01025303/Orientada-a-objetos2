#include "Person.h"
using namespace std; 


Person::Person(string elNombre): name(elNombre){}
Person::Person(string theName, Fecha theBirthday, string dir, string tel): name(theName), 
birthday(theBirthday), address(dir), phone_number(tel) {}

//Método getName
string Person::getName()
{
    return name; 
}

Fecha Person::getFecha()
{
    return birthday; 
}

//Método para encontrar la edad de una persona a partir de su fecha de nacimiento
int Person::personAge()
{
    // Inicializar variables en tipo de dato int 
    int diaNacimiento = birthday.day; 
    int mesNacimiento = stoi(birthday.month); 
    int anioNacimiento = stoi(birthday.year); 
    
    //Obtener fecha actual 
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    //Día actual
    int diaActual = (tPtr->tm_mday);
    //Mes actual
    int mesActual = (tPtr->tm_mon)+1;
    //Año actual
    int anioActual = (tPtr->tm_year)+1900;

    //Inicializar variable para edad
    int edad; 
    //condiciones para calcular la edad 
    //Si el mes actual es mayor o igual al mes de nacimiento
    if (mesActual == mesNacimiento)
    {
        // Si el día actual es mayor o igual al día de nacimiento
        if (diaActual >= diaNacimiento)
        {
            // edad es el año actual menos el año de nacimiento (ya cumplió años en el año actual)
            edad = anioActual - anioNacimiento; 
        }
        else
        {
            // edad es el año actual menos el año de nacimiento menos uno (no ha cumplido años en el año actual)
            edad = anioActual - anioNacimiento - 1; 
        }
    }
    // Si el mes actual es menor al mes de nacimiento
    else if (mesActual < mesNacimiento)
    {
        // edad es el año actual menos el año de nacimiento menos uno (no ha cumplido años en el año actual)
        edad = anioActual - anioNacimiento - 1; 
    }
    else if (mesActual > mesNacimiento)
    {
        edad = edad = anioActual - anioNacimiento; 
    }
    return edad; 
}
