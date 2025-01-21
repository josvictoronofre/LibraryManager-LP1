#include <iostream>
#include <string>

class Leitor {

    private:
        std::string nomeCompleto;
    
    public:
        Leitor(std::string &nome) {
            nomeCompleto = nome;
        }

        std::string getNome() {
            return nomeCompleto;
        }

        void setNome(std::string &nome) {
            nomeCompleto = nome;
        }
};