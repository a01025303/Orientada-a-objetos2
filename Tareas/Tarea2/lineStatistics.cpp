#include "lineStatistics.h"

//Constructor por default con lista de inicialización
LineStatistics::LineStatistics(): elemento(Elemento("Paula", Time(15, 6), Time(15, 10), 0)){} 
//Constructor con parámetros con lista de inicialización
LineStatistics::LineStatistics(Elemento elElemento): elemento(elElemento){}
    
//Método para obtener el tiempo mínimo entre llegadas
int LineStatistics::getTiempoMin()
{
    // Inicialización de variables 
    //Variable auxiliar para llegada
    Time arrival_aux = elemento.getLlegada(); 
    //Variable auxiliar para minutos de la persona que acaba de llegar
    int minutos1 = arrival_aux.toMins();
    //Variable auxiliar para minutos de una persona antes de la persona que acaba de llegar
    int minutos2;
    // Variable de menor cantidad de minutos posibles
    int menor = 24*60;  
    // variable para diferencia entre dos horas de llegada para personas consecutivas en la fila
    int resta; 
    //Variable para persona de enfrente
    Elemento* next = elemento.getPersonaEnfrente(); 
    // Ciclo para ir pasando por las personas de la fila hasta que ya no haya nadie adelante
    while (next != 0)
    {
        arrival_aux = next->getLlegada();
        minutos2 = arrival_aux.toMins(); 
        resta = minutos1 - minutos2;
        //Condición para determinar menor diferencia entre tiempo
        if (resta < menor)
        {
            menor = resta; 
        }
        //Nuevas asignaciones 
        minutos1 = minutos2; 
        next = next -> getPersonaEnfrente(); 
    }
    return menor; 
}

//Método para obtener el tiempo máximo entre llegadas
int LineStatistics::getTiempoMax()
{
    // Inicialización de variables 
    //Variable auxiliar para llegada
    Time arrival_aux = elemento.getLlegada(); 
    //Variable auxiliar para minutos de la persona que acaba de llegar
    int minutos1 = arrival_aux.toMins();
    //Variable auxiliar para minutos de una persona antes de la persona que acaba de llegar
    int minutos2;
    //Variable para mayor cantidad de minutos
    int mayor = 0;  
    // variable para diferencia entre dos horas de llegada para personas consecutivas en la fila
    int resta; 
    //Variable para persona de enfrente
    Elemento* next = elemento.getPersonaEnfrente(); 
    // Ciclo para ir pasando por las personas de la fila hasta que ya no haya nadie adelante
    while (next != 0)
    {
        arrival_aux = next->getLlegada();
        minutos2 = arrival_aux.toMins(); 
        resta = minutos1 - minutos2;
        //Condición para determinar mayor diferencia entre tiempo
        if (resta > mayor)
        {
            mayor = resta; 
        }
        //Nuevas asignaciones
        minutos1 = minutos2; 
        next = next -> getPersonaEnfrente(); 
    }
    return mayor;
} 

//Método para obtener el promedio de tiempo entre llegadas
float LineStatistics::getTiempoProm()
{
    // Inicialización de variables 
    Time arrival_aux = elemento.getLlegada(); 
    int minutos1 = arrival_aux.toMins();  
    int minutos2;
    //Suma de diferencias de llegadas
    int suma = 0; 
    int resta;
    //Variable para contar la cantidad de elementos para el promedio
    int count = 0; 
    Elemento* next = elemento.getPersonaEnfrente(); 
    while (next != 0)
    {
        arrival_aux = next->getLlegada();
        minutos2 = arrival_aux.toMins(); 
        resta = minutos1 - minutos2;
        suma = suma + resta;
        minutos1 = minutos2; 
        next = next -> getPersonaEnfrente(); 
        count ++; 
    }
    return (float)suma/(float)count;
}

//Método para obtener el tiempo mínimo de atención 
int LineStatistics::TiempoMinAtencion()
{
    //Inicialización de variables 
    //Variables para tiempos de llegada y de salida
    Time arrival_aux = elemento.getLlegada(); 
    Time salida_aux = elemento.getSalida(); 
    int minutosLlegada = arrival_aux.toMins();  
    int minutosSalida = salida_aux.toMins();
    int resta = minutosSalida - minutosLlegada;
    int menor = resta;
    Elemento* next = elemento.getPersonaEnfrente(); 
    //Iteración en las personas de la fila 
    while (next != 0)
    {
        arrival_aux = next->getLlegada();
        minutosLlegada = arrival_aux.toMins(); 
        salida_aux = next-> getSalida(); 
        minutosSalida = salida_aux.toMins(); 
        resta = minutosSalida - minutosLlegada;
        //condición para determinar menor tiempo de atención
        if (resta < menor)
        {
            menor = resta; 
        }
        //siguiente persona
        next = next -> getPersonaEnfrente();
    }
    return menor;
}

//Método para obtener el mayor tiempo de atención
int LineStatistics::TiempoMaxAtencion()
{
    //Inicialización de variables
    Time arrival_aux = elemento.getLlegada(); 
    Time salida_aux = elemento.getSalida(); 
    int minutosLlegada = arrival_aux.toMins();  
    int minutosSalida = salida_aux.toMins();
    int resta = minutosSalida - minutosLlegada;
    int mayor = resta;
    Elemento* next = elemento.getPersonaEnfrente(); 
    //Iteración de personas en la fila 
    while (next != 0)
    { 
        arrival_aux = next->getLlegada();
        minutosLlegada = arrival_aux.toMins(); 
        salida_aux = next-> getSalida(); 
        minutosSalida = salida_aux.toMins(); 
        resta = minutosSalida - minutosLlegada;
        //Condición para determinar mayor tiempo de atención 
        if (resta > mayor)
        {
            mayor = resta; 
        }
        // Siguiente persona
        next = next -> getPersonaEnfrente(); 
    }
    return mayor;
}

//Método para obtener el promedio de tiempo de atención
float LineStatistics::TiempoPromAtencion()
{
    //Inicialización de variables 
    Time arrival_aux = elemento.getLlegada(); 
    Time salida_aux = elemento.getSalida(); 
    int minutosLlegada = arrival_aux.toMins();  
    int minutosSalida = salida_aux.toMins();
    int resta = minutosSalida - minutosLlegada;
    int suma = resta; 
    //Inicialización de count en 1 porque ya se calculó el primer tiempo de atención
    int count = 1; 
    Elemento* next = elemento.getPersonaEnfrente(); 
    //Iteración en personas de la fila 
    while (next != 0)
    { 
        arrival_aux = next->getLlegada();
        minutosLlegada = arrival_aux.toMins(); 
        salida_aux = next-> getSalida(); 
        minutosSalida = salida_aux.toMins(); 
        resta = minutosSalida - minutosLlegada;
        suma = suma + resta; 
        next = next -> getPersonaEnfrente(); 
        count++; 
    }
    return (float)suma/(float)(count);
} 

//Método para obtener a la persona de atrás de Y en la fila
//Se obtiene al encontrar a la persona Y y ver quién está atrás
string LineStatistics::personaDespues(string elNombre)
{
    //Inicializar variables
    Elemento* elElemento = &elemento; 
    string nombreAtras = "Nadie"; 
    //Condición para revisar si se trata de la última persona en la fila
    if (elNombre == elElemento->getName())
    {
        cout << "Esta es la última persona en la fila" << endl; 
    }
    Elemento* elem_aux = elElemento->getPersonaEnfrente();
    //Iteración en la fila
    while (elem_aux != 0)
    {
        //Condición para detectar a la persona X
        if (elNombre == elem_aux->getName())
        {
            //Obtener a la persona que llegó después de X
            nombreAtras = elElemento->getName(); 
            break;
        }
        //Nueva asignación de variables
        elElemento = elem_aux; 
        elem_aux = elElemento->getPersonaEnfrente(); 
    }
    return nombreAtras; 
}
//Método para obtener a la persona de adelante de X en la fila
//Se obtiene al encontrar a la persona X y ver quién está enfrente
string LineStatistics::personaAntes(string elNombre)
{
    //Inicializar variables
    Elemento* elElemento = &elemento; 
    string nombreAdelante = "Nadie"; 
    Elemento* elem_aux = elElemento->getPersonaEnfrente();
    //Iteración en la fila
    while (elem_aux != 0)
    {
        //condición para verificar si el nombre del elemento es el pedido por el usuario
        if (elNombre == elElemento->getName())
        {
            //Encontrar a la persona de adelante
            nombreAdelante = elem_aux->getName(); 
            break;
        }
        //Nueva asignación de variables
        elElemento = elem_aux; 
        elem_aux = elElemento->getPersonaEnfrente(); 
    }
    return nombreAdelante; 
}