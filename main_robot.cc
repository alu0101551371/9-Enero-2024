// Compilar con g++ -o Simulator_Robot robot.cc main_robot.cc

#include "robot.h"

using robot::Robot;
using robot::Direccion;

int main() {
    const Point2D posicion(7,3);
    const Direccion orientacion(Direccion::Norte);
    Robot c3po("c3po", posicion, orientacion, 0);
    c3po.EjecutaSecuencia("DAAIAI");
    std::cout << c3po << std::endl;
    Robot r2d2("r2d2", posicion, Direccion::Sur, 0);
    std::cout << r2d2 << std::endl;
    return 0;
}