#include <iostream>
#include <string>
#include "Date.h"
#include "Person.h"

class Employee : public Person//vamos a usar tipo de herencia pública
{
protected:
    int id_employee; 
    string position; 
    double salary; 
public: 
    Employee(){}
    Employee(int id, string pos, double sal, string nombre): id_employee(id), position(pos), 
    salary(sal), Person::Person(nombre){} //Llamamos al constructor de Person
}; 

class Patient : public Person
{
protected:
    int id_patient; 
public:
    Patient(){}
    Patient(int id, string nombre): id_patient(id), Person::Person(nombre){}
};

class Doctor : public Employee //el doctor es un empleado
{
protected:
    int license_number; 
    bool busy; 
    Patient paciente; 
public:
    Doctor(){}
    Doctor(int lic, int id, string nombre, string pos, double sal): license_number(lic), Employee(id, position, salary, name){}
    bool isBusy();
    void consult(Patient patient); 
    Patient getPatient(); 
}; 

bool Doctor::isBusy()
{
    return busy;
} 

void Doctor::consult(Patient patient)
{
    busy = true;
    paciente = patient; //this-> es un apuntador a la instancia de la clase 
}

Patient Doctor::getPatient()
{
    return paciente; 
}

class MedicalAssistant : public Employee //No tiene atributos
{  
    Doctor doctor; 
public: 
    MedicalAssistant(){}
    MedicalAssistant(Doctor doc, int id, string nombre, string pos, double sal): doctor(doc), Employee(id, pos, sal, nombre){}
public: 
    void setAppointment(Patient paciente); 
};

void MedicalAssistant::setAppointment(Patient patient)
{
    if (doctor.isBusy()==true)
    {
        cout << "El doctor está ocupado atendiendo a " << doctor.getPatient().getName() << endl; 
    }
    else
    {
        doctor.consult(patient);
        cout << "El doctor " << doctor.getName() << " te va a dar consulta. ¡Adelante!" << endl; 
    }
}

int main()
{
    Doctor who(1, 1, "Pedro", "Médico", 100000); 
    MedicalAssistant asist1(who, 2, "Mike", "Asistente", 10000); 
    Patient pac(1, "Ramiro");
    asist1.setAppointment(pac);
}