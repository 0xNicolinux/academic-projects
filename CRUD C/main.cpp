#include <iostream>
#include "student.h"

using namespace std;

void showMenu()
{
    int option = 0;

    while (option != 5)
    {
        cout << "\n==============================\n";
        cout << " Sistema de cadastro - C++\n";
        cout << "==============================\n";
        
        cout << "\n[1] Cadastrar\n[2] Buscar\n[3] Atualizar\n[4] Deletar\n[5] Sair\n\n";
        cout << "Opção: ";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            addStudent();
            break;
        case 2:
            searchStudent();
            break;
        case 3:
            updateStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            cout << "Saindo do sistema...\n";
            break;

        default:
            cout << "Opção inválida!";
            break;
        }
    }
}

int main()
{
    showMenu();
}
