#include "Usuario.h"
#include "Livro.h"
#include "Emprestimo.h"
#include <iostream>

using namespace std;

void exibirMenu() {
    cout << "---------------------------------------" << endl;
    cout << "Sistema de Gerenciamento de Biblioteca" << endl;
    cout << "---------------------------------------" << endl;
    cout << "1. Adicionar Usuario" << endl;
    cout << "2. Remover Usuario" << endl;
    cout << "3. Consultar Usuario" << endl;
    cout << "4. Adicionar Livro" << endl;
    cout << "5. Remover Livro" << endl;
    cout << "6. Consultar Livro" << endl;
    cout << "7. Registrar Emprestimo" << endl;
    cout << "8. Verificar Disponibilidade de Livro" << endl;
    cout << "9. Aplicar Multa" << endl;
    cout << "10.Controlar Prazo de Devolucao" << endl;
    cout << "0. Sair\n" << endl;
}

