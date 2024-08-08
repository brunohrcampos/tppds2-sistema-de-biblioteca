#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(int id, const std::string &nome, const std::string &telefone)
    : id(id), nome(nome), telefone(telefone) {}

// Getters
int Usuario::getId() const {
    return id;
}
string Usuario::getNome() const {
    return nome;
}
string Usuario::getTelefone() const {
    return telefone;
}

// Setters
void Usuario::setNome(const string &nome) {
    this->nome = nome;
}
void Usuario::setTelefone(const string &telefone) {
    this->telefone = telefone;
}

void GerenciamentoUsuario::adicionarUsuario(const Usuario &usuario) {
    usuarios.push_back(usuario);
}

void GerenciamentoUsuario::removerUsuario(int id) {
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
        if (it->getId() == id) {
            usuarios.erase(it);
            break;
        }
    }
}

Usuario* GerenciamentoUsuario::consultarUsuario(int id) {
    for (auto &usuario : usuarios) {
        if (usuario.getId() == id) {
            return &usuario;
        }
    }
    return nullptr;
}

void GerenciamentoUsuario::exibirRelatorioUsuarios() const {
    if (usuarios.empty()) {
        cout << "Sem usuarios cadastrados." << endl;
        return;
    }
    cout << "Relatorio de Usuarios:" << endl;
    for (const auto& usuario : usuarios) {
        cout << "ID: " << usuario.getId() << ", Nome: " << usuario.getNome() << ", Telefone: " << usuario.getTelefone() << endl;
    }
}
