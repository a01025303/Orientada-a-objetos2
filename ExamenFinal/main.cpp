#include "juegos.h"
int main()
{
    char elTipo = 'M'; 
    int elID = 1; 
    string elNombre = "Memoria"; 
    OneLevelGame memoria1("Memoria", elID, &elTipo); 
    cout << memoria1.getNombre() << endl; 
    cout << memoria1.getID() << endl; 
}
    
    //Game memoria(elNombre, elID, &elTipo); 
    //cout << memoria.getNombre(); 
    //cout << memoria.getNombre() << endl; 
    //cout << memoria.getID() << endl; 
    //cout << memoria.getTipo() << endl; 
    /*Game* juego1niv = new OneLevelGame("Cuerda", elID, elTipo); 
    Game* juego2niv = new MultilevelGame(elNombre, elID, elTipo); 

    cout << juego1niv->play() << endl; 
    cout << juego2niv->play() << endl; 

    delete juego1niv; 
    delete juego2niv;*/
//}