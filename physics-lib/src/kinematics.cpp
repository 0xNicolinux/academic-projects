#include <cmath>
#include "kinematics.h"

namespace physics::kinematics
{

    // Velocidade média: v = d / t
    double velocity(double distance, double time)
    {
        if (time <= 0)
            return 0;
        return distance / time;
    }

    // Aceleração média: a = Δv / t
    double acceleration(double deltaVelocity, double time)
    {
        if (time == 0)
            return 0;
        return deltaVelocity / time;
    }

    // Posição no MU: s = s0 + v * t
    double position(double initialPosition, double velocity, double time)
    {
        return initialPosition + velocity * time;
    }

    // Velocidade final: v = v0 + a * t
    double finalVelocity(double initialVelocity, double acceleration, double time)
    {
        return initialVelocity + acceleration * time;
    }

    // Posição no MUV: s = s0 + v0*t + (1/2)*a*t²
    double positionMUV(double initialPosition, double initialVelocity, double acceleration, double time)
    {
        return initialPosition + initialVelocity * time + 0.5 * acceleration * time * time;
    }

    // Torricelli: v² = v0² + 2*a*Δs
    double torricelli(double v0, double a, double deltaS)
    {
        double value = v0 * v0 + 2 * a * deltaS;

        if (value < 0)
            return 0; // evita sqrt de número negativo

        return std::sqrt(value);
    }

}