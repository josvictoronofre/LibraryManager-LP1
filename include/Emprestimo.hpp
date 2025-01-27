#ifndef EMPRESTIMO_H
#define EMPRESTIMO_H

#include <iostream>
#include <string>
#include "Livro.hpp"
#include "Alerta.hpp"

class Emprestimo {
private:
    Livro livros[3];
    Alerta alertas[3];

    void verificar_alertas_automatico();

public:
    Emprestimo();

    // Função de adicionar livros ao vetor
    void adicionarLivros(int posicao, const std::string &nomeLivro, const std::string &nomeAutor);
};

#endif // EMPRESTIMO_H
