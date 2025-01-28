#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <iostream>
#include <string>
#include "Livro.hpp"
#include "../include/Alerta.hpp"

class Emprestimo
{
private:
    Livro livro;
    Alerta alerta;

public:
    Emprestimo();

    // Métodos para manipular o livro emprestado
    Livro &getLivro();                                                               // Retorna o livro emprestado
    void setLivro(const Livro &livro);                                               // Define o livro emprestado
    void devolverLivro();                                                            // Devolve o livro emprestado
    void adicionarLivro(const std::string &nomeLivro, const std::string &nomeAutor); // Adiciona o livro
};

#endif // EMPRESTIMO_HPP
