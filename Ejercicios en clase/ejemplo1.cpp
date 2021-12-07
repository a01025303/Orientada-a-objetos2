#include <iostream>
#include <string> 
using namespace std; 
class Person
{
    public: 
        string name; 
        int age; 
        //No podemos crear un Person aquí adentro, podemos crear un apuntador a un Person
        Person* parent; //Esto sí se puede
        //Person mother; --> Esto no se puede 
    public: 
        Person(){} //Constructor por default, también puedes ponerlo como Person()=default
        Person(string, int, Person*); //Constructor por parámetro 
        //Person(const Person&); //Constructor copia, se pasa por referencia &, el problema es que cambia el original
        string getName()
        {
            return name; 
        }
};


//Implementación constructor con parámetros 
Person::Person(string theName, int theAge, Person* parent) : name(theName), age(theAge), parent(parent)
{

    //name = theName; 
    //age = theAge; 
}
/*
//Implementación constructor-copia 
Person::Person(const Person& original)
{
    //name = "genérico";
    //age = original.getAge(); 
    parent = new Person("otherName", 90, 0); //apuntador reserva nuevo espacio de memoria --> deep copy
    //Constructor copia se necesita cuando tienes algún apuntador en el constructor 
}
*/


int main()
{  
    Person andrew("andrew", 60, 0); //los apuntadores pueden ser = 0, lo que significa que no apuntan a ningún lado
    Person john("John", 75, &andrew); 
    Person dave = john; //Constructor copia, se va a copiar john
    cout << john.name << endl; 
    cout << dave.name << endl; 
    cout << dave.parent << endl; 
    cout << john.parent << endl; 
    cout << dave.parent-> name; 

}
