#include <iostream>
#include <string>
#include "Emprestimo.cpp"

class Leitor {

    private:
        std::string nomeCompleto;
        Emprestimo emprestimo;
    
    public:
        Leitor(std::string &nome, Emprestimo emprestimo) {
            nomeCompleto = nome;
        }

        std::string getNome() {
            return nomeCompleto;
        }

        void setNome(std::string &nome) {
            nomeCompleto = nome;
        }

        Emprestimo getEmprestimo() {
            return emprestimo;
        }
};