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

int main() {
    GerenciamentoUsuario gerenciaUsuario;
    GerenciamentoLivros gerenciaLivros;
    EmprestimoLivros gerenciaEmprestimos;

    int opcao;
    do {
        exibirMenu();
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        cin.ignore();  // Ignorar o '\n' deixado pelo cin

        switch(opcao) {
            case 1: {
                int id;
                string nome, telefone;
                cout << "ID do Usuario: ";
                cin >> id;
                cin.ignore();
                cout << "Nome do Usuario: ";
                getline(cin, nome);
                cout << "Telefone do Usuario: ";
                getline(cin, telefone);
                Usuario novoUsuario(id, nome, telefone);
                gerenciaUsuario.adicionarUsuario(novoUsuario);
                cout << "Usuario adicionado com sucesso!" << endl;
                break;
            }
            case 2: {
                int id;
                cout << "ID do Usuario a ser removido: ";
                cin >> id;
                gerenciaUsuario.removerUsuario(id);
                cout << "Usuario removido com sucesso!" << endl;
                break;
            }
            case 3: {
                int id;
                cout << "ID do Usuario a ser consultado: ";
                cin >> id;
                Usuario* usuario = gerenciaUsuario.consultarUsuario(id);
                if (usuario) {
                    cout << "Usuario encontrado: " << usuario->getNome() << ", Telefone: " << usuario->getTelefone() << endl;
                } else {
                    cout << "Usuario nao encontrado." << endl;
                }
                break;
            }
            case 4: {
                int id;
                string titulo, autor, genero;
                cout << "ID do Livro: ";
                cin >> id;
                cin.ignore();
                cout << "Título do Livro: ";
                getline(cin, titulo);
                cout << "Autor do Livro: ";
                getline(cin, autor);
                cout << "Gênero do Livro: ";
                getline(cin, genero);
                Livro novoLivro(id, titulo, autor, genero);
                gerenciaLivros.adicionarLivro(novoLivro);
                cout << "Livro adicionado com sucesso!" << endl;
                break;
            }
            case 5: {
                int id;
                cout << "ID do Livro a ser removido: ";
                cin >> id;
                gerenciaLivros.removerLivro(id);
                cout << "Livro removido com sucesso!" << endl;
                break;
            }
            case 6: {
                int id;
                cout << "ID do Livro a ser consultado: ";
                cin >> id;
                Livro* livro = gerenciaLivros.consultarLivro(id);
                if (livro) {
                    cout << "Livro encontrado: " << livro->getTitulo() << ", Autor: " << livro->getAutor() << "Genero: " << livro ->getGenero() << endl;
                } else {
                    cout << "Livro nao encontrado." << endl;
                }
                break;
            }
            case 7: {
                int idEmprestimo, idUsuario, idLivro;
                string dataEmprestimo, dataDevolucao;
                cout << "ID do Emprestimo: ";
                cin >> idEmprestimo;
                cout << "ID do Usuario: ";
                cin >> idUsuario;
                cout << "ID do Livro: ";
                cin >> idLivro;
                cin.ignore();
                cout << "Data do Emprestimo: "; // modelo data 20-08-2024
                getline(cin, dataEmprestimo);
                cout << "Data de Devolucao: "; // modelo data 20-08-2024
                getline(cin, dataDevolucao);
                Usuario* usuario = gerenciaUsuario.consultarUsuario(idUsuario);
                Livro* livro = gerenciaLivros.consultarLivro(idLivro);
                if (usuario && livro && livro->isDisponivel()) {
                    Emprestimo novoEmprestimo(idEmprestimo, *usuario, *livro, dataEmprestimo, dataDevolucao);
                    gerenciaEmprestimos.registrarEmprestimo(novoEmprestimo);
                    livro->setDisponivel(false);
                    cout << "Emprestimo registrado com sucesso!" << endl;
                } else {
                    cout << "Usuario ou Livro invalido, ou Livro nao disponivel." << endl;
                }
                break;
            }
            case 8: {
                int id;
                cout << "ID do Livro para verificar disponibilidade: ";
                cin >> id;
                gerenciaLivros.verificarDisponibilidade(id);
                break;
            }
            case 9: {
                int id;
                double multa;
                cout << "ID do Emprestimo para aplicar multa: ";
                cin >> id;
                cout << "Valor da multa: ";
                cin >> multa;
                if (gerenciaEmprestimos.aplicarMulta(id, multa)) {
                cout << "Multa aplicada com sucesso!" << endl;}
                break;
                }
            case 10: {
                int id;
                string novaData;
                cout << "ID do Emprestimo para controlar prazo: ";
                cin >> id;
                cin.ignore();
                cout << "Nova Data de Devolucao: ";
                getline(cin, novaData);
                gerenciaEmprestimos.controlarPrazoDevolucao(id, novaData);
                cout << "Prazo de devolucao atualizado com sucesso!" << endl;
                break;
            }
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
        }

    } while (opcao != 0);

    return 0;
}

