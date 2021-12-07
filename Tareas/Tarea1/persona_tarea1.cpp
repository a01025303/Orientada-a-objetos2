#include "persona_tarea.h"
using namespace std; 


Person::Person(string theName, Fecha theBirthday, Person* theMother, Person* theFather): name(theName), birthday(theBirthday), father(theFather), mother(theMother) 
{}

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

//Método getMother()
Person* Person::getMother()
{
    return mother; 
}

//Método getFather()
Person* Person::getFather()
{
    return father; 
}

// Método para contar la cantidad de antecesores de una pesona
int Person:: getAntecesores()
{
    int antecesoresNum = 0; 
    Person* madre = getMother(); 
    while (madre != 0)
    {
        antecesoresNum ++; 
        madre = madre->getMother(); 
    }
    return antecesoresNum; 
}

// Método para imprimir los nombres de los antecesores 
int Person::nombresAntecesores()
{
    Person* madre = getMother(); 
    while (madre != 0)
    { 
        cout << madre -> name << endl;
        madre = madre -> getMother(); 
    }
    return 1; 
} 

int Person::antecesorViejo()
{
    Person* madre = getMother();
    string nombreViejo = madre -> name; 
    int edadViejo = madre -> personAge(); 
    while (madre != 0)
    { 
        madre = madre -> getMother(); 
        if (madre == NULL)
        {
            break; 
        }
        if (edadViejo < madre -> personAge())
        {
            edadViejo = madre -> personAge(); 
            nombreViejo = madre -> name; 
        }
    }
    cout << nombreViejo  << " quien tiene " << edadViejo << " años de edad" << endl; 
    return 1; 
}

int Person::antecesorJoven()
{
    Person* madre = getMother();
    string nombreJoven = madre -> name; 
    int edadJoven = madre -> personAge(); 
    while (madre != 0)
    { 
        madre = madre -> getMother();
        if (madre == NULL)
        {
            break; 
        }
        if (edadJoven > madre -> personAge())
        {
            edadJoven = madre -> personAge(); 
            nombreJoven = madre -> name; 
        }
    }
    cout << nombreJoven  << " quien tiene " << edadJoven << " años de edad" << endl;
    return 1; 
}
