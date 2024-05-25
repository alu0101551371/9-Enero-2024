// Creación y definición de la clase Robot

#ifndef ROBOT_H
#define ROBOT_H

#include "point2D.h"
#include <iostream>
#include <string>

namespace robot {
    enum class Direccion {
        Norte,
        Sur,
        Este,
        Oeste
    };

    class Robot {
        public:
            // Constructor
            Robot(std::string nombre, Point2D posicion, Direccion orientacion, int cansancio);

            // Getters
            std::string GetNombre() const;
            Point2D GetPosicion() const;
            Direccion GetOrientacion() const;
            int GetCansancio() const;

            // Metodos
            void GiroDerecha();
            void GiroIzquierda();
            void Avanzar();
            void EjecutaSecuencia(std::string secuencia);

        private:
            std::string nombre_;
            Point2D posicion_;
            Direccion direccion_;
            int cansancio_;
    };

    std::ostream& operator<<(std::ostream& os, const Robot& robot);
}

#endif
