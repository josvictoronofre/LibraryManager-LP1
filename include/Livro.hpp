#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>
#include <optional>
#include <algorithm>

class Livro {
private:
    std::string nomeLivro;
    std::string nomeAutor;
    bool emprestado = false; 

public:
    // Construtores e operador de atribuição
    Livro();
    Livro(const std::string &livro, const std::string &autor);
    Livro(const Livro &other);
    Livro& operator=(const Livro &other);

    // Getters e Setters
    std::string getNomeLivro() const;
    std::string getAutor() const;
    bool getEmprestado() const;  
    void setNomeAutor(const std::string &autor);
    void setNomeLivro(const std::string &livro);
    void emprestar();
    void devolver();

    // Funções para procurar livro ou autor
    std::optional<Livro> procurarNomeLivro(const std::string &procura) const;
    std::optional<Livro> procurarNomeAutor(const std::string &procura) const;
};

#endif // LIVRO_HPP
