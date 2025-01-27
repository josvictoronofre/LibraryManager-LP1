#include <iostream>
#include "Livro.cpp"
#include "Alerta.cpp"

class Emprestimo {
    private:
        Livro livros[3];
        Alerta alertas[3];

        void verificar_alertas_automatico() {
            for (int i = 0; i < 3; i++) {
                alertas[i].verificar_e_disparar();
            }
        }

    public:
        Emprestimo() {
            for (int i = 0; i < 3; i++) {
                livros[i] = Livro("", "");
            }
        }

        //Funcao de adicionar livros ao vetor
        void adicionarLivros(int posicao, const std::string &nomeLivro, const std::string &nomeAutor) {
            if (posicao >= 0 && posicao < 3) {
                livros[posicao] = Livro(nomeLivro, nomeAutor);
                std::cout << "Livro \"" << nomeLivro << "\" emprestado. Prazo de devolução: " << alertas[posicao].get_alerta_time() << std::endl;
                verificar_alertas_automatico();
            }
            else {
                std::cout << "Posicao invalida" << std::endl;
            }
        }

        //Funcao de exibir os livros alugados
        void exibirLivros() {
            verificar_alertas_automatico();
            for (int i = 0; i < 3; i++) {
                std::cout << "Livro " << i + 1 << ": " << livros[i].getTitulo() << " por " << livros[i].getAutor();
                if (alertas[i].is_disparado()) {
                    std::cout << " [ALERTA: prazo vencido]";
                }
                std::cout << std::endl;
            }
        }
};
