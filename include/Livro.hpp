#ifndef LIVRO_H
#define LIVRO_H

#include <string>
#include <optional>
#include <algorithm>

class Livro {
private:
    std::string nomeLivro;
    std::string nomeAutor;

public:

    Livro();
    Livro(const std::string &livro, const std::string &autor);
    Livro(const Livro &other);
    Livro& operator=(const Livro &other);


    std::string getNomeLivro();
    std::string getAutor();
    void setNomeAutor(std::string &autor);
    void setNomeLivro(std::string &livro);


    std::optional<Livro> procurarNomeLivro(const std::string &procura);
    std::optional<Livro> procurarNomeAutor(const std::string &procura);
};

#endif // LIVRO_H
