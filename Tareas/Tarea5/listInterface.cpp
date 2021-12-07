#include "listInterface.h"
//Constructores de ListElement
ListElement::ListElement(){}
ListElement::ListElement(string elIdentificador): elementIdentifier(elIdentificador), nextElement(NULL), elementIndex(1){}

//Getter de identificador de elemento
string ListElement::getElementIdentifier()
{
    return elementIdentifier;
}
//Getter de index
int ListElement::getIndex()
{
    return elementIndex;
}
//Getter de siguiente elemento
ListElement* ListElement::getNext()
{   
    return nextElement; 
}

//Constructor de LinkedList
LinkedList::LinkedList():firstElement(0){} 
LinkedList::LinkedList(ListElement* first) : firstElement(first){} 

//Método para agregar elemento al final de la fila 
void LinkedList::Add(ListElement* element)
{
    //Inicializar variable que asigna index
    int counter = firstElement->getIndex();
    //Inicializar variable auxiliar para ir al siguiente elemento
    ListElement* siguiente = firstElement; 
    //Iterar en los elementos de la fila
    while (siguiente != NULL)
    {
        //Condición para agregar el elemento al final 
        if (siguiente->nextElement == NULL)
        {
            counter = siguiente->getIndex();
            element->elementIndex = counter + 1; 
            siguiente->nextElement = element;  
            break;
        }
        //Siguiente elemento
        siguiente = siguiente->getNext();
    }
}

//Agregar elemento en posición determinada
void LinkedList::Add(int position, ListElement* element)
{
    //Obtener tamaño de la lista
    int size = Size(); 
    //Inicializar variables auxiliares
    int ind = firstElement->getIndex();
    ListElement* siguiente = firstElement; 
    //Iterar en los elementos
    while (siguiente != NULL)
    {
        if (siguiente == NULL)
        {

        }
        //Condición para posición en el lugar 1
        if (position == 1)
        {  
            siguiente = element; 
            firstElement->elementIndex = 2; 
            siguiente->nextElement = firstElement;
            firstElement = element; 
            siguiente = siguiente->getNext();
            position++; 
            ind++; 
        }
        //Condición para posición en cualquier lugar dentro de la lista
        if (ind == position - 1)
        { 
            ind = position; 
            ListElement* nextNext = siguiente->getNext();
            siguiente->nextElement = element; 
            element->elementIndex = ind; 
            element->nextElement = nextNext; 
            siguiente = siguiente->getNext(); 
        }
        //Siguiente elemento
        siguiente = siguiente->getNext();
        ind ++; 
        //Condición en caso de que se ingrese una posición mayor al tamaño de la lista
        if (position > size)
        {
            ind = siguiente->getIndex();
            element->elementIndex = ind + 2; 
            siguiente->nextElement->nextElement = element; 
            siguiente = siguiente->getNext();  
            break;
        }
        //Condición para romper ciclo
        if (siguiente == NULL)
        { 
            break; 
        }
        //Siguiente elemento
        siguiente->elementIndex = ind;  
    }
}

//Obtener un elemento de la lista a partir de su posición 
void LinkedList::Get(int index)
{
    //Inicializar variables auxiliares 
    int auxIndex = firstElement->getIndex(); 
    ListElement* siguiente = firstElement; 
    //Iterar en los elementos
    while (siguiente != 0)
    {
        //Condición para ubicar el elemento con el índice requerido
        if (auxIndex == index)
        {
            cout << siguiente->getElementIdentifier() << endl;
            break; 
        }
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Condición para cerrar ciclo
        if (siguiente == NULL)
        {
            cout << "No existen elementos con ese índice" << endl; 
            break;
        }
        //índice del siguiente elemento
        auxIndex= siguiente->getIndex(); 
    }
} 

//Eliminar elemento dado el índice
void LinkedList::Remove(int index)
{
    //Tamaño de la lista
    int size = Size(); 
    //Inicializar variables auxiliares
    int ind = firstElement->getIndex();
    ListElement* siguiente = firstElement; 
    //iterar elementos
    while (siguiente != NULL)
    {
        //Condición si se quiere eliminar el primer elemento
        if (index == 1)
        {   
            siguiente = siguiente->getNext();
            firstElement->nextElement = NULL; 
            firstElement = siguiente; 
            firstElement->elementIndex = ind; 
            //ind++; 
            index ++; 
            //siguiente = siguiente->getNext(); 
            siguiente->elementIndex = ind; 
        }
        //Condición si se quiere eliminar cualquier elemento en medio de la lista
        if (ind == index - 1 && index < size)
        {  
            ind = index; 
            ListElement* nextNext = siguiente->getNext()->getNext();
            siguiente->nextElement = NULL; 
            nextNext->elementIndex = ind;
            siguiente->nextElement = nextNext;  
            siguiente = siguiente->getNext(); 
        }
        //Condición si se quiere eliminar último elemento
        else if (ind == index - 1 && index == size)
        {
            siguiente->nextElement = NULL; 
        }
        //siguiente elemento
        siguiente = siguiente->getNext();
        ind ++; 
        //Condición si se quiere eliminar un elemento inexistente
        if (index > size)
        {
            break;
        }
        //Cerrar ciclo
        if (siguiente == NULL)
        {
            break; 
        }
        //Asignar índice al elemento
        siguiente->elementIndex = ind;  
    }
}

//Tamaño de una lista
int LinkedList::Size()
{
    //Inicializar variables auxiliares
    ListElement* siguiente = firstElement; 
    int count = 0; 
    //Iterar elementos
    while (siguiente != 0)
    {
        //Agregar 1 al contador
        count ++;
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Condición para el final de la lista
        if (siguiente == NULL)
        {
            return count; 
            //break;
        }
    }
    return count; 
    //cout << "El tamaño de la lista es de: " << count << " elementos" << endl; 
} 
void LinkedList::Print()
{
    //Inicializar variable auxiliar
    ListElement* siguiente = firstElement; 
    //Iterar elementos
    while (siguiente != 0)
    {
        //Imprimir cada elemento con su índice
        cout << siguiente->elementIndex << ". " << siguiente->getElementIdentifier() << endl; 
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Cerrar ciclo al terminar la lista
        if (siguiente == NULL)
        {
            break;
        }
    }
}