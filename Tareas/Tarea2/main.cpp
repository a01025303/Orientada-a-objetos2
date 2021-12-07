#include "lineStatistics.h"

using namespace std; 

int main()
{
    //Creación de instancias
    Elemento luisa("Luisa", Time(11, 0), Time(12, 0), 0);
    Elemento pedro("Pedro", Time(11, 25), Time(12, 16), &luisa); 
    Elemento juana("Juana", Time(12, 15), Time(13, 22), &pedro);
    Elemento roberto("Roberto", Time(12, 17), Time(13, 20), &juana);
    Elemento rubi("Rubí", Time(12, 54), Time(14, 0), &roberto);
    Elemento julio("Julio", Time(12, 55), Time(14, 1), &rubi);
    Elemento adriana("Adriana", Time(13, 5), Time(14, 10), &julio);
    Elemento ana("Ana", Time(14, 3), Time(14, 35), &adriana); 
    Elemento rodrigo("Rodrigo", Time(14, 5), Time(14, 36), &ana);
    Elemento andrea("Andrea", Time(14, 43), Time(14, 50), &rodrigo);

    LineStatistics ultimo(andrea);  

    //Respuesta a preguntas

    //a)¿Cuál fue el tiempo mínimo entre llegadas en minutos? En el ejemplo anterior 2 minutos
    cout << "El tiempo mínimo entre llegadas fue de " << ultimo.getTiempoMin() << " minutos" << endl;
    //b)¿Cuál fue el tiempo máximo entre llegadas en minutos? En el ejemplo son 50 minutos
    cout << "El tiempo máximo entre llegadas fue de " << ultimo.getTiempoMax() << " minutos" << endl;
    //c)¿Cuá fue el tiempo promedio entre llegadas?
    cout << "El tiempo promedio entre llegadas fue de " << ultimo.getTiempoProm() << " minutos" << endl;
    //d)¿Cuál fue el tiempo mínimo de atención (diferencia entre la hora de salida y de entrada)?
    cout << "El tiempo mínimo de atención fue de " << ultimo.TiempoMinAtencion() << " minutos" << endl;
    //e)¿Cuál fue el tiempo máximo de atención (diferencia entre la hora de salida y de entrada)?
    cout << "El tiempo máximo de atención fue de " << ultimo.TiempoMaxAtencion() << " minutos" << endl;
    //f)¿Cuál fue el tiempo promedio de atención (diferencia entre la hora de entrada y de salida)? 
    cout << "El tiempo promedio de atención fue de " << ultimo.TiempoPromAtencion() << " minutos" << endl;

    //Sección 2
    //g)¿Quién llegó después de X? Donde X puede ser cualquiera de los nombres de la fila  
    string personY; 
    cout << "¿Quién llegó después de Y?" << endl; 
    cout << "¿Quién es Y? (escribe su nombre con la inicial mayúscula y acentos de ser necesario): "; 
    cin >> personY; 
    cout << ultimo.personaDespues(personY) << " llegó después que " << personY << endl;
    //h)¿Quién llegó antes de X? Donde X puede ser cualquiera de los nombres de la fila
    string personX; 
    cout << "¿Quién llegó antes de X?" << endl; 
    cout << "¿Quién es X? (escribe su nombre con la inicial mayúscula y acentos de ser necesario): "; 
    cin >> personX; 
    cout << ultimo.personaAntes(personX) << " llegó antes que " << personX << endl;
}