#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;

const string FILE_NAME = "dados.csv";
const string FILE_NAME_TEMP = "temp.csv";

Student inputStudent()
{
    Student student;

    cout << "Nome do aluno: ";
    getline(cin, student.name);

    cout << "Nota 1: ";
    cin >> student.grade1;

    cout << "Nota 2: ";
    cin >> student.grade2;

    cin.ignore();

    return student;
}

void addStudent()
{
    Student student;
    char confirmName;

    do
    {
        student = inputStudent();

        cout << "Você digitou: \"" << student.name << "\","
             << "Nota1: " << student.grade1 << ","
             << "Nota2: " << student.grade2 << endl;

        cout << "Está correto? (s/n): ";
        cin >> confirmName;

        confirmName = tolower(confirmName);
        cin.ignore();

    } while (confirmName == 'n');

    ofstream file(FILE_NAME, ios::app);

    if (!file.is_open())
        cout << "Erro ao abrir o arquivo!\n";
    else
        file << student.name << ","
             << student.grade1 << ","
             << student.grade2 << endl;
}

void searchStudent()
{
    string studentName;
    string line;
    char searchAll;
    bool found = false;

    ifstream file(FILE_NAME);

    if (!file.is_open())
    {
        cout << "Erro ao abrir arquivo!\n";
        return;
    }

    cout << "\nVocê deseja buscar por todos os alunos? (s/n): ";
    cin >> searchAll;
    searchAll = tolower(searchAll);
    cin.ignore();

    if (searchAll == 's')
    {
        cout << "\nAlunos cadastrados: " << endl;

        while (getline(file, line))
        {
            cout << line << endl;
        }

        return;
    }

    cout << "Nome do aluno: ";
    getline(cin, studentName);

    while (getline(file, line))
    {

        if (line.find(studentName) != string::npos)
        {
            found = true;
            cout << "Aluno encontrado:\n"
                 << line << endl;
        }
    }

    if (!found)
        cout << "Não encontrado!\n";
}

void updateStudent()
{
    string studentName;
    bool found = false;

    cout << "Nome do aluno: ";
    getline(cin, studentName);

    ifstream file(FILE_NAME);
    ofstream temp(FILE_NAME_TEMP);

    if (!file.is_open() || !temp.is_open())
    {
        cout << "Erro ao abrir arquivo!\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.find(studentName) != string::npos)
        {
            found = true;
            cout << "Aluno encontrado: " << line << endl;

            Student student;

            student = inputStudent();

            temp << student.name << "," << student.grade1 << "," << student.grade2 << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove(FILE_NAME.c_str());
    rename(FILE_NAME_TEMP.c_str(), FILE_NAME.c_str());

    if (!found)
        cout << "Aluno não encontrado!\n";
}

void deleteStudent()
{
    string studentName;
    bool found = false;

    cout << "Nome do aluno: ";
    getline(cin, studentName);

    ifstream file(FILE_NAME);
    ofstream temp(FILE_NAME_TEMP);

    if (!file.is_open() || !temp.is_open())
    {
        cout << "Erro ao abrir arquivo!\n";
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.find(studentName) != string::npos)
        {
            found = true;
            cout << "Aluno removido: " << line << endl;
        }
        else
        {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove(FILE_NAME.c_str());
    rename(FILE_NAME_TEMP.c_str(), FILE_NAME.c_str());

    if (!found)
        cout << "Aluno não encontrado!\n";
}