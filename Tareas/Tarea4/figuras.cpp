#include "figuras.h"

//Implementación clase Shape
Shape::Shape():shapeName("Cuadrado"){}
Shape::Shape(string theName): shapeName(theName){} 
string Shape::getName()
{
    return shapeName;
}

//Implementación clase TwoD
TwoD::TwoD(): Shape("Cuadrado"), area(1), perimeter(4){}
TwoD::TwoD(string theName): Shape(theName){}
float TwoD::calculateArea()
{
    return 0; 
}
float TwoD::calculatePerimeter()
{
    return 0;
} 

//Implementación Square
Square::Square():sideSize(){} 
Square::Square(string theName, float elLado): TwoD(theName), sideSize(elLado){} 
float Square::getSideSize()
{
    return sideSize; 
}
float Square::calculateArea()
{
    return sideSize*sideSize; 
}
float Square::calculatePerimeter()
{ 
    return sideSize * 4;
} 

//Implementación Rectangle
Rectangle::Rectangle():TwoD("Rectángulo") , shortSide(1), longSide(3){} 
Rectangle::Rectangle(string theName, float theShortSide, float theLongSide): TwoD(theName), shortSide(theShortSide), longSide(theLongSide){}
float Rectangle::getLongSide()
{
    return longSide; 
}
float Rectangle::getShortSide()
{
    return shortSide; 
}
float Rectangle::calculateArea()
{
    return longSide*shortSide; 
}
float Rectangle::calculatePerimeter()
{
    return (longSide * 2) + (shortSide*2);
} 

//Implementación Circle 
Circle::Circle():TwoD("Círculo"), radius(1){}
Circle::Circle(string theName, float theRadius): TwoD(theName), radius(theRadius){}
float Circle::getRadius()
{
    return radius; 
} 
float Circle::calculateArea()
{
    return M_PI * (radius) * (radius); 
} 
float Circle::calculatePerimeter() 
{
    return 2 * M_PI * (radius); 
} 

//Implementación triángulo
Triangle::Triangle():TwoD("Triángulo rectángulo"), sideA(1), sideB(1), sideC(1), height(3){}
Triangle::Triangle(string theName, float theSideA, float theSideB, float theSideC, float theHeight): TwoD(theName), sideA(theSideA), sideB(theSideB), sideC(theSideC), height(theHeight){}
float Triangle::getSideA()
{
    return sideA;
}
float Triangle::getSideB()
{
    return sideB;
} 
float Triangle::getSideC()
{
    return sideC;
}
float Triangle::getHeight()
{
    return height;
}
float Triangle::calculateArea()
{
    return sideB*height/2;
}
float Triangle::calculatePerimeter()
{
    return sideA+sideB+sideC;
}


//Implementación clase ThreeD
ThreeD::ThreeD():Shape("Cubo"), volume(1), surfaceArea(1){} 
ThreeD::ThreeD(string theName): Shape(theName){}
float ThreeD::getVolume()
{
    return volume; 
}
float ThreeD::getSurfaceArea()
{
    return surfaceArea; 
}

float ThreeD::calculateVolume()
{
    return 0; 
} 
float ThreeD::calculateSurfaceArea()
{
    return 0; 
} 

Sphere::Sphere():ThreeD("Esfera"), radio(1){}
Sphere::Sphere(string theName, float theRadius): ThreeD(theName), radio(theRadius){}
float Sphere::getRadio()
{
    return radio;
}
float Sphere::calculateVolume()
{
    return (4/3)*M_PI*(radio*radio*radio); 
}
float Sphere::calculateSurfaceArea()
{
    return 4*M_PI*(radio*radio); 
} 

Cube::Cube():ThreeD("Cubo"), lado(1){} 
Cube::Cube(string theName, float elLado): ThreeD("Cubo"), lado(elLado){}
float Cube::getLado()
{
    return lado; 
}
float Cube::calculateVolume()
{
    return (lado*lado*lado); 
} 
float Cube::calculateSurfaceArea()
{
    return (6*lado*lado);
} 

Parallelogram::Parallelogram():TwoD("Paralelogramo"), base(1), side1(1.5), height(1){} 
Parallelogram::Parallelogram(string theName, float theBase, float theSide1, float theHeight): TwoD(theName), base(theBase), side1(theSide1), height(theHeight){}
float Parallelogram::getBase()
{
    return base; 
}
float Parallelogram::getSide2()
{
    return side1; 
}
float Parallelogram::getHeight()
{
    return height; 
} 
float Parallelogram::calculateArea()
{
    return base*height; 
} 
float Parallelogram::calculatePerimeter()
{
    return 2*side1 + 2*base; 
}

Trapeze::Trapeze(): TwoD("Trapecio"), base(4), side2(3), height(2), shortBase(2){} 
Trapeze::Trapeze(string theName, float theBase, float theSide2, float theHeight, float theShortBase): TwoD(theName), base(theBase), side2(theSide2), height(theHeight), shortBase(theShortBase){}
float Trapeze::getBase1()
{
    return base; 
} 
float Trapeze::getSide3()
{
    return side2; 
} 
float Trapeze::getHeight1()
{
    return height;
}
float Trapeze::calculateArea()
{
    return (base+shortBase)*height/2;
}
float Trapeze::calculatePerimeter()
{
    return base + shortBase + 2*side2; 
}

Tetrahedron::Tetrahedron():ThreeD("Tetraedro"), side(1){} 
Tetrahedron::Tetrahedron(string theName, float theSide):ThreeD(theName), side(theSide){} 
float Tetrahedron::getSide()
{
    return side; 
}
float Tetrahedron::calculateVolume()
{
    return ((side*side*side)*sqrt(2))/12;
} 
float Tetrahedron::calculateSurfaceArea()
{
    return (side*side)*sqrt(3); 
} 

RectangularPrism::RectangularPrism():ThreeD("Prisma rectangular"), ancho(1), largo(2), alto(1){} 
RectangularPrism::RectangularPrism(string theName, float elAncho, float elLargo, float elAlto):ThreeD(theName), ancho(elAncho), largo(elLargo), alto(elAlto){} 
float RectangularPrism::getAncho()
{
    return ancho;
}
float RectangularPrism::getLargo()
{
    return largo; 
} 
float RectangularPrism::getAlto()
{
    return alto; 
} 
float RectangularPrism::calculateVolume()
{
    return ancho*largo*alto;
} 
float RectangularPrism::calculateSurfaceArea()
{
    return (2*ancho*alto) + 2*largo*(ancho+alto);
}   

Cone::Cone():ThreeD("Cono"), rad(1), altura(2){} 
Cone::Cone(string theName, float theRad, float theH):ThreeD(theName), rad(theRad), altura(theH){} 
float Cone::getRadio1()
{
    return rad; 
} 
float Cone::getAltura()
{
    return altura; 
}
float Cone::calculateVolume()
{
    return M_PI*(rad*rad)*altura/3;
} 
float Cone::calculateSurfaceArea()
{
    float g = sqrt(rad*rad + altura*altura);
    return M_PI*rad*g + M_PI*(rad*rad); 
} 