#include <iostream>
#include "Livro.cpp"

class Emprestimo {
    private:
        Livro livros[3];
        std::string data_hora;

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
            }
            else {
                std::cout << "Posicao invalida" << std::endl;
            }
        }
    
    
};
