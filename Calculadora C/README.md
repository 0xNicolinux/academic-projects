# 🧮 Calculadora em C

Projeto simples de uma calculadora de terminal desenvolvida em linguagem C.  
O programa permite realizar operações básicas como soma, subtração, multiplicação e divisão, com validação de entrada do usuário.

---

## 📌 Funcionalidades

- Soma de dois números
- Subtração de dois números
- Multiplicação de dois números
- Divisão de dois números (com proteção contra divisão por zero)
- Validação de entrada para evitar valores inválidos
- Menu interativo no terminal

---

## 🛠️ Tecnologias utilizadas

- Linguagem C
- Biblioteca padrão (`stdio.h`)
- Suporte a caracteres wide (`wchar.h`)
- Locale para suporte a caracteres especiais (`locale.h`)

---

## ▶️ Como executar o projeto

### 1. Compile o código

Use um compilador C como `gcc`:

```bash
gcc calculadora.c -o calculadora
````

### 2. Execute o programa

```bash
./calculadora
```

No Windows:

```bash
calculadora.exe
```

---

## 🧠 Como funciona

O programa exibe um menu com opções:

```
[1] Soma  
[2] Subtração  
[3] Multiplicação  
[4] Divisão  
[0] Sair
```

O usuário escolhe a operação, insere dois números e recebe o resultado formatado com duas casas decimais.

---

## ⚙️ Estrutura do código

O projeto é dividido em funções para melhor organização:

* `exibir_mensagem()` → exibe o título da calculadora
* `exibir_operador()` → mostra o menu de operações
* `validar_entrada()` → garante que o usuário digite números válidos
* `soma()`, `subtracao()`, `multiplicacao()`, `divisao()` → operações matemáticas
* `main()` → controle principal do programa

---

## 🚨 Regras importantes

* A divisão por zero não é permitida
* Entradas inválidas são tratadas automaticamente
* O programa roda em loop até o usuário escolher sair

---

## 📷 Exemplo de uso

```
+-----------------------+
|      Calculadora      |
+-----------------------+

[1] - Soma
[2] - Subtração
[3] - Multiplicação
[4] - Divisão
[0] - Sair do programa...

Digite o valor da operação desejada: 1
Digite o valor de x: 10
Digite o valor de y: 5
Resultado: 15.00
```

---

## 👨‍💻 Autor

Desenvolvido por Nícolas como projeto de prática em linguagem C.

---

## 📄 Licença

Este projeto é livre para fins educacionais.
