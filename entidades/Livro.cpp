#include <iostream>
#include <string>

class Livro {

    private:
        std::string nomeLivro;
        std::string nomeAutor;

    public:

        Livro(std::string &livro, std::string &autor) {
            nomeLivro = livro;
            nomeAutor = autor;
        }

        std::string getNomeLivro() {
            return nomeLivro;
        }

        std::string getAutor() {
            return nomeAutor;
        }

        void setNomeAutor(std::string &autor) {
            nomeAutor = autor;
        }

        void setNomeLivro(std::string &livro) {
            nomeLivro = livro;
        }
};