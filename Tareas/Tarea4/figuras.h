#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

#pragma once 

class Shape
{
    protected: 
        string shapeName; 
    public: 
        Shape(); 
        Shape(string theName); 
        string getName(); 
}; 

class TwoD : public Shape
{
    protected: 
        float area; 
        float perimeter; 
    public: 
        TwoD(); 
        TwoD(string theName, float theArea, float thePerimeter); 
        TwoD(string theName);
        virtual float calculateArea(); 
        virtual float calculatePerimeter(); 
        float getArea(); 
        float getPerimeter(); 
}; 

class ThreeD : public Shape
{
    protected:
        float volume; 
        float surfaceArea; 
    public: 
        ThreeD(); 
        ThreeD(string theName, float theVolume, float theSurfaceArea); 
        ThreeD(string theName);
        virtual float calculateVolume(); 
        virtual float calculateSurfaceArea(); 
        float getVolume(); 
        float getSurfaceArea(); 
};

class Square : public TwoD
{
    private: 
        float sideSize; 
    public: 
        Square(); 
        Square(float); 
        Square(string, float); 
        float getSideSize(); 
        float calculateArea(); 
        float calculatePerimeter(); 
}; 

class Rectangle : public TwoD
{
    protected: 
        float shortSide; 
        float longSide; 
    public: 
        Rectangle(); 
        Rectangle(string, float, float); 
        float getLongSide(); 
        float getShortSide(); 
        float calculateArea(); 
        float calculatePerimeter(); 
}; 


class Circle : public TwoD
{
    protected: 
        float radius; 
    public: 
        Circle(); 
        Circle(string, float); 
        float getRadius(); 
        float calculateArea(); 
        float calculatePerimeter(); 
}; 

class Triangle : public TwoD
{
    protected: 
        float sideA; 
        float sideB; //Este será considerado como la base
        float sideC; 
        float height; 
    public: 
        Triangle(); 
        Triangle(string, float, float, float, float);
        float getSideA(); 
        float getSideB(); 
        float getSideC(); 
        float getHeight(); 
        float calculateArea(); 
        float calculatePerimeter();
}; 

class Parallelogram : public TwoD
{
    protected: 
        float base; 
        float side1; 
        float height; 
    public: 
        Parallelogram(); 
        Parallelogram(string, float, float, float);
        float getBase(); 
        float getSide2(); 
        float getHeight(); 
        float calculateArea(); 
        float calculatePerimeter();
}; 

class Trapeze : public TwoD
{
    protected: 
        float base; 
        float side2; 
        float height; 
        float shortBase; 
    public: 
        Trapeze(); 
        Trapeze(string, float, float, float, float);
        float getBase1(); 
        float getSide3(); 
        float getHeight1(); 
        float calculateArea(); 
        float calculatePerimeter();
}; 

class Tetrahedron : public ThreeD
{
    protected:
        float side; 
    public: 
        Tetrahedron(); 
        Tetrahedron(string, float); 
        float getSide(); 
        float calculateVolume(); 
        float calculateSurfaceArea(); 

};

class Sphere : public ThreeD
{
    protected: 
        float radio; 
    public: 
        Sphere(); 
        Sphere(string, float); 
        float getRadio(); 
        float calculateVolume(); 
        float calculateSurfaceArea(); 
}; 
class Cube : public ThreeD
{
    protected: 
        float lado; 
    public: 
        Cube(); 
        Cube(string, float); 
        float getLado(); 
        float calculateVolume(); 
        float calculateSurfaceArea(); 
};
class RectangularPrism : public ThreeD
{
    protected: 
        float ancho; 
        float largo; 
        float alto;
    public: 
        RectangularPrism(); 
        RectangularPrism(string, float, float, float); 
        float getAncho(); 
        float getLargo(); 
        float getAlto(); 
        float calculateVolume(); 
        float calculateSurfaceArea(); 
};
class Cone : public ThreeD
{
    protected: 
        float rad; 
        float altura;
    public:
        Cone(); 
        Cone(string, float, float); 
        float getRadio1(); 
        float getAltura(); 
        float calculateVolume(); 
        float calculateSurfaceArea(); 
}; 
