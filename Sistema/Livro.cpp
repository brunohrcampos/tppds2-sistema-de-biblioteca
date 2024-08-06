#include "Livro.h"
#include <iostream>

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

void GerenciamentoLivros::adicionarLivro(const Livro &livro) {
    livros.push_back(livro);
}

void GerenciamentoLivros::removerLivro(int id) {
    for (auto it = livros.begin(); it != livros.end(); ++it) {
        if (it->getId() == id) {
            livros.erase(it);
            return;
        }
    }
    std::cout << "Livro com ID " << id << " não encontrado." << std::endl;
}

Livro* GerenciamentoLivros::consultarLivro(int id) {
    for (auto &livro : livros) {
        if (livro.getId() == id) {
            return &livro;
        }
    }
    std::cout << "Livro com ID " << id << " não encontrado." << std::endl;
    return nullptr;
}

void GerenciamentoLivros::verificarDisponibilidade(int id) {
    Livro* livro = consultarLivro(id);
    if (livro != nullptr) {
        if (livro->isDisponivel()) {
            std::cout << "O livro '" << livro->getTitulo() << "' está disponível." << std::endl;
        } else {
            std::cout << "O livro '" << livro->getTitulo() << "' não está disponível." << std::endl;
        }
    }
}