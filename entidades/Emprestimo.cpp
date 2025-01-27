#include <iostream>
#include "Livro.cpp"
#include "Alerta.cpp"

class Emprestimo {
    private:
        Livro livros[3];
        Alerta alertas[3];

    public:
        Emprestimo() {
            for (int i = 0; i < 3; i++) {
                livros[i] = Livro("", "");
                alertas[i] = Alerta();
            }
        }

        //Funcao de adicionar livros ao vetor
        void adicionarLivros(int posicao, const std::string &nomeLivro, const std::string &nomeAutor) {
            if (posicao >= 0 && posicao < 3) {
                livros[posicao] = Livro(nomeLivro, nomeAutor);
                std::cout << "Livro \"" << nomeLivro << "\" emprestado. Prazo de devolução: " << alertas[posicao].get_alerta_time() << std::endl;
                alertas[posicao].iniciar();
            }
            else {
                std::cout << "Posicao invalida" << std::endl;
            }
        }
};;
