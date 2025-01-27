#include <iostream>
#include "entidades/Leitor.cpp"
#include "entidades/Emprestimo.cpp"
#include "entidades/Livro.cpp"

int main() {

    Leitor *leitores = new Leitor[3];
    while (true) {
        std::cout << "Bem-vindo a biblioteca! O que deseja fazer?" << std::endl;
        std::cout << "1 - Cadastrar leitor" << std::endl;
        std::cout << "2 - Cadastrar livro" << std::endl;
        std::cout << "3 - Emprestar livro" << std::endl;
        std::cout << "4 - Devolver livro" << std::endl;
        std::cout << "5 - Sair" << std::endl;

        int opcao;
        std::cin >> opcao;
        if (opcao == 1) {
            std::string nome;
            int idade;
            std::cout << "Digite o nome do leitor: ";
            std::cin >> nome;
            std::cout << "Digite a idade do leitor: ";
            Emprestimo emprestimo;
            Leitor leitor(nome, emprestimo);
            std::cout << "Leitor cadastrado com sucesso!" << std::endl;
        }
        else if (opcao == 2) {
            std::string nomeLivro;
            std::string nomeAutor;
            std::cout << "Digite o nome do livro: ";
            std::cin >> nomeLivro;
            std::cout << "Digite o nome do autor: ";
            std::cin >> nomeAutor;
            Livro livro(nomeLivro, nomeAutor);
            std::cout << "Livro cadastrado com sucesso!" << std::endl;
        }
        else if (opcao == 3) {
            std:: cout << "Digite o nome do Leitor: ";
            std::string nomeLeitor;
            Leitor leitor;
            for (int i = 0; i < 3; i++) {
                if (leitores[i].procurarLeitor(nomeLeitor)) {
                    leitor = leitores[i];
                    break;
                }
            }

            int cont;
            std::cout << "Digite quantos livros deseja pegar(maximo de 3 livros): ";
            std::cin >> cont;
            for (int i = 1; i <= cont; i++) {
                std::string nomeLivro;
                std::cout << "Digite o nome do " << cont << "o livro: ";
                std::cin >> nomeLivro;
                std::cout << "Digite o nome do autor: ";
                std::string nomeAutor;
                std::cin >> nomeAutor;
                
            }
        }
        else if (opcao == 4) {
            std::cout << "Digite o nome do livro que deseja devolver:";
            std::string nomeLivro;
            std::cin >> nomeLivro;

        }
        else if (opcao == 5) {
            break;
        }
        else {
            std::cout << "Opcao invalida" << std::endl;
        }
    
    delete[] leitores;
    return 0;
}