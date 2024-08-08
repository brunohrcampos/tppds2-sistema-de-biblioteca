#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <vector>
using namespace std;

class Livro {
private:
    int id;
    string titulo;
    string autor;
    string genero;
    bool disponivel;

public:
    Livro(int id, const string &titulo, const string &autor, const string &genero);

    int getId() const;
    string getTitulo() const;
    string getAutor() const;
    string getGenero() const;
    bool isDisponivel() const;

    void setDisponivel(bool disponivel);
};

class GerenciamentoLivros {
private:
    vector<Livro> livros;

public:
    void adicionarLivro(const Livro &livro);
    void removerLivro(int id);
    Livro* consultarLivro(int id);
    void verificarDisponibilidade(int id);
    void exibirRelatorioLivros() const; // Novo método
};

#endif // LIVRO_H
