#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

class Shape{
    public:
    virtual void calculateArea()=0;
};

class Square : public Shape {
    private:
    double side;
    public:
    void setSide(double side){
        this->side=side;

    }
    void calculateArea(){
        printf("The Area of the Square:%.2f\n",this->side*this->side);
    }
};
class Cube : public Shape{
    private:
    double side;
    public:
    void setSide(double side){
        this->side=side;
    }
    void calculateArea(){
        printf("The area of the cube:%.2f",6*side*side);
    }
};
class Rectangle : public Shape{
    private:
    double length,breadth;
    public:
    void setDimensions(double length,double breadth){
        this->length=length;
        this->breadth=breadth;
    }
    void calculateArea(){
        printf("Area of the Rectangle:%.2f\n",this->length*this->breadth);
    }

};
class Cuboid : public Shape{
    private:
    double length,breadth,height;
    public:
    void setDimensions(double length,double breadth,double height){
        this->length=length;
        this->breadth=breadth;
        this->height=height;
    }
    void calculateArea(){
        printf("The Area of the Cuboid:%.2f\n",(2*(length*breadth+breadth*height+height*length)));
    }
};
int main(){
    int choice;
    double side,length,breadth,height;
    printf("Menu:\n");
    printf("Enter 1 for Square\n");
    printf("Enter 2 for Cube\n");
    printf("Enter 3 for Rectangel\n");
    printf("Enter 4 for Cuboid\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    
    switch(choice){
        case 1:{
            Square square;
            printf("Enter the side length of the square:");
            scanf("%lf",&length);
            square.setSide(length);
            square.calculateArea();
            break;
        }
        
        
        case 2:{
            Cube cube;
            printf("Enter the side length of the cube:");
            scanf("%lf",&length);
            cube.setSide(length);
            cube.calculateArea();
            break;

        }
        case 3:{
            Rectangle rectangle;
            printf("Enter thelength of the rectange:");
            scanf("%lf",&length);
            printf("Enter the breadth of the rectangle:");
            scanf("%lf",&breadth);
            rectangle.setDimensions(length,breadth);
            rectangle.calculateArea();
            break;


        }
        case 4:{
            Cuboid cuboid;
            printf("Enter thelength of the cuboid:");
            scanf("%lf",&length);
            printf("Enter the breadth of the cuboid:");
            scanf("%lf",&breadth);
            printf("Enter the heigth of the cuboid:");
            scanf("%lf",&height);
            cuboid.setDimensions(length,breadth,height);
            cuboid.calculateArea();
            break;

        }
        case 5:{
            printf("Exiting the program");
        }
        default:
        printf("Invalid choice,Please try again later");
    }
    return 0;


}