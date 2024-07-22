#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
using namespace std;

class Usuario {
private:
    int id;
    string nome;
    string telefone;

public:
    Usuario(int id, const string &nome, const string &telefone);

    int getId() const;
    string getNome() const;
    string getTelefone() const;

    void setNome(const string &nome);
    void setTelefone(const string &telefone);
};

class GerenciamentoUsuario {
private:
    vector<Usuario> usuarios;

public:
    void adicionarUsuario(const Usuario &usuario);
    void removerUsuario(int id);
    Usuario* consultarUsuario(int id);
};

#endif 

