#include "fecha_tarea.h"

int main()
{
    char control; 
    char option; 
    cout << "Bienvenid@ al generador de fechas. Antes de comenzar, ¿quieres saber la fecha de hoy (y/n)?"; 
    cin >> option; 
    if (option == 'y')
    {
        Fecha f; 
        f.getCurrentDate(); 
    }
    cout << "Pulsa la letra 'a' para generar nuevas fechas o la letra 'x' para terminar: "; 
    cin >> control; 
    while (control != 'x')
    {
        Fecha fecha; 
        fecha.getDate();
        cout << "Pulsa 'x' si deseas dejar de escribir fechas. Pulsa cualquier otra letra para continuar: "; 
        cin >> control; 
        }
}