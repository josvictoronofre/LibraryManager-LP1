#include <iostream>
#include <string>
#include <algorithm>
#include <optional>
#include "Emprestimo.cpp"

class Leitor {

    private:
        std::string nomeCompleto;
        Emprestimo emprestimo;
    
    public:
        Leitor () {
            nomeCompleto = "";
            emprestimo = Emprestimo();
        }

        Leitor(const std::string &nome, const Emprestimo entrandaEmprestimo) {
            nomeCompleto = nome;
            emprestimo = entrandaEmprestimo;
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

        //Procurar pelo nome do leitor(ignora maisculas e minusculas)
        std::optional<Leitor> procurarLeitor(const std::string &procura) {
            if (procura.size() != nomeCompleto.size()) return std::nullopt;

            std::string lowerProcura = procura;
            std::string lowerNomeCompleto = nomeCompleto;

            std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::_Tolower);
            std::transform(lowerNomeCompleto.begin(), lowerNomeCompleto.end(), lowerNomeCompleto.begin(), ::_Tolower);

            if (lowerProcura == lowerNomeCompleto) {
                return *this;
            }
            return std::nullopt;
        }
};