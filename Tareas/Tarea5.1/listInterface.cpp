#include "listInterface.h"
//Constructores de ListElement
ListElement::ListElement(){}
ListElement::ListElement(string elIdentificador): elementIdentifier(elIdentificador), nextElement(NULL){}

//Getter de identificador de elemento
string ListElement::getElementIdentifier()
{
    return elementIdentifier;
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
    //Si no hay elementos en la lista
    if (firstElement == NULL)
    {
        //El elemento que se agrega es el nuevo primer elemento
        firstElement = element; 
    }
    else
    {
        //Inicializar variable auxiliar para ir al siguiente elemento
        ListElement* siguiente = firstElement; 
        //Iterar en los elementos de la fila
        while (siguiente != NULL)
        {
            //Condición para agregar el elemento al final 
            if (siguiente->nextElement == NULL)
            {
                //El siguiente elemento del elemento en el que nos encontramos actualmente, se convierte en el elemento a agregar
                siguiente->nextElement = element;  
                //Romper ciclo
                break;
            }
            //Ir al siguiente elemento
            siguiente = siguiente->getNext();
        }
    }
}


//Agregar elemento en posición determinada
void LinkedList::Add(int position, ListElement* element)
{
    //Si no hay elementos en la lista 
    if (firstElement == NULL)
    {
        //El elemento que se agrega es el nuevo primer elemento
        firstElement = element; 
    }
    else
    {
        //Obtener tamaño de la lista
        int size = Size(); 
        //Inicializar variables auxiliares
        int index = 1;
        ListElement* siguiente = firstElement; 
        //Iterar en los elementos
        while (siguiente != NULL)
        {
            //Condición para posición = 1
            if ((position == index) && (index == 1))
            {
                //Hacer que el elemento proporcionado sea el nuevo primer elemento
                firstElement = element; 
                // El siguiente elemento es el antiguo primer elemento
                firstElement->nextElement = siguiente; 
            }
            //Condición para posición de elemento existente a partir de 2
            else if (index == position - 1)
            {
                //Variable auxiliar para guardar el valor del siguiente elemento de "siguiente"
                ListElement* nextNext = siguiente->getNext();
                //Asignar ahora que el siguiente elemento de "siguiente" sea element
                siguiente->nextElement = element; 
                //El elemento después de element será nextNext
                element->nextElement = nextNext;
                //Ir al siguiente elemento
                siguiente = siguiente->getNext(); 
            }
            //Condición para ver si existe un siguiente elemento
            if (siguiente->nextElement == NULL)
            {
                //Si la posición es mayor al tamaño de la lista 
                if (position > size)
                {
                    //Poner nuevo elemento al final 
                    siguiente->nextElement = element;
                    //Romper
                    break; 
                } 
            }
            //Ir al siguiente elemento
            siguiente = siguiente->getNext(); 
            //Si el siguiente elemento es nulo
            if (siguiente == NULL)
            {
                //Romper
                break; 
            }
            //Aumentar index en 1
            index = index + 1;
        }
    }
}

//Obtener un elemento de la lista a partir de su posición 
void LinkedList::Get(int index)
{
    //Inicializar variables auxiliares 
    int ind = 1;  
    ListElement* siguiente = firstElement; 
    //Condición en caso de tener una lista vacía
    if (siguiente == 0)
    {
        cout << "Esta lista no tiene elementos" << endl; 
    }
    //Iterar en los elementos
    while (siguiente != 0)
    {
        //Condición para ubicar el índice requerido
        if (ind == index)
        {
            //Imprimir el identificador del elemento con ese índice
            cout << siguiente->getElementIdentifier() << endl;
            //Romper
            break; 
        }
        //Ir al siguiente elemento
        siguiente = siguiente->getNext(); 
        //Condición para cerrar ciclo --> si llegamos a este punto, es porque ind e index nunca fueron iguales, o sea no existe un elemento con index
        if (siguiente == NULL)
        {
            //Mensaje 
            cout << "No existen elementos con ese índice" << endl; 
            //Romper
            break;
        }
        //Ind + 1
        ind ++; 
    }
} 

//Eliminar elemento dado el índice
void LinkedList::Remove(int index)
{
    //Tamaño de la lista
    int size = Size(); 
    //Inicializar variables auxiliares
    int ind = 1;
    ListElement* siguiente = firstElement; 
    //iterar elementos
    while (siguiente != NULL)
    {
        //Condición si se quiere eliminar el primer elemento
        if (index == ind && ind == 1)
        {   //Ir al siguiente elemento (elemento 2)
            siguiente = siguiente->getNext();
            // Hacer que el primer elemento deje de apuntar a cualquier lado
            firstElement->nextElement = NULL; 
            //Hacer que el elemento 2 sea el nuevo primer elemento 
            firstElement = siguiente; 
            ind++; 
            //siguiente = siguiente->getNext();
        }
        //Condición si se quiere eliminar cualquier elemento en medio de la lista
        if (ind == index - 1)
        {
            //Queremos guardar el siguiente del elemento que se quiere borrar en una variable
            //Como estamos en un elemento antes del que queremos borrar, tenemos que usar getNext() dos veces
            ListElement* nextNext = siguiente->getNext()->getNext();
            //Variable auxiliar para ir al elemento que se quiere eliminar
            ListElement* aEliminar = siguiente->getNext();
            //Hacer que el elemento que se quiere eliminar, deje de apuntar a cualquier lado
            aEliminar->nextElement = NULL; 
            // Ahora, hacemos que el elemento en el que estamos (el elemento anterior al que se quiere borrar) apunte a nextNext
            siguiente->nextElement = nextNext;  
            //Si el index elegido es menor al tamaño de la lista, ir al siguiente, si no,  no se puede ir al siguiente porque no existe 
            if (index < size)
            {
                //Ir al siguiente elemento
                siguiente = siguiente->getNext(); 
            }
        }
        //siguiente elemento
        siguiente = siguiente->getNext();
        //Condición si se quiere eliminar un elemento inexistente
        if (index > size)
        {
            cout << "No existe ese elemento" << endl; 
            break;
        }
        //Cerrar ciclo
        if (siguiente == NULL)
        {
            break; 
        }
        //ind + 1
        ind++;  
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
        }
    }
    return count; 
} 
void LinkedList::Print()
{
    //Inicializar variable auxiliar
    ListElement* siguiente = firstElement; 
    //Inicializar contador
    int count = 1; 
    //Iterar elementos
    while (siguiente != 0)
    {
        //Imprimir cada elemento con su índice
        cout << count << ". " << siguiente->getElementIdentifier() << endl; 
        //Siguiente elemento
        siguiente = siguiente->getNext(); 
        //Agregar 1 a count
        count ++; 
        //Cerrar ciclo al terminar la lista
        if (siguiente == NULL)
        {
            break;
        }
    }
}