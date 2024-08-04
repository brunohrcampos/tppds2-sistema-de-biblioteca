#include "Livro.h"
#include "Usuario.h"
#include <vector>
#include <string>
#include <iostream>

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
        this->multa = 0.0;
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

    void setDataDevolucao(const string &dataDevolucao){
        this->dataDevolucao = dataDevolucao;
    }
    
    void setMulta(double multa){
        this->multa = multa;
    }
};

class EmprestimoLivros {

private:
    vector<Emprestimo> emprestimos;

public:
    void registrarEmprestimo(const Emprestimo &emprestimo){
        emprestimos.push_back(emprestimo);
    }

    void verificarDisponibilidade(const Livro &livro){
        if(livro.isDisponivel()){
            cout << "O livro está disponivel para empréstimo." << endl;
        } 
        else{
            cout << "O livro não está disponivel para empréstimo." << endl;
        }
    }

    void aplicarMulta(int id, double valor){
            for(auto &emprestimo : emprestimos){
                if(emprestimo.getId() == id){
                    emprestimo.setMulta(valor);
                }
            }
        }
    
    void controlarPrazoDevolucao(int id, const string &novaData){
        for(auto &emprestimo : emprestimos){
            if(emprestimo.getId() == id){
                emprestimo.setDataDevolucao(novaData);
            }
        }
    } 
};
