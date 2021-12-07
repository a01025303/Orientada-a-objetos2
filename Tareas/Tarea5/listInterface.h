#include <iostream>
#include <string>

using namespace std; 

#pragma once 

class LinkedList; 
class ListElement; 
/*class listInterface; 

class List
{
    protected: 
        listInterface* list;
}; */


class ListInterface
{
    public: 
        virtual void Add(ListElement* element) = 0; 
        virtual void Add(int position, ListElement* element) = 0; 
        virtual void Get(int index) = 0; 
        virtual void Remove(int index) = 0; 
        virtual int Size() = 0; 
        virtual void Print() = 0; 
        virtual ~ListInterface(){}
};

class LinkedList: public ListInterface
{
    protected: 
        ListElement* firstElement;  
    public: 
        LinkedList(ListElement* first); 
        LinkedList(); 
        void Add(ListElement* element); 
        void Add(int position, ListElement* element); 
        void Get(int index); 
        void Remove(int index); 
        int Size(); 
        void Print(); 
};

class ListElement
{
    protected: 
        string elementIdentifier; 
        int elementIndex; 
        ListElement* nextElement; 
    public: 
        friend class LinkedList; 
        ListElement(); 
        ListElement(string);  
        string getElementIdentifier(); 
        int getIndex(); 
        ListElement* getNext();
};