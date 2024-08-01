#include "Livro.h"
#include "Usuario.h"
#include <vector>
#include <string>

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
    Emprestimo(int id, const Usuario &usuario, const Livro &livro, const string &dataEmprestimo, const string &dataDevolucao){
        this->id = id;
        this->usuario = usuario;
        this->livro = livro;
        this->dataEmprestimo = dataEmprestimo;
        this->dataDevolucao = dataDevolucao;
        this->multa = 0;
    }

    int getId() const{
        return id;
    }

    Usuario getUsuario() const{
        return usuario;
    }

    Livro getLivro() const{
        return livro;
    }

    string getDataEmprestimo() const{
        return dataEmprestimo;
    }

    string getDataDevolucao() const{
        return dataDevolucao;
    }

    double getMulta() const{
        return multa;
    }
