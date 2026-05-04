# Physics Lib ⚙️📘

Biblioteca em C/C++ com funções básicas de física voltada para estudantes e iniciantes em programação.

O projeto implementa conceitos fundamentais da Física como velocidade, aceleração, força, peso e atrito de forma simples e modular, com foco em aprendizado, clareza e boas práticas de código.

---

## 📚 Conteúdo

A biblioteca atualmente possui dois módulos principais:

### 🔹 Kinematics (Cinemática)
- Velocidade média
- Aceleração média
- Movimento uniforme (MU)
- Movimento uniformemente variado (MUV)
- Equação de Torricelli

### 🔹 Dynamics (Dinâmica)
- Força resultante (F = m · a)
- Aceleração (a = F / m)
- Peso (P = m · g)
- Força de atrito (Fa = μ · N)

---

## 🧠 Exemplo de uso

```cpp
#include <iostream>
#include "dynamics.h"

int main()
{
    double mass = 10.0;
    double acceleration = 5.0;

    double force = physics::dynamics::force(mass, acceleration);

    std::cout << "Forca: " << force << " N" << std::endl;

    return 0;
}
