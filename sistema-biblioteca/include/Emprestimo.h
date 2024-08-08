#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include "Usuario.h"
#include "Livro.h"
#include <string>
#include <vector>

using namespace std;

class Emprestimo {
private:
    int id;
    Usuario usuario;
    Livro livro;
    string dataEmprestimo;
    string dataDevolucao;
    double multa;

public:
    Emprestimo(int id, const Usuario &usuario, const Livro &livro, const string &dataEmprestimo, const string &dataDevolucao);

    int getId() const;
    Usuario getUsuario() const;
    Livro getLivro() const;
    string getDataEmprestimo() const;
    string getDataDevolucao() const;
    double getMulta() const;

    void setDataDevolucao(const string &dataDevolucao);
    void setMulta(double multa);
};

class EmprestimoLivros {
private:
    vector<Emprestimo> emprestimos;

public:
    void registrarEmprestimo(const Emprestimo &emprestimo);
    bool aplicarMulta(int id, double valor);
    bool controlarPrazoDevolucao(int id, const string &novaData);
};

#endif // EMPRESTIMO_H
