#include <iostream>
#include <string>
#include <algorithm>
#include <optional>

class Livro {

    private:
        std::string nomeLivro;
        std::string nomeAutor;

    public:
        //Construtores(C++ eu te odeio)
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

        //Getters e Setters
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
        std::optional<Livro> procurarNomeLivro(const std::string &procura) {
            if (procura.size() != nomeLivro.size()) return std::nullopt;

            std::string lowerProcura = procura;
            std::string lowerNomeLivro = nomeLivro;

            std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::_Tolower);
            std::transform(lowerNomeLivro.begin(), lowerNomeLivro.end(), lowerNomeLivro.begin(), ::_Tolower);

            if (lowerProcura == lowerNomeLivro) {
                return *this;
            }
            else return std::nullopt;
        }

        //funcao de procurar pelo nome do autor(ignora maisculas e minusculas)
        std::optional<Livro> procurarNomeAutor(const std::string &procura) {
            if (procura.size() != nomeAutor.size()) return std::nullopt;

            std::string lowerProcura = procura;
            std::string lowerNomeAutor = nomeAutor;

            std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::_Tolower);
            std::transform(lowerNomeAutor.begin(), lowerNomeAutor.end(), lowerNomeAutor.begin(), ::_Tolower);

            if (lowerProcura == lowerNomeAutor) {
                return *this;
            }
            else return std::nullopt;
        }
};