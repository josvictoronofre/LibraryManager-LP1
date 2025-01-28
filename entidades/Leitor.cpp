#include "../include/Leitor.hpp"
#include <algorithm>  // Para std::transform

// Construtores
Leitor::Leitor() {
    nomeCompleto = "";
    emprestimo = Emprestimo();
}

Leitor::Leitor(const std::string &nome, const Emprestimo &entradaEmprestimo) {
    nomeCompleto = nome;
    emprestimo = entradaEmprestimo;
}

// Getters e Setters
std::string Leitor::getNome() const {
    return nomeCompleto;
}

void Leitor::setNome(const std::string &nome) {
    nomeCompleto = nome;
}

Emprestimo Leitor::getEmprestimo() const {
    return emprestimo;
}

// Função de buscar pelo nome do leitor (ignora maiúsculas e minúsculas)
std::optional<Leitor> Leitor::procurarLeitor(const std::string &procura) const {
    if (procura.size() != nomeCompleto.size()) return std::nullopt;

    std::string lowerProcura = procura;
    std::string lowerNomeCompleto = nomeCompleto;

    // Convertendo os dois strings para minúsculas
    std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::tolower);
    std::transform(lowerNomeCompleto.begin(), lowerNomeCompleto.end(), lowerNomeCompleto.begin(), ::tolower);

    // Comparando as versões minúsculas
    if (lowerProcura == lowerNomeCompleto) {
        return *this;
    }
    return std::nullopt;
}
