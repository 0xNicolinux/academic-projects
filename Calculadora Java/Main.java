import java.util.Scanner;
import java.util.InputMismatchException;

class calculator {

    public double addition(double x, double y) {
        return x + y;
    }

    public double subtraction(double x, double y) {
        return x - y;
    }

    public double multiplication(double x, double y) {
        return x * y;
    }

    public double division(double x, double y) { return x / y; }
}

public class Main {

    public static double readDouble(Scanner sc) {
        boolean numberIsValid = false;
        double number = 0;

        while (!numberIsValid) {
            try {
                number = sc.nextDouble();
                numberIsValid = true;
            } catch (InputMismatchException e) {
                System.out.println("Erro: Digite somente números decimais com pontos. (ex: 1.10): ");
                sc.next();
            }
        }
        return number;
    }

    public static int readInt(Scanner sc) {
        boolean numberIsValid = false;
        int number = 0;

        while (!numberIsValid) {
            try {
                number = sc.nextInt();
                if (number >= 1 && number <=5) {
                    break;
                } else {
                    System.out.println("Erro: Digite somente números entre 1 e 5: ");
                }
            } catch (InputMismatchException e) {
                System.out.println("Erro: Digite somente números inteiros: ");
                sc.next();
            }
        }
        return number;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        calculator calc = new calculator();

        int choice = 0;
        double num1 = 0;
        double num2 = 0;
        char keepRunning;

        do {
            System.out.println("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Sair");
            System.out.println("Escolha um número referente a operação matemática desejada: ");
            choice = readInt(sc);

            if (choice == 5){
                System.exit(0);
            }

            System.out.println("Digite o valor de x: ");
            num1 = readDouble(sc);
            System.out.println("Digite o valor de y: ");
            num2 = readDouble(sc);

            switch (choice) {
                case 1 -> System.out.println("O resultado da soma é: " + calc.addition(num1, num2));
                case 2 -> System.out.println("O resultado da subtração é: " + calc.subtraction(num1, num2));
                case 3 -> System.out.println("O resultado da multiplicação é: " + calc.multiplication(num1, num2));
                case 4 -> {
                    if (num2 == 0){
                        System.out.println("Não dá para dividir por zero!");
                    } else {
                        System.out.println("O resultado da divisão é: " + calc.division(num1, num2));
                    }
                }
                default -> System.out.println("Opção inválida! Escolha entre 1 e 4.");
            }
            System.out.println("\nDeseja fazer outra operação? (S/N) ");
            keepRunning = sc.next().charAt(0);
        } while (keepRunning == 's' || keepRunning == 'S');
        sc.close();
    }
}
