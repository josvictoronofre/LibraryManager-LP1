#include <iostream>
#include "../include/Entrada.hpp"
#include <string.h>
#include <vector>

std::vector<Livro> ler_csv(const char *filename)
{
    char linha[1024];
    Livro livro_temp;
    std::vector<Livro> vetor;
    std::string temp;
    FILE *arquivo_csv = fopen(filename, "r");

    if (arquivo_csv == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    while (fgets(linha, sizeof(linha), arquivo_csv))
    {
        // Remover o '\n' no final da linha, se presente
        linha[strcspn(linha, "\n")] = 0;

        char *token = strtok(linha, ",");
        if (token == NULL)
            continue;
        temp = token;
        livro_temp.setNomeLivro(temp);

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            temp = token;
            livro_temp.setNomeAutor(temp);
        }

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            // Lê o status de "emprestado" e ajusta o livro
            if (strcmp(token, "1") == 0)
            {
                livro_temp.emprestar(); // Marca como emprestado
            }
            else 
            {
                livro_temp.devolver(); // Marca como disponível
            }
        }

        inserir_livro(vetor, livro_temp);
    }
    fclose(arquivo_csv);
    return vetor;
}

void inserir_livro(std::vector<Livro> &vetor, Livro livro)
{
    vetor.push_back(livro);
}