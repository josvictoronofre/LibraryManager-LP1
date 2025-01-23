#include <iostream>
#include "Livro.cpp"

class Emprestimo {
    private:
        Livro livros[3];

    public:
        Emprestimo() {}

        void adicionarLivros(int posicao, std::string &nomeLivro, std::string &nomeAutor) {
            if (posicao >= 0 && posicao < 3) {
                livros[posicao] = new Livro(nomeLivro, nomeAutor);
            }
            else {
                std::cout << "Posicao invalida" << std::endl;
            }
        }
    
    
};