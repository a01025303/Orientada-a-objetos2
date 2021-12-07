#include "cine.h"

using namespace std; 

//USER
//Constuctores por default y con parámetros con lista de inicialización 
User::User():nombre("Juan"), telefono("5537485990"){}
User::User(string elNombre, string elTelefono): nombre(elNombre), telefono(elTelefono){}

//Método getNombre
string User::getNombre()
{
    return nombre; 
}

//Método getCel
string User::getCel()
{
    return telefono;
}

//CLIENTE
//Constuctores por default y con parámetros con lista de inicialización 
Cliente::Cliente(): num_cliente(0), User("Fernanda", "5453739283"){}
Cliente::Cliente(int numeroCliente, string name, string celular): num_cliente(numeroCliente), 
User(name, celular){}

//Método getClientNum
int Cliente::getClientNum()
{
    return num_cliente;
} 

//ASIENTOS
//Constuctores por default y con parámetros con lista de inicialización 
Asientos::Asientos(): reservado(false), num_ubicacion(1), costo_reserva(120){}
Asientos::Asientos(bool reserved, int num, float precio, string type, Asientos* nextseat):reservado(reserved), 
num_ubicacion(num), costo_reserva(precio), tipo(type), sig_asiento(nextseat){}

//Método isReserved
bool Asientos::isReserved()
{
    return reservado; 
}

//Método getLocation
int Asientos::getLocation()
{
    return num_ubicacion;
}

//Método getPrecio
float Asientos::getPrecio()
{
    return costo_reserva;
}

//Método getClient
Cliente Asientos::getClient()
{
    return cliente; 
} 

//Método getNext
Asientos* Asientos::getNext()
{
    return sig_asiento; 
}

//Método getType
string Asientos::getType()
{
    return tipo; 
}

//ADMIN
//Constuctores por default y con parámetros con lista de inicialización 
Admin::Admin(): fecha_ingreso(Fecha(1,"2","2020")), sueldo(2000), num_empleado(3), User("Lety", "5555643209"){}
Admin::Admin(Fecha fecha_in, double sal, int num, string name, string celular, Asientos first): fecha_ingreso(fecha_in), 
sueldo(sal), num_empleado(num), User(name, celular), primer_asiento(first){} 

//Método getEmployeeNum
int Admin::getEmployeeNum()
{
    return num_empleado;
}

//Método getSalary
double Admin::getSalary()
{
    return sueldo; 
}

//Método getFecha
Fecha Admin::getFecha()
{
    return fecha_ingreso;
}

//Método reserveByNumber
void Admin::reserveByNumber(int numero_reservar, Cliente elCliente)
{
    //Creación de variables auxiliares
    int num_asiento_aux = primer_asiento.getLocation(); 
    Asientos* next = &primer_asiento;  
    //Ciclo para iterar en los asientos (cada asiento sabe quién es el asiento siguiente)
    while (next != 0)
    {
        //Condición para identificar cuando nos encontramos en el número de asiento deseado
        if(num_asiento_aux == numero_reservar)
        {
            //Condiciones para reservar o no dependiendo de la disponibilidad del asiento
            if (next->isReserved() == false)
            {
                cout << "Se reservará el asiento " << next->getType() << "-" << next->getLocation() << endl; 
                //Cambiar reserva a ocupado y asignar un cliente
                next->reservado = true; 
                next->cliente = elCliente; 
                break;
            }
            else
            {
                cout << "El asiento " << next->getType() << "-" << next->getLocation() << " ya está reservado, intenta con otro asiento" << endl; 
                break; 
            }
        } 
        //Ir al siguiente asiento
        next = next->getNext(); 
        if (next == NULL)
        {
            //Si ningún asiento del tipo deseado está disponible:
            cout << "No existe el asiento número " << numero_reservar <<  endl; 
            break;
        }
        //Obtener número del siguiente asiento
        num_asiento_aux = next->getLocation(); 
    }
}

//Método reserveByType
void Admin::reserveByType(string seatType, Cliente elCliente)
{
    //Inicialización de variables auxiliares
    string tipo_asiento_aux = primer_asiento.getType(); 
    Asientos* next = &primer_asiento;  
    //Ciclo para iterar en los asientos
    while (next != 0)
    {
        //Condición para identificar cuando nos encontramos en un asiento del tipo deseado
        if(tipo_asiento_aux == seatType)
        {
            //Condición para ver si está reservado y reservar el asiento si está desocupado
            if (next->isReserved() == false)
            {
                cout << "Se reservará el asiento " << next->getType() << "-" << next->getLocation() << endl; 
                //Cambiar reserva a ocupado y asignar un cliente
                next->reservado = true; 
                next->cliente = elCliente; 
                break;
            }
        } 
        //Ir al siguiente asiento
        next = next->getNext(); 
        if (next == NULL)
        {
            //Si ningún asiento del tipo deseado está disponible:
            cout << "No hay asientos del tipo " << seatType << " disponibles" << endl; 
            break;
        }
        //Ver tipo de asiento
        tipo_asiento_aux = next->getType(); 
        
    }
    
}

//Método printReserved
void Admin::printReserved()
{
    //Inicialización de variable auxiliar que pasa por asientos
    Asientos* next = &primer_asiento;  
    cout << "Los asientos reservados son: " << endl; 
    //Iterar en los asientos
    while (next != 0)
    {
        //Identificar cuando un asiento está reservado
        if (next->isReserved() == true)
        {
            //Imprimir el asiento reservado
            cout << next->getType() << "-" << next->getLocation() << endl; 
        }
        //Siguiente asiento
        next = next->getNext(); 
    }
}

//Método printCost
void Admin::printCost(int numAsiento)
{
    //Inicialización de variables 
    int num_asiento_aux = primer_asiento.getLocation(); 
    Asientos* next = &primer_asiento;  
    //iterar en los asientos
    while (next != 0)
    {
        //Verificar el número de asiento
        if(num_asiento_aux == numAsiento)
        {
            //Imprimir el precio
            cout << "El precio del asiento " << next->getType() << "-" << next->getLocation() << " es " << next->getPrecio() << endl;
            break;  
        } 
        //Siguiente asiento
        next = next->getNext(); 
        if (next == NULL)
        {
            break;
        }
        //Siguiente número de asiento
        num_asiento_aux = next->getLocation(); 
    }
}

//Método cancelSeat
void Admin::cancelSeat(int numAsiento)
{
    //Inicializar varible que pasa por asientos
    Asientos* next = &primer_asiento;  
    //Iterar en asientos 
    while (next != 0)
    {
        //Comprobar que el número de asiento sea el deseado
        if(next->getLocation() == numAsiento)
        {
            //Verificar que sí esté reservado
            //Si no está reservado:
            if (next->isReserved() == false)
            {
                cout << "Este asiento no está reservado. No se puede cancelar." << endl; 
                break; 
            }
            //Si está reservado:
            else if (next->isReserved() == true)
            {
                //Quitar reservación
                next->reservado = false; 
                cout << "Se canceló la reservación del asiento " << next->getType() << "-" << next->getLocation() << endl; 
            }
        } 
        //Siguiente asiento
        next = next->getNext();
    }
}

//Método modifyCosts
void Admin::modifyCosts(string elTipo, float elNuevoPrecio)
{
    //Inicializar variable que pasa por asientos
    Asientos* next = &primer_asiento;  
    //Iterar asientos
    while (next != 0)
    {
        //Condición para verificar el tipo de asiento que se quiere cambiar 
        if(next->getType() == elTipo)
        {
            //Cambio de precio
            next->costo_reserva = elNuevoPrecio; 
        } 
        //Siguiente asiento
        next = next->getNext();
    }
}

//Método nomobreCliente
void Admin::nombreCliente(int numAsiento)
{
    //Inicialización de variable que pasa por los asientos
    Asientos* next = &primer_asiento; 
    //Iteración de asientos 
    while (next != 0)
    {
        //Verificar número de asiento deseado
        if(next->getLocation() == numAsiento)
        {
            if (next->isReserved() == true)
            {
                //Imprimir el nombre del cliente que reservó el asiento
                cout << "El asiento " << next->getType() << "-" << next->getLocation()<< " está reservado a nombre de: " << next->cliente.getNombre() << endl;
                break; 
            }
            else
            {
                //Indicar que el lugar no está reservado
                cout << "El asiento " << next->getType() << "-" << next->getLocation()<< " no está reservado" << endl; 
                break; 
            }
        } 
        //Siguiente
        next = next->getNext();
    }
}