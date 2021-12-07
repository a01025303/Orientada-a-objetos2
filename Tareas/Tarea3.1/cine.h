#include <iostream>
#include <string>
#include "Date.h"

using namespace std; 

#pragma once 

//Clase User
class User
{
protected:
    //Atributos
    string nombre; 
    string telefono; 
public:
    //Métodos
    string getNombre(); 
    string getCel(); 
    User(); 
    User(string, string); 
}; 

//Clase Cliente que hereada atributos de User
class Cliente : public User
{
protected: 
    //Atributos que no tiene en común con User
    int num_cliente; 
public: 
    //Métodos 
    int getClientNum(); 
    Cliente(); 
    Cliente(int, string, string); 
}; 

class Admin;


//Clase asientos
class Asientos
{
protected: 
    //Atributos protegidos
    int num_ubicacion; 
    string tipo;   
    Asientos* sig_asiento; 
    Cliente cliente;
    float costo_reserva;
    bool reservado; 
    Admin* admin_asiento; 
public: 
    friend class Admin;
    //Métodos
    bool isReserved(); 
    int getLocation(); 
    float getPrecio();
    Cliente getClient(); 
    Asientos* getNext(); 
    string getType(); 
    Asientos(); 
    Asientos(bool, int, float , string, Asientos*); 
}; 


class Admin : public User
{
    //Primer asiento
    Asientos* primer_asiento; 
protected: 
    //Atributos
    int num_empleado; 
    double sueldo; 
    Fecha fecha_ingreso; 
public: 
    //Métodos
    int getEmployeeNum(); 
    double getSalary(); 
    Fecha getFecha(); 
    Admin();
    Admin(Fecha, double, int, string, string, Asientos*); 
    void reserveByNumber(int, Cliente); 
    void reserveByType(string, Cliente); 
    void nombreCliente(int); 
    void printReserved(); 
    void printCost(int); 
    void cancelSeat(int); 
    void modifyCosts(string, float); 
    void adminReserve(Asientos*);
}; 