# Sistema de Gerenciamento de Biblioteca em C++

## Visão Geral do Projeto

Este projeto implementa um sistema de gerenciamento de biblioteca em C++ que permite a administração completa de usuários, livros e empréstimos.

## Requisitos do Sistema

O sistema deve ser capaz de realizar as seguintes operações:

### Administrador do Sistema:

- Armazenar informações de usuários (ID, nome, telefone).
- Adicionar, remover e consultar usuários.
- Armazenar informações de livros (título, autor, gênero).
- Adicionar, remover e consultar livros.
- Registrar empréstimos de livros.
- Verificar disponibilidade de livros.
- Aplicar multas por atraso e calcular valor das multas.
- Controlar prazos de entrega dos livros emprestados.

## Funcionalidades Implementadas

O sistema inclui as seguintes funcionalidades principais:

- **Gerenciamento de usuários:** adição, remoção e consulta.
- **Gerenciamento de livros:** adição, remoção e consulta.
- **Empréstimo de livros:** registro, verificação de disponibilidade, controle de prazos e aplicação de multas.

## Instruções de Configuração do Ambiente de Desenvolvimento

Para configurar o ambiente de desenvolvimento em C++, siga os passos abaixo:

#### 1. **Clone o repositório:**

```bash
git clone https://github.com/brunohrcampos/tppds2-sistema-de-biblioteca.git
```

#### 2. **Abra o git na pasta "sistema-biblioteca" do projeto:**

#### 3. **Compile o projeto manualmente:**

```bash
g++ -Iinclude -o NomeExecutavel src/main.cpp src/Usuario.cpp src/Livro.cpp src/Emprestimo.cpp

./NomeExecutavel
```

## Estrutura do Projeto

![image](https://github.com/user-attachments/assets/1ff85a2d-de2e-4dd3-8ea3-cf24592ca52f)
