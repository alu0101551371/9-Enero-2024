#include "robot.h"
#include <iostream>

using robot::Robot;

Robot::Robot(std::string nombre, Point2D posicion, Direccion orientacion, int cansancio) {
    nombre_ = nombre;
    posicion_ = posicion;
    direccion_ = orientacion;
    cansancio_ = cansancio;
}

std::string Robot::GetNombre() const {
    return nombre_;
}

Point2D Robot::GetPosicion() const {
    return posicion_;
}

robot::Direccion Robot::GetOrientacion() const {
    return direccion_;
}

int Robot::GetCansancio() const {
    return cansancio_;
}

void Robot::GiroDerecha() {
    switch (direccion_) {
        case Direccion::Norte:
            direccion_ = Direccion::Este;
            break;
        case Direccion::Sur:
            direccion_ = Direccion::Oeste;
            break;
        case Direccion::Este:
            direccion_ = Direccion::Sur;
            break;
        case Direccion::Oeste:
            direccion_ = Direccion::Norte;
            break;
    }
}

void Robot::GiroIzquierda() {
    switch (direccion_) {
        case Direccion::Norte:
            direccion_ = Direccion::Oeste;
            break;
        case Direccion::Sur:
            direccion_ = Direccion::Este;
            break;
        case Direccion::Este:
            direccion_ = Direccion::Norte;
            break;
        case Direccion::Oeste:
            direccion_ = Direccion::Sur;
            break;
    }
}

void Robot::Avanzar() {
    switch (direccion_) {
        case Direccion::Norte:
            posicion_.Move(posicion_.GetX(), posicion_.GetY() + 1);
            break;
        case Direccion::Sur:
            posicion_.Move(posicion_.GetX(), posicion_.GetY() - 1);
            break;
        case Direccion::Este:
            posicion_.Move(posicion_.GetX() + 1, posicion_.GetY());
            break;
        case Direccion::Oeste:
            posicion_.Move(posicion_.GetX() - 1, posicion_.GetY());
            break;
    }
}

void Robot::EjecutaSecuencia(std::string secuencia) {
    for (char c : secuencia) {
        switch (c) {
            case 'D':
                GiroDerecha();
                break;
            case 'I':
                GiroIzquierda();
                break;
            case 'A':
                Avanzar();
                cansancio_++;
                break;
        }
    }
}

std::ostream& robot::operator<<(std::ostream& os, const Robot& robot) {
    os << "Robot " << robot.GetNombre() << " en posición ";
    robot.GetPosicion().Print(os);
    os << " orientado hacia ";
    switch (robot.GetOrientacion()) {
        case Direccion::Norte:
            os << "Norte";
            break;
        case Direccion::Sur:
            os << "Sur";
            break;
        case Direccion::Este:
            os << "Este";
            break;
        case Direccion::Oeste:
            os << "Oeste";
            break;
    }
    os << " con " << robot.GetCansancio() << " de cansancio";
    return os;
}