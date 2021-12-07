#include "figuras.h"
using namespace std; 

int main()
{
    Circle circulo("círculo", 5.0f);
    Parallelogram paralelogramo("paralelogramo", 20.0f, 13.0f, 12.0f);
    Rectangle rectangulo("rectángulo", 7.0f, 15.0f);
    Square cuadrado("cuadrado", 4.6f);
    Trapeze trapecio("trapecio", 10.0f, 5.0f, 4.0f, 4.0f);
    Triangle TEquilatero("triángulo equilátero", 10.0f, 10.0f, 10.0f, 8.6f);
    Triangle TIsosceles("triángulo isósceles", 8.0f, 5.0f, 8.0f, 7.6f);
    Triangle TRectangulo("triángulo rectángulo", 6.0f, 5.2f, 3.0f, 3.0f);
    Cone cono("cono", 5.0f, 13.0f);
    Cube cubo("cubo", 15.0f);
    RectangularPrism prismaRectangular("prisma Rectangular", 4.0f, 1.5f, 3.0f);
    Sphere esfera("esfera", 2.2f);
    Tetrahedron tetraedro("tetraedro", 9.6f);

    cout << "Área del " << circulo.getName() << ": "<< circulo.calculateArea() << endl;
    cout << "Perímetro del " << circulo.getName() << ": "<< circulo.calculatePerimeter() << endl; 
    cout << "Área del " <<  rectangulo.getName() << ": " << rectangulo.calculateArea() << endl;
    cout <<  "Perímetro del "<< rectangulo.getName() << ": " << rectangulo.calculatePerimeter() << endl; 
    cout << "Área del "<< cuadrado.getName() << ": " << cuadrado.calculateArea() << endl;
    cout <<  "Perímetro del "<< cuadrado.getName() << ": " << cuadrado.calculatePerimeter() << endl; 
    cout << "Área del "<< TEquilatero.getName() << ": " << TEquilatero.calculateArea() << endl;
    cout << "Perímetro del "<< TEquilatero.getName() << ": " << TEquilatero.calculatePerimeter() << endl; 
    cout << "Área del "<< TIsosceles.getName() << ": " << TIsosceles.calculateArea() << endl;
    cout <<  "Perímetro del "<< TIsosceles.getName() << ": " << TIsosceles.calculatePerimeter() << endl; 
    cout << "Área del "<< TRectangulo.getName() << ": " << TRectangulo.calculateArea() << endl;
    cout <<  "Perímetro del "<< TRectangulo.getName() << ": " << TRectangulo.calculatePerimeter() << endl; 
    cout << "Área del " << paralelogramo.getName() << ": " << paralelogramo.calculateArea() << endl;
    cout <<  "Perímetro del " << paralelogramo.getName() << ": " << paralelogramo.calculatePerimeter() << endl; 
    cout << "Área del " <<  trapecio.getName() << ": " << trapecio.calculateArea() << endl;
    cout <<  "Perímetro del "<< trapecio.getName() << ": " << trapecio.calculatePerimeter() << endl; 
    cout << "Volumen del "<< cono.getName() << ": " << cono.calculateVolume() << endl;
    cout << "Área superficial del "<< cono.getName() << ": " << cono.calculateSurfaceArea() << endl; 
    cout << "Volumen del "<< cubo.getName() << ": " << cubo.calculateVolume() << endl;
    cout << "Área superficial del "<< cubo.getName() << ": " << cubo.calculateSurfaceArea() << endl; 
    cout << "Volumen del "<< prismaRectangular.getName() << ": " << prismaRectangular.calculateVolume() << endl;
    cout << "Área superficial del "<< prismaRectangular.getName() << ": " << prismaRectangular.calculateSurfaceArea() << endl; 
    cout << "Volumen del "<< esfera.getName() << ": " << esfera.calculateVolume() << endl;
    cout << "Área superficial del "<< esfera.getName() << ": " << esfera.calculateSurfaceArea() << endl; 
    cout << "Volumen del "<< tetraedro.getName() << ": " << tetraedro.calculateVolume() << endl;
    cout << "Área superficial del "<< tetraedro.getName() << ": " << tetraedro.calculateSurfaceArea() << endl; 
}