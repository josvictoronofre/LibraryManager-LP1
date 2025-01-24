#include <iostream>
#include "../entidades/Livro.cpp"
#include <string.h>

void ler_csv(const char *filename)
{
    char linha[1024];
    Livro livro_temp;
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
        if (token == NULL) continue;
        temp = token;
        livro_temp.setNomeLivro(temp);

        token = strtok(NULL, ",");
        if (token != NULL)
        {
            temp = token;
            livro_temp.setNomeAutor(temp);
        }
        //inserir_livro(Livro_temp)
    }
    fclose(arquivo_csv);
}
