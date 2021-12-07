#include "listInterface.h"

int main()
{
    //Inicializar elementos
    ListElement apple("Apple"); 
    ListElement pear("Pear"); 
    ListElement mango("Mango");
    ListElement banana("Banana"); 
    ListElement berry("Berry"); 
    ListElement orange("Orange"); 
    ListElement watermelon("Watermelon"); 
    ListElement pineapple("Pineapple"); 
    ListElement mango2("Mango"); 

    //Lista de frutas
    ListInterface* fruits = new LinkedList;

    //Implementaciones 
    cout << "Lista de frutas: " << endl; 
    fruits->Add(&pear); 
    fruits->Add(&mango); 
    fruits->Add(2, &banana); 
    fruits->Add(1, &orange); 
    fruits->Add(6, &pineapple); 
    fruits->Add(&apple); 
    fruits->Add(&berry); 
    fruits->Add(3, &watermelon); 
    fruits->Add(&mango2); 
    fruits->Print(); 
    cout << endl; 

    cout << "Eliminar el quinto elemento: " << endl; 
    fruits->Remove(5);  
    fruits->Print(); 
    cout << endl; 

    cout << "La lista contiene " << fruits->Size() << " elementos" << endl; 

    cout << endl; 

    cout << "El elemento número 4 de la lista es: "; 
    fruits->Get(4);
    cout << endl; 

    LinkedList juegos; 
    ListElement amongUs("Among Us");
    ListElement Invictus("Invictus"); 
    juegos.Add(&amongUs); 
    juegos.Add(&Invictus); 
    juegos.Print(); 
    delete fruits; 
}