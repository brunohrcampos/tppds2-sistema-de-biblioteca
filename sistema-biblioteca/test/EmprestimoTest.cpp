#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.cpp"
#include "Emprestimo.h"
#include "Usuario.h"
#include "Livro.h"
#include <sstream>

using namespace std;

// Testando a classe Emprestimo
TEST_CASE("Teste da classe Emprestimo") {
    Usuario usuario(1, "Bruno", "123456789");
    Livro livro(1, "Primeiros Passos em C++", "Lippman", "Informática");

    Emprestimo emprestimo(1, usuario, livro, "2024-08-01", "2024-08-15");

    SECTION("Teste de getters") {
        REQUIRE(emprestimo.getId() == 1);
        REQUIRE(emprestimo.getUsuario().getNome() == "Bruno");
        REQUIRE(emprestimo.getLivro().getTitulo() == "Primeiros Passos em C++");
        REQUIRE(emprestimo.getDataEmprestimo() == "2024-08-01");
        REQUIRE(emprestimo.getDataDevolucao() == "2024-08-15");
        REQUIRE(emprestimo.getMulta() == 0);
    }

    SECTION("Teste de setters") {
        emprestimo.setDataDevolucao("2024-08-20");
        emprestimo.setMulta(50.0);

        REQUIRE(emprestimo.getDataDevolucao() == "2024-08-20");
        REQUIRE(emprestimo.getMulta() == 50.0);
    }
}

// Testando a classe EmprestimoLivros
TEST_CASE("Teste da classe EmprestimoLivros") {
    Usuario usuario1(1, "Bruno", "123456789");
    Usuario usuario2(2, "Hugo", "987654321");
    Usuario usuario3(3, "Julio", "555555555");
    Usuario usuario4(4, "Carlos", "666666666");

    Livro livro1(1, "Primeiros Passos em C++", "Lippman", "Informática");
    Livro livro2(2, "Código Limpo", "Martin", "Informática");

    EmprestimoLivros gerenciador;

    Emprestimo emprestimo1(1, usuario1, livro1, "2024-08-01", "2024-08-15");
    Emprestimo emprestimo2(2, usuario2, livro2, "2024-08-05", "2024-08-20");

    SECTION("Registrar e consultar empréstimos") {
        gerenciador.registrarEmprestimo(emprestimo1);
        gerenciador.registrarEmprestimo(emprestimo2);

        stringstream buffer;
        streambuf* prevcoutbuf = cout.rdbuf(buffer.rdbuf());

        gerenciador.exibirRelatorioEmprestimos();

        cout.rdbuf(prevcoutbuf);
        string resultado = buffer.str();

        REQUIRE(resultado.find("ID do Emprestimo: 1") != string::npos);
        REQUIRE(resultado.find("Usuario: Bruno") != string::npos);
        REQUIRE(resultado.find("Livro: Primeiros Passos em C++") != string::npos);
        REQUIRE(resultado.find("Data do Emprestimo: 2024-08-01") != string::npos);
        REQUIRE(resultado.find("Data de Devolucao: 2024-08-15") != string::npos);
        REQUIRE(resultado.find("Multa: 0") != string::npos);

        REQUIRE(resultado.find("ID do Emprestimo: 2") != string::npos);
        REQUIRE(resultado.find("Usuario: Hugo") != string::npos);
        REQUIRE(resultado.find("Livro: Código Limpo") != string::npos);
        REQUIRE(resultado.find("Data do Emprestimo: 2024-08-05") != string::npos);
        REQUIRE(resultado.find("Data de Devolucao: 2024-08-20") != string::npos);
        REQUIRE(resultado.find("Multa: 0") != string::npos);
    }

    SECTION("Aplicar multa") {
        gerenciador.registrarEmprestimo(emprestimo1);

        REQUIRE(gerenciador.aplicarMulta(1, 25.0) == true);
        REQUIRE(emprestimo1.getMulta() == 25.0);

        REQUIRE(gerenciador.aplicarMulta(2, 30.0) == false); 
    }

    SECTION("Controlar prazo de devolução") {
        gerenciador.registrarEmprestimo(emprestimo2);

        REQUIRE(gerenciador.controlarPrazoDevolucao(2, "2024-08-25") == true);
        REQUIRE(emprestimo2.getDataDevolucao() == "2024-08-25");

        REQUIRE(gerenciador.controlarPrazoDevolucao(3, "2024-08-30") == false);
    }
}
