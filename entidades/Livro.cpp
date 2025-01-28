#include "../include/Livro.hpp"
#include <algorithm>
Livro::Livro() {
    nomeLivro = "";
    nomeAutor = "";
}
// Construtores
Livro::Livro(const std::string &livro, const std::string &autor) {
    nomeLivro = livro;
    nomeAutor = autor;
}

Livro::Livro(const Livro &other)
    : nomeLivro(other.nomeLivro), nomeAutor(other.nomeAutor), emprestado(other.emprestado) {}

Livro& Livro::operator=(const Livro &other) {
    if (this != &other) {
        nomeLivro = other.nomeLivro;
        nomeAutor = other.nomeAutor;
        emprestado = other.emprestado;
    }
    return *this;
}

// Getters e Setters
std::string Livro::getNomeLivro() const {
    return nomeLivro;
}

std::string Livro::getAutor() const {
    return nomeAutor;
}

bool Livro::getEmprestado() const {
    return emprestado;
}

void Livro::setNomeAutor(const std::string &autor) {
    nomeAutor = autor;
}

void Livro::setNomeLivro(const std::string &livro) {
    nomeLivro = livro;
}

void Livro::emprestar() {
    emprestado = true;
}

void Livro::devolver() {
    emprestado = false;
}

// Função de procurar pelo nome do livro (ignora maiúsculas e minúsculas)
std::optional<Livro> Livro::procurarNomeLivro(const std::string &procura) const {
    std::string lowerProcura = procura;
    std::string lowerNomeLivro = nomeLivro;

    std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::tolower);
    std::transform(lowerNomeLivro.begin(), lowerNomeLivro.end(), lowerNomeLivro.begin(), ::tolower);

    // Comparando as strings em minúsculas
    if (lowerProcura == lowerNomeLivro) {
        return *this;
    }
    return std::nullopt;
}


std::optional<Livro> Livro::procurarNomeAutor(const std::string &procura) const {
    if (procura.size() != nomeAutor.size()) return std::nullopt;

    std::string lowerProcura = procura;
    std::string lowerNomeAutor = nomeAutor;

    // Corrigindo a transformação para minúsculas
    std::transform(lowerProcura.begin(), lowerProcura.end(), lowerProcura.begin(), ::tolower);
    std::transform(lowerNomeAutor.begin(), lowerNomeAutor.end(), lowerNomeAutor.begin(), ::tolower);

    if (lowerProcura == lowerNomeAutor) {
        return *this;
    }
    return std::nullopt;
}
