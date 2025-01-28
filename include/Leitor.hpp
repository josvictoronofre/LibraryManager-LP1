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
    Leitor(const std::string &nome, const Emprestimo &entradaEmprestimo); // Passagem por referência constante

    // Getters e Setters
    std::string getNome() const;           
    void setNome(const std::string &nome); 
    Emprestimo getEmprestimo() const;      

    // Função de busca
    std::optional<Leitor> procurarLeitor(const std::string &procura) const; 
};

#endif // LEITOR_H
