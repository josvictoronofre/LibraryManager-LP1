#ifndef LEITOR_H
#define LEITOR_H

#include <string>
#include <optional>
#include <algorithm>
#include "../include/Emprestimo.hpp"

class Leitor {
private:
    std::string nomeCompleto;
    Emprestimo emprestimo;

public:
    // Construtores
    Leitor();
    Leitor(const std::string &nome, const Emprestimo entrandaEmprestimo);

    // Getters e Setters
    std::string getNome();
    void setNome(std::string &nome);
    Emprestimo getEmprestimo();

    // Função de busca
    std::optional<Leitor> procurarLeitor(const std::string &procura);
};

#endif // LEITOR_H
