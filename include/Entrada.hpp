#include <iostream>
#include "../entidades/Livro.cpp"
#include <string.h>
#include <vector>

std::vector<Livro> ler_csv(const char *filename);

void inserir_livro(std::vector<Livro> &vetor, Livro livro);
