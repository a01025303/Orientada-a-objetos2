#include "persona_tarea.h"
using namespace std; 


int main()
{
    //Creación de instancias
    Person sara("Sara", Fecha(1, "1", "1924"), 0, 0);
    Person javier("Javier", Fecha(1, "1", "1924"), 0, 0); 
    Person leticia("Leticia", Fecha(8, "4", "1993"), &sara, &javier); 
    Person pedro("Pedro", Fecha(8, "4", "1993"), 0, 0); 
    Person laura("Laura", Fecha(20, "3", "1968"), &leticia, &pedro);
    Person soledad("Soledad", Fecha(2, "4", "1987"), &laura, 0);
    Person pedro2("Pedro", Fecha(2, "4", "1987"), 0, 0);
    Person camila("Camila", Fecha(13, "2", "2003"), &soledad, &pedro2);

    
    //Preguntas
    // 1.¿Cuántos antecesores tiene Camila?
    cout << "Camila tiene " << camila.getAntecesores() << " antecesores." << endl; 
    cout << endl; 
    
    // 2.¿Cómo se llama la abuelita de Camila? 
    cout << "Los nombres de los antecesores de Camila son los siguentes (empezando por la mamá --> abuelita es segunda en la lista): " << endl; 
    camila.nombresAntecesores(); 
    cout << endl; 

    cout << "El nombre de la abuelita de Camila es: "; 
    Person* mama = camila.getMother(); 
    mama = mama -> getMother(); 
    cout << mama -> name << endl; 
    cout << endl; 
    
    //3.¿quién es el antecesor más joven de Camila?
    cout << "El antecesor más joven de Camila es: "; 
    camila.antecesorJoven(); 
    cout << endl; 

    //4.¿quién es el antecesor más longevo de Camila?
    cout << "El antecesor más longevo de Camila es: "; 
    camila.antecesorViejo(); 
    cout << endl; 

    
    //5.¿Javier es Papá de quién?
    Person* ma = camila.getMother(); 
    Person* papa = camila.getFather(); 
    while (papa -> name != "Javier")
    {
        ma = ma -> getMother(); 
        papa = ma -> getFather(); 
    }
    cout << papa->name << " es papá de " << ma -> name << endl; 
    cout << endl; 
}