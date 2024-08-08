#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.cpp"
#include "Usuario.h"

using namespace std;

// Testando a classe Usuario
TEST_CASE("Teste da classe Usuario") {
    Usuario usuario(1, "Bruno", "123456789");

    SECTION("Teste de getters") {
        REQUIRE(usuario.getId() == 1);
        REQUIRE(usuario.getNome() == "Bruno");
        REQUIRE(usuario.getTelefone() == "123456789");
    }

    SECTION("Teste de setters") {
        usuario.setNome("Carlos");
        usuario.setTelefone("987654321");

        REQUIRE(usuario.getNome() == "Carlos");
        REQUIRE(usuario.getTelefone() == "987654321");
    }
}

// Testando a classe GerenciamentoUsuario
TEST_CASE("Teste da classe GerenciamentoUsuario") {
    GerenciamentoUsuario gerenciador;

    Usuario usuario1(1, "Bruno", "123456789");
    Usuario usuario2(2, "Carlos", "987654321");
    Usuario usuario3(3, "Hugo", "555555555");
    Usuario usuario4(4, "Julio", "666666666");

    SECTION("Adicionar e consultar usuário") {
        gerenciador.adicionarUsuario(usuario1);
        gerenciador.adicionarUsuario(usuario2);
        gerenciador.adicionarUsuario(usuario3);
        gerenciador.adicionarUsuario(usuario4);

        Usuario* u = gerenciador.consultarUsuario(1);
        REQUIRE(u != nullptr);
        REQUIRE(u->getNome() == "Bruno");

        u = gerenciador.consultarUsuario(2);
        REQUIRE(u != nullptr);
        REQUIRE(u->getNome() == "Carlos");

        u = gerenciador.consultarUsuario(3);
        REQUIRE(u != nullptr);
        REQUIRE(u->getNome() == "Hugo");

        u = gerenciador.consultarUsuario(4);
        REQUIRE(u != nullptr);
        REQUIRE(u->getNome() == "Julio");

        u = gerenciador.consultarUsuario(5);
        REQUIRE(u == nullptr);
    }

    SECTION("Remover usuário") {
        gerenciador.adicionarUsuario(usuario1);
        gerenciador.adicionarUsuario(usuario2);
        gerenciador.adicionarUsuario(usuario3);
        gerenciador.adicionarUsuario(usuario4);

        gerenciador.removerUsuario(1);
        Usuario* u = gerenciador.consultarUsuario(1);
        REQUIRE(u == nullptr);

        gerenciador.removerUsuario(2);
        u = gerenciador.consultarUsuario(2);
        REQUIRE(u == nullptr);

        gerenciador.removerUsuario(3);
        u = gerenciador.consultarUsuario(3);
        REQUIRE(u == nullptr);

        gerenciador.removerUsuario(4);
        u = gerenciador.consultarUsuario(4);
        REQUIRE(u == nullptr);
    }
    
    SECTION("Exibir r
