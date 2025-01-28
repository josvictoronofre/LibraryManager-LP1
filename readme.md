# Gerenciador de Biblioteca

Projeto de um gerenciador de biblioteca para a disciplina de Linguagem de Programação I

* **Status**: Em andamento.

## Estrutura de diretórios

* **Data**: Arquivos com os dados lidos pelo programa
* **Include**: Diretório com os árquivos fonte (.h).
* **entidades:** Contém os arquivos de código-fonte em C++. Nele estão as principais funções desenvolvidas para o projeto.  
* **main:** Contém o principal arquivo do programa.

## Fluxo do programa

O programa incia-se lendo da pasta `data` os dados contendo o nome e o autor do livro e armazenando-os num vetor.
Após isso é fornecido um menu de opções ao usuário, dentre elas existem opções para:

* Cadastrar um leitor
* Cadastrar um livro
* Consultar um livro pelo nome.
* Consultar um autor.
* Consultar a situação do leitor (livros emprestados)

## Arquivo Makefile

O projeto usa um **Makefile** para facilitar a compilação e execução. Aqui estão os comandos principais disponíveis, utilize-os no diretório : **../LIBRARYMANAGER-LP1**.

* **Compilar o programa**:
  `make`
* **Compilar e executar o programa**:
  `make run`
* **Limpar o diretório**:
  `make clean`

## Dependências

* **Compilador:** GCC
* **Make**: Para facilitar a compilação e execução do projeto.
