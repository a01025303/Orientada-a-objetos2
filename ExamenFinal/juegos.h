#include <iostream>
#include <string>

using namespace std; 

#pragma once
class Game; 
class OneLevelGame; 
class MultilevelGame; 
class ListElement
{
    protected: 
        //Atributos
        string name; //Nombre/identificador
        ListElement* nextElement; //Siguiente elemento
    public: 
        friend class LinkedList; //Perminte que linkedlist vea 
        ListElement(); //Constructor vacío
        ListElement(string theName);  //Constructor con parámetros
        string getName(); //Obtener nombre
        ListElement* getNext(); //Obtener siguiente elemento
        virtual ~ListElement(){} //Destructor virtual
};

class ListInterface
{
    public: 
        //Clase abstracta, metodos virtuales puros
        virtual void Add(ListElement* element) = 0; //Agrega elemento al final de la lista
        virtual void Add(int position, ListElement* element) = 0; //Agrega elemento en la posición especificada
        virtual ListElement* Get(int theIndex) = 0; //Devuelve elemento en una posición determinada
        virtual void Remove(int index) = 0; //Borra elemento de la posición especificada
        virtual int Size() = 0; //Devuelve cantidad de elementos
        virtual void Print() = 0; //Implime elementos
        virtual ~ListInterface(){} //Destructor virtual
};

class LinkedList: public ListInterface
{
    protected: 
        //Atributos
        ListElement* firstElement;  
    public: 
        LinkedList(); //Constructor default
        LinkedList(ListElement* first); //Constructor con parámetros

        //Implementaciones de métodos de ListInterface
        void Add(ListElement* element); 
        void Add(int position, ListElement* element); 
        ListElement* Get(int theIndex); 
        void Remove(int index); 
        int Size(); 
        void Print();
};

class GameManager
{
    protected: 
        //Atributo
        ListInterface* GameList;
    public: 
        GameManager();  
        void addGame(Game* elJuego); 
        void addGame(int thePosition, Game* elJuego); 
        void printGames(); 
        ~GameManager(){delete GameList;}
}; 

class Game
{
    protected: 
        string nombre; 
        int id; 
        bool disponible; 
        string usando; 
        char tipo; 
        Game* siguienteJuego; 
    public: 
        Game(){} 
        Game(string elNombre, int &elID, char* elTipo);
        string getNombre(); 
        int getID(); 
        bool getDisponible(); 
        string getUsando(); 
        char getTipo(); 
        Game* getSiguienteJuego(); 
        virtual string play()
        {
            return "Hola"; 
        } //Método virtual jugar 
}; 

class OneLevelGame: public virtual Game
{
    //Tiene mismos atributos que Game
    public: 
        //Constructores
        OneLevelGame(); 
        OneLevelGame(string elNombre, int &elID, char* elTipo); 
        //Método jugar
        string play(); 
}; 
class MultilevelGame: public virtual Game
{
    protected: 
        //Tiene además una lista de niveles--> apuntador a un tipo ListInterface 
        ListInterface* listaNiveles; 
    public: 
        //Constructores
        MultilevelGame(){}
        MultilevelGame(string elNombre, int &elID, char* elTipo);
        //Método jugar
        string play(); 
        //Destructor
        ~MultilevelGame(){delete listaNiveles;}
};




