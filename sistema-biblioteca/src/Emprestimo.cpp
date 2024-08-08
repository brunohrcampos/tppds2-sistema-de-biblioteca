#include "Emprestimo.h"
#include <iostream>

// Implementação da classe Emprestimo
Emprestimo::Emprestimo(int id, const Usuario &usuario, const Livro &livro, const string &dataEmprestimo, const string &dataDevolucao)
    : id(id), usuario(usuario), livro(livro), dataEmprestimo(dataEmprestimo), dataDevolucao(dataDevolucao), multa(0) {}

// Implementações dos getters
int Emprestimo::getId() const {
    return id;
}

Usuario Emprestimo::getUsuario() const {
    return usuario;
}

Livro Emprestimo::getLivro() const {
    return livro;
}

string Emprestimo::getDataEmprestimo() const {
    return dataEmprestimo;
}

string Emprestimo::getDataDevolucao() const {
    return dataDevolucao;
}

double Emprestimo::getMulta() const {
    return multa;
}

// Implementações dos setters
void Emprestimo::setDataDevolucao(const string &dataDevolucao) {
    this->dataDevolucao = dataDevolucao;
}

void Emprestimo::setMulta(double multa) {
    this->multa = multa;
}

// Implementação da classe EmprestimoLivros
void EmprestimoLivros::registrarEmprestimo(const Emprestimo &emprestimo) {
    emprestimos.push_back(emprestimo);
}

bool EmprestimoLivros::aplicarMulta(int id, double valor) {
    for (auto &emprestimo : emprestimos) {
        if (emprestimo.getId() == id) {
            emprestimo.setMulta(valor);
            return true;
        }
    }
    return false;
}

bool EmprestimoLivros::controlarPrazoDevolucao(int id, const string &novaData) {
    for (auto &emprestimo : emprestimos) {
        if (emprestimo.getId() == id) {
            emprestimo.setDataDevolucao(novaData);
            return true;
        }
    }
    return false;
}
