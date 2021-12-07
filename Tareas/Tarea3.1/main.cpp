#include "cine.h"
#include <iostream>

using namespace std; 

int main()
{
    //Creación de clientes
    Cliente peter(1, "Peter", "3734384738");
    Cliente mark(2, "Mark", "78298334595"); 
    Cliente robert(3, "Robert", "89809864"); 
    Cliente danny(4, "Danny", "824073565"); 

    //Creación de asientos
    Asientos V12(false, 12, 180, "V", 0);
    Asientos V11(false, 11, 180, "V", &V12);
    Asientos V10(false, 10, 180, "V", &V11);
    Asientos V9(false, 9, 180, "V", &V10);
    Asientos R5(false, 5, 90, "R", &V9);
    Asientos R6(false, 6, 90, "R", &R5);
    Asientos R7(false, 7, 90, "R", &R6); 
    Asientos R8(false, 8, 90, "R", &R7); 
    Asientos S4(false, 4, 40, "S", &R8); 
    Asientos S3(false, 3, 40, "S", &S4); 
    Asientos S2(false, 2, 40, "S", &S3); 
    Asientos S1(false, 1, 40, "S", &S2); 

    //Creación de admins
    Admin rose(Fecha(1, "3", "2019"), 20000, 1, "Rose", "6565549493", &S1); 
    Admin mary(Fecha(25, "11", "2020"), 20000, 2, "Mary", "2783495856", &S1);
    
    rose.reserveByNumber(3, peter); 
    rose.reserveByType("V", mark); 
    mary.reserveByNumber(6, robert); 
    mary.reserveByType("R", danny); 
    cout<<endl; 
    mary.printReserved();

    rose.reserveByNumber(1, mark); 
    rose.printCost(1); 
    mary.modifyCosts("S", 55); 
    mary.printCost(1); 
    mary.reserveByNumber(1, peter); 
    mary.cancelSeat(1); 
    rose.reserveByType("S", robert); 
    mary.adminReserve(&S1); 
}