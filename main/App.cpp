#include <iostream>
#include <vector>
#include <optional>
#include <algorithm>
#include "../include/Leitor.hpp"
#include "../include/Emprestimo.hpp"
#include "../include/Livro.hpp"
#include "../include/Entrada.hpp"

// Função para buscar livros
void buscarLivros(const std::vector<Livro> &biblioteca, const std::string &termo, bool buscarPorAutor) {
    bool encontrou = false;

    for (const Livro &livro : biblioteca) {
        std::optional<Livro> resultado;

        if (buscarPorAutor) {
            resultado = livro.procurarNomeAutor(termo);
        } else {
            resultado = livro.procurarNomeLivro(termo);
        }

        if (resultado.has_value()) {
            encontrou = true;
            std::cout << "Livro encontrado: " << resultado->getNomeLivro() << " - " << resultado->getAutor() 
                      << (livro.getEmprestado() ? " (Emprestado)" : " (Disponível)") << std::endl;
        }
    }

    if (!encontrou) {
        std::cout << "Nenhum livro encontrado com o termo \"" << termo << "\"." << std::endl;
    }
}

int main() {
    std::vector<Leitor> leitores;
    std::vector<Livro> biblioteca = ler_csv("data/livros.csv");

    while (true) {
        std::cout << "\nBem-vindo à biblioteca! O que deseja fazer?" << std::endl;
        std::cout << "1 - Cadastrar leitor" << std::endl;
        std::cout << "2 - Cadastrar livro" << std::endl;
        std::cout << "3 - Emprestar livro" << std::endl;
        std::cout << "4 - Devolver livro" << std::endl;
        std::cout << "5 - Lista de leitores" << std::endl;
        std::cout << "6 - Lista de livros" << std::endl;
        std::cout << "7 - Buscar livro por título ou autor" << std::endl;
        std::cout << "0 - Sair" << std::endl;

        int opcao;
        std::cin >> opcao;

        if (opcao == 1) {
            std::string nome;
            std::cout << "Digite o nome do leitor: ";
            std::cin.ignore();
            std::getline(std::cin, nome);
            leitores.emplace_back(nome, Emprestimo());
            std::cout << "Leitor cadastrado com sucesso!" << std::endl;
        } 
        else if (opcao == 2) {
            std::string nomeLivro, nomeAutor;
            std::cout << "Digite o nome do livro: ";
            std::cin.ignore();
            std::getline(std::cin, nomeLivro);
            std::cout << "Digite o nome do autor: ";
            std::getline(std::cin, nomeAutor);
            biblioteca.emplace_back(nomeLivro, nomeAutor);
            std::cout << "Livro cadastrado com sucesso!" << std::endl;
        } 
        else if (opcao == 3) {
            // Lógica para emprestar livro
        } 
        else if (opcao == 4) {
            // Lógica para devolver livro
        } 
        else if (opcao == 5) {
            for (const Leitor &leitor : leitores) {
                const std::string &nomeLivro = leitor.getEmprestimo().getLivro().getNomeLivro();
                if (!nomeLivro.empty()) {
                    std::cout << leitor.getNome() << " - " << nomeLivro << " ("
                              << leitor.getEmprestimo().getLivro().getAutor() << ")" << std::endl;
                } else {
                    std::cout << leitor.getNome() << " - Nenhum livro emprestado" << std::endl;
                }
            }
        } 
        else if (opcao == 6) {
            for (const Livro &livro : biblioteca) {
                std::cout << livro.getNomeLivro() << " - " << livro.getAutor()
                          << (livro.getEmprestado() ? " (Emprestado)" : " (Disponível)") << std::endl;
            }
        } 
        else if (opcao == 7) {
            std::cout << "Escolha o tipo de busca:\n1 - Buscar por título\n2 - Buscar por autor" << std::endl;
            int tipoBusca;
            std::cin >> tipoBusca;
            std::cin.ignore();
            std::string termo;
            std::cout << "Digite o termo de busca: ";
            std::getline(std::cin, termo);

            if (tipoBusca == 1) {
                buscarLivros(biblioteca, termo, false); // Busca por título
            } else if (tipoBusca == 2) {
                buscarLivros(biblioteca, termo, true); // Busca por autor
            } else {
                std::cout << "Opção inválida!" << std::endl;
            }
        } 
        else if (opcao == 0) {
            std::cout << "Encerrando o sistema. Até logo!" << std::endl;
            break;
        } 
        else {
            std::cout << "Opção inválida! Tente novamente." << std::endl;
        }
    }

    return 0;
}
