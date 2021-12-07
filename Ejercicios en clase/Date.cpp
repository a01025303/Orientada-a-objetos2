#include "Date.h"

using namespace std; 

//Implementación 
//Constructor sin parámetros 
Fecha::Fecha()
{ 
    day = 14; 
    month = "3"; 
    year = "2021"; 
}

//Constructor con parámetros
Fecha::Fecha(int theDay, string theMonth, string theYear): day(theDay), month(theMonth), year(theYear){}

//Implementación getDay()
int Fecha::getDay()
{
    return day;
}

//Implementación getMonth()
string Fecha::getMonth()
{
    return month;
}

//Implementación getYear()
string Fecha::getYear()
{
    return year;
}

//Get current date
int Fecha::getCurrentDate()
{ 
    //Arrays con strings de diferentes notaciones para el año
    //Notación normal
    string meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", 
                        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"}; 
    //Notación abreviada
    string mesesAb[12] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago",
                        "sep", "oct", "nov", "dic"};
    //Notación numérica
    string mesesNum[12] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12"};

    //Obtener fecha actual 
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    //Día actual
    int diaActual = (tPtr->tm_mday);
    //Mes actual
    int mesActual = (tPtr->tm_mon)+1;
    //Año actual
    int anioActual = (tPtr->tm_year)+1900;

    //Interacción con el usuario
    cout << "Ofrecemos los siguientes formatos: " << endl; 
    cout << "1. 14-mar" << endl; 
    cout << "2. 14-marzo-2020" << endl; 
    cout << "3. 14/03/2020" << endl; 
    cout << "4. 14/03" << endl; 
    //Pedir formato deseado
    int formato; 
    cout << "Elige una opción: "; 
    cin >> formato;
    //Condiciones para el formato
    switch (formato)
    {
    case 1:
        printf("%02d", diaActual); 
        cout << "-" << mesesAb[mesActual-1] << endl; 
        break;
    
    case 2:
        printf("%02d", diaActual); 
        cout << "-" << meses[mesActual-1] << "-" << anioActual << endl; 
        break;
    case 3:
        printf("%02d/%02d", diaActual, mesActual); 
        cout << "/" << anioActual << endl; 
        break;
    case 4:
        printf("%02d/%02d", diaActual, mesActual);
        cout << endl;  
        break;
    }
    return 1; 
}

//getDate()
int Fecha::getDate()
{ 
    //Arrays con notaciones para el mes
    //Notación normal
    string meses[12] = {"enero", "febrero", "marzo", "abril", "mayo", "junio", 
                        "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"}; 
    //Notación abreviada
    string mesesAb[12] = {"ene", "feb", "mar", "abr", "may", "jun", "jul", "ago",
                        "sep", "oct", "nov", "dic"};
    //Notación numérica
    string mesesNum[12] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12"};
    //Inicializar contador número para posición de arrays
    int elNum; 
    //Inicializar variables para el día, mes y año
    int elDia;
    string elMes; 
    string elAnio;

    //Intrucciones e interacción con el usuario
    //Selección de día, mes, año
    cout << "Escribe el día de la fecha: "; 
    cin >> elDia;
    cout << "Escribe el mes de la fecha (numéricamente, con 3 letras o la palabra completa): "; 
    cin >> elMes; 
    cout << "Escribe el año completo: "; 
    cin >> elAnio; 

    //Selección de formato 
    cout << "Ofrecemos los siguientes formatos: " << endl; 
    cout << "1. 14-mar" << endl; 
    cout << "2. 14-marzo-2020" << endl; 
    cout << "3. 14/03/2020" << endl; 
    cout << "4. 14/03" << endl; 
    int formato; 
    cout << "Elige una opción: "; 
    cin >> formato;

    //Constructor de fecha 
    Fecha date = Fecha(elDia, elMes, elAnio); 
    //Obtener mes como string 
    string mes = date.getMonth();  

    //Ciclo para determinar el valor de "elNum"
    for (int i = 0; i < 12; i++)
    {
        //Condición para un número
        if (mes.length() <= 2)
        {
            if (mesesNum[i] == elMes)
            {
                elNum = i; 
                break; 
            }
        }
        //Condición para la manera abreviada
        else if (mes.length() == 3)
        {
            if (mesesAb[i] == elMes)
            {
                elNum = i; 
                break; 
            }
            
        }
        //Condición para la manera normal
        else if (mes.length() > 3 && elMes.length() < 11)
        {
            if (meses[i] == elMes)
            {
                elNum = i; 
                break; 
            }
        }
        //Condición por si se escribe mal la fecha 
        else
        {
            cout << "Elige un mes válido. Recuerda escribirlo en minúsculas" << endl; 
        }
    }
    switch (formato)
    {
    case 1:
        printf("%02d", date.getDay());
        cout << "-" << mesesAb[elNum] << endl; 
        break;
    case 2:
        printf("%02d", date.getDay());
        cout << "-" << meses[elNum] << "-" << date.getYear() << endl; 
        break;
    case 3:
        printf("%02d", date.getDay()); 
        cout << "/" << mesesNum[elNum] << "/" << date.getYear() << endl; 
        break;
    case 4:
        printf("%02d", date.getDay()); 
        cout << "/" << mesesNum[elNum] << endl; 
        break;
    }
    return 1; 
}


/*Nota: 
Para este trabajo, no se consideraron casos en los que el usuario no sepa escribir la fecha. 
En caso de que se haya escrito algo mal (ejemplo: febrero 31) o en una notación diferente a la solicitada, 
el programa no lo tomará en cuenta.
Para hacer que este ejercicio sea más completo en un futuro, se tendrían que agregar métodos que revisen si la 
notación escrita es la solicitada y si la fecha escrita es correcta. 

PS: Ariel, perdón si está demasiado largo el código, esto fue lo mejor que se me ocurrió para hacerlo eficiente :)*/