#pragma once

namespace physics::dynamics
{
    // ===============================
    // Leis de Newton (Dynamics)
    // ===============================

    /**
     * Calcula a força resultante aplicada a um corpo.
     * Fórmula: F = m * a
     * @param mass Massa do objeto (kg)
     * @param acceleration Aceleração (m/s²)
     * @return Força (N). Retorna 0 se mass <= 0.
     */
    double force(double mass, double acceleration);

    /**
     * Calcula a aceleração a partir da força.
     * Fórmula: a = F / m
     * @param force Força aplicada (N)
     * @param mass Massa do objeto (kg)
     * @return Aceleração (m/s²). Retorna 0 se mass <= 0.
     */
    double accelerationFromForce(double force, double mass);

    /**
     * Calcula a força peso de um corpo.
     * Fórmula: P = m * g
     * @param mass Massa do objeto (kg)
     * @param gravity Aceleração da gravidade (m/s²)
     * @return Força peso (N). Retorna 0 se mass <= 0.
     */
    double weight(double mass, double gravityAcceleration = 9.8);

    /**
     * Calcula a força de atrito entre duas superfícies.
     * Fórmula: F_atrito = μ * N
     * @param normalForce Força normal exercida pela superfície (N)
     * @param frictionCoefficient Coeficiente de atrito (μ), sem unidade
     * @return Força de atrito (N). Retorna 0 se normalForce <= 0 ou frictionCoefficient <= 0.
     */
    double friction(double normalForce, double frictionCoefficient);
}