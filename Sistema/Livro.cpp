#include "livro.hpp"
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

