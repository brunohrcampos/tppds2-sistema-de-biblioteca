# Sistema de Gerenciamento de Biblioteca em C++

## Visão Geral do Projeto
Este projeto implementa um sistema de gerenciamento de biblioteca em C++ que permite a administração completa de usuários, livros e empréstimos. 

## Requisitos do Sistema
O sistema deve ser capaz de realizar as seguintes operações:

### Para o Administrador:
- Armazenar informações de usuários (ID, nome, telefone).
- Adicionar, remover e consultar usuários.
- Armazenar informações de livros (título, autor, gênero).
- Adicionar, remover e consultar livros.
- Registrar empréstimos de livros.
- Verificar disponibilidade de livros.
- Aplicar multas por atraso e calcular valor das multas.
- Controlar prazos de entrega dos livros emprestados.

### Para o Usuário Padrão:
- Visualizar seus dados cadastrados no sistema.
- Pesquisar livros disponíveis para empréstimo.
- Verificar os livros emprestados a ele e os prazos para devolução.

## Funcionalidades Implementadas
O sistema inclui as seguintes funcionalidades principais:

- **Gerenciamento de usuários:** adição, remoção e consulta.
- **Gerenciamento de livros:** adição, remoção e consulta.
- **Empréstimo de livros:** registro, verificação de disponibilidade, controle de prazos e aplicação de multas.

## Instruções de Configuração do Ambiente de Desenvolvimento
Para configurar o ambiente de desenvolvimento em C++, siga os passos abaixo:

#### 1. **Clone o repositório:**
- git clone https://github.com/brunohrcampos/tppds2-sistema-de-biblioteca.git.
- cd tppds2-sistema-de-biblioteca.

#### 2. **Compile o programa:**
- g++ -o main main.cpp

#### 3. **Execute o programa:**
- ./main


## Guia de Contribuição
Se deseja colaborar conosco, siga estes passos:

#### 1. **Fork do repositório e clone o seu fork.**
- cd tppds2-sistema-de-biblioteca

#### 2. **Crie uma branch para sua feature ou correção:**
- git checkout -b minha-branch


#### 3. **Desenvolva sua funcionalidade ou correção, seguindo as diretrizes de estilo do projeto.**

#### 4. **Compile e execute o programa localmente para testar suas alterações.**

#### 5. **Commit suas mudanças:**

- git commit -am 'Adiciona nova funcionalidade'

#### 6. **Push para a branch que você criou no seu fork:**
- git push origin minha-feature




