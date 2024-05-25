#include <iostream>

class Point2D{
  private:
    double coordenada_x;
    double coordenada_y;
  public:
    // Constructor
    Point2D(double _x, double _y){
        coordenada_x = _x;
        coordenada_y = _y;
    }

    //Getters
    double GetX() const{
        return coordenada_x;
    }

    double GetY() const{
        return coordenada_y;
    }
};