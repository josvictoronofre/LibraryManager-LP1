#include <iostream>
#include <string>
#include <algorithm>

class Livro {

    private:
        std::string nomeLivro;
        std::string nomeAutor;

    public:
        Livro() {
            nomeLivro = "";
            nomeAutor = "";
        }

        Livro(const std::string &livro, const std::string &autor) {
            nomeLivro = livro;
            nomeAutor = autor;
        }

        Livro(const Livro &other)
            : nomeLivro(other.nomeLivro), nomeAutor(other.nomeAutor) {}

        Livro& operator = (const Livro& other) {
            if (this != &other) {
                nomeLivro = other.nomeLivro;
                nomeAutor = other.nomeAutor;
            }
            return *this;
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

        //funcao de procurar pelo nome do livro(ignora maisculas e minusculas)
        bool procurarNomeLivro(const std::string &procura) {
            if (procura.size() != nomeLivro.size()) return false;

            std::string lowerProcura = procura;
            std::string lowerNomeLivro = nomeLivro;

            std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::_Tolower);
            std::transform(lowerNomeLivro.begin(), lowerNomeLivro.end(), lowerNomeLivro.begin(), ::_Tolower);

            return lowerProcura == lowerNomeLivro;
        }
};