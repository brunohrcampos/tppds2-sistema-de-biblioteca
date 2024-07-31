#include "Usuario.h"

//Implementação classe Usuario
// Construtor
Usuario::Usuario(int id, const std::string &nome, const std::string &telefone)
    : id(id), nome(nome), telefone(telefone) {}

// Getters
int Usuario::getId() const
{
    return id;
}
string Usuario::getNome() const
{
    return nome;
}
string Usuario::getTelefone() const
{
    return telefone;
}

// Setters
void Usuario::setNome(const std::string &nome)
{
    this->nome = nome;
}
void Usuario::setTelefone(const std::string &telefone)
{
    this->telefone = telefone;
}

//Implementação da classe GerenciamentoUsuario
void GerenciamentoUsuario::adicionarUsuario(const Usuario &Usuario){
    usuarios.push_back(Usuario);
}
void GerenciamentoUsuario::removerUsuario(int id){
    for(auto it = usuarios.begin(); it!=usuarios.end(); ++it){
        if (it->getId() == id){
            usuarios.erase(it);
            break;
        }
    }
}
Usuario* GerenciamentoUsuario::consultarUsuario(int id){
    for(auto &Usuario : usuarios){
        if(Usuario.getId() == id){
            return &Usuario;
        }
    }
    return nullptr;
}