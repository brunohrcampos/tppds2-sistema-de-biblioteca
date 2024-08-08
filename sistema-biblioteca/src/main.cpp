#include "Usuario.h"
#include "Livro.h"
#include "Emprestimo.h"
#include <iostream>
#include <limits>  // Para std::numeric_limits
#include <cctype>  // Para std::isdigit

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
    cout << "11. Relatorio de Usuarios" << endl; 
    cout << "12. Relatorio de Livros" << endl;    
    cout << "0. Sair\n" << endl;
}

bool isStringValid(const string& str) {
    for (char ch : str) {
        if (isdigit(ch) || ispunct(ch)) {
            return false;
        }
    }
    return true;
}

int readInt() {
    int value;
    while (!(cin >> value)) {
        cin.clear();  // Limpa caso o erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora a linha
        cout << "Entrada invalida. Digite um numero inteiro: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' deixado pelo cin
    return value;
}

double readDouble() {
    double value;
    while (!(cin >> value)) {
        cin.clear();  // Limpa o estado de erro
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora a linha
        cout << "Entrada invalida. Digite um numero decimal: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora o '\n' deixado pelo cin
    return value;
}

string readString() {
    string str;
    getline(cin, str);
    return str;
}

void pause() {
    cout << "Pressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    GerenciamentoUsuario gerenciaUsuario;
    GerenciamentoLivros gerenciaLivros;
    EmprestimoLivros gerenciaEmprestimos;

    int opcao;
    do {
        exibirMenu();
        cout << "Escolha uma opcao: ";
        opcao = readInt();

        switch(opcao) {
            case 1: {
                int id;
                string nome, telefone;
                cout << "ID do Usuario: ";
                id = readInt();
                cout << "Nome do Usuario: ";
                nome = readString();
                while (!isStringValid(nome)) {
                    cout << "Nome invalido. Digite novamente: ";
                    nome = readString();
                }
                cout << "Telefone do Usuario: ";
                telefone = readString();
                Usuario novoUsuario(id, nome, telefone);
                gerenciaUsuario.adicionarUsuario(novoUsuario);
                cout << "Usuario adicionado com sucesso!" << endl;
                pause();
                break;
            }
            case 2: {
                int id;
                cout << "ID do Usuario a ser removido: ";
                id = readInt();
                gerenciaUsuario.removerUsuario(id);
                cout << "Usuario removido com sucesso!" << endl;
                pause();
                break;
            }
            case 3: {
                int id;
                cout << "ID do Usuario a ser consultado: ";
                id = readInt();
                Usuario* usuario = gerenciaUsuario.consultarUsuario(id);
                if (usuario) {
                    cout << "Usuario encontrado: " << usuario->getNome() << ", Telefone: " << usuario->getTelefone() << endl;
                } else {
                    cout << "Usuario nao encontrado." << endl;
                }
                pause();
                break;
            }
            case 4: {
                int id;
                string titulo, autor, genero;
                cout << "ID do Livro: ";
                id = readInt();
                cout << "Título do Livro: ";
                titulo = readString();
                while (!isStringValid(titulo)) {
                    cout << "Título inválido. Digite novamente: ";
                    titulo = readString();
                }
                cout << "Autor do Livro: ";
                autor = readString();
                while (!isStringValid(autor)) {
                    cout << "Autor inválido. Digite novamente: ";
                    autor = readString();
                }
                cout << "Gênero do Livro: ";
                genero = readString();
                while (!isStringValid(genero)) {
                    cout << "Gênero inválido. Digite novamente: ";
                    genero = readString();
                }
                Livro novoLivro(id, titulo, autor, genero);
                gerenciaLivros.adicionarLivro(novoLivro);
                cout << "Livro adicionado com sucesso!" << endl;
                pause();
                break;
            }
            case 5: {
                int id;
                cout << "ID do Livro a ser removido: ";
                id = readInt();
                gerenciaLivros.removerLivro(id);
                cout << "Livro removido com sucesso!" << endl;
                pause();
                break;
            }
            case 6: {
                int id;
                cout << "ID do Livro a ser consultado: ";
                id = readInt();
                Livro* livro = gerenciaLivros.consultarLivro(id);
                if (livro) {
                    cout << "Livro encontrado: " << livro->getTitulo() << ", Autor: " << livro->getAutor() << ", Gênero: " << livro->getGenero() << endl;
                } else {
                    cout << "Livro nao encontrado." << endl;
                }
                pause();
                break;
            }
            case 7: {
                int idEmprestimo, idUsuario, idLivro;
                string dataEmprestimo, dataDevolucao;
                cout << "ID do Emprestimo: ";
                idEmprestimo = readInt();
                cout << "ID do Usuario: ";
                idUsuario = readInt();
                cout << "ID do Livro: ";
                idLivro = readInt();
                cin.ignore();
                cout << "Data do Emprestimo (formato dd-mm-aaaa): ";
                dataEmprestimo = readString();
                cout << "Data de Devolucao (formato dd-mm-aaaa): ";
                dataDevolucao = readString();
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
                pause();
                break;
            }
            case 8: {
                int id;
                cout << "ID do Livro para verificar disponibilidade: ";
                id = readInt();
                gerenciaLivros.verificarDisponibilidade(id);
                pause();
                break;
            }
            case 9: {
                int id;
                double multa;
                cout << "ID do Emprestimo para aplicar multa: ";
                id = readInt();
                cout << "Valor da multa: ";
                multa = readDouble();
                if (multa < 0) {
                    cout << "Valor da multa não pode ser negativo." << endl;
                    pause();
                    break;
                }
                if (gerenciaEmprestimos.aplicarMulta(id, multa)) {
                    cout << "Multa aplicada com sucesso!" << endl;
                }
                pause();
                break;
            }
            case 10: {
                int id;
                string novaData;
                cout << "ID do Emprestimo para controlar prazo: ";
                id = readInt();
                cin.ignore();
                cout << "Nova Data de Devolucao (formato dd-mm-aaaa): ";
                novaData = readString();
                gerenciaEmprestimos.controlarPrazoDevolucao(id, novaData);
                cout << "Prazo de devolucao atualizado com sucesso!" << endl;
                pause();
                break;
            }
            case 11: {
                gerenciaUsuario.exibirRelatorioUsuarios();
                pause();
                break;
            }
            case 12: {
                gerenciaLivros.exibirRelatorioLivros();
                pause();
                break;
            }
            case 0:
                cout << "Saindo do sistema..." << endl;
                break;
            default:
                cout << "Opcao invalida. Tente novamente." << endl;
                pause();
        }

    } while (opcao != 0);

    return 0;
}
