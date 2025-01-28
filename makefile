# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -g -Iinclude

# Arquivos fonte e objetos
SRC = main/App.cpp entidades/Emprestimo.cpp entidades/Livro.cpp entidades/Leitor.cpp entidades/Alerta.cpp entidades/Entrada.cpp
OBJ = $(SRC:.cpp=.o)

# Caminho do executável
EXEC = bin/main

# Regra principal para gerar o executável
all: $(EXEC)

# Como gerar o executável
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(EXEC)

# Regra de execução
.PHONY: run
run: $(EXEC)
	./$(EXEC)

# Como compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJ) $(EXEC)
	@echo "Diretório limpo"
