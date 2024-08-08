#include "Livro.h"
#include <iostream>

using namespace std;

Livro::Livro(int id, const string &titulo, const string &autor, const string &genero)
    : id(id), titulo(titulo), autor(autor), genero(genero), disponivel(true) {}

int Livro::getId() const {
    return id;
}

string Livro::getTitulo() const {
    return titulo;
}

string Livro::getAutor() const {
    return autor;
}

string Livro::getGenero() const {
    return genero;
}

bool Livro::isDisponivel() const {
    return disponivel;
}

void Livro::setDisponivel(bool disponivel) {
    this->disponivel = disponivel;
}

void GerenciamentoLivros::adicionarLivro(const Livro &livro) {
    livros.push_back(livro);
}

void GerenciamentoLivros::removerLivro(int id) {
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if (it->getId() == id) {
            livros.erase(it);
            break;
        }
    }
}

Livro* GerenciamentoLivros::consultarLivro(int id) {
    for (auto &livro : livros) {
        if (livro.getId() == id) {
            return &livro;
        }
    }
    return nullptr;
}

void GerenciamentoLivros::verificarDisponibilidade(int id) {
    Livro* livro = consultarLivro(id);
    if (livro) {
        if (livro->isDisponivel()) {
            cout << "O livro '" << livro->getTitulo() << "' esta disponivel." << endl;
        } else {
            cout << "O livro '" << livro->getTitulo() << "' nao esta disponivel." << endl;
        }
    }
}

void GerenciamentoLivros::exibirRelatorioLivros() const {
    if (livros.empty()) {
        cout << "Sem livros cadastrados." << endl;
        return;
    }
    cout << "Relatorio de Livros:" << endl;
    for (const auto& livro : livros) {
        cout << "ID: " << livro.getId() << ", Titulo: " << livro.getTitulo() << ", Autor: " << livro.getAutor() << ", Genero: " << livro.getGenero() << ", Disponivel: " << (livro.isDisponivel() ? "Sim" : "Nao") << endl;
    }
}
