#pragma once

namespace physics::kinematics
{

    // ===============================
    // Movimento Uniforme (MU)
    // ===============================

    /**
     * Calcula a velocidade média.
     * Fórmula: v = d / t
     * @param distance Distância percorrida (m)
     * @param time Tempo decorrido (s)
     * @return Velocidade (m/s). Retorna 0 se time == 0.
     */
    double velocity(double distance, double time);

    /**
     * Calcula a posição final no movimento uniforme.
     * Fórmula: s = s0 + v * t
     * @param initialPosition Posição inicial (m)
     * @param velocity Velocidade constante (m/s)
     * @param time Tempo (s)
     * @return Posição final (m)
     */
    double position(double initialPosition, double velocity, double time);

    // ===============================
    // Movimento Uniformemente Variado (MUV)
    // ===============================

    /**
     * Calcula a aceleração média.
     * Fórmula: a = Δv / t
     * @param deltaVelocity Variação da velocidade (m/s)
     * @param time Tempo (s)
     * @return Aceleração (m/s²). Retorna 0 se time == 0.
     */
    double acceleration(double deltaVelocity, double time);

    /**
     * Calcula a velocidade final.
     * Fórmula: v = v0 + a * t
     * @param initialVelocity Velocidade inicial (m/s)
     * @param acceleration Aceleração (m/s²)
     * @param time Tempo (s)
     * @return Velocidade final (m/s)
     */
    double finalVelocity(double initialVelocity, double acceleration, double time);

    /**
     * Calcula a posição final no movimento uniformemente variado.
     * Fórmula: s = s0 + v0*t + (1/2)*a*t²
     * @param initialPosition Posição inicial (m)
     * @param initialVelocity Velocidade inicial (m/s)
     * @param acceleration Aceleração (m/s²)
     * @param time Tempo (s)
     * @return Posição final (m)
     */
    double positionMUV(double initialPosition, double initialVelocity, double acceleration, double time);

    /**
     * Calcula a velocidade final usando a equação de Torricelli.
     * Fórmula: v² = v0² + 2*a*Δs
     * @param v0 Velocidade inicial (m/s)
     * @param a Aceleração (m/s²)
     * @param deltaS Variação da posição (m)
     * @return Velocidade final (m/s)
     */
    double torricelli(double v0, double a, double deltaS);

}