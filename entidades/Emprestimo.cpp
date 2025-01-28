#include "../include/Emprestimo.hpp"

// Construtor
Emprestimo::Emprestimo()
{
   
}

// Método para retornar o livro emprestado
Livro &Emprestimo::getLivro()
{
    return livro; // Retorna a referência para o livro
}

// Método para definir o livro emprestado
void Emprestimo::setLivro(const Livro &livro)
{
    this->livro = livro; // Atribui o livro ao Emprestimo
}

// Método para devolver o livro emprestado
void Emprestimo::devolverLivro()
{
    livro.devolver(); // Marca o livro como devolvido
}

// Método para adicionar um livro (usado apenas para setar o livro inicialmente)
void Emprestimo::adicionarLivro(const std::string &nomeLivro, const std::string &nomeAutor)
{
    livro = Livro(nomeLivro, nomeAutor); // Cria e define o livro
}
