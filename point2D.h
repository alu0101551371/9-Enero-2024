#include <iostream>
#pragma once

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

    Point2D() {
      coordenada_x = -1;
      coordenada_y = -1;
    }

    //Getters
    double GetX() const{
        return coordenada_x;
    }

    double GetY() const{
        return coordenada_y;
    }

    void Move(double x, double y) {
      coordenada_x = x;
      coordenada_y = y;
    }

    void Print(std::ostream& os) {
      os << "[" << GetX() << ", " << GetY() << "]";
    }
};