#ifndef ENTRADA_HPP
#define ENTRADA_HPP

#include <iostream>
#include "Livro.hpp"
#include <string.h>
#include <vector>

std::vector<Livro> ler_csv(const char *filename);

void inserir_livro(std::vector<Livro> &vetor, Livro livro);
#endif