# 🧮 Calculadora em Java (Console)

Projeto de uma calculadora simples desenvolvida em Java, executada via terminal.  
O sistema permite realizar operações matemáticas básicas com validação de entrada e tratamento de erros.

---

## 📌 Funcionalidades

- Soma de dois números
- Subtração de dois números
- Multiplicação de dois números
- Divisão de dois números (com verificação de divisão por zero)
- Validação de entrada para números inteiros e decimais
- Loop para múltiplas operações sem reiniciar o programa

---

## 🛠️ Tecnologias utilizadas

- Java
- Classe `Scanner` (entrada de dados)
- Tratamento de exceções (`InputMismatchException`)
- Programação orientada a objetos (POO)

---

## ▶️ Como executar o projeto

### 1. Compile o código

No terminal, execute:

```bash
javac Main.java
````

### 2. Execute o programa

```bash
java Main
```

---

## 🧠 Como funciona

O programa exibe um menu com as opções:

```text
1 - Soma  
2 - Subtração  
3 - Multiplicação  
4 - Divisão  
5 - Sair
```

O usuário escolhe uma operação, informa dois números e recebe o resultado no console.

Após cada operação, o sistema pergunta se deseja continuar (`S/N`).

---

## ⚙️ Estrutura do projeto

O código é dividido em duas partes principais:

### 📦 Classe `calculator`

Responsável pelas operações matemáticas:

* `addition(x, y)` → Soma
* `subtraction(x, y)` → Subtração
* `multiplication(x, y)` → Multiplicação
* `division(x, y)` → Divisão

---

### 🧾 Classe `Main`

Responsável pelo controle do programa:

* `readDouble()` → valida entrada de números decimais
* `readInt()` → valida entrada de opções do menu
* `main()` → fluxo principal da aplicação

---

## 🚨 Regras do sistema

* Apenas números válidos são aceitos
* Menu aceita apenas opções de 1 a 5
* Divisão por zero é bloqueada
* Entrada inválida gera mensagem de erro e nova tentativa
* O programa pode ser encerrado pelo usuário (opção 5 ou S/N)

---

## 📷 Exemplo de uso

```text
1 - Soma
2 - Subtração
3 - Multiplicação
4 - Divisão
5 - Sair

Escolha um número referente a operação matemática desejada:
1
Digite o valor de x:
10
Digite o valor de y:
5

O resultado da soma é: 15.0

Deseja fazer outra operação? (S/N)
N
```

---

## 👨‍💻 Autor

Desenvolvido por Nícolas como prática de lógica de programação e Java básico.

---

## 📄 Licença

Projeto livre para fins educacionais.
