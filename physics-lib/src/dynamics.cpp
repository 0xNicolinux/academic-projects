#include "dynamics.h"

namespace physics::dynamics
{

    // Força resultante: F = m * a
    double force(double mass, double acceleration)
    {
        if (mass <= 0)
            return 0;

        return mass * acceleration;
    }

    // Aceleração: a = F / m
    double accelerationFromForce(double force, double mass)
    {
        if (mass <= 0)
            return 0;

        return force / mass;
    }

    // Peso: P = m * g
    double weight(double mass, double gravityAcceleration)
    {
        if (mass <= 0)
            return 0;

        return mass * gravityAcceleration;
    }

    // Atrito: Fa = μ * N
    double friction(double normalForce, double frictionCoefficient)
    {
        if (normalForce < 0 || frictionCoefficient < 0)
            return 0;

        return normalForce * frictionCoefficient;
    }

}